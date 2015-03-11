#pragma once
#include "commonDefain.h"

//-------------------------------------------------------------------------------------
//��`
//-------------------------------------------------------------------------------------
enum class BTN : int
{
	//����
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
	D8,
	D9,

	//�{�^��
	A,
	B,
	X,
	Y,
	L1,
	L2,
	L3,
	R1,
	R2,
	R3,
	SE,
	ST,

	//���̑�
	S2,
	S4,
	S6,
	S8,
	YES,
	NO,

	All
};

//�i�Q�[�p�̃{�^�����̂ɕϊ�
#define eBTN (int)BTN::
#define Sp R1
#define Low Y
#define Mid X
#define Hi A
#define Ult B
#define Tri L1

class btnMng
{
private:
	//-------------------------------------------------------------------------------------
	///private member
	//-------------------------------------------------------------------------------------
	//�ғ��͂�L���ɂ���
	bool useTsuji = true;
	bool m_tsujiBtn[ePNUM All][eBTN All];

	//�L�[�{�[�h�̓��͏��
	int m_key[256]; 

	//�p�b�h�̐ݒ�
	int m_setting[ePNUM All][eBTN All];

	//�{�^���̓��͏��
	int m_input[ePNUM All][eBTN All];


	//-------------------------------------------------------------------------------------
	///private �֐�
	//-------------------------------------------------------------------------------------
	//�p�b�h1�̃L�[�{�[�h�Ή�������
	void KeyPad1Format();
	

	//�L�[�{�[�h�̓��͏�Ԃ��X�V����֐�
	void UpdateKeybord();
	//�w�肵���{�^����������Ă��邩���`�F�b�N
	bool btnMng::GetBtnState(PNUM player,BTN btn);
	//���݂̃t���[���̃p�b�h�̏�Ԃ𓾂�
	int GetPadState(PNUM player);
	//���݂̃t���[����POV�i�n�b�g�X�C�b�`�j�̏�Ԃ𓾂�
	unsigned int GetPovState(PNUM player);
	//�������̗͂D�揈��
	void ConvertBtnPriority(PNUM player);
	//�ғ��͂�K�p����
	void ConvertTsuji(PNUM player);

public:
	//-------------------------------------------------------------------------------------
	///public member
	//-------------------------------------------------------------------------------------
	

	//-------------------------------------------------------------------------------------
	///public �֐�
	//-------------------------------------------------------------------------------------
	btnMng();
	~btnMng();
	
	//�{�^���̓��͏�Ԃ��X�V����
	void Update();

	//�e�{�^���������ꂽ����
	//1:�����ꂽ 2�`:�������� -1:������ 0:������Ă��Ȃ�
	int GetBtnTime(PNUM player, BTN btn);
	// �{�^���������ꂽ���Ԃ����Z�b�g
	void btnMng::ResetBtnTime(PNUM player);

	//�{�^���z�u�ݒ�
	bool SettingBtn(PNUM player, BTN btn);
	//�{�^���z�u��������(1-4:�e�R���g���[���[ )
	void ResetSetting(PNUM player);

};