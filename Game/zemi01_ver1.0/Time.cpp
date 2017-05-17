#include"DxLib.h"
#include"Time.h"
#include<time.h>
#include"Define.h"

time_t LimitStart, Now;  // 開始時の時間, 経過時間
time_t DeliStart;        // 納品者が来るまでの計測開始時間
bool timer_flg;     // 制限時間が経過したかどうかのフラグ
bool deli_flg;      // 納品者情報の表示の切り替えフラグ

/****************************************
機能　：タイマーの初期化
引数　：None
返り値：None
*****************************************/
void TimerInitialize() {

	time(&LimitStart);
	time(&DeliStart);
	timer_flg = false;
	deli_flg = false;
	
}

/****************************************
機能　：タイマーの更新
引数　：None
返り値：None
*****************************************/
void TimerUpdate() {
	
	// 経過時間の取得
	time(&Now);
	// 制限時間が過ぎたら
	if ((LimitStart + MAX_TIME) <= Now) {
		timer_flg = true;
	}
	// 制限時間の表示
	DrawFormatString(0, 130, GetColor(255, 255, 255), "制限時間:%d秒", (int)((LimitStart + MAX_TIME) - Now));

	time(&Now);
	// 納品者が到着していないなら
	if (deli_flg == false) {
		// 到着の時間になったら
		if ((DeliStart + DELI_GET_TIME) <= Now) {
			deli_flg = true;
			time(&DeliStart);
		}
		// 時間の表示
		DrawFormatString(0, 170, GetColor(255, 255, 255), "納品者が来るまで:%d秒", (int)((DeliStart + DELI_GET_TIME) - Now));
	}
	// 到着しているなら
	else {
		// 通り過ぎる時間になったら
		if ((DeliStart + DELI_PASS_TIME) <= Now) {
			deli_flg = false;
			time(&DeliStart);
		}
		// 時間の表示
		DrawFormatString(0, 170, GetColor(255, 255, 255), "納品者が通過するまで:%d秒", (int)((DeliStart + DELI_PASS_TIME) - Now));
	}

}

/****************************************
機能　：タイマーのフラグを返す
引数　：None
返り値：None
*****************************************/
int ReturnTimerFlg() {

	return timer_flg;

}