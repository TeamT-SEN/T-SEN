/**
* @file   InputKey.h
* @brief  ����L�[�Ɋւ���N���X��h
* @author haga
*/
#ifndef INPUT_KEY_H
#define INPUT_KEY_H


#include <dinput.h>
#include "InputDevice.h"

/**�L�[���*/
enum  KEYKIND
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	ESCAPE,
	SHIFT,
	SPACE,
	TAB,
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	KEYMAX,
};



/**
* �L�[�Ɋւ���N���X
*/
class InputKey
{
private:
	LPDIRECTINPUTDEVICE8  m_pKeyDevice;			//!< �L�[�{�[�h�f�o�C�X�i�[�p
	int					  m_PreKey[KEYMAX];		//!< �L�[�̏�Ԋi�[����ϐ�

	/**
	* ��Ԃ��m�F����֐�.
	* @param[in] DIK	�_�C���N�g�C���v�b�g�L�[
	* @param[in] st	�L�[���
	*/
	void CheckState(BYTE* DIK, KEYKIND st);

public:
	BYTE     m_diks[256];			//!< DIK���i�[����ϐ�
	BTN_STATE m_Key[KEYMAX];			//!< �L�[�̎�ނ��i�[����ϐ�

	/**�R���X�g���N�^*/
	InputKey();

	/**�f�X�g���N�^*/
	~InputKey();

	/**�L�[�̍X�V*/
	void UpdateKey();

	/**
	* �L�[��Ԋm�F�֐�
	* @param[in] DIK	�_�C���N�g�C���v�b�g�L�[ID
 	* @param[in] st		�L�[�̎��
	*/
	BTN_STATE CheckKey(int DIK, KEYKIND st);
};

#endif		// INPUT_KEY_H