/**
* @file XFileManager.h
* @brief X�t�@�C�����ꊇ�ň����N���X��h
* @haga
*/
#ifndef XFILE_MANAGER_H
#define XFILE_MANAGER_H

#include <map>
using namespace std;

class XFile;

class XFileManager
{
private:
	std::map<int,XFile>  m_xFile;	//!< X�t�@�C�����i�[����ϐ�

public:
	/**�R���X�g���N�^*/
	XFileManager();
	/**�f�X�g���N�^*/
	~XFileManager();

	/**
	* X�t�@�C�������[�h����֐�
	* @param[in] key �o�^����L�[
	* @param[in] pFilePath �t�@�C����
	*/
	void Load(int key,LPCTSTR pFilePath);

	/**
	* X�t�@�C����`�悷��֐�
	* @param[in] key �o�^�����L�[
	*/
	void Draw(int key);

	/**
	* X�t�@�C�����������֐�
	* @param[in] key �o�^�����L�[
	*/
	void Release(int key);

	/**
	* �}�l�[�W���[���Ǘ����Ă��邷�ׂẴt�@�C�����������֐�
	*/
	void ReleaseALL();
};

#endif	// XFILE_MANAGER_H

