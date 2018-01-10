// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_150
#define argv_150



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <windows.h>
#include "../lib/argv_139.hpp"
#if defined (__RC4_USE_DES__)
	#include "../lib/argv_135.hpp"
#endif // __RC4_USE_DES__

#define argv_729		10000000
#define argv_670				10
#define	argv_648		64 * 8 
#if defined (__RC4_USE_DES__)
	#define argv_233 8
#endif // __RC4_USE_DES__
#define argv_647	16
#define argv_730 16
#define argv_754			256
#define argv_671	256
#define argv_665				16

#define argv_735		10
#define argv_734		2048
#define argv_732			25
#define argv_237			256


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;

union argv_179 {
	uint8_t argv_156[4];
	uint32_t argv_157;
};


class argv_195
{
public:
	uint8_t				argv_733[argv_734];
	bool				argv_763;
	vector<HANDLE>		argv_782;
#if defined (__GUI_RC4__)
	argv_188				argv_770;
#endif // __GUI_RC4__

	argv_195 () {
		argv_763 = false;
	}

	void argv_265 ();
};


class argv_218
{
private:
	argv_179	argv_178;
	uint8_t		argv_629;
	uint8_t		argv_630;
	uint8_t		argv_637[argv_754];
	uint8_t		argv_631[argv_730];
	bool		argv_722;
	void		argv_610 (vector<uint8_t>&);

	void		argv_726 (vector<uint8_t>&);
	void		argv_311 (argv_218&);
	void		argv_259 (vector<uint8_t>&);

public:
	argv_218 ();
	void		argv_265 ();
	void		argv_728 ();
	bool		argv_723 (vector<uint8_t>&);
	void		argv_723 (argv_218&);

	uint8_t		argv_323 ();
	uint32_t		argv_322 ();
	bool		argv_608 ();
};


#endif // #define argv_150



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

