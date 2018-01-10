#include "../lib/argv_139.hpp"

#ifndef HIGHFIRST
//#define byteReverse(argv_186, len)	/* Nothing */
#else
//void byteReverse(unsigned char *argv_186, unsigned longs);


#ifndef ASM_MD5
// Note: this code is harmless on little-endian machines.
/*
void byteReverse(unsigned char *argv_186, unsigned longs)
{
    argv_776 t;
    do {
	t = (argv_776) ((unsigned) argv_186[3] << 8 | argv_186[2]) << 16 |
	    ((unsigned) argv_186[1] << 8 | argv_186[0]);
	*(argv_776 *) argv_186 = t;
	argv_186 += 4;
    } while (--longs);
}*/
#endif
#endif

/*
 * Start MD5 accumulation.  Set bit count to 0 and buffer to mysterious
 * initialization constants.
 */
void argv_651(struct argv_649 *ctx)
{
    ctx->argv_186[0] = 0x67452301;
    ctx->argv_186[1] = 0xefcdab89;
    ctx->argv_186[2] = 0x98badcfe;
    ctx->argv_186[3] = 0x10325476;

    ctx->argv_181[0] = 0;
    ctx->argv_181[1] = 0;
}

/*
 * Update context to reflect the concatenation of another buffer full
 * of bytes.
 */
void argv_654(struct argv_649 *ctx, unsigned char const *argv_186, unsigned len)
{
    argv_776 t;

    /* Update bitcount */

    t = ctx->argv_181[0];
    if ((ctx->argv_181[0] = t + ((argv_776) len << 3)) < t)
	ctx->argv_181[1]++;		/* Carry from low to high */
    ctx->argv_181[1] += len >> 29;

    t = (t >> 3) & 0x3f;	/* Bytes already in shsInfo->data */

    /* Handle any leading odd-sized chunks */

    if (t) {
	unsigned char *p = (unsigned char *) ctx->in + t;

	t = 64 - t;
	if (len < t) {
	    memcpy(p, argv_186, len);
	    return;
	}
	memcpy(p, argv_186, t);
//	byteReverse(ctx->in, 16);
	argv_653(ctx->argv_186, (argv_776 *) ctx->in);
	argv_186 += t;
	len -= t;
    }
    /* Process data in 64-byte chunks */

    while (len >= 64) {
	memcpy(ctx->in, argv_186, 64);
//	byteReverse(ctx->in, 16);
	argv_653(ctx->argv_186, (argv_776 *) ctx->in);
	argv_186 += 64;
	len -= 64;
    }

    /* Handle any remaining bytes of data. */

    memcpy(ctx->in, argv_186, len);
}

/*
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of argv_181 processed, MSB-first)
 */
void argv_650(unsigned char digest[16], struct argv_649 *ctx)
{
    unsigned count;
    unsigned char *p;

    /* Compute number of bytes mod 64 */
    count = (ctx->argv_181[0] >> 3) & 0x3F;

    /* Set the first char of padding to 0x80.  This is safe since there is
       always at least one byte free */
    p = ctx->in + count;
    *p++ = 0x80;

    /* Bytes of padding needed to make 64 bytes */
    count = 64 - 1 - count;

    /* Pad out to 56 mod 64 */
    if (count < 8) {
	/* Two lots of padding:  Pad the first argv_182 to 64 bytes */
	memset(p, 0, count);
//	byteReverse(ctx->in, 16);
	argv_653(ctx->argv_186, (argv_776 *) ctx->in);

	/* Now fill the next argv_182 with 56 bytes */
	memset(ctx->in, 0, 56);
    } else {
	/* Pad argv_182 to 56 bytes */
	memset(p, 0, count - 8);
    }
//    byteReverse(ctx->in, 14);

    /* Append length in argv_181 and transform */
    ((argv_776 *) ctx->in)[14] = ctx->argv_181[0];
    ((argv_776 *) ctx->in)[15] = ctx->argv_181[1];

    argv_653(ctx->argv_186, (argv_776 *) ctx->in);
//    byteReverse((unsigned char *) ctx->argv_186, 4);
    memcpy(digest, ctx->argv_186, 16);
    memset(ctx, 0, sizeof(ctx));	/* In case it's sensitive */
}

#ifndef ASM_MD5

/* The four core functions - argv_276 is optimized somewhat */

