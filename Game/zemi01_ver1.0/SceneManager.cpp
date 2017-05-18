#include "DxLib.h"
#include "Title.h"
#include "Menu.h"
#include "Tutorial.h"
#include "Config.h"
#include "Game.h"
#include "Result.h"
#include "SceneManager.h"

/***************************************
関数名 : SceneManager()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : 最初の画面を表示(タイトル)
***************************************/
SceneManager::SceneManager() : mNextScene(eScene_Neutral) // 次のシーン管理変数
{

	mScene = (SceneTask*) new Title(this);
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void SceneManager::Initialize() {
	mScene->Initialize();
}

/***************************************
関数名 : Finalize()
概要   : 終了処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void SceneManager::Finalize() {
	mScene->Finalize();
}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void SceneManager::Update() {
	if (mNextScene != eScene_Neutral) {    // 次のシーンがセットされていたら
		mScene->Finalize();                // 現在のシーンの終了処理を実行
		delete mScene;
		switch (mNextScene) {       // シーンによって処理を分岐
		case eScene_Menu:           // 次の画面がメニューなら
			mScene = (SceneTask*) new Menu(this);   //メニュー画面のインスタンスを生成する
			break; // 以下略
		case eScene_Game:
			mScene = (SceneTask*) new Game(this);
			break;
		case eScene_Config:
			mScene = (SceneTask*) new Config(this);
			break;
		case eScene_Title:
			mScene = (SceneTask*) new Title(this);
			break;
		case eScene_Tutorial:
			mScene = (SceneTask*) new Tutorial(this);
			break;
		case eScene_Result:
			mScene = (SceneTask*) new Result(this);
			break;
		}
		mNextScene = eScene_Neutral;    // 次のシーン情報をクリア
		mScene->Initialize();           // シーンを初期化
	}

	mScene->Update(); // シーンの更新
}

/***************************************
関数名 : Draw()
概要   : 描画処理
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
void SceneManager::Draw() {
	mScene->Draw(); // シーンの描画
}

// 引数 nextScene にシーンを変更する
void SceneManager::ChangeScene(eScene NextScene) {
	mNextScene = NextScene;    // 次のシーンをセットする
}