/**
* @file   InputKey.h
* @brief  ����L�[�Ɋւ���N���X��h
* @author haga
*/
#ifndef INPUT_KEY_H
#define INPUT_KEY_H

#include <dinput.h>

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
	KEYMAX
};

/**�L�[���*/
enum KEYSTATE
{
	OFF,		//!< �L�[�𗣂�����Ԃ������Ă���
	ON,			//!< �L�[����������Ԃ������Ă���
	RELEASE,	//!< �L�[�𗣂�
	PUSH		//!< �L�[������
};

/**
* �L�[�Ɋւ���N���X
*/
class InputKey
{
private:
	LPDIRECTINPUTDEVICE8  m_pKeyDevice;			//!< �L�[�{�[�h�f�o�C�X�i�[�p
	int					  m_PreKey[KEYMAX];		//!< �L�[�̏�Ԋi�[����ϐ�

public:
	BYTE     m_diks[256];			//!< DIK���i�[����ϐ�
	KEYSTATE m_Key[KEYMAX];			//!< �L�[�̎�ނ��i�[����ϐ�

	/**�R���X�g���N�^*/
	InputKey();

	/**�f�X�g���N�^*/
	~InputKey();

	/**
	* ���̂��擾����֐�<br>
	* Singleton�p�^�[��.
	* @return ControlKey �L�[����̃I�u�W�F�N�g
	*/
	static InputKey& GetInstance()
	{
		static InputKey ControlKey;

		return ControlKey;
	}

	/**�L�[�̍X�V*/
	void UpdateKey();

	/**
	* �L�[�̏�Ԃ��m�F����֐�.
	* @param[in] DIK	�_�C���N�g�C���v�b�g�L�[
	* @param[in] st	�L�[���
	*/
	void KeyCheck(BYTE* DIK, KEYKIND st);

};

#endif		// INPUT_KEY_H