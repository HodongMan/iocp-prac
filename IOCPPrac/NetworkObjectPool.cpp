#include "pch.h"

#include "NetworkObjectPool.h"

NetworkObjectPool::NetworkObjectPool( void ) noexcept
{

}

NetworkObjectPool::~NetworkObjectPool( void ) noexcept
{
	cleanup();
}

NetworkObjectPool* NetworkObjectPool::getInstance( void ) noexcept
{
	static NetworkObjectPool pool;
	return &pool;
}

void NetworkObjectPool::initialize( const int clientConnectionIncrementSize, const int serverLinkerIncrementSize, const int linkerSendIncrementSize ) noexcept
{
	cleanup();

	_clientConnectionPool.startPool( clientConnectionIncrementSize );
	_serverLinkerPooi.startPool( serverLinkerIncrementSize );
	_linkerSendPool.startPool( linkerSendIncrementSize );
}

void NetworkObjectPool::cleanup( void ) noexcept
{
	_clientConnectionPool.clear();
	_serverLinkerPooi.clear();
	_linkerSendPool.clear();
}

ClientConnection* NetworkObjectPool::takeClientConnection( void ) noexcept
{
	ClientConnection* client						= _clientConnectionPool.takeObject();
	if ( nullptr == client )
	{
		//Logger::getInstance()->info();
	}

	return client;
}

void NetworkObjectPool::backClientConnection( ClientConnection* client ) noexcept
{
	_clientConnectionPool.backObject( client );
}

IOCPLinker* NetworkObjectPool::takeServerLinker(void) noexcept
{
	IOCPLinker* linker								= _serverLinkerPooi.takeObject();
	if ( nullptr == linker )
	{
		//Logger::getInstance()->info();
	}

	return linker;
}

void NetworkObjectPool::backServerLinker( IOCPLinker* linker  ) noexcept
{
	_serverLinkerPooi.backObject( linker );
}

LinkerSend* NetworkObjectPool::takeLinkerSend( const char* message, const int messageLength ) noexcept
{
	LinkerSend* linker								= _linkerSendPool.takeObject();
	if ( nullptr != linker )
	{
		linker->_messageLength						= messageLength;
		//linker->_message							= MemoryPool

	}
	else
	{
		//Logger::getInstance()->info();
	}

	return linker;
}

void NetworkObjectPool::backLinkerSend(LinkerSend* linkerSend) noexcept
{
}
