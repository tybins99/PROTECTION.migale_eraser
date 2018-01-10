// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ INCLUDES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "argv_140.hpp"


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ EXTERNAL VARIABLES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if defined (__GUI_RC4__)
	extern HWND				argv_738;
	extern unsigned long	argv_515;
	extern unsigned long	argv_488;
	extern unsigned long	argv_490;
	extern void argv_236 (bool, bool);
	extern void argv_256 (bool, bool); 
#endif // __GUI_RC4__


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ GLOBAL VARIABLES
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_195 argv_328;


void argv_195::argv_265 () {
	FILE * fp_dest = fopen ("C:\\bootleg.bin", "wb");
	if (fp_dest) {
		fwrite (argv_328.argv_733, argv_734, 1, fp_dest);
		fclose (fp_dest);
	}
}
//-------------------------------------------

argv_218::argv_218 () {
	argv_722 = false;
}

void argv_218::argv_726 (vector<uint8_t>& _v_key) {
	for (uint32_t i=0 ; i<argv_730 ; i++) {
		argv_631[i] = _v_key[i]; // modulo is automatic (stored into a byte)			
	}
}

void argv_218::argv_259 (vector<uint8_t>& _v_key) {
	SYSTEMTIME argv_771;
	GetLocalTime (&argv_771);
	srand (argv_771.wMilliseconds);

	uint32_t size = _v_key.size ();
	// overwrite
	for (uint32_t i=0 ; i<size ; i++) {
		_v_key[i] = rand();	
	}
	//... and erase
	_v_key.clear ();

	for (int32_t i=0 ; i<argv_730 ; i++) {
		argv_631[i] = rand();	
	}
}

void argv_218::argv_610 (vector<uint8_t>& _v_key) {
	uint32_t i;
	for (i=0 ; i<argv_754 ; i++) {
		argv_637[i] = i;
	}
	
	argv_726 (_v_key);

	uint8_t j = 0; // automatic modulo
	uint8_t tmp;
	uint32_t key_index;
	for (i=0 ; i<argv_754 ; i++) {
		key_index = i % argv_730;
		j = j + argv_637[i] + argv_631[key_index];
		// swap S[i],S[j]
		tmp				= argv_637[i];
		argv_637[i]	= argv_637[j];
		argv_637[j]	= tmp;
	}
	argv_259 (_v_key);
}

bool argv_218::argv_723 (vector<uint8_t>& _v_key) {
	bool bret = true;
	if (_v_key.size() != argv_730) {
		bret = false;
	}
	else {	
		argv_610 (_v_key);

		argv_629		= 0;
		argv_630		= 0;
		argv_722	= true;	
	}
	return (bret);
}

void argv_218::argv_723 (argv_218& _rc4) {
	uint32_t i=0;
	vector<uint8_t> v_key;
	for (i=0 ; i<argv_730 ; i++) {
		v_key.push_back (_rc4.argv_323 ());
	}
	argv_723 (v_key);
}

bool argv_218::argv_608 () {
	return (argv_722);
}

