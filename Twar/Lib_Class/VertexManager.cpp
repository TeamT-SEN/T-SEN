/**
* @file VertexManager.cpp
* @brief Vertex�N���X���Ǘ�����N���X
* @author haga
*/
#include "VertexManager.h"


VertexManager::VertexManager()
{
}


VertexManager::~VertexManager()
{
	ReleaseALL();
}

// �o�[�e�b�N�X�N���X���쐬���A�o�^����֐�
void VertexManager::CreateVertex(int key, float width, float height, float depth,
	float tuMax, float tvMax, float tuMin, float tvMin)
{
	Vertex vtx(width,height,depth,tuMax,tvMax,tuMin,tvMin);

	m_vertex[key] = vtx;
}

// XY���ŕ`�悷��֐�
void VertexManager::Draw(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y)
{
	m_vertex[key].Draw(pTexture,x,y);
}

// XZ���ŕ`�悷��֐�
void VertexManager::Draw(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y, float z)
{
	m_vertex[key].Draw(pTexture, x, y,z);
}

// XY���Ńo�[�e�b�N�X�̒��S���W�ŕ`�悷��֐�
void VertexManager::DrawCenterPos(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y)
{
	m_vertex[key].DrawCenterPos(pTexture, x, y);
}

// XZ���Ńo�[�e�b�N�X�̒��S���W�ŕ`�悷��֐�
void VertexManager::DrawCenterPos(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y, float z)
{
	m_vertex[key].DrawCenterPos(pTexture, x, y,z);
}

// �T�C�Y��ύX����֐�
void VertexManager::SetSize(int key, float width, float height, float depth)
{
	m_vertex[key].SetTexSize(width,height);
}

// tu�l��tv�l��ύX����֐�
void VertexManager::SetTuTv(int key, float tuMin, float tuMax, float tvMin, float tvMax)
{
	m_vertex[key].SetTuTvVal(tuMin,tuMax,tvMin,tvMax);
}

// �F��ύX����֐�
void VertexManager::SetColor(int key, DWORD color)
{
	m_vertex[key].SetColor(color);
}

// �o�[�e�b�N�X���������֐�
void VertexManager::Release(int key)
{
	m_vertex.erase(key);
}

// �S�Ẵo�[�e�b�N�X���������֐�
void VertexManager::ReleaseALL()
{
	m_vertex.clear();
}
