#include "commonUtil.h"

//-------------------------------------------------------------------------------------
// �I��
//-------------------------------------------------------------------------------------
commonUtil::~commonUtil()
{

}

//-------------------------------------------------------------------------------------
// ������
//-------------------------------------------------------------------------------------
commonUtil::commonUtil()
{

}



//-------------------------------------------------------------------------------------
// ��{�I�ȍX�V
//-------------------------------------------------------------------------------------
void commonUtil::CommonUpdate()
{
	//���͂̍X�V
	m_btnMng.Update();
	//60F�œ���
	Wait60F();
}

// 60F�œ��삳����
void commonUtil::Wait60F()
{
	int term;
	static int t = 0;
	term = GetNowCount() - t;
	if (16 - term>0)
		Sleep(16 - term);
	t = GetNowCount();
}

//-------------------------------------------------------------------------------------
// �{�^������
//-------------------------------------------------------------------------------------
// �{�^���������ꂽ���Ԃ����Z�b�g
void commonUtil::ResetBtnTime(PNUM player)
{
	m_btnMng.ResetBtnTime(player);
}

//�e�{�^���������ꂽ���Ԃ𓾂�
int commonUtil::GetBtnTime(PNUM player, BTN btn)
{
	return m_btnMng.GetBtnTime(player, btn);
}


//�{�^���z�u��������(1-4:�e�R���g���[���[ )
void commonUtil::ResetSetting(PNUM player)
{
	m_btnMng.ResetSetting(player); 
}

//�{�^���z�u�ݒ�
//bool commonUtil::SettingBtn(PLAYER player, BTN btn){ m_btnMng.SettingBtn(player, btn); }
