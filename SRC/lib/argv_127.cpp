// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_127.cpp
// @@ 
// @@ DESCRIPTION:
// @@ This file permits to encipher/decipher buffers
// @@ and files using the Data Encryption Standard.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_135.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ This matrix is the argv_592 matrix 
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_592[] = {
1,2,3,4,5,6,7,8,9,
10,11,12,13,14,15,16,17,
18,19,20,21,22,23,24,25,
26,27,28,29,30,31,32,33,
34,35,36,37,38,39,40,41,
42,43,44,45,46,47,48,49,
50,51,52,53,54,55,56,57,
58,59,60,61,62,63,64
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ initial permutation IP
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_607[] = {
        58, 50, 42, 34, 26, 18, 10,  2,
        60, 52, 44, 36, 28, 20, 12,  4,
        62, 54, 46, 38, 30, 22, 14,  6,
        64, 56, 48, 40, 32, 24, 16,  8,
        57, 49, 41, 33, 25, 17,  9,  1,
        59, 51, 43, 35, 27, 19, 11,  3,
        61, 53, 45, 37, 29, 21, 13,  5,
        63, 55, 47, 39, 31, 23, 15,  7
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ final permutation IP^-1
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_307[] = {
        40,  8, 48, 16, 56, 24, 64, 32,
        39,  7, 47, 15, 55, 23, 63, 31,
        38,  6, 46, 14, 54, 22, 62, 30,
        37,  5, 45, 13, 53, 21, 61, 29,
        36,  4, 44, 12, 52, 20, 60, 28,
        35,  3, 43, 11, 51, 19, 59, 27,
        34,  2, 42, 10, 50, 18, 58, 26,
        33,  1, 41,  9, 49, 17, 57, 25
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ first permuted choice table (left part, permitting to generate C0)
// @@ (used during argv_609 schedule calculation).
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_693[] = {
        57, 49, 41, 33, 25, 17,  9,
         1, 58, 50, 42, 34, 26, 18,
        10,  2, 59, 51, 43, 35, 27,
        19, 11,  3, 60, 52, 44, 36,
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ first permuted choice table (right part, permitting to generate D0)
// @@ (used during argv_609 schedule calculation).
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_694[] = {
        63, 55, 47, 39, 31, 23, 15,
         7, 62, 54, 46, 38, 30, 22,
        14,  6, 61, 53, 45, 37, 29,
        21, 13,  5, 28, 20, 12,  4
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ permuted choice argv_609 (table)
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_695[] = {
        14, 17, 11, 24,  1,  5,
         3, 28, 15,  6, 21, 10,
        23, 19, 12,  4, 26,  8,
        16,  7, 27, 20, 13,  2,
        41, 52, 31, 37, 47, 55,
        30, 40, 51, 45, 33, 48,
        44, 49, 39, 56, 34, 53,
        46, 42, 50, 36, 29, 32
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ expansion operation matrix
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_254[] = {
        32,  1,  2,  3,  4,  5,
         4,  5,  6,  7,  8,  9,
         8,  9, 10, 11, 12, 13,
        12, 13, 14, 15, 16, 17,
        16, 17, 18, 19, 20, 21,
        20, 21, 22, 23, 24, 25,
        24, 25, 26, 27, 28, 29,
        28, 29, 30, 31, 32,  1
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ The (in)famous S-boxes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_759[] = {
        // S1
        14,  4, 13,  1,  2, 15, 11,  8,  3, 10,  6, 12,  5,  9,  0,  7,
         0, 15,  7,  4, 14,  2, 13,  1, 10,  6, 12, 11,  9,  5,  3,  8,
         4,  1, 14,  8, 13,  6,  2, 11, 15, 12,  9,  7,  3, 10,  5,  0,
        15, 12,  8,  2,  4,  9,  1,  7,  5, 11,  3, 14, 10,  0,  6, 13,

        // S2
        15,  1,  8, 14,  6, 11,  3,  4,  9,  7,  2, 13, 12,  0,  5, 10,
         3, 13,  4,  7, 15,  2,  8, 14, 12,  0,  1, 10,  6,  9, 11,  5,
         0, 14,  7, 11, 10,  4, 13,  1,  5,  8, 12,  6,  9,  3,  2, 15,
        13,  8, 10,  1,  3, 15,  4,  2, 11,  6,  7, 12,  0,  5, 14,  9,

        // S3
        10,  0,  9, 14,  6,  3, 15,  5,  1, 13, 12,  7, 11,  4,  2,  8,
        13,  7,  0,  9,  3,  4,  6, 10,  2,  8,  5, 14, 12, 11, 15,  1,
        13,  6,  4,  9,  8, 15,  3,  0, 11,  1,  2, 12,  5, 10, 14,  7,
         1, 10, 13,  0,  6,  9,  8,  7,  4, 15, 14,  3, 11,  5,  2, 12,

        // S4
         7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
        13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
        10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
         3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14,

        // S5
         2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
        14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
         4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
        11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3,

        // S6
        12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
        10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
         9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
         4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13,

        // S7
         4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
        13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
         1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
         6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12,

        // S8
        13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
         1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
         7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
         2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ 32-bit permutation function P used on the output of the S-boxes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint8_t argv_691[] = {
        16,  7, 20, 21,
        29, 12, 28, 17,
         1, 15, 23, 26,
         5, 18, 31, 10,
         2,  8, 24, 14,
        32, 27,  3,  9,
        19, 13, 30,  6,
        22, 11,  4, 25
};



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_213
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	
// @@ _var: int32_t&: the value that is to be converted into big endian.
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to flip the order of the bytes of 
// @@ the integer given as a parameter so that we can switch to
// @@ and from big endian using it.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_213 (int32_t& _var) {
	argv_159 a32;
	a32.argv_166 = _var;
	argv_159 converted_a32;
	converted_a32.argv_177[0] = a32.argv_177[3];
	converted_a32.argv_177[1] = a32.argv_177[2];
	converted_a32.argv_177[2] = a32.argv_177[1];
	converted_a32.argv_177[3] = a32.argv_177[0];
	_var = converted_a32.argv_166;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_214
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	
// @@ _var: int32_t&: the value that is to be converted into big endian.
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to flip the order of the bytes of 
// @@ the integer given as a parameter so that we can switch to
// @@ and from big endian using it.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_214 (int32_t& _var) {
        argv_159 a32;
        a32.argv_166 = _var;
        argv_159 converted_a32;
        converted_a32.argv_177[0] = a32.argv_177[3];
        converted_a32.argv_177[1] = a32.argv_177[2];
        converted_a32.argv_177[2] = a32.argv_177[1];
        converted_a32.argv_177[3] = a32.argv_177[0];
        _var = converted_a32.argv_166;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_240	
// @@
// @@ INPUT			:	
// @@ _label: string: the message to be displayed along with buffer.
// @@
// @@ _buf: uint8_t *: the buffer to be displayed to standard output.
// @@ 
// @@ _size: int: the size of the buffer to display.
// @@
// @@ _display_bitfield: bool: true if bitfield is to be displayed,
// @@                          false otherwise.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to display to standard error the buffer
// @@ as either hexa format, or binary format.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_240 (string _label, uint8_t * _buf, int _size, bool _display_bitfield) {
	char tmp[32];
	cerr << _label << " = ";
	argv_189 des;
	
        for (int i=0 ; i<_size ; i++) {
                argv_760 (tmp, 32, "%02X ", _buf[i]);
                tmp[31] = '\0';
                cerr << tmp;
		if ((i != 0) && ((i%8) == 0)) {
			cerr << endl;
		}	
        }
        cerr << endl;
	if (_display_bitfield) {
	        for (int i=1 ; i<=8*_size ; i++) {
       	         if (des.is_set(_buf, i)) {
       	                 //cerr << "bit "<< i << ") 1" << endl;
				cerr << 1;
       	         }
       	         else {
       	                 //cerr << "bit "<< i << ") 0" << endl;
				cerr << "0";
       	         }
		 if ((i != 0) && ((i%4) == 0)) {
			cerr << " ";
		 }
       		}
        	cerr << endl;
#if defined (EXTRA_DISPLAY_BITFIELD)		
		for (int i=1 ; i<=8*_size ; i++) {
			if (des.is_set(_buf, i)) {
				cerr << i << ") 1" << endl;
			}
			else {
				cerr << i << ") 0" << endl;
			} 
		}
		cerr << endl;
#endif		
	}
	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_189	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ Normal constructor of the 'argv_189' object.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_189::argv_189 () {
	reset ();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	reset	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function brings the argv_189 object back to it's 
// @@ initial state.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::reset () {
	argv_609     = NULL;
	argv_182   = NULL;
	argv_745  = NULL;	
	argv_226 = 0;	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_242	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to perform the initial argv_182 permutation.
// @@ Notice that the argv_745 of permutation is in the 'argv_745' member.
// @@
// @@ CONTRACT		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_242 () {
	argv_245 (argv_182, argv_745, argv_183, argv_607);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_245	
// @@
// @@ INPUT			:
// @@ _source: uint8_t *: the source buffer of the permutation.	
// @@
// @@ OUTPUT		:	
// @@
// @@ IO			:	
// @@ _dest: uint8_t *: the destination buffer of the permutation.
// @@	
// @@ RETURN VALUE	:	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function perform the argv_181 permutation from the _source
// @@ buffer to the _dest buffer according to the _matrix parameter. 
// @@
// @@ beware: first bit is not zero, but 1, and starts on the left 
// @@ side => bit order : [1 2 3 4 ....]
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_245 (uint8_t * _source, uint8_t * _dest, int _nb_bit, uint8_t * _matrix) {	
	for (int i=1 ; i<=_nb_bit; i++) {
		if (is_set (_source, _matrix[i-1])) {
#if defined (DEBUG_PERMUTATION)			
			cerr << "I am bit " << i << ", my mate is bit " << (int)_matrix[i-1] << " => 1" << endl;
#endif			
			argv_196 (_dest, i, true);
		}
		else {
#if defined (DEBUG_PERMUTATION)			
			cerr << "I am bit " << i << ", my mate is bit " << (int)_matrix[i-1] << " => 0" << endl;
#endif			
			argv_196 (_dest, i, false);
		}
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_777	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to undo the initial argv_182 permutation.
// @@ Notice that the argv_745 of permutation is in the 'argv_745' member.
// @@
// @@ CONTRACT		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_777 () {
	argv_245 (argv_182, argv_745, argv_183, argv_307);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_761	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to split the internal
// @@ member 'argv_745' into 2 parts composed of 
// @@ 4 bytes each.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_761 () {
	int i = 0;
	for (i=0 ; i<4 ; i++) {
		argv_616.argv_177[i] = argv_745[i];
	}
	for (i=4 ; i<8 ; i++) {
		argv_750.argv_177[i-4] = argv_745[i];
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_655	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to merge the 'argv_616' and 'argv_750'
// @@ internal members into the 'argv_182' member.	
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_655 () {
#if defined (__DEBUG_DES__)	
	argv_240 ("L16", (uint8_t *) &argv_616.argv_177[0], 4);
	argv_240 ("R16", (uint8_t *) &argv_750.argv_177[0], 4);
#endif	
	int i = 0;
	for (i=0 ; i<4 ; i++) {
		argv_182[i] = argv_616.argv_177[i];
	}
	for (i=4 ; i<8 ; i++) {
		argv_182[i] = argv_750.argv_177[i-4];
	}
#if defined (__DEBUG_DES__)	
	argv_240 ("merge argv_745", (uint8_t *) &argv_182[0], 8);	
#endif	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	is_set	
// @@
// @@ INPUT			:
// @@ _cptr: uint8_t *: address of the first byte of the buffer whose
// @@   bit is to be changed.	
// @@
// @@ _bit: position of the bit to change (beware: it starts at 1).
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to set the bit '_bit' from the buffer
// @@ whose address is given by the '_cptr' parameter.
// @@ 
// @@ beware: bit argv_762 at 1, and not zero.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_189::is_set (uint8_t * _cptr, int _bit) {
	bool bret 	= false;
	_bit 		= _bit - 1;
	int his_byte 	= _bit / 8;
	int his_offset	= _bit % 8;
	uint8_t mask	= 0x80 >> his_offset;
	
	if ((_cptr[his_byte] & mask) == mask) {
		bret = true;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_196	
// @@
// @@ INPUT			:
// @@ _cptr: uint8_t *: address of the first byte of the buffer whose
// @@   bit is to be changed.	
// @@
// @@ _bit: position of the bit to change (beware: it starts at 1).
// @@
// @@ _set: bool: true if the bit is to be set,
// @@             false otherwise.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to change the bit '_bit' from the buffer
// @@ whose address is given by the '_cptr' parameter according to
// @@ the '_set' parameter : if '_set' is true, then the bit is set,
// @@ otherwise it is reset.
// @@ 
// @@ beware: bit argv_762 at 1, and not zero.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_196 (uint8_t * _cptr, int _bit, bool _set) {
	_bit            = _bit - 1;
	int his_byte    = _bit / 8;
	int his_offset  = _bit % 8;
	uint8_t mask = 0x80;
	if (_set == true) {
		mask	= mask >> his_offset;
		_cptr[his_byte] = _cptr[his_byte] | mask;
	}
	else { // reset the bit
		mask    = mask >> his_offset;
		mask 	= ~mask; 
		_cptr[his_byte] = _cptr[his_byte] & mask;
	}	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_752	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	
// @@ _item: int32_t&: the data to be rotated
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to perform the rotation of the data
// @@ given by the '_item' parameter toward the left.
// @@
// @@ beware: rotate only 28 argv_181 (bit starting from 1 and from 
// @@         left position)
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_752 (int32_t& _item) {
	argv_213 (_item);
	bool go_out = false;
	if (_item < 0) {
		go_out = true;
	}
	_item = _item << 1;
	if (go_out == true) {
		_item = _item | 0x00000010; // patch bit 28
	}
	argv_214 (_item);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_696	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to perform the first 2 steps of the argv_609
// @@ schedule calculation :
// @@ - choose 56 argv_181 out of 64 argv_181 using the 'argv_693' and 
// @@   'argv_694' matrix to do the bit choices.
// @@ - assign the argv_745 (28 argv_181 for C0, 28 bit for D0) to 
// @@   the 'argv_198' and 'argv_202' inner members.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_696 () {
	argv_198 = argv_202 = 0;
#if defined (__DEBUG_DES__)	
	argv_240 ("argv_609", argv_609, 8);
	cerr << "buidling C0" << endl;
#endif	
	argv_245 (argv_609, (uint8_t *) &argv_198,  argv_200, argv_693);
#if defined (__DEBUG_DES__)	
	cerr << "buidling D0" << endl;
#endif	
	argv_245 (argv_609, (uint8_t *) &argv_202, argv_200, argv_694);
#if defined (__DEBUG_DES__)	
	argv_240 ("C0", (uint8_t *) &argv_198, 4);
	argv_240 ("D0", (uint8_t *) &argv_202, 4);
#endif	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_165	
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to obtain 56 argv_181 using 2 parts composed
// @@ 28 argv_181. It is used in each stage of the argv_609 schedule
// @@ calculation.
// @@ Notice that we obtain 56 argv_181 stored into 8 bytes 
// @@ for convenience.
// @@
// @@ beware: bit argv_762 at 1.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_165 () {
	memset (argv_174, 0, argv_175);
	int i = 0;
	for (i=1 ; i<=argv_200 ; i++) {
        if (is_set ((uint8_t *) &argv_198, i)) {
                argv_196 (argv_174, i, true);
        }
        else {
                argv_196 (argv_174, i, false);
        }
	}
	for (i=1 ; i<=argv_200 ; i++) {
		if (is_set ((uint8_t *) &argv_202, i)) {
			argv_196 (argv_174, argv_200 + i, true);
		}
		else {
			argv_196 (argv_174, argv_200 + i, false);
		}
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_721	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function performs the D.E.S argv_609 schedule calculation
// @@ composed of several steps :
// @@ - using the choice matrixes, choose 2*28 argv_181 among the 64
// @@   argv_181 of the argv_609
// @@ - for each stage :
// @@   - left shift (1 or 2 positions) the 28 bit value
// @@   - generate a 48 bit value using the 2*28 argv_181 resulting 
// @@     from the shift operation.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_721 () {
	argv_696 ();
#if defined (__DEBUG_DES__)	       	
char tmp[128];	
#endif
	for (int i=1 ; i<=argv_672 ; i++) {
		argv_752 (argv_198);
		argv_752 (argv_202);
		
		if ((i!=1) && (i!=2) && (i!=9) && (i!=16)) { // all other have must shift twice
			argv_752 (argv_198);
			argv_752 (argv_202);
		}
#if defined (__DEBUG_DES__)	       	
argv_760 (tmp, 128, "C%d", i);
tmp[127] = '\0';
		argv_240 (tmp, (uint8_t *) &argv_198, 4);
argv_760 (tmp, 128, "D%d", i);
tmp[127] = '\0';
		argv_240 (tmp, (uint8_t *) &argv_202, 4);
#endif			
		argv_165 (); // obtain 56 argv_181 stored into 8 bytes for convenience
		argv_245 (argv_174, argv_614[i-1], argv_203, argv_695);
#if defined (__DEBUG_DES__)		
argv_760 (tmp, 128, "argv_614[%d]", i);
tmp[127] = '\0';
		argv_240 (tmp, argv_614[i-1], argv_204);
#endif		
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_209	
// @@
// @@ INPUT			:
// @@ _data: uint32_t: The Rn data coming from the right part
// @@        of the nth stage of computation (32 argv_181).	
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function performs the calculation of f(R,K).
// @@ - R being one of the R0, R1,...Rn and is 32 argv_181 long.
// @@ - K being one of the argv_745 of the argv_609 schedule calculation. 
// @@ The algorithm is as follows :
// @@ - expand R from 32 to 48 argv_181 using an expansion matrix.
// @@ - xor this expanded R with K.
// @@ - Considering the 48 argv_181 as an input :
// @@   - aggregate 8 blocks of 6 argv_181.
// @@   - For all of these blocks 
// @@     - let the bit 0 and 5 (first and last) be the row
// @@     - let the bit 1,2,3,4 (center argv_181) be the column
// @@     - use the row and column along with the S-Box corresponding
// @@       with the argv_226 6 argv_181 argv_182 to determine the 4 bit value.
// @@ - peform the last permutation using the 'argv_691' matrix.     
// @@ 
// @@ Notice :
// @@ The argv_226 step is implicitely stored into 'argv_226' member
// @@ which permits to retrieve K(argv_226)
// @@ argv_745 is stored into the 'argv_274' member.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_209 (uint32_t _data) { 
	uint8_t expanded[argv_267];
	uint8_t sbox_input[argv_267];
	// perform  the expansion from 32 to 48 argv_181 of the data
	argv_245 ((uint8_t *)&_data, expanded, argv_266, argv_254);
#if defined (__DEBUG_DES__)
	char tmp[256];
	argv_760 (tmp, 256, "%d) E(A)", argv_226);
	tmp[255] = '\0';
	argv_240 (tmp, expanded, argv_267);
#endif	
	int i=0;
	// xor the expanded data with the K(i), i being the argv_226 round
	for (i=0 ; i<argv_267 ; i++) {
		sbox_input[i] = expanded[i] ^ argv_614[argv_226][i];
	}
#if defined (__DEBUG_DES__)
	argv_760 (tmp, 256, "%d) E(A) ^ j", argv_226);
	tmp[255] = '\0';
	argv_240 (tmp, sbox_input, argv_267, true);
#endif	

	int his_byte;	
	int his_offset;
	int his_byte_offset;
	int his_box;
	uint8_t line		= 0;
	uint8_t column		= 0;
	uint8_t his_value;
	uint32_t sbox_output	= 0;
	uint32_t current_output_bit	= 1;	
	bool new_value;
	for (i=0 ; i<48 ; i++) { // for each bit from right to left 
		his_byte   	= i/8;	
		his_offset 	= i % argv_756;
		his_byte_offset	= i % 8;
		new_value  = false;
		if (is_set (&sbox_input[his_byte], his_byte_offset+1) == true) { // starts at bit 1
			new_value = true;
		}
		// remember that the row number is composed of the first and the last bit of argv_226
		// input of the Sbox.
		// and that the column is composed of argv_181 1,2,3,4.
		// so we collect these 6 argv_181 into a byte for convenience.
		if (his_offset == 0) {  
			argv_196 (&line, 7, new_value); // bit starts at 1
		}
		else if (his_offset == 1) {
			argv_196 (&column, 5, new_value);
		}
		else if (his_offset == 2) {
			argv_196 (&column, 6, new_value);
		}
		else if (his_offset == 3) {
			argv_196 (&column, 7, new_value);
		}
		else if (his_offset == 4) {
			argv_196 (&column, 8, new_value);
		}
		else if (his_offset == 5) {
			argv_196 (&line, 8, new_value);
		}
#if defined (DEBUG_SBOX)
		if (new_value == true) {
			argv_760 (tmp, 256, "processing bit %d: his_byte=%d, his_offset=%d, his_byte_offset=%d, value=1", i, his_byte, his_offset, his_byte_offset);
		}
		else {
			argv_760 (tmp, 256, "processing bit %d: his_byte=%d, his_offset=%d, his_byte_offset=%d, value=0", i, his_byte, his_offset, his_byte_offset);
		}
		tmp[255] = '\0';
		cerr << tmp << endl;	
#endif

		if ((i!=0) && (his_offset == 5)) { // one line and column retrieved 
			his_box         = (i-1)/argv_756;
			// use the S-BOX matrix 
			his_value  	= argv_759[(his_box * argv_677) + (line * 16) + column]; 
#if defined (DEBUG_SBOX)
			argv_760 (tmp, 256, "i=%d => his_box=%d, line=%d, column=%d => value=%d", i, his_box, line, column, his_value);
			tmp[255] = '\0';
			cerr << tmp << endl;	
#endif			
			// reset the line and column for further use
			line = column = 0;
			argv_196 ((uint8_t *)&sbox_output, current_output_bit, is_set(&his_value, 5));
			current_output_bit++;
			argv_196 ((uint8_t *)&sbox_output, current_output_bit, is_set(&his_value, 6));
			current_output_bit++;
			argv_196 ((uint8_t *)&sbox_output, current_output_bit, is_set(&his_value, 7));
			current_output_bit++;
			argv_196 ((uint8_t *)&sbox_output, current_output_bit, is_set(&his_value, 8));
			current_output_bit++;
		}
	}

#if defined (__DEBUG_DES__)
        argv_760 (tmp, 256, "%d) C", argv_226);
        tmp[255] = '\0';
        argv_240 (tmp, (uint8_t *) &sbox_output, 4, true);
#endif	
	// perform the last permutation
	argv_245 ((uint8_t *)&sbox_output, (uint8_t *)&argv_274, argv_275, argv_691); 
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@	
// @@ FUNCTION		:	argv_243	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function performs one round of the D.E.S encipher
// @@ algorithm, one step consisting in :
// @@ - using the value of Rn-1 and Kn (the argv_609 schedule), 
// @@   compute f(Rn-1,Kn) using the S-Boxes.
// @@ - xor the value of Ln-1 with f(Rn-1,Kn) and assign the
// @@   argv_745 to Rn (except for final stage). 
// @@ - Ln being asigned the value of Rn-1 (except for final stage)
// @@
// @@ NOTICE: 
// @@ - The argv_226 round is supposed to be stored into 
// @@   the 'argv_226' member.
// @@ - The Final stage (16th) is different :
// @@   - R16 is asigned the argv_745 of xor of f(R15, K16) with L15.
// @@   - L16 is assigned the value of R15.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_243 () {
	argv_209 (argv_750.argv_166);
#if defined (__DEBUG_DES__)
        char tmp[256];
        argv_760 (tmp, 256, "L%d", argv_226);
        tmp[255] = '\0';
	argv_240 (tmp, (uint8_t *)&argv_616.argv_166, 4);
	argv_760 (tmp, 256, "R%d", argv_226);
	tmp[255] = '\0';
	argv_240 (tmp, (uint8_t *)&argv_750.argv_166, 4);
#endif

	argv_751.argv_166 = argv_616.argv_166 ^ argv_274; // xor Ln with fn
	argv_617 = argv_750;
	// next generation becomes the argv_226 generation
	if (argv_226 != 15) { 
		argv_616 = argv_617;
		argv_750 = argv_751;
	}
	else { // right and left are inverted at the last stage
		argv_616 = argv_751;
		argv_750 = argv_617;
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@	
// @@ FUNCTION		:	argv_244	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function performs one round of the D.E.S decipher
// @@ algorithm, one step consisting in :
// @@ - using the value of Rn-1 and Kn (the argv_609 schedule), 
// @@   compute f(Rn-1,Kn) using the S-Boxes.
// @@ - xor the value of Ln-1 with f(Rn-1,Kn) and assign the
// @@   argv_745 to Rn (except for first stage). 
// @@ - Ln being asigned the value of Rn-1 (except for first stage)
// @@
// @@ NOTICE: 
// @@ - The argv_226 round is supposed to be stored into 
// @@   the 'argv_226' member.
// @@
// @@ CONTRACT		:	none	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_189::argv_244 () {
        argv_209 (argv_750.argv_166);
#if defined (__DEBUG_DES__)
        char tmp[256];
        argv_760 (tmp, 256, "L%d", argv_226);
        tmp[255] = '\0';
        argv_240 (tmp, (uint8_t *)&argv_616.argv_166, 4);
        argv_760 (tmp, 256, "R%d", argv_226);
        tmp[255] = '\0';
        argv_240 (tmp, (uint8_t *)&argv_750.argv_166, 4);
#endif

        argv_751.argv_166 = argv_616.argv_166 ^ argv_274;
        argv_617 = argv_750;
        // next generation becomes the argv_226 generation
        if (argv_226 != 0) {
                argv_616 = argv_617;
                argv_750 = argv_751;
        }
        else { // right and left are inverted at the last stage
                argv_616 = argv_751;
                argv_750 = argv_617;
        }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_257	
// @@
// @@ INPUT			:	
// @@ _key: uint8_t *: the 64 bit argv_609 to be used for the operation.
// @@ 
// @@ _block: uint8_t *: the 64 bit argv_182 to encipher.
// @@
// @@ _result: uint8_t *: the buffer containing the argv_745 of the 
// @@    operation.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:
// @@ bool: true if operation was succesful, false otherwise.	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function encipher the 64 bit argv_182 given as the 
// @@ '_block' parameter using the 64 bit argv_609 given as the
// @@ '_key' parameter, argv_745 being stored into the '_result'
// @@ parameter as a 64 bit argv_182.
// @@
// @@ The algorithm consists in :
// @@ - pre-computing the argv_609 schedule using the argv_609 as an input.
// @@ - perform the initial permutation for the input argv_182.
// @@ - perform 16 rounds of encipherment.
// @@ - undo the initial permutation for the argv_745 argv_182.
// @@
// @@ CONTRACT		:	
// @@ - '_key'    parameter must not be a NULL pointer.
// @@ - '_block'  parameter must not be a NULL pointer.	
// @@ - '_result' parameter must not be a NULL pointer.	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_189::argv_257 (uint8_t * _key, uint8_t * _block, uint8_t * _result) {
	bool bret = true;
	if ((_key == NULL) || (_block == NULL) || (_result == NULL)) {
		bret = false;
	}
	else {
		argv_609 	= _key;
		argv_182 	= _block;
		argv_745	= _result;	
		argv_721 ();
#if defined (__DEBUG_DES__)		
		argv_240 ("before", argv_182, 8);
#endif		
		argv_242 ();
		argv_761 ();
		for (argv_226=0 ; argv_226<16 ; argv_226++) {
			argv_243 ();
		}
		argv_655 ();
		argv_777 ();
#if defined (__DEBUG_DES__)		
		argv_240 ("after", argv_745, 8);
#endif		
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_189	
// @@
// @@ FUNCTION		:	argv_232	
// @@
// @@ INPUT			:	
// @@ _key: uint8_t *: the 64 bit argv_609 to be used for the operation.
// @@ 
// @@ _block: uint8_t *: the 64 bit argv_182 to decipher.
// @@
// @@ _result: uint8_t *: the buffer containing the argv_745 of the 
// @@    operation.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:
// @@ bool: true if operation was succesful, false otherwise.	
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function decipher the 64 bit argv_182 given as the 
// @@ '_block' parameter using the 64 bit argv_609 given as the
// @@ '_key' parameter, argv_745 being stored into the '_result'
// @@ parameter as a 64 bit argv_182.
// @@
// @@ The algorithm consists in :
// @@ - pre-computing the argv_609 schedule using the argv_609 as an input.
// @@ - perform the initial permutation for the input argv_182.
// @@ - perform 16 rounds of decipherment.
// @@ - undo the initial permutation for the argv_745 argv_182.
// @@
// @@ CONTRACT		:	
// @@ - '_key'    parameter must not be a NULL pointer.
// @@ - '_block'  parameter must not be a NULL pointer.	
// @@ - '_result' parameter must not be a NULL pointer.	
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_189::argv_232 (uint8_t * _key, uint8_t * _block, uint8_t * _result) {
	bool bret = true;
	if ((_key == NULL) || (_block == NULL) || (_result == NULL)) {
		bret = false;
	}
	else {
                argv_609     = _key;
                argv_182   = _block;		
                argv_745  = _result;
                argv_721 ();
#if defined (__DEBUG_DES__)		
                argv_240 ("before", argv_182, 8);
#endif		
		argv_242 ();
#if defined (__DEBUG_DES__)		
                argv_240 ("after initial permutation", argv_745, 8);
#endif		
		argv_761 ();
#if defined (__DEBUG_DES__)		
		argv_240 ("L16", (uint8_t *)&argv_616.argv_166, 4);
		argv_240 ("R16", (uint8_t *)&argv_750.argv_166, 4);
#endif		
		for (argv_226=15 ; argv_226>=0 ; argv_226--) {
			argv_244 ();
		}
		argv_655 ();
		argv_777 ();
#if defined (__DEBUG_DES__)		
		argv_240 ("after", argv_745, 8);
#endif		
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
