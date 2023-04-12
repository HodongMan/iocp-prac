#pragma once


#include "ObjectPool.h"
#include "Locker.h"


#define MEMORYPOOL_MINCHUNKSIZE					32
#define MEMORYPOOL_MININCSIZE					1024
#define MEMORYPOOL_MAXINCSIZE					402653184
#define MEMORYPOOL_MAXMEMORYSIZE				4294967295


struct MemoryChunk
{
	ULONG										_memoryAddress;
	ULONG										_memoryLength;

	MemoryChunk*								_pre;
	MemoryChunk*								_next;

	MemoryChunk( void ) noexcept;

	void										initialize( void ) noexcept;
	void										initializeMemory( void ) noexcept;
};


class MemoryPool
{
public:

private:

	std::vector<char*>							_vectorPool;
	MemoryChunk*								_freeChunkHead;
	MemoryChunk*								_freeChunkTail;
	std::unordered_map<ULONG64, MemoryChunk*>	_chunkMap;
	ObjectPool<MemoryChunk>						_poolChunk;

	ULONG										_incrementSize;

	Locker										_locker;
};