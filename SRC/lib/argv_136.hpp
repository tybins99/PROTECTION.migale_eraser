// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_136.hpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains the object that permits
// @@ to mmap a given file on both win32 or Linux
// @@ OS.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_148
#define argv_148



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if defined (__WIN32_OS__) 
	#pragma warning(disable: 4786)
	#pragma warning(disable: 4503)
	#pragma warning(disable: 4291)
#endif // #if defined (__WIN32_OS__) 

	#include <iostream>
	#include <string>
	#include <vector>
	#include <cassert>
	#include <cstdio>
	#include <stack>
	#include <list>
	#include <map>
	#include <exception>
#if defined (__WIN32_OS__) 
	#include <winsock.h>
	#include <Windows.h>
	#include <windows.h>
	#include <winnt.h>
	#include <Commdlg.h>
	#include <commctrl.h>
	#include <Commdlg.h>
	#include <shellapi.h>
	#include <fcntl.h>
	#include <shlobj.h>
	#include <Mmsystem.h>

	#include <io.h>
	#include <aclapi.h>
	#include <lmerr.h>
#endif // #if defined (__WIN32_OS__) 

#if defined (__LINUX_OS__)
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <dirent.h>             // readdir(), etc.
#include <sys/stat.h>           // stat(), etc.
#include <cstring>             // strstr(), etc.
#include <errno.h>
#endif // #if defined (__LINUX_OS__)

#include "../LIB/argv_137.hpp"




// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ file mmap possible open mode
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_657 {
	argv_658 = 0,
	argv_659,
	argv_660,
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_192
// @@
// @@ DESCRIPTION:
// @@ This object permits to map a given file to memory
// @@ so that it can be accessed as a buffer, and thus it is 
// @@ faster.
// @@ The object works on both win32 and Linux.
// @@ 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_192
{
	private:
		string	argv_638;
		uint32_t	argv_261;
		uint32_t	argv_264;
		uint32_t	argv_673;
#if defined (__WIN32_OS__) 
		HANDLE	argv_329;
		HANDLE	argv_331;
		LPCTSTR argv_692;
#endif // #if defined (__WIN32_OS__) 

#if defined (__LINUX_OS__)
		uint8_t *  argv_661;
		uint32_t    argv_662;
#endif // #if defined (__LINUX_OS__)

	public:
		argv_192();
		~argv_192();
		bool argv_656 (const char * _filename, uint32_t _open_mode, uint8_t *& _pBuf, uint32_t& _file_size, bool _fail_safe=false);
		void argv_208 ();
		void argv_320 (uint32_t&, uint32_t&);
		uint32_t argv_321 ();
};



#endif // argv_148



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
