#include "pch.h"

#include "MemoryPool.h"



MemoryChunk::MemoryChunk( void ) noexcept
	: _memoryAddress{ 0 }
	, _memoryLength{ 0 }
	, _pre{ nullptr }
	, _next{ nullptr }
{
	initialize();
}

void MemoryChunk::initialize( void ) noexcept
{
	_memoryAddress								= 0;
	_memoryLength								= 0;
	_pre										= nullptr;
	_next										= nullptr;
}

void MemoryChunk::initializeMemory( void ) noexcept
{
	char* memory								= reinterpret_cast<char*>( _memoryAddress );
	::memset( memory, 0, _memoryLength );
}
