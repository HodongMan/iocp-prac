#pragma once


#include "Locker.h"


template< typename T >
class ObjectPool
{
public:
	ObjectPool( void ) noexcept;
	~ObjectPool( void ) noexcept;


	bool						startPool( const int incrementSize = 1024 ) noexcept;
	T*							takeObject( void ) noexcept;

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
inline ObjectPool<T>::ObjectPool(void) noexcept
{
}

template<typename T>
inline ObjectPool<T>::~ObjectPool(void) noexcept
{
}

template<typename T>
inline bool ObjectPool<T>::startPool(const int incrementSize) noexcept
{
	return false;
}

template<typename T>
inline T* ObjectPool<T>::takeObject(void) noexcept
{
	return nullptr;
}

template<typename T>
inline int ObjectPool<T>::getAllSize(void) const noexcept
{
	return 0;
}

template<typename T>
inline int ObjectPool<T>::getNoUseSize(void) const noexcept
{
	return 0;
}

template<typename T>
inline void ObjectPool<T>::clear(void) noexcept
{
}

template<typename T>
inline bool ObjectPool<T>::addPool(void) noexcept
{
	return false;
}
