/**
* @file TextureManager.h
* @brief �e�N�X�`���[���Ǘ�����N���X��h
* @author haga
*/
#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <d3dx9.h>
#include <d3d9.h>
#include "GraphicsDevice.h"
#include <map>
using namespace std;

class TextureManager
{
private:
	IDirect3DDevice9*				  m_pD3Device;	//!< �f�o�C�X
	std::map<int, LPDIRECT3DTEXTURE9> m_texture;	//!< �e�N�X�`���[�����i�[����ϐ�

public:
	/**�R���X�g�^�N�^*/
	TextureManager();

	/**�f�X�g���N�^*/
	~TextureManager();

	/**
	* �e�N�X�`���[��ǂݍ��ފ֐�.
	* @param[in] key		�o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] filepath   �t�@�C����
	*/
	void Load(int key,char* filePath); 

	/**
	* �e�N�X�`���[���ڍאݒ肵�ēǂݍ��ފ֐�.
	* @param[in] key		�o�^����L�[�A�܂���ID(enum�ō쐬��z��)
	* @param[in] filepath   �t�@�C����
	* @param[in] a			�A���t�@�l
	* @param[in] r			�F��R�l 255
	* @param[in] g			�F��G�l 255
	* @param[in] b			�F��B�l 255
	* @param[in] size		�e�N�X�`���[�̃T�C�Y���Q�ׂ̂���Ȃ�true,�Ⴄ�Ȃ�false
	*/
	void LoadEx(int key, char* filePath, int a = 255, int r = 0, int g = 0, int b = 0, bool size = false);

	/**
	* �e�N�X�`���[�̃A�h���X���擾����֐�
	* @param[in] key	�o�^�����L�[
	*/
	LPDIRECT3DTEXTURE9 GetTex(int key);

	/**
	* �e�N�X�`���[����֐�
	* @param[in] key	�o�^�����L�[
	*/
	void Release(int key);

	/**
	* �e�N�X�`���[�����ׂĉ������֐�
	*/
	void ReleaseALL();

};

#endif	// TEXTURE_MANAGER_H
