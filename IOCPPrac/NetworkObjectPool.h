#pragma once

#include "ObjectPool.h"
#include "ClientConnection.h"


class NetworkObjectPool
{
public:

private:
	ObjectPool<ClientConnection>			_clientConnectionPool;
	//ObjectPool<>

};