/**
* @file		StateFactory.h
* @brief	Statefactory�N���X�w�b�_
* @author	haga
*/

#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include "State.h"

class StateFactory
{

public:
	static StateFactory& Instance()
	{
		static StateFactory factory;
		return factory;
	}

	~StateFactory();

	/**State�N���X���쐬����֐�*/
	State* Create(State::STATE_ID stateID);

private:

	StateFactory();


};

#endif	// STATE_FACTORY_H
