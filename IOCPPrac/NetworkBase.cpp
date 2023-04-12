#include "pch.h"

#include "NetworkBase.h"


AddressInfo::AddressInfo( void ) noexcept
	: _farPort{ 0 }
{
	_stringAddress.clear();
	_stringIP.clear();
}

AddressInfo::AddressInfo( const AddressInfo& rhs ) noexcept
{
	_farPort												= rhs._farPort;
	_stringAddress											= rhs._stringAddress;
	_stringIP												= rhs._stringIP;
}

AddressInfo& AddressInfo::operator=( const AddressInfo& rhs ) noexcept
{
	_farPort												= rhs._farPort;
	_stringAddress											= rhs._stringAddress;
	_stringIP												= rhs._stringIP;

	return *this;
}

bool AddressInfo::isActive( void ) const noexcept
{
	return ( 7 < _stringAddress.length() );
}

void AddressInfo::initialize( void ) noexcept
{
	_farPort												= 0;
	_stringAddress.clear();
	_stringIP.clear();
}
