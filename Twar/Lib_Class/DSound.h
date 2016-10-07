/**
* @file DSound.h
* @brief DirectSound�Ɋւ���N���X��h 
* @author haga
*/
#ifndef DSOUND_H
#define DSOUND_H

#include <dSound.h>

/**
* DirectSound�̃C���^�[�t�F�C�X���쐬�A�擾����N���X.
*/
class DSound
{
private:
	IDirectSound8 *m_pDSound8;		//!< DirectSound�̃C���^�[�t�F�C�X

public:
	/**�R���X�g���N�^*/
	DSound();

	/**�f�X�g���N�^*/
	~DSound();

	/**
	* DirectSound�̎��̂��擾����֐�<br>
	* Singleton�p�^�[��.
	* @return IDirectSound8 �C���^�[�t�F�C�X
	*/
	static DSound& GetInstance()
	{
		static DSound IDirectSound8;

		return IDirectSound8;
	}

	/**
	* �C���^�[�t�F�C�X��������.
	* @param[in] hWnd �E�B���h�E�n���h��
	*/
	void InitDSound(HWND hWnd);

	/**
	* �C���^�[�t�F�C�X�̎擾.
	* @return m_pDSound8 �C���^�[�t�F�C�X
	*/
	IDirectSound8* GetInterface(){ return m_pDSound8; };
};


#endif		// DSOUND_H