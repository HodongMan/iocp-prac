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
	MemoryPool( void ) noexcept;
	~MemoryPool( void ) noexcept;

public:

	MemoryPool*									getInstance( void ) noexcept;


	bool										startPool( const ULONG64 ullIncrementSize = 67108864 ) noexcept;
	char*										getMemory( ULONG64 ullSize ) noexcept;
	bool										backMemory( char** memory ) noexcept;

	ULONG64										getAllSize( void ) const noexcept;
	ULONG64										getNoUseSize( void ) const noexcept;
	void										clear( void ) noexcept;

private:
	bool										addMemoryPool( void ) noexcept;
	ULONG64										alignNumForMinSize( ULONG64& ullIn ) noexcept;

	char*										realPopMemory( ULONG64 ullSize ) noexcept;
	void										insertChunkToFree( MemoryChunk* insertChunk ) noexcept;
	void										removeFreeChunk( MemoryChunk* removeChunk ) noexcept;

private:

	std::vector<char*>							_vectorPool;
	MemoryChunk*								_freeChunkHead;
	MemoryChunk*								_freeChunkTail;
	std::unordered_map<ULONG64, MemoryChunk*>	_chunkMap;
	ObjectPool<MemoryChunk>						_poolChunk;

	ULONG64										_incrementSize;

	Locker										_locker;
};