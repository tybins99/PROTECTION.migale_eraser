// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_142.hpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains all functions and
// @@ data structures that are useful for any
// @@ kind of plugin.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_147
#define argv_147



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//#include "../../lib/argv_137.hpp"
//#include "../../lib/hidden_data.hpp"
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include "../lib_plugin/argv_141.hpp"
#include <windows.h>



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const uint32_t argv_185 = 54;



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ possible files types list
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_288 {
	argv_295 = 0,
	argv_291,
	argv_290,
	argv_287,
	argv_294,
	argv_293,
	argv_300,
	argv_296,
	argv_299,
	argv_297,
	argv_298,
	argv_289,
	argv_301,
	argv_286,
	argv_285,
	argv_292,
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ possible operations argv_745 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_720 {
	argv_682 = 0,
	argv_678,
	argv_679,
	argv_683,
	argv_686,
	argv_684,
	argv_681,
	argv_687,
	argv_680,
};


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ return codes for the entire application
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
enum argv_173 {
	// === plugins related error codes ===
	argv_716 = 74000,	
	argv_714,
	argv_712,
	argv_708,
	argv_715,
	argv_709,
	argv_702,
	argv_718,
	argv_697,
	argv_717,
	argv_701,
	argv_707,
	argv_705,
	argv_704,
	argv_703,
	argv_710,
	argv_706,
	argv_713,
	argv_699,
	argv_711,
	argv_698,

	// ==== analysis argv_745 related errors =====
	argv_171 = 75000,
	argv_168,
	argv_169,
	argv_170,
	argv_172,
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ general functions used by plugins
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void	argv_742					();
void	argv_625					(const char *);
void	argv_628					(const char *, vector<uint8_t>&);
void	log_vectors					(const char *, vector<uint8_t>&, vector<uint8_t>&);
bool	argv_317			(const char *, uint32_t&);
uint32_t	argv_313				(uint8_t *, uint32_t);
string	argv_272	(const char *);
string	argv_700			(int32_t);


#endif // argv_147



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
