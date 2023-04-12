#pragma once


#include "Locker.h"
#include "Logger.h"


template< typename T >
class ObjectPool
{
public:
	ObjectPool( void ) noexcept;
	~ObjectPool( void ) noexcept;


	bool						startPool( const int incrementSize = 1024 ) noexcept;
	T*							takeObject( void ) noexcept;
	void						backObject( T* object ) noexcept;

	int							getAllSize( void ) const noexcept;
	int							getNoUseSize( void ) const noexcept;

	void						clear( void ) noexcept;

private:
	bool						addPool( void ) noexcept;

private:

	int							_incrementSize;
	std::vector<T*>				_vectorPool;
	std::vector<T*>				_vectorUse;

	Locker						_locker;
};

template<typename T>
inline ObjectPool<T>::ObjectPool( void ) noexcept
{
	_vectorPool.clear();
	_vectorUse.clear();

	_incrementSize				= 0;
}

template<typename T>
inline ObjectPool<T>::~ObjectPool( void ) noexcept
{
	clear();
}

template<typename T>
inline bool ObjectPool<T>::startPool( const int incrementSize ) noexcept
{
	if ( incrementSize < 1 )
	{
		return false;
	}

	AutoLocker autoLocker( _locker );

	clear();

	_incrementSize				= incrementSize;

	return addPool();

}

template<typename T>
inline T* ObjectPool<T>::takeObject( void ) noexcept
{
	AutoLocker autoLocker( _locker );

	T* returnValue				= nullptr;

	if ( true == _vectorUse.empty() )
	{
		if ( ( false == addPool() ) || ( true == _vectorUse.empty() ) )
		{
			return returnValue;
		}
	}

	returnValue					= _vectorUse.back();
	_vectorUse.pop_back();


	return returnValue;
}

template<typename T>
inline void ObjectPool<T>::backObject( T* object ) noexcept
{
	AutoLocker autoLocker( _locker );

	_vectorUse.push_back( object );
}

template<typename T>
inline int ObjectPool<T>::getAllSize( void ) const noexcept
{
	return _incrementSize * _vectorPool.size();
}

template<typename T>
inline int ObjectPool<T>::getNoUseSize( void ) const noexcept
{
	return _vectorUse.size();
}

template<typename T>
inline void ObjectPool<T>::clear( void ) noexcept
{
	AutoLocker autoLocker( _locker );

	T* tempValue				= nullptr;

	for ( int ii = 0; ii < _vectorPool.size(); ++ii )
	{
		tempValue				= _vectorPool[ ii ];
		if ( nullptr != tempValue )
		{
			delete[] tempValue;
			tempValue			= nullptr;	
		}
	}

	_vectorPool.clear();
	_vectorUse.clear();

	_incrementSize				= 0;
}

template<typename T>
inline bool ObjectPool<T>::addPool( void ) noexcept
{
	// nolock function
	// check external lock

	T* newPool					= new T[ _incrementSize ];
	if ( nullptr == newPool )
	{
		// 에러 로그
		//Logger::getInstance()->info();
		return false;
	}

	_vectorPool.push_back( newPool );

	for ( int ii = 0; ii < _incrementSize; ++ii )
	{
		_vectorUse.push_back( &( newPool[ ii ] ) );
	}

	return true;
}
