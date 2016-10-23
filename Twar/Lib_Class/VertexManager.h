/**
* @file VertexManager.h
* @brief Vertex�N���X���Ǘ�����N���X
* @author haga
*/
#ifndef VERTEX_MANAGER_H
#define VERTEX_MANAGER_H

#include <map>
#include "Vertex.h"
using namespace std;

class VertexManager
{
private:
	std::map<int, Vertex> m_vertex;				//!< �o�[�e�b�N�X�N���X���i�[����ϐ� 

public:
	/**�R���X�g���N�^*/
	VertexManager();
	/**�f�X�g���N�^*/
	~VertexManager();

	/**
	* �o�[�e�b�N�X�N���X���쐬���A�o�^����֐�.
	* @param[in] key	map�̃L�[
	* @param[in] width	����(X��)
	* @param[in] height ����(Y��)
	* @param[in] depth  ���s(Z��)
	* @param[in] tuMax  tu�l�̍ő�l
	* @param[in] tvMax  tv�l�̍ő�l
	* @param[in] tuMin  tu�l�̍ŏ��l
	* @param[in] tvMin  tv�l�̍ŏ��l
	*/
	void CreateVertex(int key,float width, float height, float depth = 0.0f,
		float tuMax = 1.0f, float tvMax = 1.0f, float tuMin = 0.0f, float tvMin = 0.0f);

	/**
	* XY���ŕ`�悷��֐�
	* @param[in] key		map�̃L�[
	* @param[in] pTexture   �e�N�X�`���[���i�[��
	* @param[in] x			x���W
	* @param[in] y			y���W
	*/
	void Draw(int key, LPDIRECT3DTEXTURE9 pTexture,float x,float y);

	/**
	* XZ���ŕ`�悷��֐�
	* @param[in] key		map�̃L�[
	* @param[in] pTexture   �e�N�X�`���[���i�[��
	* @param[in] x			x���W
	* @param[in] y			y���W
	* @param[in] z			z���W
	*/
	void Draw(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y, float z);

	/**
	* XY���Ńo�[�e�b�N�X�̒��S���W�ŕ`�悷��֐�
	* @param[in] key		map�̃L�[
	* @param[in] pTexture   �e�N�X�`���[���i�[��
	* @param[in] x			x���W
	* @param[in] y			y���W
	*/
	void DrawCenterPos(int key, LPDIRECT3DTEXTURE9 pTexture,float x,float y);

	/**
	* XZ���Ńo�[�e�b�N�X�̒��S���W�ŕ`�悷��֐�
	* @param[in] key		map�̃L�[
	* @param[in] pTexture   �e�N�X�`���[���i�[��
	* @param[in] x			x���W
	* @param[in] y			y���W
	* @param[in] z			z���W
	*/
	void DrawCenterPos(int key, LPDIRECT3DTEXTURE9 pTexture, float x, float y,float z);

	/**
	* �T�C�Y��ύX����֐�
	* @param[in] key	map�̃L�[
	* @param[in] width	����(X��)
	* @param[in] height ����(Y��)
	* @param[in] depth  ���s(Z��)
	*/
	void SetSize(int key, float width, float height, float depth = 0.0f);

	/**
	* tu�l��tv�l��ύX����֐�
	* @param[in] key	map�̃L�[
	* @param[in] tuMin  tu�l�̍ŏ��l
	* @param[in] tuMax  tu�l�̍ő�l
	* @param[in] tvMin  tv�l�̍ŏ��l
	* @param[in] tvax	tv�l�̍ő�l
	*/
	void SetTuTv(int key, float tuMin, float tuMax, float tvMin, float tvMax);

	/**
	* �F��ύX����֐�
	* @param[in] key	map�̃L�[
	* @param[in] color  �F
	*/
	void SetColor(int key, DWORD color);

	/**
	* �o�[�e�b�N�X���������֐�
	* @param[in] key	map�̃L�[
	*/
	void Release(int key);

	/**�S�Ẵo�[�e�b�N�X���������֐�*/
	void ReleaseALL();
};

#endif	// VERTEX_MANAGER_H