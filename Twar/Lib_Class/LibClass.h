/**
* @file LibClass.h
* @brief Lib_Class�̃w�b�_�[�t�@�C�����܂Ƃ߂��w�b�_�[�t�@�C��<br>
* �w�b�_�[���t�B���^�[���Ƃɕ����Ă���.
* @author haga
*/

#ifndef LIB_CLASS_H
#define LIB_CLASS_H

//--------------------------------------------
//�@�@�@�@�@ DirectXGraphics
//--------------------------------------------
#include "GraphicsDevice.h"			//!< GraphicsDevice�̃N���X
#include "Texture.h"				//!< �e�N�X�`���N���X
#include "Vertex.h"					//!< ���_�N���X
#include "XFile.h"					//!< X�t�@�C���N���X
#include "Font.h"					//!< �t�H���g�N���X

//-------------------------------------------
//�@�@�@�@�@�@ DirectInput
//-------------------------------------------
#include "InputDevice.h"			//!< DirectInput�f�o�C�X�֘A�N���X
#include "InputKey.h"				//!< �L�[�{�[�h����֘A�N���X
#include "InputMouse.h"				//!< �}�E�X����֘A�N���X

//-------------------------------------------
//				DirectSound
//-------------------------------------------
#include "DSound.h"					//!< DirectSound�f�o�C�X�֘A�N���X
#include "SoundPlayer.h"			//!< ���y�Đ��N���X

//-------------------------------------------
//�@�@�@�@�@	WindowCreater
//-------------------------------------------
#include "WindowCreator.h"			//!< Window�֘A�N���X

//-------------------------------------------
//				���̑�
//-------------------------------------------
#include "Camera.h"					//!< �J�����N���X
#include "Light.h"					//!< ���C�g�N���X
#include "DebugTimer.h"				//!< �f�o�b�N�^�C�}�[�N���X

/*
�ݒ肷��Lib
#pragma comment (lib,"winmm.lib")
#pragma comment (lib,"d3d9.lib")
#pragma comment (lib,"d3dx9.lib")
#pragma comment (lib,"dxguid.lib")
#pragma comment (lib,"shlwapi.lib")
#pragma comment (lib,"dinput8.lib")
#pragma comment (lib,"Dsound.lib")
#pragma comment (lib,"Lib_Class.lib")
*/

#endif