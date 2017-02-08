﻿//==================================================================================================================================//
//!< @file		BattleDataManager.cpp 
//!< @brief		BattleDataManagerクラス実装
//!< @author	haga
//==================================================================================================================================//

//--------------------------------------------------------------------------------------------------------------//
//Includes
//--------------------------------------------------------------------------------------------------------------//

#include "BattleDataManager.h"

//--------------------------------------------------------------------------------------------------------------//
//Public functions
//--------------------------------------------------------------------------------------------------------------//

void BattleDataManager::Initialize()
{
	m_PlayerHp				= 0;
	m_PlayerSpeed			= 0.0f;
	m_MonsterHp				= 0;
	m_MonsterHpMax			= 0;
	m_PlayerAttackedDamage	= 0;
	m_BattleResult			= false;
}

//==================================================================================================================================//
//END OF FILE
//==================================================================================================================================//
