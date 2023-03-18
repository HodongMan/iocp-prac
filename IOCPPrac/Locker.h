#pragma once


class Locker
{
public:
	Locker( void ) noexcept;
	~Locker( void ) noexcept;

	void						lock( void ) noexcept;
	void						unlock( void ) noexcept;

private:
	CRITICAL_SECTION			_locker;
};


class AutoLocker
{
public:
	AutoLocker( Locker& locker ) noexcept;
	~AutoLocker( void ) noexcept;
private:
	Locker*						_locker;
};


class RWLocker
{
public:
	RWLocker( void ) noexcept;
	~RWLocker( void ) noexcept;

	void						readLock( void ) noexcept;
	void						readUnlock( void ) noexcept;

	void						writeLock( void ) noexcept;
	void						writeUnlock( void ) noexcept;
private:
	SRWLOCK						_locker;
};