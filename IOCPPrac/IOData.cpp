#include "pch.h"

#include "IOData.h"

IOData::IOData( void ) noexcept
{
	ZeroMemory( &_overlapped, sizeof( OVERLAPPED ) );
	_opType												= OpType::IO_ACCEPT;
	_iocpLinker											= nullptr;
}

ConnectionIOData::ConnectionIOData( void ) noexcept
	: IOData()
{
	ZeroMemory( _dataBuffer, BUFFER_LENGTH );
}

RecvIOData::RecvIOData( void ) noexcept
	: IOData()
{
	_opType												= OpType::IO_READ;
	ZeroMemory( _dataBuffer, NETWORK_IO_BUFFER_LENGTH );
	_wsaBuffer.buf										= _dataBuffer;
	_wsaBuffer.len										= NETWORK_IO_BUFFER_LENGTH;
}

SendIOData::SendIOData( void ) noexcept
	: IOData()
{

}

void SendIOData::initializeWSABuffer( void ) noexcept
{
	for ( int ii = 0; ii < MAX_SEND_WSABUF; ++ii )
	{
		_wsaBuffer->buf									= nullptr;
		_wsaBuffer->len									= 0;
	}
}
