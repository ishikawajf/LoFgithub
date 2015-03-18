#include "main.h"
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	//���C�����[�v
	main m_main;
	// ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 )
	{
		m_main.Update();
	}
	return 0;
}



//-------------------------------------------------------------------------------------
//���C�����[�v
//-------------------------------------------------------------------------------------
// �I��
main::~main()
{
	
	// DX���C�u�����I������
	DxLib_End();
}
//������
main::main()
{
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	SetUseXInputFlag(false);

	//���C�u����������
	DxLib_Init();

	//����ʕ`��ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);
}
//�X�V
void main::Update()
{
	m_commonUtil.CommonUpdate();

	//�{�^���\���e�X�g
	TestDispInput();
}


//�{�^���\���e�X�g
void main::TestDispInput()
{
	int posX = 20;
	int posY = 300;

	// ������̕`��
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