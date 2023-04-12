#pragma once

#include "INetworkStreamObject.h"
#include "NetworkStream.h"


class Buffer;
class Thread;

class ClientConnection : public INetworkStreamObject
{
public:
	ClientConnection( void ) noexcept;
	virtual ~ClientConnection( void ) noexcept;

public:

	virtual void								onNormalMessage( const char* message, const int messageLength ) noexcept override;
	virtual void								on843Message( void ) noexcept override;
	virtual void								onErrorMessage( void ) noexcept override;
	virtual void								onHTTPRequest( const char* message, const int messageLength ) noexcept override;
	virtual void								printLogInfo( const char* info, bool isViewInWindow = false ) noexcept override;
	virtual void								sendAppThreadMessage( BYTE byteMessageType, const char* message = nullptr, const int messageLength = 0 ) noexcept override;
	virtual DWORD								getID( void ) const noexcept override;
	virtual AddressInfo							getAddressInfo( void ) const noexcept override;

public:
	bool										connect( const char* farAddress, USHORT port, Thread* thread ) noexcept;
	bool										close( void ) noexcept;
	int											send( Buffer* buffer ) noexcept;
	int											send( const char* buffer, const int bufferLength ) noexcept;
	bool										isConnected( void ) const noexcept;

public:
	static DWORD WINAPI							SocketThreadProc( void* param ) noexcept;

protected:

	void										onClose( void ) noexcept;
	void										onRecv( void ) noexcept;

	int											sendN( const char* buffer, const int bufferLength ) noexcept;

protected:

	static DWORD								_connectID;

	SOCKET										_socket;

	bool										_isConnected;
	HANDLE										_socketThread;
	HANDLE										_socketEvent;

	DWORD										_id;
	AddressInfo									_addressInfo;

	Thread*										_thread;
	NetworkStream								_networkStream;
};

