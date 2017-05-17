#ifndef _PLAYER_H_
#define _PLAYER_H_

// プレイヤーの基本データ
struct PLAYER {
	int mX;				 // x座標
	int mY;				 // y座標
	int mCenterX;		 // 中心のx座標
	int mCenterY;        // 中心のy座標
	int mSpeed;		     // 移動速度
	int mDirec;          // 移動する向き
	int mGraphNum;       // 表示する画像の番号
	int mAnimationCnt;   // アニメーションのカウント
	int mTakeFlg;        // 箱を持っているかどうかのフラグ
	bool mGraphFlg;      // 画像切り替えのフラグ
};


// プレイヤーの関数

void PlayerInitialize();    // 初期化
void PlayerRender();          // プレイヤーの描画
void PlayerController();    // 操作
void PlayerMove();          // プレイヤーの動き
void PlayerUpdate();        // プレイヤーの更新
void PlayerMoveLimit();     // プレイヤーの動きの制限
void PlayerAnimation();     // プレイヤーのアニメーション
int ReturnPlayerRight();    // プレイヤーの当たり判定の右端を返す
int ReturnPlayerLeft();     // プレイヤーの当たり判定の左端を返す
int ReturnPlayerCenterX();  // プレイヤーの中心x座標を返す
int ReturnPlayerCenterY();  // プレイヤーの中心y座標返す

#endif // !_PLAYER_H_