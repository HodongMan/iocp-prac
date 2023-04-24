#pragma once


#include "NetworkBase.h"

#define IONull				0
#define IORead				101
#define IOWrite				102
#define IOAccept			103
#define IOClose				104


enum class OpType
{
	IO_NULL					= 0,
	IO_READ					= 101,
	IO_WRITE				= 102,
	IO_ACCEPT				= 103,
	IO_CLOSE				= 104,
};



struct IOData
{
	OVERLAPPED				_overlapped;
	OpType					_opType;
	void*					_iocpLinker;

	IOData( void ) noexcept;
};


struct ConnectionIOData : public IOData
{
	enum
	{
		BUFFER_LENGTH		= ( sizeof( SOCKADDR_IN ) + 16 ) * 2,
	};

	char					_dataBuffer[ BUFFER_LENGTH ];

	ConnectionIOData( void ) noexcept;
};


struct RecvIOData : public IOData
{
	char					_dataBuffer[ NETWORK_IO_BUFFER_LENGTH ];
	WSABUF					_wsaBuffer;

	RecvIOData( void ) noexcept;
};

struct SendIOData : public IOData
{
	char					_dataBuffer[ NETWORK_IO_BUFFER_LENGTH ];
	WSABUF					_wsaBuffer[ MAX_SEND_WSABUF ];
	u_int					_validWsaBufferCount;

	SendIOData( void ) noexcept;

	void					initializeWSABuffer( void ) noexcept;
};