#pragma once

#include "ObjectPool.h"
#include "ClientConnection.h"
#include "IOCPLinker.h"
#include "Buffer.h"

class NetworkObjectPool
{
private:
	NetworkObjectPool( void ) noexcept;
	~NetworkObjectPool( void ) noexcept;

public:

	static NetworkObjectPool*				getInstance( void ) noexcept;

	void									initialize( const int clientConnectionIncrementSize, const int serverLinkerIncrementSize, const int linkerSendIncrementSize ) noexcept;
	void									cleanup( void ) noexcept;

	ClientConnection*						takeClientConnection( void ) noexcept;
	void									backClientConnection( ClientConnection* client ) noexcept;
	
	IOCPLinker*								takeServerLinker( void ) noexcept;
	void									backServerLinker( IOCPLinker* linker ) noexcept;

	LinkerSend*								takeLinkerSend( const char* message, const int messageLength ) noexcept;
	void									backLinkerSend( LinkerSend* linkerSend ) noexcept;

private:
	ObjectPool<ClientConnection>			_clientConnectionPool;
	ObjectPool<IOCPLinker>					_serverLinkerPooi;
	ObjectPool<LinkerSend>					_linkerSendPool;

};