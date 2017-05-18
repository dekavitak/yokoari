#ifndef SYSTEM_MANAGER_H
#define SYSTEM_MANAGER_H
/***************************************
クラス名 : SystemManager
作成者   : 高津 優太
概要     : システムの根幹を担うクラス
***************************************/

#include "SceneManager.h"



class SystemManager
{
public:
	SystemManager();  // コンストラクタ
	~SystemManager(); // デストラクタ

	SceneManager sceneMgr; // シーンマネージャークラス

	int Update();     // 更新処理

private:
	void GameIsInit();            // ゲームの初期化
	void GameIsEnd();             // ゲームの修了処理
	void GetWindowMode(int, int); // ウィンドウサイズ指定
};

#endif //SYSTEM_MANAGER_H