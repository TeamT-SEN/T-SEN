/**
* @file  Light.h
* @brief ���C�g�Ɋւ���N���X
* @author haga
*/
#ifndef LIGHT_H
#define LIGHT_H
#include <d3dx9.h>
#include "GraphicsDevice.h"

/**
* ���C�g�Ɋւ���N���X
*/
class Light
{
private:
	LPDIRECT3DDEVICE9		m_pD3Device;		//!< Direct3D�̃f�o�C�X
	D3DLIGHT9				m_light;			//!< ���C�g�\����
	D3DXVECTOR3				m_lightPos;			//!< ���C�g�̈ʒu
	D3DXVECTOR3             m_direction;		//!< ���C�g�̌���
	DWORD					m_ambientColor;		//!< �A���r�G���g�F

public:
	/**
	* �R���X�g���N�^
	* @param[in] direction ���C�g�̌���
	*/
	Light(D3DXVECTOR3 direction);

	/**
	* �R���X�g���N�^
	* @param[in] lightPos  ���C�g�̈ʒu
	* @param[in] direction ���C�g�̌���
	*/
	Light(D3DXVECTOR3 lightPos,D3DXVECTOR3 direction);

	/**�f�X�g���N�^*/
	~Light();

	/**
	* ���C�g�A�b�v�֐�
	*/
	void LightUp();

	/**
	* ���C�g�̎�ނ�ݒ肷��<br>
	* D3DLIGHT_POINT,D3DLIGHT_SPOT,D3DLIGHT_DIRECTIONAL�̎�ނ�����
	* @param[in] type ���C�g�̎�� 
	*/
	void SetLightType(D3DLIGHTTYPE type);

	/**
	* ���C�g�̍��W�ƌ������Z�b�g����
	* @param[in] pos ���C�g�̍��W
	* @param[in] direction ���C�g�̌���
	*/
	void SetLightPos(D3DXVECTOR3 pos);

	/**
	* ���C�g�̌������Z�b�g����
	* @param[in] direction ���C�g�̌���
	*/
	void SetLightDirection(D3DXVECTOR3 direction);

	/**
	* ���C�g�̋������Z�b�g����
	* @param[in] range ���C�g�́v�͂�����
	*/
	void SetLightRange(float range);

	/**
	* ���C�g�̃f�B�q���[�Y���Z�b�g����֐�
	* @param[in] dR R�l 
	* @param[in] dG G�l
	* @param[in] dB B�l
	*/
	void SetDiffuse(float dR,float dG,float dB);

	/**
	* ���C�g�̃X�y�L�������Z�b�g����֐�
	* @param[in] dR R�l
	* @param[in] dG G�l
	* @param[in] dB B�l
	*/
	void SetSpecular(float dR, float dG, float dB);
};

#endif		// LIGHT_H