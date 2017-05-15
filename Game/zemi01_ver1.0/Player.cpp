#include "DxLib.h"
#include "Player.h"
#include "Define.h"
#include "Enum.h"
#include "Hit.h"
#include "Box.h"

// 構造体オブジェクトの生成
struct PLAYER player;

// 画像ハンドル
int PlayerImage[4];

// マウスの座標を格納する変数
int Mouse_x, Mouse_y;

/****************************************
機能　：プレイヤー関連の変数等の初期化
引数　：None
返り値：None
*****************************************/
void PlayerInitialize() {

	// プレイヤーの初期化
	player.mDirec = NEUTRAL;
	player.mX = 384;
	player.mY = 289;
	player.mCenterX = player.mX + (PLAYER_WIDTH / 2);
	player.mCenterY = player.mY + (PLAYER_HEIGHT / 2);
	player.mSpeed = 5;
	player.mGraphNum = 0;
	player.mAnimationCnt = 0;
	player.mTakeFlg = 0;
	player.mGraphFlg = false;
    InitPlayerHitFlg();

	// 画像のロード
	LoadDivGraph("img/yokoari.png", 4, 4, 1, 128, 128, PlayerImage);

}

/****************************************
機能　：プレイヤーの描画
引数　：None
返り値：None
*****************************************/
void PlayerView() {

	// 表示する画像の更新
	PlayerAnimation();

	// プレイヤーの描画
	DrawGraph(player.mX, player.mY, PlayerImage[player.mGraphNum + player.mTakeFlg], TRUE);

}

/****************************************
機能　：プレイヤーの操作
引数　：None
返り値：None
*****************************************/
void PlayerController() {

	// マウスの座標を取得
	GetMousePoint(&Mouse_x, &Mouse_y);

	// マウスの座標によって移動する向き変更
	if (player.mCenterX > Mouse_x + player.mSpeed) {
		player.mDirec = LEFT;
	}
	else if (player.mCenterX < Mouse_x - player.mSpeed) {
		player.mDirec = RIGHT;
	}
	else {
		player.mCenterX = Mouse_x;
		player.mDirec = NEUTRAL;
	}

}

/****************************************
機能　：プレイヤーの動き
引数　：None
返り値：None
*****************************************/
void PlayerMove() {

	// プレイヤーの移動する向きを更新
	PlayerController();

	// 移動する向きによってプレイヤーの座標を動かす
	if (player.mDirec == RIGHT) {
		player.mX += player.mSpeed;
	}
	else if (player.mDirec == LEFT) {
		player.mX -= player.mSpeed;
	}

	// 動きの制御
	PlayerMoveLimit();

	// 持っている状態の更新
	for (int i = 0; i < BOX_LENGTH; i++) {
		// 持っているなら
		if (ReturnBoxTakeFlg(i) == true) {
			// 画像を切り替えるフラグをtrueにする
			player.mGraphFlg = true;
			break;
		}
		// 持っていないなら
		else {
			// 画像を切り替えるフラグをfalseにする
			player.mGraphFlg = false;
		}
	}
	// 画像を切り替える
	if (player.mGraphFlg == true) {
		player.mTakeFlg = BOX;
	}
	else {
		player.mTakeFlg = NEUTRAL;
	}
	// 中心座標の更新
	player.mCenterX = player.mX + (PLAYER_WIDTH / 2);
}

/****************************************
機能　：プレイヤーの動きの制限
引数　：None
返り値：None
*****************************************/
void PlayerMoveLimit() {

	// 画面外に出ようとしたら
	if (player.mX <= STAGE_LEFT) {
		player.mX = STAGE_LEFT;
	}
	else if (player.mX >= STAGE_RIGHT) {
		player.mX = STAGE_RIGHT;
	}
}

/****************************************
機能　：プレイヤーのアニメーション
引数　：None
返り値：None
*****************************************/
void PlayerAnimation() {

	// 一定時間経過したら
	if (player.mAnimationCnt >= 30) {

		// 描画する画像を切り替え
		if (player.mGraphNum == 0) {
			player.mGraphNum = 1;
		}
		else {
			player.mGraphNum = 0;
		}

		// カウントをリセット
		player.mAnimationCnt = 0;
	}

	// カウントを加算
	player.mAnimationCnt++;

}

/****************************************
機能　：プレイヤーの当たり判定の右端を返す
引数　：None
返り値：プレイヤーの当たり判定の右端
*****************************************/
int ReturnPlayerRight() {

	return player.mCenterX + (PLAYER_WIDTH / 2);

}

/****************************************
機能　：プレイヤーの当たり判定の左端を返す
引数　：None
返り値：プレイヤーの当たり判定の左端
*****************************************/
int ReturnPlayerLeft() {

	return player.mCenterX - (PLAYER_WIDTH / 2);

}

/****************************************
機能　：プレイヤーの中心x座標を返す
引数　：None
返り値：player.mCenterX
*****************************************/
int ReturnPlayerCenterX() {

	return player.mCenterX;

}

/****************************************
機能　：プレイヤーの中心y座標を返す
引数　：None
返り値：player.mCenterY
*****************************************/
int ReturnPlayerCenterY() {

	return player.mCenterY;

}