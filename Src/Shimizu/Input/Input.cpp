#include "DxLib.h"
#include "Input.h"

#define KEY_BUF_LEN	(256)

// 現在のフレームのキー情報
char currentKeyBuf[KEY_BUF_LEN] = { 0 };

// 前のフレームのキー情報
char preKeyBuf[KEY_BUF_LEN] = { 0 };

// 入力制御初期化
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

// 入力制御ステップ
void StepInput()
{
	// 前フレームのキー情報変数に記録しておく
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}

	// 現在のキー情報を取得
	GetHitKeyStateAll(currentKeyBuf);
}

bool IsKeyPush(int key_code)
{
	// 前フレームで押されていない　かつ　現フレームで押されている
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1) {
		return true;
	}

	// 押されていないのでfalse
	return false;
}

bool IsKeyKeep(int key_code)
{
	// 前フレームで押されていない　かつ　現フレームで押されている
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1) {
		return true;
	}

	// 押されていないのでfalse
	return false;
}

//たった今離されたか
bool IsKeyRelease(int key_code)
{
	{
		//前フレで押されている現フレで押されていない
		if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0)
			return true;

		//押されていないので false
		return false;
	}
}