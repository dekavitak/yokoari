#ifndef _TRUCK_H_
#define _TRUCK_H_

// 納品者の基本データ
struct TRUCK {
	int mX;
	int mY;
	int mCenterX;
	int mCenterY;
	int mHitCeil;
	int mHitFloor;
	int mDirec;
	bool mLivingFlg;
};

// 納品者の関数
void TruckIntialize();         // 納品者の初期化
void TruckMove();              // 納品者の動き
void TruckUpdate();            // 納品者の更新
void TruckRender();            // 納品者の描画
int ReturnTruckHitCeil();      // 納品者の納品範囲の上限を返す
int ReturnTruckHitCeil();      // 納品者の納品範囲の下限を返す

#endif // !_TRUCK_H_