/* #define argv_276(x, y, z) (x & y | ~x & z) */
#define argv_276(x, y, z) (z ^ (x & (y ^ z)))
#define argv_277(x, y, z) argv_276(z, x, y)
#define argv_278(x, y, z) (x ^ y ^ z)
#define argv_279(x, y, z) (y ^ (x | ~z))

/* This is the central step in the MD5 algorithm. */
#ifdef __PUREC__
#define argv_652(f, w, x, y, z, data, s) \
	( w += f /*(x, y, z)*/ + data,  w = w<<s | w>>(32-s),  w += x )
#else
#define argv_652(f, w, x, y, z, data, s) \
	( w += f(x, y, z) + data,  w = w<<s | w>>(32-s),  w += x )
#endif

/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new data.  argv_654 blocks
 * the data and converts bytes into longwords for this routine.
 */
void argv_653(argv_776 argv_186[4], argv_776 const in[16])
{
    register argv_776 a, b, c, d;

    a = argv_186[0];
    b = argv_186[1];
    c = argv_186[2];
    d = argv_186[3];

#ifdef __PUREC__	/* PureC Weirdness... (GG) */
    argv_652(argv_276(b,c,d), a, b, c, d, in[0] + 0xd76aa478L, 7);
    argv_652(argv_276(a,b,c), d, a, b, c, in[1] + 0xe8c7b756L, 12);
    argv_652(argv_276(d,a,b), c, d, a, b, in[2] + 0x242070dbL, 17);
    argv_652(argv_276(c,d,a), b, c, d, a, in[3] + 0xc1bdceeeL, 22);
    argv_652(argv_276(b,c,d), a, b, c, d, in[4] + 0xf57c0fafL, 7);
    argv_652(argv_276(a,b,c), d, a, b, c, in[5] + 0x4787c62aL, 12);
    argv_652(argv_276(d,a,b), c, d, a, b, in[6] + 0xa8304613L, 17);
    argv_652(argv_276(c,d,a), b, c, d, a, in[7] + 0xfd469501L, 22);
    argv_652(argv_276(b,c,d), a, b, c, d, in[8] + 0x698098d8L, 7);
    argv_652(argv_276(a,b,c), d, a, b, c, in[9] + 0x8b44f7afL, 12);
    argv_652(argv_276(d,a,b), c, d, a, b, in[10] + 0xffff5bb1L, 17);
    argv_652(argv_276(c,d,a), b, c, d, a, in[11] + 0x895cd7beL, 22);
    argv_652(argv_276(b,c,d), a, b, c, d, in[12] + 0x6b901122L, 7);
    argv_652(argv_276(a,b,c), d, a, b, c, in[13] + 0xfd987193L, 12);
    argv_652(argv_276(d,a,b), c, d, a, b, in[14] + 0xa679438eL, 17);
    argv_652(argv_276(c,d,a), b, c, d, a, in[15] + 0x49b40821L, 22);

    argv_652(argv_277(b,c,d), a, b, c, d, in[1] + 0xf61e2562L, 5);
    argv_652(argv_277(a,b,c), d, a, b, c, in[6] + 0xc040b340L, 9);
    argv_652(argv_277(d,a,b), c, d, a, b, in[11] + 0x265e5a51L, 14);
    argv_652(argv_277(c,d,a), b, c, d, a, in[0] + 0xe9b6c7aaL, 20);
    argv_652(argv_277(b,c,d), a, b, c, d, in[5] + 0xd62f105dL, 5);
    argv_652(argv_277(a,b,c), d, a, b, c, in[10] + 0x02441453L, 9);
    argv_652(argv_277(d,a,b), c, d, a, b, in[15] + 0xd8a1e681L, 14);
    argv_652(argv_277(c,d,a), b, c, d, a, in[4] + 0xe7d3fbc8L, 20);
    argv_652(argv_277(b,c,d), a, b, c, d, in[9] + 0x21e1cde6L, 5);
    argv_652(argv_277(a,b,c), d, a, b, c, in[14] + 0xc33707d6L, 9);
    argv_652(argv_277(d,a,b), c, d, a, b, in[3] + 0xf4d50d87L, 14);
    argv_652(argv_277(c,d,a), b, c, d, a, in[8] + 0x455a14edL, 20);
    argv_652(argv_277(b,c,d), a, b, c, d, in[13] + 0xa9e3e905L, 5);
    argv_652(argv_277(a,b,c), d, a, b, c, in[2] + 0xfcefa3f8L, 9);
    argv_652(argv_277(d,a,b), c, d, a, b, in[7] + 0x676f02d9L, 14);
    argv_652(argv_277(c,d,a), b, c, d, a, in[12] + 0x8d2a4c8aL, 20);

    argv_652(argv_278(b,c,d), a, b, c, d, in[5] + 0xfffa3942L, 4);
    argv_652(argv_278(a,b,c), d, a, b, c, in[8] + 0x8771f681L, 11);
    argv_652(argv_278(d,a,b), c, d, a, b, in[11] + 0x6d9d6122L, 16);
    argv_652(argv_278(c,d,a), b, c, d, a, in[14] + 0xfde5380cL, 23);
    argv_652(argv_278(b,c,d), a, b, c, d, in[1] + 0xa4beea44L, 4);
    argv_652(argv_278(a,b,c), d, a, b, c, in[4] + 0x4bdecfa9L, 11);
    argv_652(argv_278(d,a,b), c, d, a, b, in[7] + 0xf6bb4b60L, 16);
    argv_652(argv_278(c,d,a), b, c, d, a, in[10] + 0xbebfbc70L, 23);
    argv_652(argv_278(b,c,d), a, b, c, d, in[13] + 0x289b7ec6L, 4);
    argv_652(argv_278(a,b,c), d, a, b, c, in[0] + 0xeaa127faL, 11);
    argv_652(argv_278(d,a,b), c, d, a, b, in[3] + 0xd4ef3085L, 16);
    argv_652(argv_278(c,d,a), b, c, d, a, in[6] + 0x04881d05L, 23);
    argv_652(argv_278(b,c,d), a, b, c, d, in[9] + 0xd9d4d039L, 4);
    argv_652(argv_278(a,b,c), d, a, b, c, in[12] + 0xe6db99e5L, 11);
    argv_652(argv_278(d,a,b), c, d, a, b, in[15] + 0x1fa27cf8L, 16);
    argv_652(argv_278(c,d,a), b, c, d, a, in[2] + 0xc4ac5665L, 23);

    argv_652(argv_279(b,c,d), a, b, c, d, in[0] + 0xf4292244L, 6);
    argv_652(argv_279(a,b,c), d, a, b, c, in[7] + 0x432aff97L, 10);
    argv_652(argv_279(d,a,b), c, d, a, b, in[14] + 0xab9423a7L, 15);
    argv_652(argv_279(c,d,a), b, c, d, a, in[5] + 0xfc93a039L, 21);
    argv_652(argv_279(b,c,d), a, b, c, d, in[12] + 0x655b59c3L, 6);
    argv_652(argv_279(a,b,c), d, a, b, c, in[3] + 0x8f0ccc92L, 10);
    argv_652(argv_279(d,a,b), c, d, a, b, in[10] + 0xffeff47dL, 15);
    argv_652(argv_279(c,d,a), b, c, d, a, in[1] + 0x85845dd1L, 21);
    argv_652(argv_279(b,c,d), a, b, c, d, in[8] + 0x6fa87e4fL, 6);
    argv_652(argv_279(a,b,c), d, a, b, c, in[15] + 0xfe2ce6e0L, 10);
    argv_652(argv_279(d,a,b), c, d, a, b, in[6] + 0xa3014314L, 15);
    argv_652(argv_279(c,d,a), b, c, d, a, in[13] + 0x4e0811a1L, 21);
    argv_652(argv_279(b,c,d), a, b, c, d, in[4] + 0xf7537e82L, 6);
    argv_652(argv_279(a,b,c), d, a, b, c, in[11] + 0xbd3af235L, 10);
    argv_652(argv_279(d,a,b), c, d, a, b, in[2] + 0x2ad7d2bbL, 15);
    argv_652(argv_279(c,d,a), b, c, d, a, in[9] + 0xeb86d391L, 21);
#else
    argv_652(argv_276, a, b, c, d, in[0] + 0xd76aa478, 7);
    argv_652(argv_276, d, a, b, c, in[1] + 0xe8c7b756, 12);
    argv_652(argv_276, c, d, a, b, in[2] + 0x242070db, 17);
    argv_652(argv_276, b, c, d, a, in[3] + 0xc1bdceee, 22);
    argv_652(argv_276, a, b, c, d, in[4] + 0xf57c0faf, 7);
    argv_652(argv_276, d, a, b, c, in[5] + 0x4787c62a, 12);
    argv_652(argv_276, c, d, a, b, in[6] + 0xa8304613, 17);
    argv_652(argv_276, b, c, d, a, in[7] + 0xfd469501, 22);
    argv_652(argv_276, a, b, c, d, in[8] + 0x698098d8, 7);
    argv_652(argv_276, d, a, b, c, in[9] + 0x8b44f7af, 12);
    argv_652(argv_276, c, d, a, b, in[10] + 0xffff5bb1, 17);
    argv_652(argv_276, b, c, d, a, in[11] + 0x895cd7be, 22);
    argv_652(argv_276, a, b, c, d, in[12] + 0x6b901122, 7);
    argv_652(argv_276, d, a, b, c, in[13] + 0xfd987193, 12);
    argv_652(argv_276, c, d, a, b, in[14] + 0xa679438e, 17);
    argv_652(argv_276, b, c, d, a, in[15] + 0x49b40821, 22);

    argv_652(argv_277, a, b, c, d, in[1] + 0xf61e2562, 5);
    argv_652(argv_277, d, a, b, c, in[6] + 0xc040b340, 9);
    argv_652(argv_277, c, d, a, b, in[11] + 0x265e5a51, 14);
    argv_652(argv_277, b, c, d, a, in[0] + 0xe9b6c7aa, 20);
    argv_652(argv_277, a, b, c, d, in[5] + 0xd62f105d, 5);
    argv_652(argv_277, d, a, b, c, in[10] + 0x02441453, 9);
    argv_652(argv_277, c, d, a, b, in[15] + 0xd8a1e681, 14);
    argv_652(argv_277, b, c, d, a, in[4] + 0xe7d3fbc8, 20);
    argv_652(argv_277, a, b, c, d, in[9] + 0x21e1cde6, 5);
    argv_652(argv_277, d, a, b, c, in[14] + 0xc33707d6, 9);
    argv_652(argv_277, c, d, a, b, in[3] + 0xf4d50d87, 14);
    argv_652(argv_277, b, c, d, a, in[8] + 0x455a14ed, 20);
    argv_652(argv_277, a, b, c, d, in[13] + 0xa9e3e905, 5);
    argv_652(argv_277, d, a, b, c, in[2] + 0xfcefa3f8, 9);
    argv_652(argv_277, c, d, a, b, in[7] + 0x676f02d9, 14);
    argv_652(argv_277, b, c, d, a, in[12] + 0x8d2a4c8a, 20);

    argv_652(argv_278, a, b, c, d, in[5] + 0xfffa3942, 4);
    argv_652(argv_278, d, a, b, c, in[8] + 0x8771f681, 11);
    argv_652(argv_278, c, d, a, b, in[11] + 0x6d9d6122, 16);
    argv_652(argv_278, b, c, d, a, in[14] + 0xfde5380c, 23);
    argv_652(argv_278, a, b, c, d, in[1] + 0xa4beea44, 4);
    argv_652(argv_278, d, a, b, c, in[4] + 0x4bdecfa9, 11);
    argv_652(argv_278, c, d, a, b, in[7] + 0xf6bb4b60, 16);
    argv_652(argv_278, b, c, d, a, in[10] + 0xbebfbc70, 23);
    argv_652(argv_278, a, b, c, d, in[13] + 0x289b7ec6, 4);
    argv_652(argv_278, d, a, b, c, in[0] + 0xeaa127fa, 11);
    argv_652(argv_278, c, d, a, b, in[3] + 0xd4ef3085, 16);
    argv_652(argv_278, b, c, d, a, in[6] + 0x04881d05, 23);
    argv_652(argv_278, a, b, c, d, in[9] + 0xd9d4d039, 4);
    argv_652(argv_278, d, a, b, c, in[12] + 0xe6db99e5, 11);
    argv_652(argv_278, c, d, a, b, in[15] + 0x1fa27cf8, 16);
    argv_652(argv_278, b, c, d, a, in[2] + 0xc4ac5665, 23);

    argv_652(argv_279, a, b, c, d, in[0] + 0xf4292244, 6);
    argv_652(argv_279, d, a, b, c, in[7] + 0x432aff97, 10);
    argv_652(argv_279, c, d, a, b, in[14] + 0xab9423a7, 15);
    argv_652(argv_279, b, c, d, a, in[5] + 0xfc93a039, 21);
    argv_652(argv_279, a, b, c, d, in[12] + 0x655b59c3, 6);
    argv_652(argv_279, d, a, b, c, in[3] + 0x8f0ccc92, 10);
    argv_652(argv_279, c, d, a, b, in[10] + 0xffeff47d, 15);
    argv_652(argv_279, b, c, d, a, in[1] + 0x85845dd1, 21);
    argv_652(argv_279, a, b, c, d, in[8] + 0x6fa87e4f, 6);
    argv_652(argv_279, d, a, b, c, in[15] + 0xfe2ce6e0, 10);
    argv_652(argv_279, c, d, a, b, in[6] + 0xa3014314, 15);
    argv_652(argv_279, b, c, d, a, in[13] + 0x4e0811a1, 21);
    argv_652(argv_279, a, b, c, d, in[4] + 0xf7537e82, 6);
    argv_652(argv_279, d, a, b, c, in[11] + 0xbd3af235, 10);
    argv_652(argv_279, c, d, a, b, in[2] + 0x2ad7d2bb, 15);
    argv_652(argv_279, b, c, d, a, in[9] + 0xeb86d391, 21);
#endif

    argv_186[0] += a;
    argv_186[1] += b;
    argv_186[2] += c;
    argv_186[3] += d;
}

