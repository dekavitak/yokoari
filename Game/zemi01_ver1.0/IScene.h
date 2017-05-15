/***************************************
クラス名 : IScene
作成者   : 高津 優太
概要     : シーン関連クラスはこのクラスを継承する
***************************************/

#pragma once

class IScene {

public:
	virtual ~IScene() {}          // デストラクタ
	virtual void Initialize() {}  // 初期化処理
	virtual void Finalize() {}    // 終了処理
	virtual void Update() = 0;   // 更新処理
	virtual void Draw() = 0;     // 描画処理
};