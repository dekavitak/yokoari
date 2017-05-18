#include "DxLib.h"
#include "Truck.h"
#include "Player.h"
#include <time.h>
#include "Define.h"
#include "Enum.h"

// 構造体オブジェクトの生成
struct TRUCK truck;
time_t TruckStart, TruckNow;        // 納品者が来るまでの計測開始時間と経過時間

// 画像ハンドル
int TruckImage;

// プレイヤーと納品者の距離を格納する変数
int Len;


/**************************************************
機能　：納品者の初期化
引数　：None
返り値：None
**************************************************/
void TruckInitialize() {

	// 変数などの初期化
	truck.mDirec = GetRand(1) + 1;

	// 乱数により描画するx座標を変える
	if (truck.mDirec == RIGHT) {
		truck.mX = TRUCK_SPAWN_RIGHT;
	}
	else {
		truck.mX = TRUCK_SPAWN_LEFT;
	}
	truck.mY = 750;
	truck.mCenterX = truck.mX + (TRUCK_WIDTH / 2);
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;
	truck.mHitLeft = truck.mCenterX - TRUCK_WIDTH;
	truck.mHitRight = truck.mCenterX + TRUCK_WIDTH;
	truck.mGetFlg = false;
	truck.mLivingFlg = true;
	// プレイヤーと納品者の距離を算出
	Len = ReturnPlayerCenterY() - truck.mCenterY;

	truck.mSpeed = (int)(Len / (DELI_GET_TIME * 60));
	// 時間取得
	time(&TruckStart);

	// 画像のロード
	TruckImage = LoadGraph(TRUCK_OBJECT);
}

/***************************************************
機能　：納品者の動き
引数　：None
返り値：None
***************************************************/
void TruckMove() {

	// 納品者を動かす
	if (truck.mGetFlg == false) {
		truck.mY--;
	}
	else{
		truck.mY++;
    }

	// 止める
	if (truck.mY < 300) {
		truck.mY = 300;
	}
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;

}

/***************************************************
機能　：納品者の更新
引数　：None
返り値：None
***************************************************/
void TruckUpdate() {

	time(&TruckNow);
	// 納品者が到着していないなら
	if (truck.mGetFlg == false) {
		// 到着の時間になったら
		if ((TruckStart + DELI_GET_TIME) <= TruckNow) {
			truck.mGetFlg = true;
			truck.mLivingFlg = true;
			time(&TruckStart);
		}
	}
	// 到着しているなら
	else {
		// 通り過ぎる時間になったら
		if ((TruckStart + DELI_PASS_TIME) <= TruckNow) {
			truck.mGetFlg = false;
			time(&TruckStart);
		}
	}

	TruckMove();

}

/***************************************************
機能　：納品者の描画
引数　：None
返り値：None
***************************************************/
void TruckRender() {

	time(&TruckNow);
	// 納品者が到着していないなら
	if (truck.mGetFlg == false) {
		// 時間の表示
		DrawFormatString(0, 170, GetColor(255, 255, 255), "納品者が来るまで:%d秒", (int)((TruckStart + DELI_GET_TIME) - TruckNow));
	}
	// 到着しているなら
	else {
		// 時間の表示
		DrawFormatString(0, 170, GetColor(255, 255, 255), "納品者が通過するまで:%d秒", (int)((TruckStart + DELI_PASS_TIME) - TruckNow));
	}

	DrawGraph(truck.mX, truck.mY, TruckImage, TRUE);
}

/****************************************
機能　：納品者の納品範囲の上限を返す
引数　：None
返り値：truck.mHitCeil
*****************************************/
int ReturnTruckHitCeil() {

	return truck.mHitCeil;

}

/****************************************
機能　：納品者の納品範囲の下限を返す
引数　：None
返り値：truck.mHitFloor
*****************************************/
int ReturnTruckHitFloor() {

	return truck.mHitFloor;

}

/****************************************
機能　：納品者の納品範囲の左側を返す
引数　：None
返り値：truck.mHitLeft
*****************************************/
int ReturnTruckHitLeft() {

	return truck.mHitLeft;

}

/****************************************
機能　：納品者の納品範囲の右側を返す
引数　：None
返り値：truck.mHitRight
*****************************************/
int ReturnTruckHitRight() {

	return truck.mHitRight;

}