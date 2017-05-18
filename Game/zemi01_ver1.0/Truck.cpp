#include "DxLib.h"
#include "Truck.h"
#include <time.h>
#include "Define.h"
#include "Enum.h"

// 構造体オブジェクトの生成
struct TRUCK truck;
time_t TruckStart, TruckNow;        // 納品者が来るまでの計測開始時間と経過時間

// 画像ハンドル
int TruckImage[2];


/**************************************************
機能　：納品者の初期化
引数　：None
返り値：None
**************************************************/
void TruckInitialize() {

	// 変数などの初期化
	truck.mX = 0;
	truck.mY = 0;
	truck.mCenterX = truck.mX + (TRUCK_WIDTH / 2);
	truck.mCenterY = truck.mY + (TRUCK_HEIGHT / 2);
	truck.mHitCeil = truck.mCenterY - TRUCK_HEIGHT;
	truck.mHitFloor = truck.mCenterY + TRUCK_HEIGHT;
	truck.mDirec = NEUTRAL;
	truck.mSpeed = (int)(720 / DELI_PASS_TIME);
	truck.mGetFlg = false;
	truck.mLivingFlg = false;

	// 時間取得
	time(&TruckStart);

	// 画像のロード
	LoadDivGraph(TRUCK_OBJECT, 2, 2, 1, TRUCK_WIDTH, TRUCK_HEIGHT, TruckImage);
}

/***************************************************
機能　：納品者の動き
引数　：None
返り値：None
***************************************************/
void TruckMove() {

	// 納品者を動かす
	truck.mY += truck.mSpeed;

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
			truck.mLivingFlg = false;
			time(&TruckStart);
		}
	}

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

}