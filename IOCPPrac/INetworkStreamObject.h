#pragma once

#include "NetworkBase.h"


struct LinkerSend
{
	char*				_message;
	int					_messageLength;

	LinkerSend( void ) noexcept;
};


class INetworkStreamObject
{
public:

	virtual void		onNormalMessage( const char* message, const int messageLength ) noexcept = 0;
	virtual void		on843Message( void ) noexcept = 0;
	virtual void		onErrorMessage( void ) noexcept = 0;
	virtual void		onHTTPRequest( const char* message, const int messageLength ) noexcept = 0;
	virtual void		printLogInfo( const char* info, bool isViewInWindow = false ) noexcept = 0;
	virtual void		sendAppThreadMessage( BYTE byteMessageType, const char* message = nullptr, const int messageLength = 0 ) noexcept = 0;
	virtual DWORD		getID( void ) const noexcept = 0;
	virtual AddressInfo getAddressInfo( void ) const noexcept = 0;

};