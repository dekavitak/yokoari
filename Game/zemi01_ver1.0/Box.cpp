#include"DxLib.h"
#include"Box.h"
#include"Define.h"
#include"Enum.h"
#include"Hit.h"
#include"Player.h"

// 構造体オブジェクトの生成
struct Box box[10];



// 画像ハンドル
int BoxImage;

// 段ボールの生成時に使用する変数
int SpawnCnt;   // 段ボール出現までのカウント
int TakeCnt;    // 現在持っている数
int DeliveryNum;// 納品した数を格納する変数

// マウスの状態を格納する変数
int Mouse_Input;

/***************************************
機能　：段ボール関連の初期化
引数　：配列の部屋番号
返り値：None
***************************************/
void BoxInitialize(int number) {

	// 変数などの初期化
	
	box[number].mLivingFlg = false;
	box[number].mTakeFlg = false;
	box[number].mX = 500;
	box[number].mY = -50;
	box[number].mCenterX = box[number].mX + (BOX_WIDTH / 2);
	box[number].mCenterY = box[number].mY + (BOX_HEIGHT / 2);
	
	for (int i = 0; i < BOX_LENGTH; i++) {
		box[i].mLivingFlg = false;
		box[i].mTakeFlg = false;
		box[i].mX = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
		box[i].mY = 100;
		box[i].mCenterX = box[i].mX + (BOX_WIDTH / 2);
		box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);
	}

	InitBoxHitFlg();
	SpawnCnt = 0;
	TakeCnt = 0;
	DeliveryNum = 0;
	// 画像のロード
	BoxImage = LoadGraph("img/Box.png");
}

/***************************************
機能　：段ボールの描画
引数　：None
返り値：None
***************************************/
void BoxRender() {
	// 描画
	for (int i = 0; i < BOX_LENGTH; i++) {

		// 段ボールが存在するなら
		if (box[i].mLivingFlg == true) {

			// 段ボールがプレイヤーに持たれていないなら
			if (box[i].mTakeFlg == false) {
				DrawGraph(box[i].mX, box[i].mY, BoxImage, TRUE);
			}
			// 段ボールがプレイヤーに持たれているなら
			else {
				// プレイヤーの中心x座標 - プレイヤーの横幅 / 4,
				// プレイヤーの中心y座標 - ((プレイヤーの縦幅 / 4) + ((持っている数 - 1) * 段ボールの縦幅)),
				// 以上の座標に描画
				DrawGraph(box[i].mX, box[i].mY, BoxImage, TRUE);
			}
		}
	}

	// 残り納品数の表示
	DrawFormatString(0, 150, GetColor(255, 255, 255), "ノルマまで残り%d個", (GOAL - DeliveryNum));
	// 持てる数の表示
	DrawFormatString(0, 190, GetColor(255, 255, 255), "持てる数:%d個", (BOX_TAKE_LIMIT - TakeCnt));

}

/***************************************
機能　：段ボールの動き
引数　：配列の部屋番号
返り値：None
***************************************/
void BoxMove(int number) {
	

	// 段ボールが存在するなら
	if (box[number].mLivingFlg == true) {

		// 段ボールが持たれていないなら
		if (box[number].mTakeFlg == false) {
			box[number].mY += BOX_SPEED;
			box[number].mCenterY = box[number].mY + (BOX_HEIGHT / 2);
		}
		// 持たれているなら
		else {
			// プレイヤーについていかせる
			box[number].mX = ReturnPlayerCenterX() - (PLAYER_WIDTH / 4);
		}
	}
}

