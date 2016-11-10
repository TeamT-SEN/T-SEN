/**
* @file   CameraController.h
* @brief  �J�����R���g���[���[�N���X��h
* @author haga
*/
#ifndef CAMERA_CONTROLLER_H
#define CAMERA_CONTROLLER_H

#include <d3dx9.h>

class Camera;
class InputKey;

/**
* �J�����R���g���[���[�N���X��h
*/
class CameraController
{
private:
	D3DXVECTOR3 m_vEyePt;			//!< �J�����̈ʒu
	D3DXVECTOR3 m_vLookPt;			//!< �J�����̒����_
	float		m_angle;			//!< �J�����̔{��
	Camera*		m_pCamera;			//!< �J����
	InputKey*    m_pInputKey;         //!< �R���g���[���L�[

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
	* �R���g���[���֐�
	*/
	void Control();

	/**
	* ���W�ϊ��֐�
	*/
	void TransformView(D3DXVECTOR3 vLookPt);

	/**
	* �Q�b�^�[�֐�
	*/
	D3DXVECTOR3 GetEyePos(){ return m_vEyePt; }
	D3DXVECTOR3 GetLookAtPos(){ return m_vLookPt; }
	float GetAngle(){ return m_angle; }

};

#endif	// CAMERA_CONTROLLER_H
