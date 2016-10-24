/**
* @file SoundFileManager
* @brief  �T�E���h���Ǘ�����N���X��h
* @author haga
*/
#ifndef SOUND_FILE_MANAGER_H
#define SOUND_FILE_MANAGER_H

#include <windows.h>
#include <mmsystem.h>
#include <map>
#include <dsound.h>
using namespace std;

//#pragma comment(lib, "dsound.lib")

/**���y�̍Đ�����*/
enum SOUND_MODE
{
	Play,			//!< �Đ�
	PlayLoop,		//!< ���[�v�Đ�
	Stop,			//!< ��~
	Reset,			//!< �����ʒu�ɖ߂�
	Stop_Reset,		//!< ��߂ď����ʒu�߂�
	Reset_Play		//!< �����ʒu����Đ�������
};


/**
* �T�E���h���Ǘ�����N���X
*/
class SoundFileManager
{
private:
	IDirectSound8*								m_pDSound8;			//!< DirectSound�̃C���^�[�t�F�C�X
	std::map<int, LPDIRECTSOUNDBUFFER8>			m_soundMap;			//!< �T�E���h�t�@�C�����i�[����ϐ�
	bool										m_releaseFlag;		//!< ����������t���O

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

	/**�R���X�g���N�^*/
	SoundFileManager();

public:
	
	/**d�f�X�g���N�^*/
	~SoundFileManager();

	/**
	* Singlton�p�^�[��
	*/
	static SoundFileManager& GetInstance()
	{
		static SoundFileManager soundFileManager;

		return soundFileManager;
	}

	/**
	* DirectSound����������֐�
	* @param[in] hWnd �E�B���h�E�n���h��
	*/
	void InitSound(HWND hWnd);

	/**
	* ���y��ǂݍ��ފ֐�.
	* @param[in]    key			�o�^����L�[
	* @param[in]	filepath	���y�t�@�C����
	* @retval S_OK		�ǂݍ��ݐ���
	* @retval E_FAIL	�ǂݍ��ݎ��s
	*/
	HRESULT LoadSound(int key,TCHAR* filePath);

	/**
	* ���y���Đ�����֐�
	* @param[in]  key			�o�^�����L�[
	* @param[in] mode		���y�̍Đ�����
	*/
	void SoundPlayer(int key, SOUND_MODE sMode); 

	/**
	* �T�E���h����֐�
	* @param[in] key �o�^�����L�[
	*/
	void Release(int key);

	/**�T�E���h�S�Ă��������֐�*/
	void ReleaseALL();
};



#endif	// SOUND_FILE_MANAGER_H