/**
* @file   XFile.cpp
* @brief  X�t�@�C���������N���X��cpp
* @author haga
*/

#include "XFile.h"

// �R���X�g���N�^
XFile::XFile() :m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_pMesh(NULL),
m_pMaterials(NULL),
m_pTextures(NULL),
m_dwNumMaterials(0)
{
}

// �f�X�g���N�^
XFile::~XFile()
{
	if (m_pMesh)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
	delete m_pMaterials;
	delete m_pTextures;
}

// X�t�@�C������f�[�^��ǂݍ��ފ֐�
bool XFile::LoadXFile(LPCTSTR pFilename)
{
	// ���b�V�������[�h����
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL; // �}�e���A�������i�[����f�[�^�o�b�t�@

	if (FAILED(D3DXLoadMeshFromX(
		pFilename,					// �t�@�C����
		D3DXMESH_SYSTEMMEM,			// ���b�V���쐬�I�v�V����
		m_pD3Device,
		NULL,						// �אڐ��f�[�^���܂ރo�b�t�@�ւ̃|�C���^
		&pD3DXMtrlBuffer,
		NULL,						// �Ԃ���郁�b�V�����̑����O���[�v���Ƃ� 1 �́A�G�t�F�N�g �C���X�^���X�̔z����܂ރo�b�t�@�ւ̃|�C���^
		&m_dwNumMaterials, 
		&m_pMesh)))
	{
		MessageBox(NULL,"X�t�@�C���̓ǂݍ��݂Ɏ��s���܂���",NULL,MB_OK);
		return false;
	}

	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();		// �}�e���A���E�o�b�t�@�ւ̃|�C���^��錾�A������
	m_pMaterials = new D3DMATERIAL9[m_dwNumMaterials];										// �}�e���A���̃��������}�e���A���̐��������m�ۂ���
	m_pTextures = new LPDIRECT3DTEXTURE9[m_dwNumMaterials];									// �e�N�X�`���[�̃��������}�e���A���̐��������m�ۂ���

	// m_pMaterials��m_pTextures�̒��g����Ȃ̂Ń}�e���A���f�[�^��������
	for (DWORD i = 0; i < m_dwNumMaterials; i++)
	{
		m_pMaterials[i] = d3dxMaterials[i].MatD3D;
		 m_pMaterials[i].Ambient = m_pMaterials[i].Diffuse;
		 m_pTextures[i] = NULL;
		 if (d3dxMaterials[i].pTextureFilename != NULL &&
			 lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
		 {
			 if (FAILED(D3DXCreateTextureFromFile(
				 m_pD3Device,
				 d3dxMaterials[i].pTextureFilename,
				 &m_pTextures[i])))
			 {
				 MessageBox(0, "�e�N�X�`���̓ǂݍ��݂Ɏ��s���܂����B", NULL, MB_OK);
			 }
		 }
	}

	pD3DXMtrlBuffer->Release();		// �s�v�Ȃ̂Ń��������J������

	return true;
}

// �`��֐�
void XFile::DrawX()
{
	for (DWORD i = 0; i < m_dwNumMaterials;i++)
	{
		m_pD3Device->SetMaterial(&m_pMaterials[i]);
		m_pD3Device->SetTexture(0, m_pTextures[i]);
		m_pMesh->DrawSubset(i);
	}
}

// ���������
void XFile::Release()
{
	if (m_pMesh)
	{
		m_pMesh->Release();
		m_pMesh = NULL;
	}
	delete m_pMaterials;
	delete m_pTextures;
}