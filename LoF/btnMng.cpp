#include "btnMng.h"

//-------------------------------------------------------------------------------------
// 初期化
//-------------------------------------------------------------------------------------
btnMng::btnMng()
{
	//キーボードの入力状態を初期化
	for (int i = 0; i < 256; i++) m_key[i] = 0;

	//パッドのキーボード対応を消す
	KeyPad1Format();

	//すべてのパッドを初期化
	for (int i = 0; i < (int)ePNUM::All; i++)
	{
		ResetSetting((ePNUM)i);
		ResetBtnTime((ePNUM)i);
	}

}
// パッド1のキーボード対応を消す関数
void btnMng:: KeyPad1Format()
{
	//パッドの対応ボタンの初期化
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_DOWN, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_LEFT, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_RIGHT, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_UP, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_1, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_2, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_3, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_4, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_5, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_6, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_7, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_8, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_9, -1, -1, -1, -1);
	SetJoypadInputToKeyInput(DX_INPUT_PAD1, PAD_INPUT_10, -1, -1, -1, -1);
}

//-------------------------------------------------------------------------------------
// 終了
//-------------------------------------------------------------------------------------
btnMng::~btnMng()
{
}



//-------------------------------------------------------------------------------------
// 更新
//-------------------------------------------------------------------------------------
//ボタンの入力状態を更新する
void btnMng::Update()
{
	//キーボードの入力状態を更新
	UpdateKeybord();

	//全プレイヤーの入力状態を更新
	for (int player = 0; player < (int)ePNUM::All; player++)
	{
		for (int i = 0; i < (int)eBTN:: All; i++)
		{
			//ニュートラルは無視（後で別処理）
			if (i == (int)eBTN::D5) continue;

			//1:押された
			//2～:押しっぱ
			if (GetBtnState((ePNUM)player, (eBTN)i))
			{
				if (m_input[player][i] < 0) m_input[player][i] = 0;
				if (m_input[player][i] < IntMax) m_input[player][i]++;

				//辻で減らした分を戻す
				if (m_tsujiBtn[player][i] && m_input[player][i] == 2) m_input[player][i] = 3;
			}
			//-1:離した
			else if (m_input[player][i]>0) m_input[player][i] = -1;
			//0:押されていない
			else m_input[player][i] = 0;
		}
		//方向キーの同時入力の優先処理
		ConvertBtnPriority((ePNUM)player);

		//辻入力を適用する
		if (useTsuji) ConvertTsuji((ePNUM)player);
	}
}

//キーボードの入力状態を更新する
void btnMng::UpdateKeybord()
{
	//全てのキー入力状態をtmpKeyに格納
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);

	for (int i = 0; i<256; i++)
	{
		//i番のキーの入力がある場合は加算する
		if (tmpKey[i] != 0 && m_key[i] + 1 < IntMax) m_key[i]++;
		//入力がない場合は0に戻す
		else m_key[i] = 0;
	}
}

