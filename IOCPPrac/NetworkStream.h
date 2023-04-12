#pragma once


class INetworkStreamObject;
class Buffer;


class NetworkStream
{
public:
	NetworkStream( void ) noexcept;
	~NetworkStream( void ) noexcept;


	bool								initialize( INetworkStreamObject* object ) noexcept;
	void								final( void ) noexcept;


	bool								dealWithSocketMessage( const char* inBuf, DWORD dwRecv ) noexcept;
	bool								checkSafeSandBox( void ) noexcept;
	bool								loopBuffer( void ) noexcept;
	void								freeBuffer( void ) noexcept;


private:

	char*								getMemory( const int allocSize ) noexcept;
	int									alignNumForMinSize( int& in ) noexcept;

private:
	INetworkStreamObject*				_object;
	char*								_buffer;
	int									_bufferUse;
	int									_bufferRealSize;

	Buffer*								_dataBuffer;

	bool								_isSafeRequestChecked;
};