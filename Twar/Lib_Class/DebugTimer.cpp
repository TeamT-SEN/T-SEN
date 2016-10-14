/**
* @file	DebugTimer.cpp
* @brief �f�o�b�N�ׂ̈̎��Ԃ��v������N���X��cpp
* @author haga
*/
#include <windows.h>
#include <string>
#include "DebugTimer.h"

// �R���X�g���N�^
DebugTimer::DebugTimer()
{
}

// �f�X�g���N�^
DebugTimer::~DebugTimer()
{
	m_debugTime.clear();
}

// �v�����鎞�Ԃ��Z�b�g����
void DebugTimer::SetDebugTimer(std::string  timeName)
{
	DebugTime temp;
	temp.timeName = timeName;
	temp.time = 0;
	temp.measureFlag = true;
	m_debugTime.push_back(temp);
}

// ���Ԍv���J�n
void DebugTimer::StartTimer(std::string  timeName)
{
	for (auto itr = m_debugTime.begin(); itr != m_debugTime.end(); itr++)
	{
		if (itr->timeName == timeName)
		{
			if (itr->measureFlag == true)
			{
				itr->time = timeGetTime();
			}
			break;
		}
	}
}

// ���Ԍv���I��
void DebugTimer::EndTimer(std::string  timeName)
{
	DWORD currentTime = timeGetTime();
	for (auto itr = m_debugTime.begin(); itr != m_debugTime.end();itr++)
	{
		if (itr->timeName == timeName && itr->measureFlag == true)
		{
			currentTime -= itr->time;
			itr->time = currentTime;
			itr->measureFlag = false;
			break;
		}
	}
}

// ���Ԍv���Čv��
void DebugTimer::ReStart(std::string  timeName)
{
	for (auto itr = m_debugTime.begin(); itr != m_debugTime.end(); itr++)
	{
		if (itr->timeName == timeName)
		{
			if (itr->measureFlag == false)
			{
				itr->time = timeGetTime();
				itr->measureFlag = true;
			}
			break;
		}
	}
}

// �v�����ʕ\��
void DebugTimer::DrawResult(std::string  timeName, D3DXVECTOR2 pos)
{
	for (auto itr = m_debugTime.begin(); itr != m_debugTime.end(); itr++)
	{
		if (itr->timeName == timeName)
		{
			if (itr->measureFlag == false)
			{
				std::string  Str =
					timeName +":"+ std::to_string(itr->time) + "�~���b" +"\n";
				Font timeDisp;
				timeDisp.Draw(Str.c_str(), pos);
			}
			break;
		}
	}
}


// ���Ԃ̑����v��\������
void DebugTimer::DrawSumResult(D3DXVECTOR2 pos)
{
	DWORD TotalTime = 0;				// ���Ԃ����v���邽�߂̊�

	for (auto i: m_debugTime)
	{
		if (i.measureFlag == false)		// �v�����I����Ă�������Z����
		{
			TotalTime += i.time;
		}
	}

	std::string  Str =
		"���v���Ԃ�:" +  std::to_string(TotalTime) + "�~���b" + "\n";
	Font timeDisp;
	timeDisp.Draw(Str.c_str(), pos);
}


// ���ׂĂ̌v�����Ԃƍ��v���Ԃ�\������
void DebugTimer::DrawAllResult(D3DXVECTOR2 pos)
{
	Font timeDisp;					// �\���p�t�H���g
	int fontHeight = timeDisp.GetFontHeight();	// 1�����̍���
	int dispCount = 0;							// �\����

	for (auto i : m_debugTime)
	{
		if (i.measureFlag == false)
		{
			pos.y += (fontHeight * dispCount);				// �����̍��������W�����炷
			std::string  Str =
				i.timeName + ":" + std::to_string(i.time) + "�~���b" + "\n";
			timeDisp.Draw(Str.c_str(), pos);
			dispCount++;
			
		}
	}

	// 1�ł����ʕ\�����Ă���Ȃ瑍���v��\������
	if (dispCount != 0)
	{
		pos.y += fontHeight;
		DrawSumResult(pos);
	}
	
}