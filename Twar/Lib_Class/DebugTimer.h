/**
* @file   DebugTimer.h
* @brief   �f�o�b�N�ׂ̈̎��Ԃ��v������N���X��h
* @author haga
*/
#ifndef DEBUG_TIMER_H
#define DEBUG_TIMER_H

#include <iostream>
#include <vector>
#include "DebugFont.h"
using namespace std;


/**
* �f�o�b�N�p�^�C�}�[�N���X<br>
* ���Ԏ擾�ɂ�timeGetTime���g�p�B���̎��Ԏ擾�֐�����������
*/
class DebugTimer
{
private:
	/**�v�����ԊǗ��p�\����*/
	struct DebugTime
	{
		std::string  timeName;					//!< �v�����Ă��鎞��
		DWORD		 time;						//!< �v������
		bool		 measureFlag;				//!< �v�����Ă��邩�̃t���O
	};

	std::vector<DebugTime>	m_debugTime;		//!< �v�����Ԃ��Ǘ�����ϐ�
	
public:
	/**�R���X�g���N�^*/
	DebugTimer();

	/**�f�X�g���N�^*/
	~DebugTimer();

	/**
	* �v�����鎞�Ԃ��Z�b�g����.
	* @param[in] timeName �v�����鎞�Ԃ̖��O
	*/
	void SetDebugTimer(std::string  timeName);

	/**
	* ���Ԍv�����͂��߂�
	* @param[in] timeName �v�����͂��߂鎞�Ԃ̖��O
	*/
	void StartTimer(std::string  timeName);

	/**
	* ���Ԍv���I��
	* @param[in] timeName �v�����I���鎞�Ԃ̖��O
	*/
	void EndTimer(std::string  timeName);

	/**
	* ���Ԍv�����Čv������
	* @param[in] timeName �Čv�����������Ԃ̖��O
	*/
	void ReStart(std::string  timeName);

	/**
	* 1�̌v�����ʂ����`�悷��
	* @param[in] timeName ���ʂ�\���������v�����Ԃ̖��O
	* @param[in] pos �\��������W
	*/
	void DrawResult(std::string  timeName, D3DXVECTOR2 pos);

	/**
	* ���v���ʂ����`�悷��
	* @param[in] pos �\��������W
	*/
	void DrawSumResult(D3DXVECTOR2 pos);

	/**
	* ���ׂĂ̌v�����ʂƍ��v���ʂ�`�悷��
	* @param[in] pos �\���J�n���W
	*/
	void DrawAllResult(D3DXVECTOR2 pos);
};


#endif // DEBUG_TIMER_H
