#pragma once
#include "commonDefain.h"

//-------------------------------------------------------------------------------------
//��`
//-------------------------------------------------------------------------------------
enum class eBTN : int
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
	bool m_tsujiBtn[(int)ePNUM:: All][(int)eBTN::All];

	//�L�[�{�[�h�̓��͏��
	int m_key[256]; 

	//�p�b�h�̐ݒ�
	int m_setting[(int)ePNUM::All][(int)eBTN::All];

	//�{�^���̓��͏��
	int m_input[(int)ePNUM::All][(int)eBTN::All];


	//-------------------------------------------------------------------------------------
	///private �֐�
	//-------------------------------------------------------------------------------------
	//�p�b�h1�̃L�[�{�[�h�Ή�������
	void KeyPad1Format();
	

	//�L�[�{�[�h�̓��͏�Ԃ��X�V����֐�
	void UpdateKeybord();
	//�w�肵���{�^����������Ă��邩���`�F�b�N
	bool btnMng::GetBtnState(ePNUM player,eBTN btn);
	//���݂̃t���[���̃p�b�h�̏�Ԃ𓾂�
	int GetPadState(ePNUM player);
	//���݂̃t���[����POV�i�n�b�g�X�C�b�`�j�̏�Ԃ𓾂�
	unsigned int GetPovState(ePNUM player);
	//�������̗͂D�揈��
	void ConvertBtnPriority(ePNUM player);
	//�ғ��͂�K�p����
	void ConvertTsuji(ePNUM player);

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
	int GetBtnTime(ePNUM player, eBTN btn);
	// �{�^���������ꂽ���Ԃ����Z�b�g
	void btnMng::ResetBtnTime(ePNUM player);

	//�{�^���z�u�ݒ�
	bool SettingBtn(ePNUM player, eBTN btn);
	//�{�^���z�u��������(1-4:�e�R���g���[���[ )
	void ResetSetting(ePNUM player);

};