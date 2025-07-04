#pragma once

class BaseManager
{
public:
	virtual ~BaseManager() = 0;
	virtual void Init() = 0;
	virtual void Link() = 0;
	virtual void Update() = 0;
};