#pragma once


enum class NetworkMessageID
{
	SYSTEM_MESSAGE_BEGIN			= 1,
	SYSTEM_MESSAGE_CLOSE			= 2,
	SYSTEM_MESSAGE_LUA_DEBUG		= 3,
	SYSTEM_MESSAGE_END				= 99,
};