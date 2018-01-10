// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_138.hpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains the definition of the 
// @@ log facility that permits to log events and
// @@ to associate a time and date, coming along
// @@ with a severity level for each event.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_149
#define argv_149



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../lib/argv_137.hpp"
#if defined (__WIN32_OS__) 
//	#include <Windows.h>
	#include <windows.h>
//	#include <winnt.h>
#endif // #if defined (__WIN32_OS__) 
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <map>



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ log related constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define argv_624				65536
#define argv_627		256

//"02/20-17h51m48s "
#define argv_230					16
//"|NOR| "
#define argv_615				6

#if defined (__WIN32_OS__) 
	#define argv_618				512 - argv_230 - argv_615
#endif // #if defined (__WIN32_OS__) 
#if defined (__LINUX_OS__)
	#define argv_618				256 - argv_230 - argv_615
#endif // #if defined (__LINUX_OS__)



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ log related constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define argv_624				65536
#define argv_627		256

//"02/20-17h51m48s "
#define argv_230					16
//"|NOR| "
#define argv_615				6

#if defined (__WIN32_OS__) 
	#define argv_618				512 - argv_230 - argv_615
#endif // #if defined (__WIN32_OS__) 
#if defined (__LINUX_OS__)
	#define argv_618				256 - argv_230 - argv_615
#endif // #if defined (__LINUX_OS__)

#if defined (__WIN32_OS__) 
	#define argv_760 _snprintf
#endif // #if ! defined (__WIN32_OS__) 



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ log relative constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_719 {
    argv_675,
    argv_783,
    argv_262,
    argv_162,
    argv_231,
    argv_674,
};

#if defined (__LINUX_OS__)
	#define MAX_PATH	256
#endif // #if defined (__LINUX_OS__)




// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_212
// @@
// @@ DESCRIPTION:
// @@ This object permits to have a fixed size line
// @@ composed of 
// @@ - a date
// @@ - a severity level
// @@ - a message
// @@
// @@ Notice that if the message to append to the line
// @@ exceeds the line's maximum size, then the remaining
// @@ part of the message is lost.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_212
{
private:
	string argv_769;
	void insert_terminator (FILE *);

public:

	argv_212 () {
#if defined (__WIN32_OS__)
		argv_769 = "\r\n";
#endif // #if defined (__WIN32_OS__)
#if defined (__LINUX_OS__)
		argv_769 = "\n";
#endif // #if defined (__LINUX_OS__)
	}

	void insert_date (FILE *, CCPTR);
	void insert_level (FILE *, CCPTR);
	void insert_body (FILE *, CCPTR);
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS: argv_206
// @@
// @@ DESCRIPTION:
// @@ This object permits to open a log file,
// @@ save data into it, and close it.
// @@ It can be thread safe depending on the compilation
// @@ flags you choose.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_206
{
	private:
		string		argv_302;
		string		argv_225;
		argv_212	argv_676;
		FILE *		argv_307;
		argv_206 *		argv_263;
		UI32		argv_227;
		bool		argv_623;
		char		argv_768[argv_627];
#if defined (__WIN32_OS__)
		SYSTEMTIME	argv_771;
#endif // #if defined (__WIN32_OS__)
#if defined (__LINUX_OS__)
        time_t      argv_229;
        struct tm * argv_772;
#endif // #if defined (__LINUX_OS__)
		void		argv_779 (bool _large_mode=false);
		void		insert_date ();
		void		insert_level (UI32);
		void		argv_197 ();
		void		reset ();

	public:
		argv_206();
		virtual		~argv_206();
		bool		argv_689 (string, argv_206 *, string);
		void		argv_207 ();
		void		argv_625 (UI32, CCPTR);
		void		argv_625 (UI32, CCPTR, SI32);
		void		argv_625 (UI32, CCPTR, UI32);
		void		argv_625 (UI08);
		void		argv_625 (UI32, UI32, UI32);
		void		argv_625 (UI32, CCPTR, CCPTR);
		void		argv_625 (UI32, CCPTR, CCPTR, CCPTR);
		void		argv_625 (UI32, CCPTR, CCPTR, CCPTR, CCPTR);
		void		argv_625 (UI32, CCPTR, unsigned long);
		void		argv_625 (UI32, UI32);
		void		argv_626 (UI32, CCPTR, UI32);
		void		argv_622 (UI32, UI08 *, CCPTR);
		void		argv_621 (UI32, UI08 *, UI32, CCPTR);
		FILE *		argv_316 ();
		string		argv_319 ();
		void		argv_306 ();
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ misc functions declarations
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_239 (CCPTR, argv_206&); 
string err_2_string (SI32);
void argv_241 (argv_206 *, CCPTR, UI32, UI32);



#endif // argv_149



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
