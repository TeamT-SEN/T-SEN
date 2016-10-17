/**
* @file SoundFileManager.cpp
* @brief �T�E���h���Ǘ�����N���X��cpp
* @author haga
*/

#include "SoundFileManager.h"

SoundFileManager::SoundFileManager():
m_pDSound8(NULL)
{
}

SoundFileManager::~SoundFileManager()
{
	for (auto itr = m_soundMap.begin(); itr != m_soundMap.end();itr++)
	{
		if (itr->second)
		{
			itr->second->Release();
			itr->second = NULL;
		}
	}

	m_soundMap.clear();
		
	if (m_pDSound8)
	{
		m_pDSound8->Release();
		m_pDSound8 = NULL;
	}
}

void SoundFileManager::InitSound(HWND hWnd)
{
	DirectSoundCreate8(NULL, &m_pDSound8, NULL);
	// �������x���ݒ�
	m_pDSound8->SetCooperativeLevel(hWnd, DSSCL_NORMAL);
}

// WAVE�t�@�C���I�[�v���֐�
bool SoundFileManager::OpenWave(TCHAR* filepath, WAVEFORMATEX* waveFormatEx, char** pwaveData, DWORD* dataSize)
{
	if (filepath == 0)
		return false;

	HMMIO hMmio = NULL;
	MMIOINFO mmioInfo;

	// wave�t�@�C���I�[�v��
	memset(&mmioInfo, 0, sizeof(MMIOINFO));
	hMmio = mmioOpen(filepath, &mmioInfo, MMIO_READ);
	if (!hMmio)
		return false; // �t�@�C���I�[�v�����s

	// RIFF�`�����N����
	MMRESULT mmRes;
	MMCKINFO riffChunk;
	riffChunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	mmRes = mmioDescend(hMmio, &riffChunk, NULL, MMIO_FINDRIFF);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}

	// �t�H�[�}�b�g�`�����N����
	MMCKINFO formatChunk;
	formatChunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	mmRes = mmioDescend(hMmio, &formatChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}
	DWORD fmsize = formatChunk.cksize;
	DWORD size = mmioRead(hMmio, (HPSTR)waveFormatEx, fmsize);
	if (size != fmsize) {
		mmioClose(hMmio, 0);
		return false;
	}

	mmioAscend(hMmio, &formatChunk, 0);

	// �f�[�^�`�����N����
	MMCKINFO dataChunk;
	dataChunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	mmRes = mmioDescend(hMmio, &dataChunk, &riffChunk, MMIO_FINDCHUNK);
	if (mmRes != MMSYSERR_NOERROR) {
		mmioClose(hMmio, 0);
		return false;
	}
	*pwaveData = new char[dataChunk.cksize];
	size = mmioRead(hMmio, (HPSTR)*pwaveData, dataChunk.cksize);
	if (size != dataChunk.cksize) {
		delete[] * pwaveData;
		return false;
	}
	*dataSize = size;

	// �n���h���N���[�Y
	mmioClose(hMmio, 0);

	return true;
}

HRESULT SoundFileManager::LoadSound(TCHAR* filePath)
{
	LPDIRECTSOUNDBUFFER8 pDSBuffer = NULL;
	// Wave�t�@�C���I�[�v��
	WAVEFORMATEX wFmt;
	char *pWaveData = 0;
	DWORD waveSize = 0;

	if (!OpenWave((filePath), &wFmt, &pWaveData, &waveSize))
	{
		return E_FAIL;
	}

	DSBUFFERDESC DSBufferDesc;
	DSBufferDesc.dwSize = sizeof(DSBUFFERDESC);
	DSBufferDesc.dwFlags = 0;
	DSBufferDesc.dwBufferBytes = waveSize;
	DSBufferDesc.dwReserved = 0;
	DSBufferDesc.lpwfxFormat = &wFmt;
	DSBufferDesc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer *ptmpBuf = 0;
	m_pDSound8->CreateSoundBuffer(&DSBufferDesc, &ptmpBuf, NULL);
	ptmpBuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)&pDSBuffer);

	ptmpBuf->Release();
	if (pDSBuffer == NULL)
	{
		m_pDSound8->Release();
		return E_FAIL;
	}


	// �Z�J���_���o�b�t�@��Wave�f�[�^��������
	//�����f�[�^
	LPVOID lpvWrite = 0;
	//�����f�[�^�̑傫��
	DWORD dwLength = 0;
	if (DS_OK == pDSBuffer->Lock(0, 0, &lpvWrite, &dwLength, NULL, NULL, DSBLOCK_ENTIREBUFFER))
	{
		memcpy(lpvWrite, pWaveData, dwLength);
		pDSBuffer->Unlock(lpvWrite, dwLength, NULL, 0);
	}

	delete[] pWaveData; // �����͂�������Ȃ�


	m_soundMap[filePath] = pDSBuffer;

	return S_OK;
}

// ���y���Đ�����֐�
void SoundFileManager::SoundPlayer(TCHAR* filePath, SOUND_MODE sMode)
{
	switch (sMode)
	{
	case Play:
		m_soundMap[filePath]->Play(0, 0, 0);
		break;
	case PlayLoop:
		m_soundMap[filePath]->Play(0, 0, DSBPLAY_LOOPING);
		break;
	case Stop:
		m_soundMap[filePath]->Stop();
		break;
	case Reset:
		m_soundMap[filePath]->SetCurrentPosition(0);
		break;
	case Stop_Reset:
		m_soundMap[filePath]->Stop();
		m_soundMap[filePath]->SetCurrentPosition(0);
		break;
	case Reset_Play:
		m_soundMap[filePath]->SetCurrentPosition(0);
		m_soundMap[filePath]->Play(0, 0, 0);
		break;

	}
}