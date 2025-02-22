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
void BoxInitialize(int); // 段ボールの初期化
void BoxRender();       // 段ボールの描画
void BoxMove(int);       // 段ボールの動き
void BoxUpdate();  // 段ボールの更新処理
void BoxMoveLimit(int);     // 段ボールの動きの制限
int ReturnBoxRight(int);    // 段ボールの当たり判定の右端を返す
int ReturnBoxLeft(int);     // 段ボールの当たり判定の左端を返す
int ReturnBoxTakeFlg(int);     // 段ボールの持たれているフラグを返す
int ReturnTakeCnt();           // 段ボールを持っている数を返す
int ReturnDeliveryNum();       // 段ボールを納品した数の合計を返す
void ResetTakeCnt();         // 段ボールを持ってる数をリセットする


#endif // !_BOX_H_