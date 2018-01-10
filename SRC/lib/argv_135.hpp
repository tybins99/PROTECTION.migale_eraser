// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_135.hpp
// @@ 
// @@ DESCRIPTION:
// @@ implementation of the Data Encryption 
// @@ Standard symetric argv_609 algorithm.
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ multiple inclusion problem avoidance
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#ifndef argv_145
#define argv_145



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ namespace usage declaration
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
using namespace std;




// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ constants
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#define argv_183 					64
#define argv_184			8
#define argv_612				64
#define argv_613			8
#define argv_201			7
#define argv_199				56
#define argv_203				48
#define argv_204			6
#define argv_200		28
#define argv_611   					8
#define argv_672					16
#define argv_175	8
#define argv_267			6
#define argv_266				48
#define argv_756			6
#define argv_275				32
#define argv_677			64			

#if defined (__WIN32_OS__) 
	#define argv_760 _snprintf
#endif // #if ! defined (__WIN32_OS__) 


union argv_159 {
	int8_t argv_177[4];
      	int32_t  argv_166; 	
};

union argv_158 {
	uint8_t argv_177[2];
	int argv_176;
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ DESCRIPTION	:
// @@ This object permits to cipher/decipher a given 64 bit buffer
// @@ using the "Data Encryption Standard" algorithm.
// @@ 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class argv_189
{
private:
	uint8_t * 	argv_609;
    uint8_t * 	argv_182;
	uint8_t * 	argv_745;	
	int    	argv_226;	
	argv_159		argv_616;
	argv_159		argv_617;
	argv_159		argv_750;
	argv_159		argv_751;
	int		argv_198;
	int		argv_202;
	uint32_t	argv_274;
	uint8_t	argv_174[8]; // only 7 necessary, but 8 is more convenient for computing
	uint8_t	argv_614[argv_672][argv_204];
	bool 	is_set (uint8_t *, int);
	void	argv_196 (uint8_t *, int, bool);	
	void	argv_242 ();
	void	argv_777 ();
	void	argv_245 (uint8_t *, uint8_t *, int, uint8_t *);
	void	argv_761 ();
	void	argv_655 ();
	void	argv_244 ();
	void	argv_243 ();
	void	reset ();
	void	argv_209 (uint32_t);
	void	argv_752 (signed int&);
	void	argv_696 ();
	void	argv_165 ();
	void	argv_721 ();	
	
public:
	argv_189();
	bool	argv_257 (uint8_t *, uint8_t *, uint8_t *);		
	bool	argv_232 (uint8_t *, uint8_t *, uint8_t *);
	friend void argv_240 (string, uint8_t *, int, bool);
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ Functions
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void			argv_240 (string, uint8_t *, int, bool _display_bitfield=false);



#endif // argv_145



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

