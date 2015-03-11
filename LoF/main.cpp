#include "main.h"

//�I��
void End()
{
	// DX���C�u�����I������
	DxLib_End();
}

//������
void Init()
{
	//�E�B���h�E���[�h�ɕύX
	ChangeWindowMode(TRUE);
	SetUseXInputFlag(false);

	//���C�u����������
	DxLib_Init();

	//����ʕ`��ɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);
}

// ���C�����[�v
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

	//-------------------------------------------------------------------------------------
	// member
	//-------------------------------------------------------------------------------------
	commonUtil m_commonUtil;

	//-------------------------------------------------------------------------------------
	// ������
	//-------------------------------------------------------------------------------------
	Init();


	//-------------------------------------------------------------------------------------
	// ���C�����[�v 
	//-------------------------------------------------------------------------------------
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)// ����ʂ�\��ʂɔ��f, ���b�Z�[�W����, ��ʃN���A )
	{
		// ��{�X�V
		m_commonUtil.CommonUpdate();

		// ������̕`��
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
	// �I��
	//-------------------------------------------------------------------------------------
	End();

	return 0;
}


//-------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------