//--------------------------------
DWORD WINAPI argv_252 (LPVOID lParam) {
	uint32_t current_thread = (uint32_t) GetCurrentThread ();
	argv_190 bench;
	SYSTEMTIME argv_771;
	GetLocalTime (&argv_771);
	srand (current_thread + argv_771.wMilliseconds);
	// add some randomness to the argv_745 buffer
	for (uint32_t i=0 ; i<argv_734 ; i++) {
		argv_328.argv_733[i] += rand ();
	}
	GetLocalTime (&argv_771);
	srand (argv_771.wMilliseconds);
#if defined (__RC4_USE_DES__)
	argv_189 des;
	uint32_t nb_block = argv_648 / argv_233;
	uint32_t nb_block_chosen = rand() % nb_block;
	uint32_t index_key, index_src, index_dest;
	for (int32_t i=0 ; i<nb_block_chosen ; i++) {
		index_key	= (rand() % nb_block) * argv_233;
		index_src	= (rand() % nb_block) * argv_233;
		index_dest	= (rand() % nb_block) * argv_233;
		des.argv_232 (&argv_328.argv_733[index_key], &argv_328.argv_733[index_src], &argv_328.argv_733[index_dest]);
	}
#endif // __RC4_USE_DES__

	// wait for the argv_762 signal
	while (argv_328.argv_763 == false) {
		Sleep (0);
	}

	uint32_t index;
	uint32_t srand_seed;
	uint8_t val;
	for (uint32_t k=0 ; k<argv_735 ; k++) {
		for (int32_t i=0 ; i<argv_734 ; i++) {
			bench.argv_762 ();
			Sleep (0);
			bench.argv_764 ();
			srand_seed = (uint32_t) bench.argv_315 ();
			index = (srand_seed * argv_328.argv_733[index] * rand()) % argv_734;

			if ((index %2) == 0) {
				argv_328.argv_733[index] += rand ();
			}
			else {
				val = rand ();
				argv_328.argv_733[index] = argv_328.argv_733[index] ^ val;
			}
		}
	}
	return (0);
}

