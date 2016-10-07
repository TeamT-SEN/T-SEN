/**
* @file  SoundPlayer.h
* @brief ���y�̍Đ��Ɋւ���N���X.h
* @author haga
*/
#ifndef SOUND_PLAYER_H
#define SOUND_PLAYER_H

#include <windows.h>
#include <dSound.h>
#include "Dsound.h"

/**���y�̍Đ��`��*/
enum SOUNDMODE
{
	Play,			//!< �Đ�
	PlayLoop,		//!< ���[�v�Đ�
	Stop,			//!< ��~
	Reset,			//!< �����ʒu�ɖ߂�
	Stop_Reset,		//!< ��߂ď����ʒu�߂�
	Reset_Play		//!< �����ʒu����Đ�������
};

/**
* ���y���Ǘ�����N���X.
*/
class SoundPlayer
{
private:
	IDirectSound8 *m_pDSound8;			//!< DirectSound�̃C���^�[�t�F�C�X
	IDirectSoundBuffer8 *m_pDSBuffer;   //!< �Ȃ��i�[����o�b�t�@

	/**
	* WAVE�t�@�C���I�[�v���֐�.
	* @param[in]	filepath		���y�t�@�C����
	* @param[out]   waveFormatEx	wave�t�H�[�}�b�g
	* @param[out]	pwaveData		wave�f�[�^
	* @param[out]	dataSize		�f�[�^�T�C�Y
	* @retval	true	wave�t�@�C���I�[�v������
	* @retval	false	wave�t�@�C���I�[�v�����s
	*/
	bool OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize);

public:
	/**�R���X�g���N�^*/
	SoundPlayer();

	/**�f�X�g���N�^*/
	~SoundPlayer();

	/**
	* ���y��ǂݍ��ފ֐�.
	* @param[in]	filepath	���y�t�@�C����
	* @retval S_OK		�ǂݍ��ݐ���
	* @retval E_FAIL	�ǂݍ��ݎ��s
	*/
	HRESULT LoadSound(TCHAR* filepath);

	/**
	* ���y�Đ����[�h.
	* @param[in] sMode ���y������@
	*/
	void SoundMode(SOUNDMODE sMode);

};

#endif		// SOUND_PLAYER_H