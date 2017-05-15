#ifndef _BOX_H_
#define _BOX_H_

// 段ボールの基本データ
struct Box {
	bool mLivingFlg; // 段ボールのアクティブ状態
	bool mTakeFlg;   // 段ボールを持たれているかのフラグ
	int mX;          // 段ボールのx座標
	int mY;          // 段ボールのy座標
	int mCenterX;    // 段ボールの中心x座標
	int mCenterY;    // 段ボールの中心y座標
};

// 段ボールの関数
void BoxInitialize(); // 段ボールの初期化
void BoxView();       // 段ボールの描画
void BoxMove();       // 段ボールの動き
void BoxMoveLimit(int);     // 段ボールの動きの制限
int ReturnBoxRight(int);    // 段ボールの当たり判定の右端を返す
int ReturnBoxLeft(int);     // 段ボールの当たり判定の左端を返す
int ReturnBoxTakeFlg(int);     // 段ボールの持たれているフラグを返す


#endif // !_BOX_H_