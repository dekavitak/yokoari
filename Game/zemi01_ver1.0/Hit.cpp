#include"DxLib.h"
#include"Hit.h"
#include"Define.h"
#include"Enum.h"

// 構造体オブジェクトの生成
struct Hit box;
struct Hit player;

/*******************************************
機能　：段ボールの当たり判定フラグの初期化
引数　：None
返り値：None
*******************************************/
void InitBoxHitFlg() {
	box.mHitFlg = NEUTRAL;
}

/*******************************************
機能　：プレイヤーの当たり判定フラグの初期化
引数　：None
返り値：None
*******************************************/
void InitPlayerHitFlg() {
	player.mHitFlg = NEUTRAL;
}

/*******************************************
機能　：段ボールの当たり判定フラグを返す
引数　：None
返り値：box.mHitFlg
box.mHitFlg　：段ボールの当たり判定フラグ
*******************************************/
int ReturnBoxHitFlg() {
	return box.mHitFlg;
}

/*******************************************
機能　：プレイヤーの当たり判定フラグを返す
引数　：None
返り値：player.mHitFlg
player.mHitFlg　：プレイヤーの当たり判定フラグ
*******************************************/
int ReturnPlayerHitFlg() {
	return player.mHitFlg;
}

/******************************************
機能　：段ボールとプレイヤーの当たり判定
引数　：プレイヤーと段ボールの当たる範囲の情報
返り値：None
******************************************/
void BoxAndPlayerHit(int player_right, int player_left, int box_right, int box_left) {

	if (player_right >= box_left &&
		player_left <= box_right) {

		player.mHitFlg = BOX;
		box.mHitFlg = PLAYER;
	}
}