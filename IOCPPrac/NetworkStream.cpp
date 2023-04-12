#include "pch.h"

#include "NetworkStream.h"

NetworkStream::NetworkStream(void) noexcept
{
}

NetworkStream::~NetworkStream(void) noexcept
{
}

bool NetworkStream::initialize(INetworkStreamObject* object) noexcept
{
	return false;
}

void NetworkStream::final(void) noexcept
{
}

bool NetworkStream::dealWithSocketMessage(const char* inBuf, DWORD dwRecv) noexcept
{
	return false;
}

bool NetworkStream::checkSafeSandBox(void) noexcept
{
	return false;
}

bool NetworkStream::loopBuffer(void) noexcept
{
	return false;
}

void NetworkStream::freeBuffer(void) noexcept
{
}

char* NetworkStream::getMemory(const int allocSize) noexcept
{
	return nullptr;
}

int NetworkStream::alignNumForMinSize(int& in) noexcept
{
	return 0;
}
