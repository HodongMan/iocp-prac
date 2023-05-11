#pragma once


#include "Locker.h"
#include "INetworkStreamObject.h"
#include "NetworkStream.h"
#include "IOData.h"


class Thread;
class IOCPServer;


enum class ConnectStatus
{
	NOT_CONNECTED,
	CONNTECED,
};


class IOCPLinker : public INetworkStreamObject
{
public:

	IOCPLinker( void ) noexcept;
	virtual ~IOCPLinker( void ) noexcept;

	void									initializeLinker( IOCPServer* iocpServer, Thread* thread ) noexcept;
	void									finalize( void ) noexcept;
	void									clearLinkerSend( void ) noexcept;
	void									closeSocket( BYTE reason, bool isNotify = true ) noexcept;

public:

	virtual void							sendAppThreadMessage( BYTE byteMessageType, const char* message = nullptr, const int messageLength = 0 ) noexcept override;
	virtual void							onNormalMessage( const char* message, const int messageLength ) noexcept override;
	virtual void							on843Message( void ) noexcept override;
	virtual void							onErrorMessage( void ) noexcept override;
	virtual void							onHTTPRequest( const char* message, const int messageLength ) noexcept override;
	virtual void							printLogInfo( const char* info, bool isViewInWindow = false ) noexcept override;
	virtual DWORD							getID( void ) const noexcept override;
	virtual AddressInfo						getAddressInfo( void ) const noexcept override;

public:
	void									onIOCPAccept( void ) noexcept;
	void									onIOCPRead( const char* inBuf, DWORD dwRecv ) noexcept;
	void									onIOCPWrite( DWORD dwRecv ) noexcept;
	bool									iocpReadRequest( void ) noexcept;

	bool									sendNetworkMessage( const char* message, const int messageLength ) noexcept;
	void									realSendMessage( void ) noexcept;

	ConnectStatus							getConnectStatus( void ) const noexcept;
	void									setConnectStatus( const ConnectStatus connectStatus ) noexcept;

	ULONG64									getDestroyTick( void ) const noexcept;
	void									setDestroyTick( const ULONG64 ullTick ) noexcept;

public:

	SOCKET									_socket;

	ConnectionIOData						_connectionData;
	RecvIOData								_recvIOData;
	SendIOData								_sendIOData;

protected:

	static DWORD							_linkerID;

	ConnectStatus							_connectStatus;
	ULONG64									_ullDestroyTick;

	bool									_isSendFlag;

	std::vector<LinkerSend*>				_linkerSendMessage;

	Locker									_sendFlagLock;
	Locker									_messageLock;

	DWORD									_dwID;
	AddressInfo								_addressInfo;

	Thread*									_appThread;
	IOCPServer*								_iocpServer;
	NetworkStream							_networkStream;
};