#include "pch.h"

#include "Buffer.h"


enum class BuffType
{
	USER,
	NET_SERVER_ACCEPT_MESSAGE,
	NET_SERVER_NORMAL_MESSAGE,
	NET_SERVER_843_MESSAGE,
	NET_SERVER_HTTP_REQUEST_MESSAGE,
	NET_SERVER_CLOSE_LINKER_MESSAGE,

	NET_CLIENT_NORMAL_MESSAGE,
	NET_CLIENT_HTTP_MESSAGE,
	NET_CLIENT_DISCONNECTED,

	APP_DISPATCH_MESSAGE,
};