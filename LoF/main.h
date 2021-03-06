#pragma once
//-------------------------------------------------------------------------------------
//定義
//-------------------------------------------------------------------------------------


//-------------------------------------------------------------------------------------
//ヘッダーの読み込み
//-------------------------------------------------------------------------------------
#include "commonDefain.h"
#include "commonUtil.h"


//-------------------------------------------------------------------------------------
//メインループ
//-------------------------------------------------------------------------------------
class main
{
private:
	//-------------------------------------------------------------------------------------
	///private member
	//-------------------------------------------------------------------------------------
	commonUtil m_commonUtil;


	//-------------------------------------------------------------------------------------
	///private 関数
	//-------------------------------------------------------------------------------------
	


public:
	//-------------------------------------------------------------------------------------
	///public member
	//-------------------------------------------------------------------------------------


	//-------------------------------------------------------------------------------------
	///public 関数
	//-------------------------------------------------------------------------------------
	main();
	~main();

	//更新
	void Update();
	
	//テストボタン表示
	void TestDispInput();

};