/****************************************
機能　：段ボールの更新
引数　：構造体の配列の部屋番号
返り値：None
*****************************************/
void BoxUpdate() {

	for (int i = 0; i < BOX_LENGTH; i++) {
		// 段ボールが存在していないなら
		if (box[i].mLivingFlg == false) {

			// カウントが生成する時間になったら
			if (SpawnCnt == BOX_SPAWN_TIME) {
				// 段ボールを出現させる
				box[i].mLivingFlg = true;
				SpawnCnt = 0;
			}
		}
		// 存在しているなら
		else {
			// 段ボールを動かす
			BoxMove(i);
			// 画面外か判定
			BoxMoveLimit(i);
			// プレイヤーのいる高さに段ボールがあるなら
			if ((box[i].mY + BOX_HEIGHT) >= PLAYER_HIT_CEIL &&
				box[i].mY <= PLAYER_HIT_FLOOR &&
				box[i].mTakeFlg == false) {

				// 当たり判定を行う
				BoxAndPlayerHit(ReturnPlayerRight(), ReturnPlayerLeft(),
					box[i].mCenterX + (PLAYER_WIDTH / 2), box[i].mCenterX - (BOX_WIDTH / 2));
			}
			// 段ボールがプレイヤーに触れたなら
			if (ReturnBoxHitFlg() == PLAYER) {

				// 持っている段ボールが５個以下なら
				if (TakeCnt < BOX_TAKE_LIMIT) {

					// 持っている数を加算する
					TakeCnt++;

					// 取得時SEの再生
					PlaySoundFile(AITEM_SE, DX_PLAYTYPE_BACK);

					// 段ボールを持たれている状態にする
					box[i].mTakeFlg = true;

					// 座標を移動(座標の詳細は描画部分にコメント)
					box[i].mX = ReturnPlayerCenterX() - (PLAYER_WIDTH / 4);
					box[i].mY = ReturnPlayerCenterY() - ((PLAYER_HEIGHT / 4) + ((TakeCnt - 1) * BOX_HEIGHT));
				}

				// 当たり判定の初期化
				InitBoxHitFlg();
			}
		}
	}
	// 生成カウントの加算
	SpawnCnt++;
	

	// マウスの状態を取得
	Mouse_Input = GetMouseInput();

	// 左クリックされたら
	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		for (int i = 0; i < BOX_LENGTH; i++) {
			// 持たれている荷物があるなら
			if (box[i].mTakeFlg == true) {

				// SEの再生
				PlaySoundFile(AITEM_SE, DX_PLAYTYPE_BACK);

				// 段ボールの初期化
				box[i].mTakeFlg = false;
				box[i].mLivingFlg = false;
				box[i].mX = 500;
				box[i].mY = -50;
				box[i].mX = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
				box[i].mY = 100;
				box[i].mCenterX = box[i].mX + (BOX_WIDTH / 2);
				box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);
				TakeCnt--;
				DeliveryNum++;
			}
		}
	}

}

/***************************************
機能　：段ボールの動きの制限
引数　：None
返り値：None
***************************************/
void BoxMoveLimit(int number) {

	// 画面下に出たら
	if (box[number].mY > STAGE_FLOOR) {
		// 段ボールの初期化
		box[number].mLivingFlg = false;
		box[number].mX = 500;
		box[number].mY = -50;
		box[number].mX = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
		box[number].mY = 100;
		box[number].mCenterX = box[number].mX + (BOX_WIDTH / 2);
		box[number].mCenterY = box[number].mY + (BOX_HEIGHT / 2);

	}

	
}

/****************************************
機能　：段ボールの当たり判定の右端を返す
引数　：構造体の配列の部屋番号
返り値：段ボールの当たり判定の右端
*****************************************/
int ReturnBoxRight(int number) {

	return box[number].mCenterX + (PLAYER_WIDTH / 2);

}

/****************************************
機能　：段ボールの当たり判定の左端を返す
引数　：構造体の配列の部屋番号
返り値：段ボールの当たり判定の左端
*****************************************/
int ReturnBoxLeft(int number) {

	return box[number].mCenterX - (BOX_WIDTH / 2);

}

/****************************************
機能　：段ボールの持たれているフラグを返す
引数　：構造体の配列の部屋番号
返り値：box.mTakeFlg
*****************************************/
int ReturnBoxTakeFlg(int number) {

	return box[number].mTakeFlg;

}

/****************************************
機能　：段ボールの持っている数を返す
引数　：None
返り値：TakeCnt
*****************************************/
int ReturnTakeCnt() {

	return TakeCnt;

}

/****************************************
機能　：段ボールの納品した数の合計を返す
引数　：None
返り値：DeliveryNum
*****************************************/
int ReturnDeliveryNum() {

	return DeliveryNum;

}

/***************************************
機能  : 段ボールの持っている数を0にする
引数  : None
返り値: None
***************************************/
void ResetTakeCnt() {

	for (int i = 0; i < BOX_LENGTH; i++) {

		// 持たれている荷物があるなら
		if (box[i].mTakeFlg == true) {
			// 段ボールの初期化
			box[i].mTakeFlg = false;
			box[i].mLivingFlg = false;
			box[i].mX = GetRand(STAGE_RIGHT - STAGE_LEFT) + STAGE_LEFT;
			box[i].mY = 100;
			box[i].mCenterX = box[i].mX + (BOX_WIDTH / 2);
			box[i].mCenterY = box[i].mY + (BOX_HEIGHT / 2);
			TakeCnt--;
		}
	}
}