#include "DxLib.h"
#include "Title.h"
#include "Define.h"



/***************************************
関数名 : Title()
概要   : コンストラクタ
引数   : なし
戻り値 : なし
備考   : なし
***************************************/
Title::Title(ISceneChanger * changer) : SceneTask(changer)
{
}

/***************************************
関数名 : Initialize()
概要   : 初期化処理
引数   : なし
戻り値 : なし
備考   : 画像をロードする
***************************************/
void Title::Initialize()
{
	SetFontSize(64);
	m_sceneHandle = LoadGraph(TITLE_PIC);
	mSoundPlayHandle = LoadSoundMem(BACK_BGN); // サウンドのロード
	
}

/***************************************
関数名 : Update()
概要   : 更新処理
引数   : なし
戻り値 : なし
備考   : シーンの切り替えなどを更新時に行う
***************************************/
void Title::Update()
{
	Mouse_Input = GetMouseInput();
	GetMousePoint(&Mouse_x, &Mouse_y);

	if (Mouse_Input & MOUSE_INPUT_LEFT) {
		PlaySoundFile(SELECT_SE, DX_PLAYTYPE_NORMAL); // SEの再生
		m_sceneChanger->ChangeScene(eScene_Menu); // シーンをタイトルに変更
	}
}

/***************************************
関数名 : Draw()
概要   :描画処理
引数   : なし
戻り値 : なし
備考   : ロードした画像を表示させる
***************************************/
void Title::Draw()
{
	SceneTask::Draw(); // 親クラスの描画メソッドを呼ぶ
	DrawString(160, 500, "クリックでスタート!!", GetColor(0, 0, 0));
}

