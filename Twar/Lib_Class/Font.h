/**
* @file Font.h
* @brief �t�H���g�������N���X��h
* @author haga
*/
#ifndef FONT_H
#define FONT_H

#include<d3dx9.h>
#include"GraphicsDevice.h"
/**
* �t�H���g�������N���X.
*/
class Font
{
private:
	IDirect3DDevice9*	m_pD3Device;		//!< Direct3D�̃f�o�C�X
	LPD3DXFONT			m_pFont;			//!< ID3DXFont�C���^�[�t�F�C�X�ւ̃|�C���^
	INT					m_height;			//!< �����̍���
	UINT				m_width;			//!< �����̕�

public:
	/**�R���X�g���N�^*/
	Font();

	/**
	* �R���X�g���N�^<br>
	* �����̑傫����ς���ꍇ�Ɏg��
	* @param[in] height		�����̍���
	* @param[in] width		�����̕�
	*/
	Font(INT height, UINT width);

	/**�f�X�g���N�^*/
	~Font();

	/**
	* �e�L�X�g��`�悷��֐�.
	* @param[in] pString	�\��������������
	* @param[in] pos		�e�L�X�g��\�����������W
	*/
	void Draw(LPCTSTR pString,D3DXVECTOR2 pos);

	/**
	* �e�L�X�g��`�悷��֐�<br>
	* ������͕����̐F��ύX�ł���
	* @param[in] pString	�\��������������
	* @param[in] pos		�e�L�X�g��\�����������W
	* @param[in] format	�e�L�X�g�^�C�v DT_LEFT(����) or DT_RIGHT(�E��) or DT_BOTTOM(����) or DT_TOP(���)
	* @param[in] color		�����̐F
	*/
	void Draw(LPCSTR pString, D3DXVECTOR2 pos, DWORD format, D3DCOLOR color);

	/**
	* �����̃t�H���g�Ȃǂ��Đݒ肷��֐�
	* @param[in] pFacename	�����t�H���g
	* @param[in] weight		�����̑��� ��{��FW_REGULAR(�ʏ�),FW_BOLD(����)�̂ǂ��炩��n��
	* @param[in] italic		�Α̂ɂ��邩�ǂ���
	*/
	void ReCreateFont(LPCTSTR pFacename, UINT weight, BOOL italic);

	/**
	* 1�����̍������擾����֐�.
	* @return m_height	�����̍���
	*/
	INT	 GetFontHeight(){ return m_height; }

	/**
	* 1�����̉������擾����֐�
	* @return 
	*/
	UINT GetFontWidth(){ return m_width; }
};

#endif		// FONT_H