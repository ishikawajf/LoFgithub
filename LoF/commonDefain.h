#pragma once
//�Q�[�������ׂĂŋ��ʂ̃w�b�_�[
//-------------------------------------------------------------------------------------
//�w�b�_�[�̓ǂݍ���
//-------------------------------------------------------------------------------------
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "DxLib.h"

#include <string>
#include <list>
#include <map>
using namespace std;


//-------------------------------------------------------------------------------------
//��`
//-------------------------------------------------------------------------------------
//int���E
#define IntMax 2147483640

//�~����
#define PI 3.141592654

//��ʃT�C�Y
#define WinSizeX 480
#define WinSizeY 270

//�t�H���g�T�C�Y
#define FontSize 9.5
#define FontSizeBig 20

//�v���C�l��
enum class ePNUM:int
{
	p1, p2, p3, p4, All
};


//-------------------------------------------------------------------------------------
//�֐�
//-------------------------------------------------------------------------------------

//list�̓���̒l���Q�Ƃ���
list<int>::iterator GetListIterator(list<int> lst ,int num)
{
	list<int>::iterator itr = lst.begin();
	int counter = 0;
	while (itr != lst.end() && counter <= num)
	{
		++itr;
		counter++;
	}
	return itr;
}