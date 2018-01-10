// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_137.hpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains all objects, and functions
// @@ that might be used throughout several 
// @@ different projects.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_146
#define argv_146



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if defined (__WIN32_OS__) 
#include <windows.h>
#endif // #if defined (__WIN32_OS__) 
#include <cstdio>
#include <cstdlib>
#if defined (__WIN32_OS__)
	#pragma warning(disable: 4786)
	#pragma warning(disable: 4503)
	#pragma warning(disable: 4291)
#endif // #if defined (__WIN32_OS__) 
#include <string>
#include <vector>
#include <commctrl.h>
#include <Commdlg.h>
#include "../lib_plugin/argv_141.hpp"
#include "../lib_plugin/argv_142.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;


#define argv_606 ((DWORD)-1)
#define argv_760 _snprintf



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants related to file mapping 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_167 {
	argv_219=54,
	argv_786,
	argv_736,
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_190
// @@
// @@ DESCRIPTION:
// @@ This object permits to perform high performance time
// @@ measurements under win32 platform.
// @@ The accuracy is the microseconds.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_190
{
protected:
	LARGE_INTEGER argv_632;
	LARGE_INTEGER argv_633;

	LONGLONG argv_635;
	LONGLONG argv_634;

public:
	argv_190();

	void	argv_762();
	void	argv_764();
	double	argv_315() const;
	string	argv_765 (const char *);
	uint8_t	argv_324 ();
	uint32_t	argv_325 ();
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_188
// @@
// @@ DESCRIPTION:
// @@ This object permits to animate a progress bar
// @@ without knowing how it is actually done to move it.
// @@ Thus it is an abstraction layer.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_188
{
private:
	int argv_226;
	int argv_639;
	HWND hwnd;
	int	argv_345;

public:
	argv_188();
	void init (HWND, int, int);
	void incr (int32_t _nb_step=1);
	void reset();
	int argv_314 () {
		return (argv_226);
	}
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ general usage functions
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool	argv_280						(const char *);
bool	argv_303					(const char *);
void	argv_241					(const char *, uint32_t, uint32_t);
string	err_2_string					(int32_t);
string	argv_685				(uint8_t);
bool	argv_222					(const char *);
bool	argv_220		(const char *);
bool	argv_646				(const char *, const char *, const char *, string&, string&);
bool	argv_644				(const char *, const char *, string&);
void	argv_234			(const char *, const char *, const char *, string&, string&);
string	argv_273	(const char *);
string	argv_284				(uint32_t);
bool	argv_216				(uint8_t *, uint32_t, const char *);
bool	argv_253				(const char *, uint8_t *, uint32_t);
string	argv_215			(const char *, uint32_t);
void	argv_255					(HWND, long);
void	argv_235					(HWND, long);
bool	argv_748	(const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
bool	argv_746		(const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
bool	argv_747	(const char *, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&, uint32_t&);
string	argv_271	(const char *);
// uint32_t	compute_file_size				(const char *); // DANGEROUS !
bool	argv_663						(const char *, const char *);
bool	argv_282				(const char *);
bool	argv_740		(const char *);
bool	argv_281					(const char *);
bool	argv_739			(const char *);
bool	argv_283					(const char *);
bool	argv_741			(const char *);
bool	argv_318					(const char *, uint32_t&);



#endif // argv_146



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