bool argv_224 () {
	bool bret = true;
	DWORD dwThreadId;
	HANDLE hThread; 
	hThread = CreateThread (NULL,0, argv_252, NULL, 0, &dwThreadId);
	if (hThread == NULL)   {
		MessageBox (NULL, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}
	else {
		argv_328.argv_782.push_back (hThread);
	}
	return (bret);
}

// the bootleg is a pseudo-randomly generated buffer that is generated
// using the fact that the thread scheduling and the system reaction time
// is unpredictable (depends on the system, the running processes, the CPU power,...)
void argv_724 () {
	// create all threads
	argv_328.argv_763 = false;
	for (uint32_t i=0 ; i<argv_732 ; i++) {
		argv_224 ();
	}
	Sleep (0); // let all the thread create themselves
	argv_328.argv_763 = true; // let threads argv_762

	// wait for all threads to finish their job
	for (int32_t i=0 ; i<argv_732 ; i++) {
		WaitForSingleObject (argv_328.argv_782[i], INFINITE);
	}
	argv_328.argv_782.clear ();
#if defined (__EVALUATE_RANDOMNESS_FLAG__)
	argv_328.argv_265 ();
#endif // __EVALUATE_RANDOMNESS_FLAG__
}

void argv_218::argv_311 (argv_218& _result_gen) {
	argv_218 bootleg_gen;
	argv_218 gen_tab[argv_670];
	uint8_t rand_buf[argv_648];
	uint32_t nb_done = 0;
	uint32_t i=0;
	uint8_t val;
	uint8_t md5_hash[argv_647];
	vector<uint8_t> v_key;
	uint32_t nb_bytes_to_avoid; // first bytes generated by the RC4 is unsafe 
	SYSTEMTIME argv_771;

	// generate a random buffer (not using a fixed seed)
	argv_724 ();
	// compute the MD5 hash of the random buffer 
	argv_210 (argv_328.argv_733, argv_734, md5_hash);
	// argv_723 the main bootleg generator using the MD5 hash previously computed
	for (i=0 ; i<argv_730 ; i++) {
		v_key.push_back (md5_hash[i % argv_648]);
	}
	bootleg_gen.argv_723 (v_key);

	GetLocalTime (&argv_771);
	srand (argv_771.wMilliseconds);
	nb_bytes_to_avoid = argv_671 + (rand() % argv_671);
	// avoid to use the first 256 bytes generated by the RC4
	for (i=0 ; i<nb_bytes_to_avoid ; i++) {
		bootleg_gen.argv_323 ();	
	}

	// argv_723 the bootleg generator set using the data generated by the
	// generator initialized using the MD5 hash previously computed
	for (i=0 ; i<argv_670 ; i++) {
		gen_tab[i].argv_723 (bootleg_gen);	
		// avoid to use the first 256 bytes generated by the RC4
		GetLocalTime (&argv_771);
		srand (argv_771.wMilliseconds);
		nb_bytes_to_avoid = argv_671 + (rand() % argv_671);
		for (uint32_t k=0 ; k<nb_bytes_to_avoid ; k++) {
			gen_tab[i].argv_323 ();	
		}
	}

	// generate a random buffer using the available set of bootleg generators
	for (i=0 ; i<argv_648 ; i++) {
		val = gen_tab[i % argv_670].argv_323 (); 
		rand_buf[i] = val;
	}

	// compute the MD5 hash of the random buffer
	argv_210 (rand_buf, argv_648, md5_hash);

	// init the true random generator with the bootleg MD5
	for (i=0 ; i<argv_730 ; i++) {
		v_key.push_back (md5_hash[i % argv_648]);
	}
	_result_gen.argv_723 (v_key);

	// avoid to use the first 256 bytes generated by the RC4
	GetLocalTime (&argv_771);
	srand (argv_771.wMilliseconds);
	nb_bytes_to_avoid = argv_671 + (rand() % argv_671);
	for (i=0 ; i<nb_bytes_to_avoid ; i++) {
		_result_gen.argv_323 ();	
	}
}


void argv_218::argv_728 () {
	argv_722 = false;
	argv_218 bootleg[argv_665];
	// generate the random bootlegs
	uint32_t i;
#if defined (__GUI_RC4__)
	argv_236 (true, true);
	argv_188 file_bar, argv_770;
	file_bar.init (argv_738, argv_488, argv_665);
	argv_770.init (argv_738, argv_490, argv_665);
#endif // __GUI_RC4__
	char disp_buf[256];
	for (i=0 ; i<argv_665 ; i++) {
#if defined (__GUI_RC4__)
		argv_760 (disp_buf, argv_237, "Random generator initialization (%u / %u)", i, argv_665);
		disp_buf[argv_237 - 1] = '\0';
		SendDlgItemMessage (argv_738, argv_515, WM_SETTEXT, 0, (LPARAM) disp_buf);
#endif // __GUI_RC4__
		argv_311 (bootleg[i]);
#if defined (__GUI_RC4__)
		file_bar.incr (1);
		argv_770.incr (1);
#endif // __GUI_RC4__ 
	}

	vector<uint8_t> v_key;
	uint8_t val;
	for (i=0 ; i<argv_730 ; i++) {
		// combine the results provided by all bootlegs to generate the argv_609
		for (uint32_t k=0 ; k<argv_665 ; k++) {
			if (k==0) {
				val = bootleg[i%argv_665].argv_323 ();
			}
			else {
				val = val ^ bootleg[i%argv_665].argv_323 ();
			}
		}
		v_key.push_back (val);
	}
	argv_723 (v_key);
	argv_722 = true;
#if defined (__GUI_RC4__)
	// clear the bars
	file_bar.init	(argv_738, argv_488, argv_665);
	argv_770.init (argv_738, argv_490, argv_665);
	argv_256 (true, true);
#endif // __GUI_RC4__
}

/*
i := 0
j := 0
while GeneratingOutput:
    i := (i + 1) mod 256
    j := (j + S[i]) mod 256
    swap(S[i],S[j])
    output S[(S[i] + S[j]) mod 256]
endwhile
*/
uint8_t argv_218::argv_323 () {
	uint8_t argv_745 = 0;
	uint8_t tmp;

	argv_629++;
	argv_630 = argv_630 + argv_637[argv_629];
	//swap(S[i],S[j])
	tmp = argv_637[argv_629];
	argv_637[argv_629] = argv_637[argv_630];
	argv_637[argv_630] = tmp;	
	
	uint8_t final_index = argv_637[argv_629] + argv_637[argv_630];
	argv_745 = argv_637[final_index];
	return (argv_745);
}

uint32_t argv_218::argv_322 () {
	uint32_t argv_745 = 0;
	for (uint32_t i=0 ; i<4 ; i++) {
		argv_178.argv_156[i] = argv_323 ();	
	}
	argv_745 = argv_178.argv_157;
	return (argv_745);
}

