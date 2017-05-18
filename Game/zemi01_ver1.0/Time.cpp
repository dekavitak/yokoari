#include"DxLib.h"
#include"Time.h"
#include<time.h>
#include"Define.h"


time_t start, now;  // 開始時の時間, 経過時間
bool timer_flg;     // 制限時間が経過したかどうかのフラグ

/****************************************
機能　：タイマーの初期化
引数　：None
返り値：None
*****************************************/
void TimerInitialize() {

	time(&start);
	timer_flg = false;
	
}

/****************************************
機能　：タイマーの更新
引数　：None
返り値：None
*****************************************/
void TimerUpdate() {
	
	// 経過時間の取得
	time(&now);
	// 60秒経ったら
	if ((start + MAX_TIME) <= now) {
		timer_flg = true;
	}
	// 制限時間の表示
	DrawFormatString(0, 130, GetColor(255, 255, 255), "制限時間:%d", (int)((start + MAX_TIME) - now));

}

/****************************************
機能　：タイマーのフラグを返す
引数　：None
返り値：None
*****************************************/
int ReturnTimerFlg() {

	return timer_flg;

}