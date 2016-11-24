/**
	@file   CameraController.h
	@brief  �J�����R���g���[���[�N���X��h
	@author kawaguchi
*/
#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <d3dx9.h>

class Camera;

/**
* �J�����R���g���[���[�N���X��h
*/
class CameraController
{
private:
	Camera*		m_pCamera;			//!< �J����

public:
	/**�R���X�g���N�^*/
	CameraController();
	/**�f�X�g���N�^*/
	~CameraController();

	// ���̂�����
	static CameraController &GetInstance()
	{
		static CameraController m_cameraController;

		return m_cameraController;
	}

	/**
	* ���W�ϊ��֐�
	*/
	void TransformView(D3DXVECTOR3 vEyePt, D3DXVECTOR3 vLookPt, float angle);
};

#endif	// CAMERA_CONTROLLER_H
