#include "pch.h"

#include "Thread.h"


Thread::Thread( void ) noexcept
	: _threadId{ 0 }
	, _thread{ INVALID_HANDLE_VALUE }
	, _isRunning{ false }
	, _frameMinTime{ 5 }
	, _frameWarnTime{ 1000 }
	, _frameAbortTime{ 30000 }
{

}

Thread::~Thread( void ) noexcept
{
	stop();
}

bool Thread::start( void ) noexcept
{
	if ( true == _isRunning )
	{
		return false;
	}

	_thread													= reinterpret_cast<HANDLE>( ::_beginthreadex( NULL, 0, Thread::myThreadProcess, this, 0, &_threadId ) );
	if ( INVALID_HANDLE_VALUE == _thread )
	{
		return false;
	}

	_isRunning												= true;
	//sleep( 25 );

	return true;
}

void Thread::stop( void ) noexcept
{
	if ( false == _isRunning )
	{
		return;
	}

	::WaitForSingleObject( _thread, 2500 );
	//::TerminateThread( _thread, 0 );
	//::CloseHandle( _thread );

	::_endthreadex( 0 );

	_thread													= INVALID_HANDLE_VALUE;
	_threadId												= 0;
	_isRunning												= false;
}

unsigned __stdcall Thread::myThreadProcess( void* param ) noexcept
{
	return 0;
}

DWORD Thread::realThreadProcess(void) noexcept
{
	return 0;
}

void Thread::setFrameTimeByValue(const int frameMinTime, const int frameWarnTime, const int frameAbortTime) noexcept
{
}

void Thread::pushMessageToList(Buffer* messageBuffer, bool isInHead) noexcept
{
}

int Thread::getMessageListSize(void) const noexcept
{
	return 0;
}
