/**
* @file GameLib.h
* @brief  Facade�p�^�[���̃��C�u�����쐬
* @author haga
*/
#ifndef GAMELIB_H
#define GAMELIB_H

#include <windows.h>
#include <iostream>
#include "WindowCreator.h"	
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "InputKey.h"
#include "InputMouse.h"
#include "TextureManager.h"
#include "XFileManager.h"
#include "SoundFileManager.h"
#include "VertexManager.h"
#include "DebugFont.h"
#include "DebugTimer.h"
using namespace std;


/**���y�̍Đ����@*/
enum SOUND_OPERATION
{
	SOUND_PLAY,			//!< �Đ�
	SOUND_STOP,			//!< ��~
	SOUND_LOOP,			//!< ���[�v�Đ�
	SOUND_RESET, 		//!< �����ʒu�ɖ߂�
	SOUND_RESET_PLAY,   //!< ��߂ď����ʒu�߂�
	SOUND_STOP_RESET	//!< �����ʒu����Đ�������
};

/**
* ���C�u�����̃N���X	
*/
class GameLib
{
private:
	WindowCreator		m_windowCreator;
	GraphicsDevice*		m_pGraphicsDevice;
	InputDevice*		m_pInputDevice;
	SoundFileManager*   m_pSoundFileManager;
	InputKey*			m_pInputKey;
	InputMouse*			m_pInputMouse;
	TextureManager*     m_pTextureManager;
	XFileManager*		m_pXFileManager;
	VertexManager*		m_pVertexManager;
	DebugTimer*			m_pDebugTimer;
	int				    m_wWidth;			//!< �E�C���h�E�̕�
	int					m_wHeight;			//!< �E�B���h�E�̍���
	bool				m_releaseFlag;		//!< ����������������ǂ����̃t���O

public:
	/**
	* �R���X�g���N�^.
	* @param[in] title  �E�B���h�E�^�C�g��
	* @param[in] width  �E�B���h�E�̉���
	* @param[in] height �E�C���h�E�̏c��
	*/
	GameLib(char* title, int width, int height);

	/**�f�X�g���N�^*/
	~GameLib();

