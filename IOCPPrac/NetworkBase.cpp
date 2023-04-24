#include "pch.h"

#include "NetworkBase.h"


AddressInfo::AddressInfo( void ) noexcept
	: _farPort{ 0 }
{
	_stringAddress.clear();
	_stringIP.clear();
}

AddressInfo::AddressInfo( const AddressInfo& rhs ) noexcept
{
	_farPort												= rhs._farPort;
	_stringAddress											= rhs._stringAddress;
	_stringIP												= rhs._stringIP;
}

AddressInfo& AddressInfo::operator=( const AddressInfo& rhs ) noexcept
{
	_farPort												= rhs._farPort;
	_stringAddress											= rhs._stringAddress;
	_stringIP												= rhs._stringIP;

	return *this;
}

bool AddressInfo::isActive( void ) const noexcept
{
	return ( 7 < _stringAddress.length() );
}

void AddressInfo::initialize( void ) noexcept
{
	_farPort												= 0;
	_stringAddress.clear();
	_stringIP.clear();
}

NetworkBase::NetworkBase( void ) noexcept
{
	clearAllServerClient();
}

NetworkBase::~NetworkBase( void ) noexcept
{
	clearAllServerClient();
}

NetworkBase* NetworkBase::getInstance( void ) noexcept
{
	static NetworkBase base;
	return &base;
}

void NetworkBase::clearAllServerClient( void ) noexcept
{
	for ( auto iter = _mapIOCPServer.begin(); iter != _mapIOCPServer.end(); ++iter )
	{
		IOCPServer* server									= iter->second;
	}
}

bool NetworkBase::startSocket(void) noexcept
{
	return false;
}

bool NetworkBase::cleanUpSocket(void) noexcept
{
	return false;
}

void NetworkBase::initializeNetworkObjectPool(const int clientConnectionIncrementSize, const int serverLinkerIncrementSize, const int linkerSendIncrementSize) noexcept
{
}

void NetworkBase::cleanUpNetworkObjectPool(void) noexcept
{
}

USHORT NetworkBase::createIOCPServer(USHORT port, Thread* thread) noexcept
{
	return USHORT();
}

void NetworkBase::closeIOCPServer(USHORT port) noexcept
{
}

bool NetworkBase::getALinkerAddress(USHORT port, DWORD linkerID, AddressInfo& addressInfo) noexcept
{
	return false;
}

void NetworkBase::closeALinker(USHORT port, DWORD dwID, BYTE byReason, bool tellApp) noexcept
{
}

void NetworkBase::sendNetworkMessage(USHORT port, DWORD dwID, const char* message, const int messageLength) noexcept
{
}

DWORD NetworkBase::createClientConnection(const char* farAddress, USHORT port, Thread* thread) noexcept
{
	return 0;
}

void NetworkBase::closeClientConnection(DWORD id) noexcept
{
}

int NetworkBase::sendMessage(DWORD id, Buffer* buffer) noexcept
{
	return 0;
}

int NetworkBase::sendMessage(DWORD id, const char* sendMessage, const int messageLength) noexcept
{
	return 0;
}
