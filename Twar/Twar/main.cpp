/**
* @file main.cpp
* @brief T���main.cpp�ł�
* @author haga
*/
#include <windows.h>
#include <crtdbg.h>
#include <d3dx9.h>
#include <dinput.h>
#include "WindowCreator.h"
#include "GraphicsDevice.h"
#include "InputDevice.h"
#include "SoundFileManager.h"
#include "Font.h"


//#define FULLSCREEN

#define WINDOW_TITLE TEXT("T��")		// �E�B���h�E�^�C�g��
#define CLIENT_SIZE_W 1600				// �N���C�A���g�T�C�Y�̕�
#define CLIENT_SIZE_H 900 				// �N���C�A���g�T�C�Y�̍���
#define GAME_FPS (1000 / 60)			// �Q�[��FPS


WindowCreator*  g_pGameWindow = NULL;
GraphicsDevice* g_pGraphicsDevice = NULL;				// DirectXDevice
InputDevice*	g_pInputDevice = NULL;					// DirectInput

// �v���V�[�W���֐�
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);


// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// ���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	//-------------------------------------------------------------------
	//				         �E�B���h�E����
	//-------------------------------------------------------------------	
	g_pGameWindow = new WindowCreator(WINDOW_TITLE, CLIENT_SIZE_W, CLIENT_SIZE_H);
#ifndef FULLSCREEN

	g_pGameWindow->MakeWindow(hInstance, WindowProc, true);

#else

	g_pGameWindow->MakeWindow(hInstance, WindowProc, false);

#endif

	//-------------------------------------------------------------------
	//						  DirectX�֘A
	//-------------------------------------------------------------------

	// �O���t�B�b�N�f�o�C�X
	g_pGraphicsDevice = &GraphicsDevice::GetInstance();
#ifndef FULLSCREEN

	g_pGraphicsDevice->InitDevice(g_pGameWindow->GetHwnd(), true, CLIENT_SIZE_W, CLIENT_SIZE_H);

#else

	pGraphicsDevice->InitDevice(g_pGameWindow->GetHwnd(), false, CLIENT_SIZE_W, CLIENT_SIZE_H);

#endif


	g_pGraphicsDevice->SetRenderState3D();

	// �_�C���N�g�C���v�b�g
	g_pInputDevice = &InputDevice::GetInstance();
	g_pInputDevice->InitDinput();
	g_pInputDevice->InitDinputKey(g_pGameWindow->GetHwnd());
	g_pInputDevice->InitDinputMouse(g_pGameWindow->GetHwnd());

	// �_�C���N�g�T�E���h
	SoundFileManager* pSoundFileManager = NULL;
	pSoundFileManager = &SoundFileManager::GetInstance();
	pSoundFileManager->InitSound(g_pGameWindow->GetHwnd());

	//-------------------------------------------------------------------
	//						���b�Z�[�W���[�v
	//-------------------------------------------------------------------


	DWORD currentTime = timeGetTime();		// ���݂̎���
	DWORD oldTime = timeGetTime();			// �O�̎���

	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			currentTime = timeGetTime();
			if (currentTime - oldTime >= GAME_FPS)
			{
				oldTime = timeGetTime();
			}
		}
	}


	delete g_pGameWindow;

	return (INT)msg.wParam;
}
// �E�C���h�E�v���V�[�W���֐�
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
	case WM_DESTROY:
	{
		int a = MessageBox(hwnd, TEXT("�I���܂����H"), TEXT("�I��"), MB_YESNO);
		if (a == IDYES)
		{
			PostQuitMessage(0);
		}
	}
		return  0;
		break;
	case WM_KEYDOWN:
		switch ((CHAR)wparam)
		{
		case VK_ESCAPE:
		{
			int a = MessageBox(hwnd, TEXT("�I���܂����H"), TEXT("�I��"), MB_YESNO);
			if (a == IDYES)
			{
				PostQuitMessage(0);
			}
		}
			return 0;
			break;
		}
		break;

	case WM_SYSKEYDOWN:     // Alt + ����L�[�̏����Ɏg��
		switch ((CHAR)wparam)
		{
		case VK_RETURN:     // Alt + Enter�������ƃE�B���h�E�؂�ւ�
			g_pGraphicsDevice->ChangeDisplayMode();
			g_pGameWindow->ChangeWindowSize();
			break;
		default:
			break;
		}
		break;

	case WM_ACTIVATE:
		switch ((CHAR)wparam)
		{
		case WA_ACTIVE:
		case WA_CLICKACTIVE:

			break;
		}
	}
	return  DefWindowProc(hwnd, message, wparam, lparam);
}