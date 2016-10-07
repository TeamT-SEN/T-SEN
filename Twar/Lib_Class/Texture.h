/**
* @file Texture.h
* @brief �e�N�X�`���[�Ɋ֘A����N���X.h
* @author haga
*/
#ifndef TEXTURE_H
#define TEXTURE_H

#include <d3dx9.h>
#include <d3d9.h>
#include "GraphicsDevice.h"

/**
* �J�X�^���o�[�e�b�N�X�\����.
*/
struct CUSTOMVERTEX
{
	FLOAT	x, y, z, rhw;	//!< ���W�n
	DWORD	color;			//!< �F
	FLOAT	tu, tv;			//!< �e�N�X�`���[��tu,tv�l
};

/**
* �e�N�X�`���[���Ǘ�����N���X.
*/
class Texture
{
private:
	LPDIRECT3DTEXTURE9	m_pTexture;		//!< �e�N�X�`���[���i�[����ϐ�
	IDirect3DDevice9*	m_pD3Device;	//!< �f�o�C�X

public:
	/**�R���X�g���N�^*/
	Texture();
	/**�f�X�g���N�^*/
	~Texture();

	/**
	* �摜�ǂݍ��݊ȈՔ�.
	* @param[in] text   �摜�t�@�C���̖��O
	* @retval S_OK		�摜�ǂݍ��ݐ���
	* @retval E_FAIL	�摜�ǂݍ��ݎ��s
	*/
	HRESULT LoadTex(char* text);

	/**
	* �摜�ǂݍ��ݏڍאݒ��.
	* @param[in] text �摜�t�@�C���̖��O
	* @param[in] a	  �A���t�@�l
	* @param[in] r	  �F��r�l
	* @param[in] g	  �F��g�l
	* @param[in] b	  �F��b�l
	* @param[in] size 2�ׂ̂���T�C�Y���ǂ���
	* @retval S_OK	  �摜�ǂݍ��ݐ���
	* @retval E_FAIL  �摜�ǂݍ��ݎ��s
	*/
	HRESULT LoadTexEx(char* text,int a,int r,int g,int b,bool size);

	/**
	* �`��.
	* @param[in] setdraw
	*/
	void RenderTex(CUSTOMVERTEX* setdraw);

	/**
	* �f�o�C�X���擾����֐�<br>
	* static��CTexture���g���ꍇ.
	*/
	void GetDevice();

	/**
	* �e�N�X�`���[���J������֐�<br>
	*/
	void Release();

	/**
	* �e�N�X�`���[���i�[���Ă��邩���m�F.
	* @return m_pTexture �e�N�X�`���[���i�[����ϐ�
	*/
	LPDIRECT3DTEXTURE9 GetStateTex(){ return m_pTexture; }

};

#endif		// TEXTURE_H