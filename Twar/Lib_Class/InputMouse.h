/**
* @file   InputMouse.h
* @brief  �}�E�X����Ɋւ���N���X
* @author haga
*/
#ifndef INPUT_MOUSE_H
#define INPUT_MOUSE_H

#include <dinput.h>
#include <d3dx9.h>
#include "InputDevice.h"

/**�}�E�X�̃{�^��*/
enum MOUSEBUTTON
{
	MouseLeft,		//!< ���{�^��
	MouseRight,		//!< �E�{�^��
	MouseCenter,	//!< �^��
	ButtonMAX,
};
/**�}�E�X�z�C�[���̏��*/
enum WHEELSTATE
{
	WHEEL_NONE = 0,		//!< ��]���Ă��Ȃ�
	WHEEL_UP = 1,		//!< ���ɉ�]�����Ă�����
	WHEEL_DOWN = -1,	//!< ��O�ɉ�]�����Ă�����
};

/**
* �}�E�X����Ɋւ���N���X
*/
class InputMouse
{
private:
	HWND				 m_hWnd;								//!< �E�B���h�E�n���h���i�[
	LPDIRECTINPUTDEVICE8 m_pMouseDevice;						//!< �}�E�X�f�o�C�X
	DIMOUSESTATE2		 m_dims;								//!< �}�E�X�\����(�{�^���֘A)
	INT					 m_wndWid;								//!< �E�C���h�E�T�C�Y��
	INT					 m_wndHgt;								//!< �E�B���h�h�E�T�C�Y����
	LONG				 m_posX;								//!< �}�E�X��x���W
	LONG				 m_posY;								//!< �}�E�X��y���W
	LONG				 m_wheel;								//!< �}�E�X�̃z�C�[��
	bool				 m_LDown;								//!< Update���_�̍��{�^�����
	bool				 m_RDown;								//!< Update���_�̉E�{�^�����
	bool				 m_MDown;								//!< Update���_�̒��{�^�����
	bool				 m_LAction;								//!< �{�^�����������ゾ��ON�ɂȂ�(�N���b�N���E���Ƃ���)
	bool				 m_RAction;								//!< �{�^�����������ゾ��ON�ɂȂ�(�N���b�N���E���Ƃ���)
	bool				 m_MAction;								//!< �{�^�����������ゾ��ON�ɂȂ�(�N���b�N���E���Ƃ���)
	int					 m_PreMouse[MOUSEBUTTON::ButtonMAX];	//!< �}�E�X�̃{�^���̑O�̏�Ԃ��i�[����ϐ�
	BTN_STATE			 m_mouse[MOUSEBUTTON::ButtonMAX];		//!< �}�E�X�̃{�^���̏�Ԃ��i�[����ϐ�

	/**��Ԋm�F*/
	bool GetIsLAction() const { return m_LAction; }
	bool GetIsRAction() const { return m_RAction; }
	bool GetIsMAction() const { return m_MAction; }

	/**
	* ��Ԃ��m�F����֐�
	* @param[in] mouseButton �}�E�X�̃{�^���̎��
	*/
	void CheckState(MOUSEBUTTON mouseButton);

public:
	/**�R���X�g���N�^*/
	InputMouse();
	/**�f�X�g���N�^*/
	~InputMouse();


	/**�}�E�X�̍X�V*/
	void UpdateMouse();

	/**
	* �}�E�X�̏�Ԃ��m�F����֐�
	* @param[in] mouseButton �}�E�X�̃{�^���̎��
	* @return �{�^����������Ă��邩�ǂ���
	*/
	BTN_STATE ChecKMouse(MOUSEBUTTON mouseButton);

	/**
	* �}�E�X�z�C�[����Ԃ��擾����֐�
	* @return �z�C�[�����
	*/
	WHEELSTATE GetWheelState();

	/**�}�E�X���W���擾����*/
	LONG GetPosX() const { return m_posX; }
	LONG GetPosY() const { return m_posY; }
	LONG GetWheel() const { return m_wheel; }

	
	/**
	* �}�E�X�̍��W���Z�b�g.
	* @param[in] x ���Wx
	* @param[in] y ���Wy
	*/
	void SetCursorPos(int x, int y)
	{
		m_posX = x;
		m_posY = y;
	}
};

#endif // INPUT_MOUSE_H