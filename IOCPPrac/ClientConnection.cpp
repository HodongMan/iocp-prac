#include "pch.h"

#include "ClientConnection.h"

ClientConnection::ClientConnection(void) noexcept
{
}

ClientConnection::~ClientConnection(void) noexcept
{
}

void ClientConnection::onNormalMessage(const char* message, const int messageLength) noexcept
{
}

void ClientConnection::on843Message(void) noexcept
{
}

void ClientConnection::onErrorMessage(void) noexcept
{
}

void ClientConnection::onHTTPRequest(const char* message, const int messageLength) noexcept
{
}

void ClientConnection::printLogInfo(const char* info, bool isViewInWindow) noexcept
{
}

void ClientConnection::sendAppThreadMessage(BYTE byteMessageType, const char* message, const int messageLength) noexcept
{
}

DWORD ClientConnection::getID(void) const noexcept
{
	return 0;
}

AddressInfo ClientConnection::getAddressInfo(void) const noexcept
{
	return AddressInfo();
}

bool ClientConnection::connect(const char* farAddress, USHORT port, Thread* thread) noexcept
{
	return false;
}

bool ClientConnection::close(void) noexcept
{
	return false;
}

int ClientConnection::send(Buffer* buffer) noexcept
{
	return 0;
}

int ClientConnection::send(const char* buffer, const int bufferLength) noexcept
{
	return 0;
}

bool ClientConnection::isConnected(void) const noexcept
{
	return false;
}

DWORD __stdcall ClientConnection::SocketThreadProc(void* param) noexcept
{
	return 0;
}

void ClientConnection::onClose(void) noexcept
{
}

void ClientConnection::onRecv(void) noexcept
{
}

int ClientConnection::sendN(const char* buffer, const int bufferLength) noexcept
{
	return 0;
}
