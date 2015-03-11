#include "commonUtil.h"

//-------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------
commonUtil::~commonUtil()
{

}

//-------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------
commonUtil::commonUtil()
{

}



//-------------------------------------------------------------------------------------
// 基本的な更新
//-------------------------------------------------------------------------------------
void commonUtil::CommonUpdate()
{
	//入力の更新
	m_btnMng.Update();
	//60Fで動作
	Wait60F();
}

// 60Fで動作させる
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
// ボタン操作
//-------------------------------------------------------------------------------------
// ボタンが押された時間をリセット
void commonUtil::ResetBtnTime(PNUM player)
{
	m_btnMng.ResetBtnTime(player);
}

//各ボタンが押された時間を得る
int commonUtil::GetBtnTime(PNUM player, BTN btn)
{
	return m_btnMng.GetBtnTime(player, btn);
}


//ボタン配置を初期化(1-4:各コントローラー )
void commonUtil::ResetSetting(PNUM player)
{
	m_btnMng.ResetSetting(player); 
}

//ボタン配置設定
//bool commonUtil::SettingBtn(PLAYER player, BTN btn){ m_btnMng.SettingBtn(player, btn); }
