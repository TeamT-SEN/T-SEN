#include "Camera.h"

// �R���X�g���N�^
Camera::Camera(float width, float height) :
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_windowWidth(width),
m_windowHeight(height)
{
}

// �f�X�g���N�^
Camera::~Camera()
{
}

// ���_���W�ϊ��Ǝˉe���W�ϊ����s���֐�(���l�͉��u��)
void Camera::LookInCamera(const D3DXVECTOR3* vEyePt, const D3DXVECTOR3* vLookatPt, const float* angle)
{
	// ���_���W
	D3DXMATRIX    matView;						  // �ϊ���̎��_���W���i�[����s��
	D3DXVECTOR3   vUpVec = { 0.0f, 1.0f, 0.0f };  // �J�����̏�����̃x�N�g��
	D3DXMatrixLookAtLH(&matView, vEyePt, vLookatPt, &vUpVec);
	m_pD3Device->SetTransform(D3DTS_VIEW, &matView);

	// �ˉe���W
	D3DXMATRIX matProj;							   // �ϊ���̎ˉe���W���i�[����s��
	float viewAngle = D3DXToRadian(*angle);		   // ����p
	float aspect = m_windowWidth / m_windowHeight; // �A�X�y�N�g��(��ʃT�C�Y�ɂ���ĕύX)
	float nearZ = 1.0f;							   // �ŋߓ_
	float farZ = 10000.f;						   // �ŉ��_
	D3DXMatrixPerspectiveFovLH(&matProj, viewAngle, aspect, nearZ, farZ);
	m_pD3Device->SetTransform(D3DTS_PROJECTION, &matProj);
}