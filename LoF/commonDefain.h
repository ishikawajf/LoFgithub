#pragma once
//ゲーム内すべてで共通のヘッダー
//-------------------------------------------------------------------------------------
//ヘッダーの読み込み
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
//定義
//-------------------------------------------------------------------------------------
//int限界
#define IntMax 2147483640

//円周率
#define PI 3.141592654

//画面サイズ
#define WinSizeX 480
#define WinSizeY 270

//フォントサイズ
#define FontSize 9.5
#define FontSizeBig 20

//プレイ人数
enum class ePNUM:int
{
	p1, p2, p3, p4, All
};


//-------------------------------------------------------------------------------------
//関数
//-------------------------------------------------------------------------------------

//listの特定の値を参照する
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