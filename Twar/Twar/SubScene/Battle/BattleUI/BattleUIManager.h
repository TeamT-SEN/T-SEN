﻿/**
* @file BattleUIManager.h
* @brief BattleUIManagerクラスヘッダ
* @author ichikawa
*/

#ifndef BUTTLE_UI_MANAGER_H
#define BUTTLE_UI_MANAGER_H

#include "vector"

class UI;

class BattleUIManager
{
public:
	BattleUIManager();
	~BattleUIManager();
	void Control();
	void Draw();
	

private:
	std::vector<UI*>	m_pUI;
	void InitData();
};

#endif	// BUTTLE_UI_MANAGER_H
