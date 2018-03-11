#pragma once

#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>
#include "GameObject.h"

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GameObjectFactory
{
	std::map<std::string, BaseCreator*> m_creators;

	GameObjectFactory(){}
	~GameObjectFactory(){}

	static GameObjectFactory* s_pInstance;

public:

	static GameObjectFactory* instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new GameObjectFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool registerType(std::string typeID, BaseCreator* pCreator);

	GameObject* create(std::string typeID);
};

#endif //defined!(__GameObjectFactory__)