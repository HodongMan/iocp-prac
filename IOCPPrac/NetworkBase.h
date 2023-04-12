#pragma once


#define NETWORK_IO_BUFFER_LENGTH					4096
#define MAX_SEND_WSABUF								32
#define CLIENT_CONNSTARTID							200000
#define SERVER_LINKER_START_ID						100000
#define LINKER_DESTROY_WAIT_TIME					15000
#define THREAD_WAIT_OBJECT_TIME						2500


enum class LinkerCloseReason
{
	CLOSE_FROM_APP,
	CLOSE_FROM_CLIENT,
	CLOSE_FROM_PROGRAM_ERROR,
	CLOSE_FROM_CLIENT_ERROR,
};


struct AddressInfo
{
	std::string										_stringAddress;
	std::string										_stringIP;
	int												_farPort;

	AddressInfo( void ) noexcept;
	AddressInfo( const AddressInfo& rhs ) noexcept;

	AddressInfo&									operator=( const AddressInfo& rhs ) noexcept;
	//AddressInfo&									operator=( const AddressInfo&& rhs ) noexcept;

	bool											isActive( void ) const noexcept;
	void											initialize( void ) noexcept;

};


class Buffer;
class IOCPServer;
class ClientConnection;
class Thread;


class NetworkBase
{
public:
	NetworkBase( void ) noexcept;
	~NetworkBase( void ) noexcept;

public:


	static NetworkBase*								getInstance( void ) noexcept;
	void											clearAllServerClient( void ) noexcept;

	bool											startSocket( void ) noexcept;
	bool											cleanUpSocket( void ) noexcept;


	void											initializeNetworkObjectPool( const int clientConnectionIncrementSize, const int serverLinkerIncrementSize, const int linkerSendIncrementSize ) noexcept;
	void											cleanUpNetworkObjectPool( void ) noexcept;

	USHORT											createIOCPServer( USHORT port, Thread* thread ) noexcept;
	void											closeIOCPServer( USHORT port ) noexcept;

	bool											getALinkerAddress( USHORT port, DWORD linkerID, AddressInfo& addressInfo ) noexcept;

	void											closeALinker( USHORT port, DWORD dwID, BYTE byReason, bool tellApp = true ) noexcept;
	void											sendNetworkMessage( USHORT port, DWORD dwID, const char* message, const int messageLength ) noexcept;

	DWORD											createClientConnection( const char* farAddress, USHORT port, Thread* thread ) noexcept;
	void											closeClientConnection( DWORD id ) noexcept;

	int												sendMessage( DWORD id, Buffer* buffer ) noexcept;
	int												sendMessage( DWORD id, const char* sendMessage, const int messageLength ) noexcept;

private:
	std::unordered_map<DWORD, IOCPServer*>			_mapIOCPServer;
	std::unordered_map<DWORD, ClientConnection*>	_mapClientConnection;
};