#endif

string argv_210 (const char * argv_302) {
	argv_649 mdContext;
	unsigned char digest[16];
	char hex[33];
	int bytes;
	const int BUFFER_SIZE = 65536;
	unsigned char data[BUFFER_SIZE];

	FILE * inFile = fopen (argv_302, "rb");
	if (inFile == NULL) {
		printf ("%s can't be opened.\n", argv_302);
		fclose (inFile);
		return ("can't open file");
	}

	argv_651 (&mdContext);
	while ((bytes = fread (data, 1, BUFFER_SIZE, inFile)) != 0)
		argv_654 (&mdContext, data, bytes);
	argv_650 (digest, &mdContext);

	for(int i = 0; i < 16; i++) {
		argv_760(hex + 2 * i, 
				3, 
				"%02x", 
				(unsigned char) digest[i]);
	}

	// cerr << "hash = " << hex << endl;
		
	// printf (" %s\n", argv_302);
	fclose (inFile);
	return ((char *) &hex[0]);
}

string argv_210 (uint8_t * _buf, uint32_t _file_size) {
	argv_649 mdContext;
	unsigned char digest[16];
	char hex[33];

	argv_651 (&mdContext);
		argv_654 (&mdContext, _buf, _file_size);
	argv_650 (digest, &mdContext);

	for(int i = 0; i < 16; i++) {
		argv_760(hex + 2 * i, 3, "%02X", (unsigned char) digest[i]); 
	}
	return ((char *) &hex[0]);
}

void argv_210 (uint8_t * _buf, uint32_t _file_size, uint8_t * _result) {
	argv_649 mdContext;
	unsigned char digest[16];

	argv_651 (&mdContext);
		argv_654 (&mdContext, _buf, _file_size);
	argv_650 (digest, &mdContext);

	for(int i = 0; i < 16; i++) {
		_result[i] = digest[i];
	}
}



string argv_211 (signed char * _filename, bool& _bret) {
	_bret = true;
	string hash = "NONE";
	argv_192 mapper;
	uint8_t * argv_186;
	uint32_t file_size;
	bool bret = mapper.argv_656 ((const char *)_filename, argv_658, argv_186, file_size);
	if (bret == true) {
		argv_649 mdContext;
		unsigned char digest[16];
		char hex[33];

		argv_651 (&mdContext);
			argv_654 (&mdContext, argv_186, file_size);
		argv_650 (digest, &mdContext);

		for(int i = 0; i < 16; i++) {
			argv_760(hex + 2 * i, 3, "%02X", (unsigned char) digest[i]); 
		}
		mapper.argv_208 ();
		return ((char *) &hex[0]);
	}
	else {
		_bret = false;		
	}
	return (hash);
}