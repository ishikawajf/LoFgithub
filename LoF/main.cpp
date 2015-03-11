#include "main.h"

//終了
void End()
{
	// DXライブラリ終了処理
	DxLib_End();
}

//初期化
void Init()
{
	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);
	SetUseXInputFlag(false);

	//ライブラリ初期化
	DxLib_Init();

	//裏画面描画に設定
	SetDrawScreen(DX_SCREEN_BACK);
}

// メインループ
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//-------------------------------------------------------------------------------------
	// member
	//-------------------------------------------------------------------------------------
	commonUtil m_commonUtil;

	//-------------------------------------------------------------------------------------
	// 初期化
	//-------------------------------------------------------------------------------------
	Init();


	//-------------------------------------------------------------------------------------
	// メインループ 
	//-------------------------------------------------------------------------------------
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)// 裏画面を表画面に反映, メッセージ処理, 画面クリア )
	{
		// 基本更新
		m_commonUtil.CommonUpdate();

		// 文字列の描画
		DrawFormatString(200, 240 - 100, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D8));
		DrawFormatString(200 - 30, 240 - 100, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D7));
		DrawFormatString(200 + 30, 240 - 100, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D9));

		DrawFormatString(200 + 30, 240 - 80, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1,BTN::D6));
		DrawFormatString(200 - 30, 240 - 80, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D4));
		
		DrawFormatString(200, 240 - 60, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D2));
		DrawFormatString(200 - 30, 240 - 60, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D1));
		DrawFormatString(200 + 30, 240 - 60, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::D3));


		DrawFormatString(350, 200 - 80, GetColor(255, 255, 255), "A %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::A));
		DrawFormatString(350, 200 - 60, GetColor(255, 255, 255), "B %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::B));
		DrawFormatString(350, 200 - 40, GetColor(255, 255, 255), "X %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::X));
		DrawFormatString(350, 200 - 20, GetColor(255, 255, 255), "Y %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::Y));
		DrawFormatString(350, 200 - 0, GetColor(255, 255, 255), "L %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::L1));
		DrawFormatString(350, 200 + 20, GetColor(255, 255, 255), "R %d ", m_commonUtil.GetBtnTime(PNUM::p1, BTN::R1));
	}


	//-------------------------------------------------------------------------------------
	// 終了
	//-------------------------------------------------------------------------------------
	End();

	return 0;
}


//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------