//ボタンが押されているかをチェック
bool btnMng::GetBtnState(ePNUM player,eBTN btn)
{
	unsigned int pov = GetPovState(player);
	int pad = GetPadState(player);

	int btnInt = (int)btn;
	int pInt = (int)player;

	switch (btn)
	{
	//方向キー
	case eBTN::D1:
		if (pov == 22500) return true;
		if ((pad & (1 << m_setting[pInt][(int)eBTN::D2])) && (pad & (1 << m_setting[pInt][(int)eBTN::D4]))) return true;
		break;
	case eBTN::D2:
		if (pov == 18000) return true;
		if (pad & (1 << m_setting[pInt][(int)eBTN::D2])) return true;
		break;
	case eBTN::D3:
		if (pov == 13500) return true;
		if ((pad & (1 << m_setting[pInt][(int)eBTN::D2])) && (pad & (1 << m_setting[pInt][(int)eBTN::D6]))) return true;
		break;
	case eBTN::D4:
		if (pov == 27000) return true;
		if (pad & (1 << m_setting[pInt][(int)eBTN::D4])) return true;
		break;
	case eBTN::D5:
		break;
	case eBTN::D6:
		if (pov == 9000) return true;
		if (pad & (1 << m_setting[pInt][(int)eBTN::D6]))  return true;
		break;
	case eBTN::D7:
		if (pov == 31500) return true;
		if ((pad & (1 << m_setting[pInt][(int)eBTN::D8])) && (pad & (1 << m_setting[pInt][(int)eBTN::D4]))) return true;
		break;
	case eBTN::D8:
		if (pov == 0) return true;
		if (pad & (1 << m_setting[pInt][(int)eBTN::D8])) return true;
		break;
	case eBTN::D9:
		if (pov == 4500) return true;
		if ((pad & (1 << m_setting[pInt][(int)eBTN::D8])) && (pad & (1 << m_setting[pInt][(int)eBTN::D6]))) return true;
		break;

	//システムボタン
	case eBTN::YES:
		if (m_key[KEY_INPUT_RETURN] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	case eBTN::NO:
		if (m_key[KEY_INPUT_BACK] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	case eBTN::S2:
		if (m_key[KEY_INPUT_DOWN] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	case eBTN::S4:
		if (m_key[KEY_INPUT_LEFT] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	case eBTN::S6:
		if (m_key[KEY_INPUT_RIGHT] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	case eBTN::S8:
		if (m_key[KEY_INPUT_UP] > 0)return true;
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;

	//通常のボタン
	default:
		if (pad & (1 << m_setting[pInt][btnInt]))return true;
		break;
	}
	return false;
}

//現在のフレームのパッドの状態を得る
int btnMng::GetPadState(ePNUM player)
{
	switch (player)
	{
	case ePNUM::p1 :
		return GetJoypadInputState(DX_INPUT_PAD1);
	case ePNUM::p2:
		return GetJoypadInputState(DX_INPUT_PAD2);
	case ePNUM::p3:
		return GetJoypadInputState(DX_INPUT_PAD3);
	case ePNUM::p4:
		return GetJoypadInputState(DX_INPUT_PAD4);
	}
	return 0;
}

//現在のフレームのPOV（ハットスイッチ）の状態を得る
unsigned int btnMng::GetPovState(ePNUM player)
{

	DINPUT_JOYSTATE input;
	switch (player)
	{
	case ePNUM::p1:
		GetJoypadDirectInputState(DX_INPUT_PAD1, &input);
		return input.POV[0];
	case ePNUM::p2:
		GetJoypadDirectInputState(DX_INPUT_PAD2, &input);
		return input.POV[0];
	case ePNUM::p3:
		GetJoypadDirectInputState(DX_INPUT_PAD3, &input);
		return input.POV[0];
	case ePNUM::p4:
		GetJoypadDirectInputState(DX_INPUT_PAD4, &input);
		return input.POV[0];
	}
	return 0xffffffff;
}

//同時入力の優先処理
void btnMng::ConvertBtnPriority(ePNUM player)
{
	int pInt = (int)player;

	//ニュートラルのとき
	if (m_input[pInt][(int)eBTN::D2] < 1 && m_input[pInt][(int)eBTN::D4] < 1 && m_input[pInt][(int)eBTN::D6] < 1 && m_input[pInt][(int)eBTN::D8] < 1)
	{
		if (m_input[pInt][(int)eBTN::D5] < 0) m_input[pInt][(int)eBTN::D5] = 0;
		if (m_input[pInt][(int)eBTN::D5] < IntMax) m_input[pInt][(int)eBTN::D5]++;
	}
	//-1:離した
	else if (m_input[pInt][(int)eBTN::D5]>0) m_input[pInt][(int)eBTN::D5] = -1;
	//0:押されていない
	else m_input[pInt][(int)eBTN::D5] = 0;


	//方向キーのありえない同時入力があったときの優先処理
	//上下：上入力を優先
	if (m_input[pInt][(int)eBTN::D7]>0 || m_input[pInt][(int)eBTN::D8]>0 || m_input[pInt][(int)eBTN::D9]>0) m_input[pInt][(int)eBTN::D1] = 0, m_input[pInt][(int)eBTN::D2] = 0, m_input[pInt][(int)eBTN::D3] = 0;
	//左右：左入力を優先
	if (m_input[pInt][(int)eBTN::D7]>0 || m_input[pInt][(int)eBTN::D4]>0 || m_input[pInt][(int)eBTN::D1]>0) m_input[pInt][(int)eBTN::D9] = 0, m_input[pInt][(int)eBTN::D6] = 0, m_input[pInt][(int)eBTN::D3] = 0;

	//同時押しボタンが押されたときの処理
	if (m_input[pInt][(int)eBTN::Tri] > 0)
	{
		if (m_input[pInt][(int)eBTN::Tri] > m_input[pInt][(int)eBTN::Low])m_input[pInt][(int)eBTN::Low] = m_input[pInt][(int)eBTN::Tri];
		if (m_input[pInt][(int)eBTN::Tri] > m_input[pInt][(int)eBTN::Mid])m_input[pInt][(int)eBTN::Mid] = m_input[pInt][(int)eBTN::Tri];
		if (m_input[pInt][(int)eBTN::Tri] > m_input[pInt][(int)eBTN::Hi])m_input[pInt][(int)eBTN::Hi] = m_input[pInt][(int)eBTN::Tri];
	}

	//キーボード十字キー
	if (m_input[pInt][(int)eBTN::S6] > 0)
	{
		m_input[pInt][(int)eBTN::S2] = 0;
		m_input[pInt][(int)eBTN::S4] = 0;
		m_input[pInt][(int)eBTN::S8] = 0;
	}
	else if (m_input[pInt][(int)eBTN::S4] > 0)
	{
		m_input[pInt][(int)eBTN::S2] = 0;
		m_input[pInt][(int)eBTN::S6] = 0;
		m_input[pInt][(int)eBTN::S8] = 0;
	}
	else if (m_input[pInt][(int)eBTN::S2] > 0)
	{
		m_input[pInt][(int)eBTN::S6] = 0;
		m_input[pInt][(int)eBTN::S4] = 0;
		m_input[pInt][(int)eBTN::S8] = 0;
	}
	else if (m_input[pInt][(int)eBTN::S8] > 0)
	{
		m_input[pInt][(int)eBTN::S2] = 0;
		m_input[pInt][(int)eBTN::S6] = 0;
		m_input[pInt][(int)eBTN::S4] = 0;
	}
}

//辻入力を適用する
void btnMng::ConvertTsuji(ePNUM player)
{
	int pInt = (int)player;

	if (m_input[pInt][(int)eBTN::Low] == 2)
	{
		if (m_input[pInt][(int)eBTN::Mid] == 1 || m_input[pInt][(int)eBTN::Hi] == 1 || m_input[pInt][(int)eBTN::Ult] == 1)
		{
			m_input[pInt][(int)eBTN::Low] = 1;
			m_tsujiBtn[pInt][(int)eBTN::Low] = true;
		}
	}
	else m_tsujiBtn[pInt][(int)eBTN::Low] = false;

	if (m_input[pInt][(int)eBTN::Mid] == 2)
	{
		if (m_input[pInt][(int)eBTN::Low] == 1 || m_input[pInt][(int)eBTN::Hi] == 1 || m_input[pInt][(int)eBTN::Sp] == 1)
		{
			m_input[pInt][(int)eBTN::Mid] = 1;
			m_tsujiBtn[pInt][(int)eBTN::Mid] = true;
		}
	}
	else m_tsujiBtn[pInt][(int)eBTN::Mid] = false;

	if (m_input[pInt][(int)eBTN::Hi] == 2)
	{
		if (m_input[pInt][(int)eBTN::Low] == 1 || m_input[pInt][(int)eBTN::Mid] == 1 || m_input[pInt][(int)eBTN::Sp] == 1)
		{
			m_input[pInt][(int)eBTN::Hi] = 1;
			m_tsujiBtn[pInt][(int)eBTN::Hi] = true;
		}
	}
	else m_tsujiBtn[pInt][(int)eBTN::Hi] = false;

	if (m_input[pInt][(int)eBTN::Sp] == 2)
	{
		if (m_input[pInt][(int)eBTN::Low] == 1 || m_input[pInt][(int)eBTN::Mid] == 1 || m_input[pInt][(int)eBTN::Hi] == 1)
		{
			m_input[pInt][(int)eBTN::Sp] = 1;
			m_tsujiBtn[pInt][(int)eBTN::Sp] = true;
		}
	}
	else m_tsujiBtn[pInt][(int)eBTN::Sp] = false;
}



//-------------------------------------------------------------------------------------
//各ボタンが押された時間を得る
//-------------------------------------------------------------------------------------
int btnMng::GetBtnTime(ePNUM player, eBTN btn)
{
	return m_input[(int)player][(int)btn];
}

// ボタンが押された時間をリセット
void btnMng::ResetBtnTime(ePNUM player)
{
	int pInt = (int)player;
	for (int i=0; i < (int)eBTN::All; i++)
	{
		m_input[pInt][i] = 0;
		m_tsujiBtn[pInt][i] = false;
	}
}


//-------------------------------------------------------------------------------------
//ボタン配置設定
//-------------------------------------------------------------------------------------
bool btnMng::SettingBtn(ePNUM player, eBTN btn)
{
	int padInpNow;

	//指定されたプレイヤーのボタン情報を格納する
	switch (player)
	{
	case ePNUM::p1:
		padInpNow = GetJoypadInputState(DX_INPUT_PAD1);
		break;
	case ePNUM::p2:
		padInpNow = GetJoypadInputState(DX_INPUT_PAD2);
		break;
	case ePNUM::p3:
		padInpNow = GetJoypadInputState(DX_INPUT_PAD3);
		break;
	case ePNUM::p4:
		padInpNow = GetJoypadInputState(DX_INPUT_PAD4);
		break;
	}
	//指定されたプレイヤーのボタンiの入力があったらそこにセット
	for (int i = 0; i<28; i++)
	{
		if (padInpNow & (1 << i))
		{
			m_setting[(int)player][(int)btn] = i;
			return true;
		}
	}
	return false;
}

// ボタン配置を初期化 (1-4:各コントローラー )
void btnMng::ResetSetting(ePNUM player)
{
	int pInt = (int)player;
	//指定されたコントローラーを初期化
	m_setting[pInt][(int)eBTN::D2] = 0, m_setting[pInt][(int)eBTN::D4] = 1, m_setting[pInt][(int)eBTN::D6] = 2, m_setting[pInt][(int)eBTN::D8] = 3;
	m_setting[pInt][(int)eBTN::S2] = 0, m_setting[pInt][(int)eBTN::S4] = 1, m_setting[pInt][(int)eBTN::S6] = 2, m_setting[pInt][(int)eBTN::S8] = 3;

	m_setting[pInt][(int)eBTN::Y] = 3 + 4, m_setting[pInt][(int)eBTN::X] = 3 + 3, m_setting[pInt][(int)eBTN::A] = 3 + 1, m_setting[pInt][(int)eBTN::B] = 3 + 2;
	m_setting[pInt][(int)eBTN::L1] = 3 + 5, m_setting[pInt][(int)eBTN::R1] = 3 + 6;
	m_setting[pInt][(int)eBTN::ST] = 3 + 8, m_setting[pInt][(int)eBTN::SE] = 3 + 7;
	
	m_setting[pInt][(int)eBTN::YES] = 6, m_setting[pInt][(int)eBTN::NO] = 5;

	//割り当てられないもの
	m_setting[pInt][(int)eBTN::D1] = -1, m_setting[pInt][(int)eBTN::D3] = -1;
	m_setting[pInt][(int)eBTN::D5] = -1;
	m_setting[pInt][(int)eBTN::D7] = -1, m_setting[pInt][(int)eBTN::D9] = -1;
	m_setting[pInt][(int)eBTN::L2] = -1, m_setting[pInt][(int)eBTN::L3] = -1;
	m_setting[pInt][(int)eBTN::R2] = -1, m_setting[pInt][(int)eBTN::R3] = -1;
}