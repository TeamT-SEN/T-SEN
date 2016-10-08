/**
* @file   XFile.h
* @brief  X�t�@�C���������N���X��h
* @author haga
*/
#ifndef XFILE_H
#define XFILE_H

#include "GraphicsDevice.h"

/**
* X�t�@�C���������N���X
*/
class XFile
{
private:
	IDirect3DDevice9*		m_pD3Device;		//!< Direct3D�̃f�o�C�X
	LPD3DXMESH				m_pMesh;			//!< ID3DXMesh�̃C���^�[�t�F�C�X�ւ̃|�C���^
	D3DMATERIAL9*			m_pMaterials;		//!< �}�e���A��
	LPDIRECT3DTEXTURE9*		m_pTextures;		//!< �e�N�X�`���[
	DWORD					m_dwNumMaterials;	//!< �}�e���A����

public:
	/**�R���X�g���N�^*/
	XFile();

	/**�f�X�g���N�^*/
	~XFile();

	/**
	* X�t�@�C������f�[�^��ǂݍ��ފ֐�.
	* @param[in] pFilename �t�@�C����
	* @retval	true	�ǂݍ��ݐ���
	* @retval	false	�ǂݍ��ݎ��s
	*/
	bool LoadXFile(LPCTSTR pFilename);

	/**
	* ���b�V����`�悷��֐�.
	*/
	void DrawX();

	/**
	* ����������֐�<br>
	* FailManager�Ɏg�p���邽�߂ɍ쐬
	*/
	void Release();
};

#endif	// XFILE_H