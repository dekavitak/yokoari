/***************************************
クラス名 : ISceneChanger
作成者   : 高津 優太
概要     : シーンを変更するためのインターフェースクラス
***************************************/

#pragma once

typedef enum {
	eScene_Title,    // タイトル
	eScene_Menu,     // メニュー
	eScene_Tutorial, // チュートリアル
	eScene_Config,   // 設定
	eScene_Game,     // ゲーム
	eScene_Result,   // リザルト
	eScene_Neutral,  // 無し
}eScene;

class ISceneChanger
{
public:
	virtual ~ISceneChanger() = 0;  // デストラクタ
	virtual void ChangeScene(eScene NextScene) = 0;
};

