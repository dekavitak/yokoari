// プレイヤーの移動方向
enum eDIREC {

	NEUTRAL,  // 0
	RIGHT,    // 1
	LEFT,     // 2
};


// 当たり判定関連(何に当たったか)
enum eHIT {

	//NEUTRAL, // 0
	ENEMY = 1, // 1
	BOX,       // 2
	PLAYER,    // 3
};