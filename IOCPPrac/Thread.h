#pragma once


#include "Locker.h"


class Buffer;



class Thread
{
public:
	Thread( void ) noexcept;
	virtual ~Thread( void ) noexcept;

	bool							start( void ) noexcept;
	void							stop( void ) noexcept;

	static unsigned WINAPI			myThreadProcess( void* param ) noexcept;
	DWORD							realThreadProcess( void ) noexcept;

	void							setFrameTimeByValue( const int frameMinTime, const int frameWarnTime, const int frameAbortTime ) noexcept;
	void							pushMessageToList( Buffer* messageBuffer, bool isInHead = false ) noexcept;

	int								getMessageListSize( void ) const noexcept;

public:

	virtual void					processMessage( Buffer* messageBuffer ) noexcept = 0;
	virtual void					processLogic( void ) noexcept = 0;

private:

	unsigned int					_threadId;
	HANDLE							_thread;
	bool							_isRunning;

	int								_frameMinTime;
	int								_frameWarnTime;
	int								_frameAbortTime;

private:
	std::vector<Buffer*>			_messageList;
	Locker							_locker;
};