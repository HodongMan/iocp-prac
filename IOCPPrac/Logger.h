#pragma once


#include "Locker.h"


#define WM_APPLOGINFO WM_USER + 11233
#define APP_LOG_MAX_LENGTH 4096


class Logger
{
public:
	Logger( void ) noexcept;
	~Logger( void ) noexcept;

	static Logger*				getInstance( void ) noexcept;

private:

	std::string					_strPrefix;
	std::string					_strLogDirectory;
	std::string					_strLogFileName;
	std::string					_strLogContent;


	int							_currentLogFileId;
	int							_currentLogCount;

	int							_currentYear;
	int							_currentMonth;
	int							_currentDay;


	bool						_isLogWrite;

	char						_tempBuf[ APP_LOG_MAX_LENGTH ];

	HWND						_hWndInfo;

	Locker						_locker;
};

