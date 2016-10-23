/**
* @file DebugFont�N���X
* @brief �f�o�b�N�Ŏg�p����t�H���g�̃N���X
* @author haga
*/

#ifndef DEBUG_FONT_H
#define DEBUG_FONT_H

#include<d3dx9.h>
#include"GraphicsDevice.h"

class DebugFont
{
private:
	IDirect3DDevice9*	m_pD3Device;		//!< Direct3D�̃f�o�C�X
	LPD3DXFONT			m_pFont;			//!< ID3DXFont�C���^�[�t�F�C�X�ւ̃|�C���^
	INT					m_height;			//!< �����̍���
	UINT				m_width;			//!< �����̕�
	D3DCOLOR			m_color;			//!< �����̐F

public:
	/**�R���X�g���N�^*/
	DebugFont(INT height = 20, UINT width = 10, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));

	/**�f�X�g���N�^*/
	~DebugFont();

	/**
	* �e�L�X�g��`�悷��֐�<br>
	* ������͕����̐F��ύX�ł���
	* @param[in] pString	�\��������������
	* @param[in] pos		�e�L�X�g��\�����������W
	* @param[in] color		�����̐F
	*/
	void Draw(LPCSTR pString, D3DXVECTOR2 pos);

	/**m�������J���֐�*/
	void Release();

	/**
	* 1�����̍������擾����֐�.
	* @return m_height	�����̍���
	*/
	INT	 GetFontHeight(){ return m_height; }
};

#endif // DEBUG_FONT_H
