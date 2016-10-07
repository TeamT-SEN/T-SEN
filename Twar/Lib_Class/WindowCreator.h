/**
* @file WindowCreator.h
* @brief �E�B���h�E���쐬����N���X
* @author haga
* @data 2016/09/28
*/
#ifndef WINDOW_CREATOR_H
#define WINDOW_CREATOR_H
#include <windows.h>
/*
*�E�B���h�E���쐬����N���X
*/
class WindowCreator
{
private:

	WNDCLASSEX  m_wndc;				//!< �E�B���h�E�N���X
	HWND		m_hWnd;				//!< �E�B���h�E�n���h��
	RECT		m_wRect;			//!< �E�C���h�E�T�C�Y��ێ����Ă����ϐ�
	char*       m_wTitle;			//!< �E�B���h�E�̃^�C�g��
	int		    m_wWidth;			//!< �E�C���h�E�̕�
	int			m_wHeight;			//!< �E�B���h�E�̍���
	bool		m_wType;			//!< �E�B���h�E�T�C�Y���ʏ�Ȃ�true,�t���X�N���[���Ȃ�false

public:
	/**
	* �R���X�g���N�^.
	* @param[in] title	�E�B���h�E�̃^�C�g��
	* @param[in] width	�E�C���h�E�̃N���C�A���g�T�C�Y(��)
	* @param[in] height	�E�C���h�E�̃N���C�A���g�T�C�Y(����)
	*/
	WindowCreator(char* title, int width, int height);

	/**�f�X�g���N�^*/
	~WindowCreator();

	/**
	* �E�B���h�E���쐬����֐�<br>
	* @param[in] hInstance	�C���X�^���X�n���h��
	* @param[in] Wndproc	�E�B���h�E�v���V�[�W���֐�
	* @param[in] windowType �E�B���h�E�^�C�v true�Ȃ�ʏ�,false�Ȃ�t���X�N���[��
	* @retval S_OK			�E�B���h�E�����ɐ�������
	* @retval E_FAIL		�E�B���h�E�����Ɏ��s����
	*/
	HRESULT MakeWindow(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp), bool windowType);

	/**
	* �E�B���h�E�T�C�Y�ύX
	*/
	HRESULT ChangeWindowSize();

	/**
	* �n���h���擾�p�֐�.
	* @return m_hWnd �E�B���h�E�n���h��
	*/
	HWND GetHwnd(){ return m_hWnd; };

};

#endif	// WINDOW_CREATOR_H