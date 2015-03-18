#include "main.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//メインループ
	main m_main;
	// 裏画面を表画面に反映, メッセージ処理, 画面クリア
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 )
	{
		m_main.Update();
	}
	return 0;
}



//-------------------------------------------------------------------------------------
//メインループ
//-------------------------------------------------------------------------------------
// 終了
main::~main()
{
	
	// DXライブラリ終了処理
	DxLib_End();
}
//初期化
main::main()
{
	//ウィンドウモードに変更
	ChangeWindowMode(TRUE);
	SetUseXInputFlag(false);

	//ライブラリ初期化
	DxLib_Init();

	//裏画面描画に設定
	SetDrawScreen(DX_SCREEN_BACK);
}
//更新
void main::Update()
{
	m_commonUtil.CommonUpdate();

	//ボタン表示テスト
	TestDispInput();
}


//ボタン表示テスト
void main::TestDispInput()
{
	int posX = 20;
	int posY = 300;

	// 文字列の描画
	DrawFormatString(posX, posY, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D7));
	DrawFormatString(posX + 20, posY, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D8));
	DrawFormatString(posX + 40, posY, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D9));

	DrawFormatString(posX, posY + 20, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D4));
	DrawFormatString(posX+40, posY + 20, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D6));
	
	DrawFormatString(posX, posY + 40, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D1));
	DrawFormatString(posX + 20, posY + 40, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D2));
	DrawFormatString(posX + 40, posY + 40, GetColor(255, 255, 255), "%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::D3));

	DrawFormatString(posX + 65, posY + 40, GetColor(255, 255, 255), "SE%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::SE));
	DrawFormatString(posX + 100, posY + 40, GetColor(255, 255, 255), "ST%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::ST));

	DrawFormatString(posX + 150, posY, GetColor(255, 255, 255), "L%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::L1));
	DrawFormatString(posX + 190, posY, GetColor(255, 255, 255), "R%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::R1));

	DrawFormatString(posX + 150, posY + 20, GetColor(255, 255, 255), "Y%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::Y));
	DrawFormatString(posX + 190, posY + 20, GetColor(255, 255, 255), "X%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::X));
	
	DrawFormatString(posX + 150, posY + 40, GetColor(255, 255, 255), "B%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::B));
	DrawFormatString(posX + 190, posY + 40, GetColor(255, 255, 255), "A%d ", m_commonUtil.GetBtnTime(ePNUM::p1, eBTN::A));

}