	/**
	* �������֐�.
	* @param[in] hInstance	�C���X�^���X�n���h��
	* @param[in] Wndproc	�E�B���h�E�v���V�[�W���֐�
	* @param[in] windowType �E�B���h�E�^�C�v true�Ȃ�ʏ�,false�Ȃ�t���X�N���[��
	*/
	void InitGameLib(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp), bool windowType);

	/**�������J���֐�*/
	void ReleaseGameLib();

	/**�E�B���h�E���t���X�N���[�����E�B���h�E�T�C�Y�ɕς���֐�*/
	void ChangeWindowMode();			

	/**�E�B���h�E�̉������擾����֐�*/
	int GetWindowWidth(){ return m_wWidth; }	

	/**�E�B���h�E�̏c�����擾����֐�*/
	int GetWindowHeight(){ return m_wHeight; }		

	//------------------------------------------------------------------------------------
	//									�`��֘A�֐�
	//------------------------------------------------------------------------------------
	/**�f�o�C�X���擾����֐�*/
	const IDirect3DDevice9* GetDevice();					

	/**
	* �`��J�n�����֐�.
	* @param[in] FVF ���_�t�H�[�}�b�g
	*/
	void StartRender(DWORD FVF = D3DFVF_CUSTOMVERTEX);

	/**�`��I�������֐�*/
	void EndRender();											

	/**
	* ���_�t�H�[�}�b�g��ݒ肷��֐�
	* @param[in] FVF ���_�t�H�[�}�b�g
	*/
	void SetFVF(DWORD FVF);										

	//---------------------------------------------------------------------------------------
	//								�e�N�X�`���[�֘A�֐�
	//---------------------------------------------------------------------------------------
	/**
	* �e�N�X�`���[��ǂݍ��ފ֐�.
	* @param[in] key		�o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] filepath   �t�@�C����
	*/
	void LoadTex(int key, char* filePath);																	

	/**
	* �e�N�X�`���[���ڍאݒ肵�ēǂݍ��ފ֐�.
	* @param[in] key		�o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] filepath   �t�@�C����
	* @param[in] a			�A���t�@�l  0�`255
	* @param[in] r			�F��R�l 0�`255
	* @param[in] g			�F��G�l 0�`255
	* @param[in] b			�F��B�l 0�`255
	* @param[in] size		�e�N�X�`���[�̃T�C�Y���Q�ׂ̂���Ȃ�true,�Ⴄ�Ȃ�false
	*/
	void LoadTexEx(int key, char* filePath,int a, int r, int g, int b, bool size );				

	/**
	* �o�[�e�b�N�X���쐬����֐�.
	* @param[in] key	�o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] width	����(X��)
	* @param[in] height ����(Y��)
	* @param[in] depth  ���s(Z��) �f�t�H���g�����l��0.0f
	*/
	void CreateVtx(int key, float width, float height, float depth = 0.0f);									

	/**
	* �o�[�e�b�N�X�̕ύX���s���֐�.
	* @param[in] key	�o�^�����L�[�A�܂���ID
	* @param[in] tuMin  tu�l�̍ŏ��l
	* @param[in] tuMax  tu�l�̍ő�l
	* @param[in] tvMin  tv�l�̍ŏ��l
	* @param[in] tvax	tv�l�̍ő�l
	* @param[in] color  �F���(ARGB) �f�t�H���g�����l��0xFFFFFFFF
	*/
	void SetVtx(int key, float tuMin, float tuMax, float tvMin, float tvMax, DWORD color = 0xFFFFFFFF);		 

	/**
	* �e�N�X�`���[��(XY���W)�ɂ����ĕ`�悷��֐�
	* @param[in] key	�o�^�����L�[�A�܂���ID
	* @param[in] center �ʒu���W���e�N�X�`���[�̒��S�ɂ���Ȃ�true,�Ⴄ�Ȃ�false
	* @param[in] posX	x���W
	* @param[in] posY   y���W
	*/
	void DrawXY(int key,bool center,float posX,float posY);													

	/**
	* �e�N�X�`���[��XZ���W�ŕ`�悷��֐�
	* @param[in] key	�o�^�����L�[�A�܂���ID
	* @param[in] center �ʒu���W���e�N�X�`���[�̒��S�ɂ���Ȃ�true,�Ⴄ�Ȃ�false
	* @param[in] posX	x���W
	* @param[in] posY   y���W
	* @param[in] posZ   z���W
	*/
	void DrawXZ(int key, bool center,float posX, float posY, float posZ);

	/**
	* �e�N�X�`���[���������֐�
	* @param[in] AllFlag  �S�ĉ������Ȃ�ture,����̃e�N�X�`���[�������������Ȃ�false�ő��������w�肷��
	* @param[in] key	�o�^�����L�[�A�܂���ID�B�f�t�H���g������999���o�^����Ȃ����낤���l�������Ă���
	*/
	void ReleaseTex(bool AllFlag,int key = 999);

	//-------------------------------------------------------------------------------------
	//								X�t�@�C���֘A�֐�
	//-------------------------------------------------------------------------------------
	/**
	* X�t�@�C����ǂݍ��ފ֐�.
	* @param[in] key		 �o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] pFilepath   �t�@�C����
	*/
	void LoadXFile(int key, LPCTSTR pFilePath);					

	/**
	* X�t�@�C����`�悷��֐�.
	* @param[in] key	�o�^�����L�[�A�܂���ID
	*/
	void DrawXFile(int key);				

	/**
	* X�t�@�C�����������֐�.
	* @param[in] AllFlag  �S�ĉ������Ȃ�ture,����̃e�N�X�`���[�������������Ȃ�false�ő��������w�肷��
	* @param[in] key	�o�^�����L�[�A�܂���ID�B�f�t�H���g������999���o�^����Ȃ����낤���l�������Ă���
	*/
	void ReleaseXFile(bool AllFlag,int key = 999);				

	//-----------------------------------------------------------------------------------------------------
	//									���̓f�o�C�X�֘A�֐�
	//-----------------------------------------------------------------------------------------------------

	/**�_�C���N�g�C���v�b�g���A�b�v�f�[�g����֐�*/
	void UpDateDI();											

	/**
	* �L�[�̏�Ԃ��m�F����֐�.
	* @param[in] DIK      �_�C���N�g�C���v�b�g�L�[ DIK_
	* @param[in] keyName  �L�[�̖��O
	* @return �{�^���̏��
	*/
	BUTTONSTATE CheckKey(int DIK, KEYKIND keyName);				

	/**
	* �}�E�X�̃{�^���̏�Ԃ��擾����֐�
	* @param[in] mouseButton �}�E�X�̃{�^���̎��
	* @return �{�^���̏��
	*/
	BUTTONSTATE ChecKMouse(MOUSEBUTTON mouseButton);			

	/**
	* �}�E�X�̃z�C�[���̏�Ԃ��擾����֐�.
	* @return �z�C�[���̏��
	*/
	WHEEL_STATE GetWheelState();								

	/**
	* �}�E�X�̍��W���擾����֐�.
	* @return �}�E�X�̍��W
	*/
	D3DXVECTOR2 GetMousePos();									 

	//--------------------------------------------------------------------------
	//							�T�E���h�֘A�֐�
	//--------------------------------------------------------------------------
	/**
	* ������ǂݍ��ފ֐�.
	* @param[in] key	  �o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] filePath �t�@�C����
	*/
	void LoadSound(int key,TCHAR* filePath);											

	/**
	* ���y��炷�֐�
	* @param[in] key		 �o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] operation   ���y�̍Đ����@
	*/
	void PlayDSound(int key, SOUND_OPERATION operation);

	//-------------------------------------------------------------------------------
	//								�f�o�b�N�@�\
	//-------------------------------------------------------------------------------
	/**
	* ������\��������֐�.
	* @param[in] text �\����������
	* @param[in] posX x���W
	* @param[in] posY y���W
	*/
	void DrawFont(std::string text, float posX, float posY);						

	/**
	* ���Ԍv�����J�n����֐�.
	* @param[in] timeName	�v�����������Ԃ̖��O
	*/
	void StartTimer(std::string  timeName);											

	/**
	* ���Ԍv�����I������֐�.
	* @param[in] timeName	�v�����I���������Ԃ̖��O
	*/
	void EndTimer(std::string  timeName);											

	/**
	* �v�����ʂ�\������֐�.
	* @param[in] timeName	�\���������v�����Ԃ̖��O
	* @param[in] posX x���W
	* @param[in] posY y���W
	*/
	void DrawResult(std::string  timeName,float posX,float posY);					

	/**
	* �v�����ʂ��擾����֐�.
	* @param[in] timeName	�擾�������v�����Ԃ̖��O
	*/
	DWORD GetResultTime(std::string  timeName);										

	/**
	* ���ׂĂ̎��Ԍ��ʂƂ��̍��v���Ԃ�\������֐�.
	* @param[in] posX x���W
	* @param[in] posY y���W
	*/
	void DrawAllResult(float posX,float posY);										
 };

#endif	// GAMELIB_H

