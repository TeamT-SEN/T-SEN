/**
* @file  Camera.h
* @brief �J�����N���X
* @author haga
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <d3dx9.h>
#include "GraphicsDevice.h"

/**
* �J�����N���X.
*/
class Camera
{
private:
	LPDIRECT3DDEVICE9		m_pD3Device;		//!< Direct3D�̃f�o�C�X
	float					m_windowWidth;		//!< �E�B���h�E�T�C�Y��
	float					m_windowHeight;		//!< �E�B���h�E�T�C�Y����

public:
	/**�R���X�g���N�^*/
	Camera(float width,float height);
	/**�f�X�g���N�^*/
	~Camera();
	/**
	* ���_���W�ϊ��Ǝˉe���W�ϊ����s���֐�.
	* @param[in] vEyePt			�J�����̈ʒu
	* @param[in] vLookatPt	    �����_
	* @param[in] angle			����p
	*/
	void LookInCamera(const D3DXVECTOR3* vEyePt, const D3DXVECTOR3* vLookatPt, const float* angle);

};

#endif // CAMERA_H