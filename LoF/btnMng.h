#pragma once
#include "commonDefain.h"

//-------------------------------------------------------------------------------------
//定義
//-------------------------------------------------------------------------------------
enum class BTN : int
{
	//方向
	D1,
	D2,
	D3,
	D4,
	D5,
	D6,
	D7,
	D8,
	D9,

	//ボタン
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

	//その他
	S2,
	S4,
	S6,
	S8,
	YES,
	NO,

	All
};

//格ゲー用のボタン名称に変換
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
	//辻入力を有効にする
	bool useTsuji = true;
	bool m_tsujiBtn[ePNUM All][eBTN All];

	//キーボードの入力状態
	int m_key[256]; 

	//パッドの設定
	int m_setting[ePNUM All][eBTN All];

	//ボタンの入力状態
	int m_input[ePNUM All][eBTN All];


	//-------------------------------------------------------------------------------------
	///private 関数
	//-------------------------------------------------------------------------------------
	//パッド1のキーボード対応を消す
	void KeyPad1Format();
	

	//キーボードの入力状態を更新する関数
	void UpdateKeybord();
	//指定したボタンが押されているかをチェック
	bool btnMng::GetBtnState(PNUM player,BTN btn);
	//現在のフレームのパッドの状態を得る
	int GetPadState(PNUM player);
	//現在のフレームのPOV（ハットスイッチ）の状態を得る
	unsigned int GetPovState(PNUM player);
	//同時入力の優先処理
	void ConvertBtnPriority(PNUM player);
	//辻入力を適用する
	void ConvertTsuji(PNUM player);

public:
	//-------------------------------------------------------------------------------------
	///public member
	//-------------------------------------------------------------------------------------
	

	//-------------------------------------------------------------------------------------
	///public 関数
	//-------------------------------------------------------------------------------------
	btnMng();
	~btnMng();
	
	//ボタンの入力状態を更新する
	void Update();

	//各ボタンが押された時間
	//1:押された 2～:押しっぱ -1:離した 0:押されていない
	int GetBtnTime(PNUM player, BTN btn);
	// ボタンが押された時間をリセット
	void btnMng::ResetBtnTime(PNUM player);

	//ボタン配置設定
	bool SettingBtn(PNUM player, BTN btn);
	//ボタン配置を初期化(1-4:各コントローラー )
	void ResetSetting(PNUM player);

};