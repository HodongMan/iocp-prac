#include "pch.h"

#include "IOCPLinker.h"


DWORD IOCPLinker::_linkerID = SERVER_LINKER_START_ID;


IOCPLinker::IOCPLinker( void ) noexcept
{
	_addressInfo.initialize();

	_dwID											= IOCPLinker::_linkerID++;

	_connectionData._iocpLinker						= this;
	_recvIOData._iocpLinker							= this;
	_sendIOData._iocpLinker							= this;

	_isSendFlag										= true;

	_appThread										= nullptr;
	_iocpServer										= nullptr;
}

IOCPLinker::~IOCPLinker( void ) noexcept
{

}

void IOCPLinker::initializeLinker( IOCPServer* iocpServer, Thread* thread ) noexcept
{
	_networkStream.initialize( this );

	_socket											= INVALID_SOCKET;
	_addressInfo.initialize();
	_connectStatus									= ConnectStatus::NOT_CONNECTED;
	_ullDestroyTick									= 0;

	ZeroMemory( &_connectionData._overlapped, sizeof( OVERLAPPED ) );
	_connectionData._opType							= OpType::IO_ACCEPT;
	ZeroMemory( &_connectionData._dataBuffer, ConnectionIOData::BUFFER_LENGTH );

	ZeroMemory( &_recvIOData._overlapped, sizeof( OVERLAPPED ) );
	_recvIOData._opType								= OpType::IO_READ;

	ZeroMemory( &_recvIOData._dataBuffer, sizeof( NETWORK_IO_BUFFER_LENGTH ) );
	_recvIOData._wsaBuffer.buf						= _recvIOData._dataBuffer;
	_recvIOData._wsaBuffer.len						= NETWORK_IO_BUFFER_LENGTH;

	ZeroMemory( &_sendIOData._overlapped, sizeof( OVERLAPPED ) );
	_sendIOData._opType								= OpType::IO_WRITE;
	ZeroMemory( &_recvIOData._dataBuffer, sizeof( NETWORK_IO_BUFFER_LENGTH ) );

	_sendIOData.initializeWSABuffer();
	_sendIOData._validWsaBufferCount				= 0;

	clearLinkerSend();
}

void IOCPLinker::finalize( void ) noexcept
{
	_networkStream.final();
}

void IOCPLinker::clearLinkerSend( void ) noexcept
{
	for ( auto iter = _linkerSendMessage.begin(); iter != _linkerSendMessage.end(); ++iter )
	{
		LinkerSend* linkerSend						= *iter;
		//NetworkOb
	}
}

void IOCPLinker::closeSocket(BYTE reason, bool isNotify) noexcept
{
}

void IOCPLinker::sendAppThreadMessage(BYTE byteMessageType, const char* message, const int messageLength) noexcept
{
}

DWORD IOCPLinker::getID(void) const noexcept
{
	return 0;
}

AddressInfo IOCPLinker::getAddressInfo(void) const noexcept
{
	return AddressInfo();
}

void IOCPLinker::onIOCPAccept(void) noexcept
{
}

void IOCPLinker::onIOCPRead(const char* inBuf, DWORD dwRecv) noexcept
{
}

void IOCPLinker::onIOCPWrite(DWORD dwRecv) noexcept
{
}

bool IOCPLinker::iocpReadRequest(void) noexcept
{
	return false;
}

bool IOCPLinker::sendNetworkMessage(const char* message, const int messageLength) noexcept
{
	return false;
}

void IOCPLinker::realSendMessage(void) noexcept
{
}

ConnectStatus IOCPLinker::getConnectStatus(void) const noexcept
{
	return ConnectStatus();
}

void IOCPLinker::setConnectStatus(const ConnectStatus connectStatus) noexcept
{
}

ULONG64 IOCPLinker::getDestroyTick(void) const noexcept
{
	return ULONG64();
}

void IOCPLinker::setDestroyTick(const ULONG64 ullTick) noexcept
{
}

void IOCPLinker::onNormalMessage(const char* message, const int messageLength) noexcept
{
}

void IOCPLinker::on843Message(void) noexcept
{
}

void IOCPLinker::onErrorMessage(void) noexcept
{
}

void IOCPLinker::onHTTPRequest(const char* message, const int messageLength) noexcept
{
}

void IOCPLinker::printLogInfo(const char* info, bool isViewInWindow) noexcept
{
}
