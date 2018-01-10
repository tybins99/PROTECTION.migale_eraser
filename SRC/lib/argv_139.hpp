#ifndef argv_151
#define argv_151

#include "../lib/argv_137.hpp"
#include "../lib/argv_136.hpp"


using namespace std;

#ifdef __alpha
typedef unsigned int argv_776;
#else
typedef unsigned long argv_776;
#endif

#define int32_t			signed int
#define argv_310	-1
#define argv_217	32

const int32_t	argv_643		= 256;


struct argv_649 {
	argv_776 argv_186[4];
	argv_776 argv_181[2];
	unsigned char in[64];
};

void argv_651(struct argv_649 *context);
void argv_654(struct argv_649 *context, unsigned char const *argv_186,
	       unsigned len);
void argv_650(unsigned char digest[16], struct argv_649 *context);
void argv_653(argv_776 argv_186[4], argv_776 const in[16]);

/*
 * This is needed to make RSAREF happy on some MS-DOS compilers.
 */
typedef struct argv_649 argv_645;



string argv_210 (const char *);
string argv_211 (const char *, bool&);
string argv_210 (uint8_t * _buf, uint32_t);
void argv_210 (uint8_t * _buf, uint32_t _file_size, uint8_t *);

#endif // argv_151
