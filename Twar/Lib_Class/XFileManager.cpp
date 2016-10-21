/**
* @file	XFileManager.cpp
* @brief X�t�@�C�����Ǘ�����N���X
* @author haga
*/
#include "XFile.h"
#include "XFileManager.h"


XFileManager::XFileManager()
{
}


XFileManager::~XFileManager()
{
	ReleaseALL();
}

// X�t�@�C����ǂݍ��ފ֐�
void XFileManager::Load(int key, LPCTSTR pFilePath)
{
	XFile xFile;
	m_xFile[key] = xFile;
	m_xFile[key].LoadXFile(pFilePath);

}

// X�t�@�C����`�悷��֐�
void XFileManager::Draw(int key)
{
	m_xFile[key].DrawX();
}

// ����֐�
void XFileManager::Release(int key)
{
	m_xFile[key].Release();
	m_xFile.erase(key);
}

// �Ǘ����Ă���t�@�C�������ׂĉ������֐�
void XFileManager::ReleaseALL()
{
	for (auto itr = m_xFile.begin(); itr != m_xFile.end();itr++)
	{
		//itr->second.Release();
	}
	m_xFile.clear();
}