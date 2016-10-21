/**
* @file   InputDevice.h
* @brief  DirectInput�֘A�N���X��h
* @author haga
*/
#ifndef INPUT_DEVICE_H
#define	INPUT_DEVICE_H

#include <dinput.h>
/*
* DirectInput�֘A�N���X.
*/

/**�{�^���̏�Ԋm�F*/
enum BUTTONSTATE
{
	OFF,		//!< �L�[�𗣂�����Ԃ������Ă���
	ON,			//!< �L�[����������Ԃ������Ă���
	PUSH,		//!< �L�[�𗣂�
	RELEASE,	//!< �L�[������
};

class InputDevice
{
private:
	HWND				 m_hWnd;			//!< �E�B���h�E�n���h���i�[
	LPDIRECTINPUT8		 m_pDInput;			//!< DirectInput
	LPDIRECTINPUTDEVICE8 m_pKeyDevice;		//!< �L�[�{�[�h�f�o�C�X
	LPDIRECTINPUTDEVICE8 m_pMouseDevice;	//!< �}�E�X�f�o�C�X

public:
	/**�R���X�g���N�^*/
	InputDevice();

	/**�f�X�g���N�^*/
	~InputDevice();

	/**
	* �f�o�C�X�̎��̂��擾����֐�.
	* Singleton�p�^�[��<br>
	* @return InputDevice �f�o�C�X
	*/
	static InputDevice& GetInstance()
	{
		static InputDevice InputDevice;
		return InputDevice;
	}

	/**
	* DirectInput����.
	* @retval S_OK		����������
	* @retval E_FAIL	���������s
	*/
	HRESULT InitDinput();

	/**
	* �L�[�{�[�h�f�o�C�X�̏�����.
	* @param[in] hWnd �E�B���h�E�n���h��
	* @retval S_OK		����������
	* @retval E_FAIL	���������s
	*/
	HRESULT InitDinputKey(HWND hWnd);

	/**
	* �}�E�X�f�o�C�X�̏�����
	* @param[in] hWnd �E�B���h�E�n���h��
	*/
	HRESULT InitDinputMouse(HWND hWnd);

	/**
	* �L�[�{�[�h�f�o�C�X�n��.
	* @return m_pKeyDevice �L�[�{�[�h�f�o�C�X
	*/
	LPDIRECTINPUTDEVICE8 GetKeyDevice(){ return m_pKeyDevice; };

	/**
	* �}�E�X�f�o�C�X�n��.
	* @return m_pMouseDevice �L�[�{�[�h�f�o�C�X
	*/
	LPDIRECTINPUTDEVICE8 GetMouseDevice(){ return m_pMouseDevice; };

	/**
	* ���ݎg���Ă���E�B���h�E�n���h����n��.
	* @return m_hWnd �E�B���h�E�n���h��
	*/
	HWND GethWnd(){ return m_hWnd; };
};

#endif		// INPUT_DEVICE_H