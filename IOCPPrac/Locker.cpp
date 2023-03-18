#include "pch.h"

#include "Locker.h"


Locker::Locker( void ) noexcept
{
	if ( FALSE == ::InitializeCriticalSectionAndSpinCount(&_locker, 4500) )
	{
		::InitializeCriticalSection( &_locker );
	}
}

Locker::~Locker( void ) noexcept
{
	::DeleteCriticalSection( &_locker );
}

void Locker::lock( void ) noexcept
{
	::EnterCriticalSection( &_locker );
}

void Locker::unlock( void ) noexcept
{
	::LeaveCriticalSection( &_locker );
}

AutoLocker::AutoLocker( Locker& locker ) noexcept
	: _locker{ &locker }
{
	_locker->lock();
}

AutoLocker::~AutoLocker( void ) noexcept
{
	_locker->unlock();
}

RWLocker::RWLocker( void ) noexcept
{
	::InitializeSRWLock( &_locker );
}

RWLocker::~RWLocker( void ) noexcept
{

}

void RWLocker::readLock( void ) noexcept
{
	::AcquireSRWLockShared( &_locker );
}

void RWLocker::readUnlock( void ) noexcept
{
	::ReleaseSRWLockShared( &_locker );
}

void RWLocker::writeLock( void ) noexcept
{
	::AcquireSRWLockExclusive( &_locker );
}

void RWLocker::writeUnlock( void ) noexcept
{
	::ReleaseSRWLockExclusive( &_locker );
}
