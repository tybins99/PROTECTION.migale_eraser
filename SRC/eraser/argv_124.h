
#if !defined(argv_164)
#define argv_164

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#if(_WIN32_WINNT >= 0x0501)
#define argv_187 0x0164
#endif /* _WIN32_WINNT >= 0x0501 */


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  INCLUDES
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_122.h"
#include "../lib/argv_137.hpp"
#include "../lib/argv_136.hpp"
#include "../lib/argv_140.hpp"
#include <cstdio>
#include <windows.h>
#include <string>
#include <errno.h>
#include <vector>
#include <algorithm>



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  NAMESPACES
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  CONSTANTS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define argv_641		128
#define argv_640				30000
#define argv_304	1024
#define argv_773			256

const uint32_t argv_642		= 100;


#ifndef argv_180
	#define argv_180 0x0040
#endif // !argv_180


//===============================================================
class argv_193
{
public:
	string argv_636;

	bool operator < (const argv_193& _s) {
		return (argv_636.size() > _s.argv_636.size());
	}
};


class argv_194
{
public:
	HWND					argv_755;
	HDC						argv_327;
	bool					argv_737;
	uint32_t					argv_666;
	bool					argv_305;
	bool					argv_753;
	vector<string>			argv_780;	
	vector<argv_193>	argv_781;	
	argv_218					argv_731;
	uint32_t					argv_228;

	HINSTANCE		argv_330;								
	TCHAR			argv_766[argv_642];		
	TCHAR			argv_767[argv_642];

	argv_194  ();
};



//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  GENERAL FUNCTIONS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool				argv_258 (const char *, uint32_t, argv_188&);
LRESULT CALLBACK	argv_160(HWND, UINT, WPARAM, LPARAM);
ATOM				argv_664(HINSTANCE hInstance);
BOOL				argv_605(HINSTANCE, int);
LRESULT CALLBACK	argv_785(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	argv_160(HWND, UINT, WPARAM, LPARAM);
void				argv_191 (HWND);
bool				argv_270 (string& dirname, vector<string>&);
bool				argv_269 (string dirname, string);
void				argv_268 (string);
void				argv_309 (const char *);
bool				argv_308 (const char *);
DWORD WINAPI		argv_251 (LPVOID);
bool				argv_248 ();
void				argv_744 ();
void				argv_256 (bool, bool);
void				argv_236 (bool, bool);



#endif // !defined(argv_164)
