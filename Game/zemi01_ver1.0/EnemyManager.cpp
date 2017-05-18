#include "DxLib.h"
#include "EnemyManager.h"
#include "AdultEnemy.h"
#include "KidsEnemy.h"
#include "WaterEnemy.h"


/***************************************
関数名 : EnemyManager()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
EnemyManager::EnemyManager()
{
	mEnemy[0] = (EnemyTask*) new WaterEnemy;
	mEnemy[1] = (EnemyTask*) new AdultEnemy;
	mEnemy[2] = (EnemyTask*) new KidsEnemy;

}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void EnemyManager::Initialize() {
	
}

/***************************************
関数名 : Finalize()
概要   : 終了処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void EnemyManager::Finalize() {
	delete[] mEnemy;

}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void EnemyManager::Update() {
	mEnemy[0]->Update();
	mEnemy[1]->Update();
	mEnemy[2]->Update();
}

/***************************************
関数名 : Draw()
概要   : 描画処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void EnemyManager::Draw() {
	mEnemy[0]->Draw();
	mEnemy[1]->Draw();
	mEnemy[2]->Draw();
}

