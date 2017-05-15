#include"SystemManager.h"
#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{


	SystemManager SysMgr;

	SysMgr.Update();

	return 0;					// ソフトの終了
}