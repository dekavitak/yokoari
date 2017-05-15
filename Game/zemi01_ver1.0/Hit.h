#ifndef _HIT_H_
#define _HIT_H_

// キャラなどの当たり判定フラグ
struct Hit {
	int mHitFlg;
};

// 当たり判定の関数
void InitBoxHitFlg();    // 段ボールの当たり判定フラグの初期化
void InitPlayerHitFlg(); // プレイヤーの当たり判定フラグの初期化
int ReturnBoxHitFlg();      // 段ボールの当たり判定フラグを返す	
int ReturnPlayerHitFlg();   // プレイヤーの当たり判定フラグを返す
void BoxAndPlayerHit(int, int, int, int);  // 段ボールとプレイヤーの当たり判定


#endif _HIT_H_