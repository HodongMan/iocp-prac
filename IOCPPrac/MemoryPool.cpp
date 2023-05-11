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

MemoryPool::MemoryPool(  void ) noexcept
{
	_vectorPool.clear();
	_freeChunkHead								= nullptr;
	_freeChunkTail								= nullptr;
	_chunkMap.clear();
	_poolChunk.clear();

	_incrementSize								= 0;
}

MemoryPool::~MemoryPool( void ) noexcept
{
	clear();
}

MemoryPool* MemoryPool::getInstance( void ) noexcept
{
	static MemoryPool instance;
	return &instance;
}

bool MemoryPool::startPool( const ULONG64 ullIncrementSize ) noexcept
{
	AutoLocker autoLocker( _locker );
	clear();

	ULONG64 incnrementSize						= ullIncrementSize;

	if ( MEMORYPOOL_MAXINCSIZE < incnrementSize )
	{
		//Logger::getInstance()
		incnrementSize							= MEMORYPOOL_MAXINCSIZE;
	}
	else if ( incnrementSize < MEMORYPOOL_MININCSIZE)
	{
		//Logger::getInstance()
		incnrementSize							= MEMORYPOOL_MININCSIZE;
	}

	alignNumForMinSize( incnrementSize );

	_incrementSize								= incnrementSize;
	_poolChunk.startPool();


	return addMemoryPool();
}

char* MemoryPool::getMemory( ULONG64 ullSize ) noexcept
{
	alignNumForMinSize( ullSize );

	if ( _incrementSize <= ullSize )
	{
		//Logger::getInstance()
		return nullptr;
	}

	AutoLocker locker( _locker );

	char* result								= realPopMemory( ullSize );
	if ( nullptr == result )
	{
		//Logger::getInstance()
		return result;
	}

	ULONG64	ullCurrentSize						= getAllSize();
	if ( MEMORYPOOL_MAXMEMORYSIZE < ( ullCurrentSize + _incrementSize ) )
	{
		//Logger::getInstance()
		return result;
	}

	if ( false == addMemoryPool() )
	{
		//Logger::getInstance()
		return result;
	}

	result										= realPopMemory( ullSize );
	if ( nullptr == result )
	{
		//Logger::getInstance()
		return result;
	}

	return result;
}

bool MemoryPool::backMemory( char** memory ) noexcept
{
	if ( nullptr == *( memory )  )
	{
		//Logger::getInstance()
		return false;
	}

	AutoLocker locker( _locker );

	ULONG64 ullLeft								= reinterpret_cast<ULONG64>( *memory );
	auto iter									= _chunkMap.find( ullLeft );
	if ( iter == _chunkMap.end() )
	{
		//Logger::getInstance()
		return false;
	}

	MemoryChunk* chunk							= iter->second;
	chunk->initializeMemory();

	insertChunkToFree( chunk );

	_chunkMap.erase( iter );
	(* memory )									= nullptr;

	return true;
}

ULONG64 MemoryPool::getAllSize( void ) const noexcept
{
	return _incrementSize * _vectorPool.size();
}

ULONG64 MemoryPool::getNoUseSize(void) const noexcept
{
	return ULONG64();
}

void MemoryPool::clear(void) noexcept
{
}

bool MemoryPool::addMemoryPool(void) noexcept
{
	return false;
}

ULONG64 MemoryPool::alignNumForMinSize(ULONG64& ullIn) noexcept
{
	return ULONG64();
}

char* MemoryPool::realPopMemory(ULONG64 ullSize) noexcept
{
	return nullptr;
}

void MemoryPool::insertChunkToFree(MemoryChunk* insertChunk) noexcept
{
}

void MemoryPool::removeFreeChunk(MemoryChunk* removeChunk) noexcept
{
}
