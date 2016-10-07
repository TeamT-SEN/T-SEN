/**
* @file  Light.h
* @brief ���C�g�Ɋւ���N���X
* @author haga
*/

#include "Light.h"

// �R���X�g���N�^ ����
Light::Light(D3DXVECTOR3 direction) :
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_direction(direction),
m_ambientColor(0x00111111)
{
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_DIRECTIONAL;
	m_light.Diffuse.r = 1.0f;
	m_light.Diffuse.g = 1.0f;
	m_light.Diffuse.b = 1.0f;
	m_light.Specular.r = 1.0f;
	m_light.Specular.g = 1.0f;
	m_light.Specular.b = 1.0f;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &m_direction);
	m_light.Range = 500.0f;
}

// �R���X�g���N�^ 
Light::Light(D3DXVECTOR3 lightPos,D3DXVECTOR3 direction):
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_direction(direction),
m_lightPos(lightPos),
m_ambientColor(0x00111111)
{
	ZeroMemory(&m_light, sizeof(D3DLIGHT9));
	m_light.Type = D3DLIGHT_SPOT;
	m_light.Diffuse.r = 1.0f;
	m_light.Diffuse.g = 1.0f;
	m_light.Diffuse.b = 1.0f;
	m_light.Specular.r = 1.0f;
	m_light.Specular.g = 1.0f;
	m_light.Specular.b = 1.0f;
	m_light.Position = m_lightPos;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &m_direction);
	m_light.Range = 500.0f;
}

// �f�X�g���N�^
Light::~Light()
{
}

// ���C�g�g�p����֐�
void Light::LightUp()
{
	m_pD3Device->SetLight(0, &m_light);
	m_pD3Device->LightEnable(0, TRUE);
	m_pD3Device->SetRenderState(D3DRS_LIGHTING, TRUE);				     // ���C�g��L���ɂ���
	m_pD3Device->SetRenderState(D3DRS_AMBIENT, m_ambientColor);			 // �A���r�G���g���C�g(����)��ݒ肷��
	m_pD3Device->SetRenderState(D3DRS_SPECULARENABLE, TRUE);		     // �X�y�L����(���ʔ���)��L���ɂ���
}
 
// ���C�g�̎�ނ�ݒ肷��
void Light::SetLightType(D3DLIGHTTYPE type)
{
	m_light.Type = type;
}


// ���C�g�̍��W�ƌ������Z�b�g����
void Light::SetLightPos(D3DXVECTOR3 pos)
{
	m_light.Position = pos;

}

// ���C�g�̌������Z�b�g����
void  Light::SetLightDirection(D3DXVECTOR3 direction)
{
	m_direction = direction;
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &direction);
}

// ���C�g�̋������Z�b�g����
void Light::SetLightRange(float range)
{
	m_light.Range = range;
}

// �f�B�q���[�Y���Z�b�g����
void Light::SetDiffuse(float dR, float dG, float dB)
{
	m_light.Diffuse.r = dR;
	m_light.Diffuse.g = dG;
	m_light.Diffuse.b = dB;
}

// ���C�g�̃X�y�L�������Z�b�g����
void Light::SetSpecular(float dR, float dG, float dB)
{
	m_light.Specular.r = dR;
	m_light.Specular.g = dG;
	m_light.Specular.b = dB;
}