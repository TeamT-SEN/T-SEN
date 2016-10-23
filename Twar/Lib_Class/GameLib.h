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
	GameLib(char* title, int width, int height);
	~GameLib();

	/**�������֐�*/
	void InitGameLib(HINSTANCE hInstance, LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp), bool windowType);

	/**�������J���֐�*/
	void ReleaseGameLib();

	/**�E�B���h�E�֘A�֐�*/
	void ChangeWindowMode();						//!< �E�B���h�E�T�C�Y��ς���֐�
	int GetWindowWidth(){ return m_wWidth; }		//!< �E�B���h�E�̉������擾����֐�
	int GetWindowHeight(){ return m_wHeight; }		//!< �E�B���h�E�̏c�����擾����֐�

	/**�`��֘A�֐�*/
	//----SetRenderState�n�̍Đݒ�͊֐���邩�A����Ƃ����L��GetDevice�łȂ�Ƃ����Ă��炤����������--------//
	const IDirect3DDevice9* GetDevice();						//!< �f�o�C�X���擾����֐�
	void StartRender(DWORD FVF = D3DFVF_CUSTOMVERTEX);			//!< �`��J�n�����֐�
	void EndRender();											//!< �`��I�������֐�
	void SetFVF(DWORD FVF);										//!< ���_�t�H�[�}�b�g��ݒ肷��֐�

	/**�e�N�X�`���[�֘A�֐�*/
	void LoadTex(int key, char* filePath);																	//!< �e�N�X�`���[��ǂݍ��ފ֐�
	void LoadTexEx(int key, char* filePath,int a, int r, int g, int b, bool size );							//!< �e�N�X�`���[���ڍאݒ肵�ēǂݍ��ފ֐�
	void CreateVtx(int key, float width, float height, float depth = 0.0f);									//!< �o�[�e�b�N�X���쐬����֐�
	void SetVtx(int key, float tuMin, float tuMax, float tvMin, float tvMax, DWORD color = 0xFFFFFFFF);		//!< �o�[�e�b�N�X�̕ύX���s���֐�
	void DrawXY(int key,bool center,float posX,float posY);													//!< �e�N�X�`���[(XY���W)��`�悷��֐�
	void DrawXZ(int key, bool center,float posX, float posY, float posZ);									//!< �e�N�X�`���[(XZ���W)��`�悷��֐�
	void ReleaseTex(bool AllFlag,int key = 999);

	/**X�t�@�C���֘A�֐�*/
	void LoadXFile(int key, LPCTSTR pFilePath);					//!< X�t�@�C����ǂݍ��ފ֐�
	void DrawXFile(int key);									//!< X�t�@�C����`�悷��֐�
	void ReleaseXFile(bool AllFlag,int key = 999);				//!< X�t�@�C�����������֐�

	/**���̓f�o�C�X�֘A�֐�*/
	void UpDateDI();											//!< �_�C���N�g�C���v�b�g���A�b�v�f�[�g����֐�
	BUTTONSTATE CheckKey(int DIK, KEYKIND keyName);				//!< �L�[�̏�Ԃ��m�F����֐�
	BUTTONSTATE ChecKMouse(MOUSEBUTTON mouseButton);			//!< �}�E�X�̃{�^���̏�Ԃ��擾����֐�
	WHEEL_STATE GetWheelState();								//!< �}�E�X�̃z�C�[���̏�Ԃ��擾����֐�
	D3DXVECTOR2 GetMousePos();									//!< �}�E�X�̍��W���擾����֐�

	/**�T�E���h�֘A�֐�*/
	void LoadSound(TCHAR* filePath);											//!< ������ǂݍ��ފ֐�
	void PlayDSound(TCHAR* filePath, SOUND_MODE sMode);							//!< ���y��炷�֐�

	/**�f�o�b�N�@�\*/
	void DrawFont(std::string text, float posX, float posY);						//!< ������\��������֐�
	void StartTimer(std::string  timeName);											//!< ���Ԍv�����J�n����֐�
	void EndTimer(std::string  timeName);											//!< ���Ԍv�����I������֐�
	void DrawResult(std::string  timeName,float posX,float posY);					//!< �v�����ʂ�\������֐�
	DWORD GetResultTime(std::string  timeName);										//!< �v�����ʂ��擾����֐�
	void DrawAllResult(float posX,float posY);										//!< ���ׂĂ̎��Ԍ��ʂƂ��̍��v���Ԃ�\������֐�
 };

#endif	// GAMELIB_H

