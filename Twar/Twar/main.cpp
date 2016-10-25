/**
* @file main.cpp
* @brief T���main.cpp�ł�
* @author haga
*/
#include <windows.h>
#include <crtdbg.h>
#include <d3dx9.h>
#include <dinput.h>
#include "GameLib.h"




//#define FULLSCREEN

#define WINDOW_TITLE TEXT("T��")		// �E�B���h�E�^�C�g��
#define CLIENT_SIZE_W 1600				// �N���C�A���g�T�C�Y�̕�
#define CLIENT_SIZE_H 900 				// �N���C�A���g�T�C�Y�̍���
#define GAME_FPS (1000 / 60)			// �Q�[��FPS

GameLib*		g_pGameLib = NULL;

// �v���V�[�W���֐�
LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);


// �G���g���|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	// ���������[�N���o
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	MSG msg;

	g_pGameLib = &GameLib::GetInstance();
	//-------------------------------------------------------------------
	//				         �E�B���h�E����
	//-------------------------------------------------------------------	
#ifndef FULLSCREEN

	g_pGameLib->InitGameLib(WINDOW_TITLE, CLIENT_SIZE_W, CLIENT_SIZE_H,hInstance, WindowProc, true);

#else
	g_pGameLib->InitGameLib(WINDOW_TITLE, CLIENT_SIZE_W, CLIENT_SIZE_H,hInstance, WindowProc, false);

#endif



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


	g_pGameLib->ReleaseGameLib();

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
		return  0;
	}
		
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
				return 0;
			}
		}
			
			break;
		}
		break;

	case WM_SYSKEYDOWN:     // Alt + ����L�[�̏����Ɏg��
		switch ((CHAR)wparam)
		{
		case VK_RETURN:     // Alt + Enter�������ƃE�B���h�E�؂�ւ�
			g_pGameLib->ChangeWindowMode();
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