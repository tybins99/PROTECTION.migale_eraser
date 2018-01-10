// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_137.hpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains all objects, and functions
// @@ that might be used throughout several 
// @@ different projects.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../lib/argv_137.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_190	
// @@
// @@ FUNCTION		:	argv_190				
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
// @@ Normal constructor of the 'argv_190' object.
// @@ It prepares the object before first use by
// @@ calibrating it.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_190::argv_190() {
	LARGE_INTEGER liFrequency;
	QueryPerformanceFrequency(&liFrequency);
	argv_635 = liFrequency.QuadPart;

	argv_762(); // Calibration
	argv_764();
	argv_634 = argv_633.QuadPart-argv_632.QuadPart;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_190	
// @@
// @@ FUNCTION		:	argv_762				
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
// @@ This function permits to argv_762 the precision counter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_190::argv_762() {
	// Ensure we will not be interrupted by any other thread for a while
	// Sleep(0);
	QueryPerformanceCounter(&argv_632);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_190	
// @@
// @@ FUNCTION		:	argv_764				
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
// @@ This function permits to argv_764 the precision counter.
// @@ To obtain the elapsed duration, you may use either the
// @@ function 'argv_315' or 'argv_765'
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_190::argv_764() {
	QueryPerformanceCounter(&argv_633);
}

uint8_t argv_190::argv_324 () {
	LARGE_INTEGER m_lirand;
	QueryPerformanceCounter(&m_lirand);
	srand (m_lirand.QuadPart);
	uint8_t nb_wait = rand ();
	Sleep (nb_wait);
	return (uint8_t)(m_lirand.QuadPart);
}

uint32_t argv_190::argv_325 () {
	LARGE_INTEGER m_lirand;
	QueryPerformanceCounter(&m_lirand);
	srand (m_lirand.QuadPart);
	uint8_t nb_wait = rand ();
	Sleep (nb_wait);
	return (uint32_t)(m_lirand.QuadPart);
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_190	
// @@
// @@ FUNCTION		:	argv_315			
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ double: the elapsed time between the call to the 'argv_762' function
// @@         the unit being the microsecond.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the time elapsed between the 
// @@ to argv_762 and argv_764. The extracted duration's unit is the 
// @@ microsecond.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
double argv_190::argv_315() const {
	return (double)(argv_633.QuadPart-argv_632.QuadPart-argv_634)*1000000.0 / argv_635;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_190	
// @@
// @@ FUNCTION		:	argv_765				
// @@
// @@ INPUT			:	
// @@ _msg: const char *: the message to use when formatting the elapsed 
// @@       time expressed in microseconds.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the elapsed time between the call to argv_762 and
// @@   this function, coming along with the message given by
// @@   the '_msg' parameter.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to do the argv_764 and the argv_315
// @@ in a unique call, the argv_745 being a string composed of
// @@ the messages given by the '_msg' parameter, coming along
// @@ with the elapsed time expressed in microseconds.
// @@ NOTICE: if you decide to use this function, you don't need
// @@         to call the 'argv_764' function, the argv_764 will be done
// @@         by the 'argv_765' function itself.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_190::argv_765 (const char * _msg) {
	argv_764 ();
	double elapsed = argv_315 ();
	char tmp[MAX_PATH];
	if (elapsed < 1000000.0) {
		argv_760 (tmp, 1024, "%s : %lf microseconds", _msg, elapsed);
	}
	else if ((elapsed >= 1000000.0) && (elapsed < 60000000.0)) {
		elapsed = elapsed / 1000000.0;
		argv_760 (tmp, 1024, "%s : %lf seconds", _msg, elapsed);
	}
	else {
		elapsed = elapsed / 60000000.0;
		argv_760 (tmp, 1024, "%s : %lf minutes", _msg, elapsed);
	}
	tmp[1024 - 1] = '\0';
	return tmp;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_282			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to check.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file whose name is given by the '_filename'
// @@       parameter is read only, 
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to determine whether the file whose 
// @@ name is given by the '_filename' parameter is read-only or not.
// @@ The argv_745 of the test is given as a return value.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_282 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_READONLY)) {
		bret = true;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_740			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to check.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the read-only protection for the file whose name
// @@       is given as the '_filename' parameter has been succesfuly
// @@       removed,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to remove the read-only protection of
// @@ the file whose name is given as the '_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_740 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_READONLY)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_READONLY;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_281			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to check.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file whose name is given as the '_filename'
// @@       parameter is a hidden file,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to determine whether the file whose
// @@ name is given by the parameter '_filename' is hidden or not.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_281 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_HIDDEN)) {
		bret = true;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_283			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to check.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file whose name is given as the '_filename'
// @@       parameter is a system file,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to determine whether the file whose
// @@ name is given by the parameter '_filename' is a 
// @@ system file or not.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_283 (const char * _filename) {
	bool bret = false;

	DWORD dwAttrs; 
	dwAttrs = GetFileAttributes (_filename); 
	if ((dwAttrs != -1) && (dwAttrs & FILE_ATTRIBUTE_SYSTEM)) {
		bret = true;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_739			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to consider.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the hidden attibute was succesfuly removed,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to remove the hidden attribute for
// @@ the file whose name is given as the '_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_739 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_HIDDEN)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_HIDDEN;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_741			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to consider.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the system attibute was succesfuly removed,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to remove the system attribute for
// @@ the file whose name is given as the '_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_741 (const char * _filename) {
	bool bret = true;

	DWORD dwAttrs;
	dwAttrs = GetFileAttributes (_filename); 
	if (dwAttrs == -1) {
		bret = false;
	}
	else {
		if (!(dwAttrs & FILE_ATTRIBUTE_SYSTEM)) {
			bret = false;
		}
		else {
			dwAttrs &= ~FILE_ATTRIBUTE_SYSTEM;
			if (! SetFileAttributes (_filename, dwAttrs)) {
				int iret = GetLastError();
				bret = false;	
			}
			else {
				bret = true;
			}
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_280			
// @@
// @@ INPUT			:	
// @@ _filename: const char *: name of the file to consider.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file whose name is given as the '_filename'
// @@       parameter exists on the file system,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to check whether the file whose name
// @@ is given as the '_filename' parameter exists on the file
// @@ system or not.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_280 (const char * _filename) {
	bool bret = false;
	FILE * argv_307 = fopen (_filename, "rb");
	if (argv_307) {
		bret = true;
		fclose (argv_307);
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_303			
// @@
// @@ INPUT			:	
// @@ _folder_name: const char *: name of the folder to consider.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the folder whose name is given as the '_folder_name'
// @@       parameter exists on the file system,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to check whether the folder whose name
// @@ is given as the '_folder_name' parameter exists on the file
// @@ system or not.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_303 (const char * _folder_name) {
	bool bret = false;
	DWORD attr = GetFileAttributes (_folder_name);
	if (attr != argv_606) {
		if (attr & FILE_ATTRIBUTE_DIRECTORY) {
			bret = true;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_303			
// @@
// @@ INPUT			:	
// @@ _folder_name: const char *: name of the folder to consider.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	
// @@ _size: uint32_t: extracted size of the file.
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file size was succesfuly retrieved,
// @@       false otherwise.	
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to retrieve the size of the file whose
// @@ name is given as the '_filename' parameter, the argv_745 being
// @@ stored into the argv_745 parameter '_size'.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_318 (const char * _filename, uint32_t& _size) {
	bool bret = true;
	_size = 0;

	if (strlen(_filename) > 0) {
		FILE * argv_307 = fopen (_filename, "rb");
		if (argv_307) {
			fseek (argv_307, 0, SEEK_END);
			_size = ftell (argv_307);
			fclose (argv_307);
		}
		else {
			bret = false;
		}
	}
	else {
		bret = false;
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_663			
// @@
// @@ INPUT			:	
// @@ const char *: _current_filename: name of the argv_226 file.
// @@
// @@ const char *: _new_filename: new name of the file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the file '_current_filename' has been 
// @@       succesfully moved to the file '_new_filename'.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to move the file whose name is 
// @@ given as the '_current_filename' parameter, to the
// @@ file whose new name is given as the '_new_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_663 (const char * _current_filename, const char * _new_filename) {
	bool bret = true;
	if (argv_280 (_new_filename) == true) {
		if (DeleteFile (_new_filename) ==0) {
			bret = false;
		}
	}

	if (bret == true) {
		if (MoveFile (_current_filename, _new_filename) == 0) {
			char tmp[256];
			argv_760 (tmp, 256, "MoveFile failed (error: %d)", GetLastError());
			tmp[256 - 1] = '\0';
			MessageBox (NULL, tmp, "", MB_ICONERROR);
			bret = false;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_216			
// @@
// @@ INPUT			:	
// @@ _buf: uint8_t *: address of the first byte of the mmapped file.
// @@
// @@ _size: uint32_t: size of the mmapped file.
// @@
// @@ _dest_filename: const char *: name of the new file that must has
// @@   the same content as the mmapped file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the copy was succesful,
// @@       false otherwise.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to create a copy of the file that was
// @@ previously mmapped, the content of the file to copy can be 
// @@ found from the '_buf' parameter, the file size being given
// @@ by the '_size' parameter, the name of the copied file is
// @@ given by the '_dest_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_216 (uint8_t * _buf, uint32_t _size, const char * _dest_filename) {
	bool bret = true;
	FILE * fp_dest = fopen (_dest_filename, "wb");
	if (! fp_dest) {
		bret = false;
	}
	else {
		if (fwrite (_buf, 1, _size, fp_dest) != _size) {
			bret = false;	
		}

		if (fclose (fp_dest) != 0) {
			bret = false;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_215			
// @@
// @@ INPUT			:
// @@ _name: const char *: the original file/folder name
// @@ 
// @@ _max_size: uint32_t: maximum size of the file/folder name	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the file/folder name reduced to fit into the 	
// @@	      window whose size is given as the '_max_size' parameter.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to generate a argv_302 whose length
// @@ is reduced to fit into the '_max_size' window.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_215 (const char * _name, uint32_t _max_size) {
	string modified_name;
	uint32_t size = strlen (_name);
	if (size < _max_size) {
		modified_name = _name;	
	}
	else {
		uint32_t block_size = (_max_size - 2) / 2;
		uint32_t argv_762;
		for (argv_762=0 ; argv_762 < block_size ; argv_762++) {
			modified_name += _name[argv_762];	
		}
		modified_name += "..";
		for (argv_762=size-block_size ; argv_762 <size ; argv_762++) {
			modified_name += _name[argv_762];
		}
	}
	return (modified_name);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_271			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to work on.
// @@ 
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the argv_302 without it's extension.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to generate the argv_302 without
// @@ it's extension, starting from the original argv_302
// @@ given by the '_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_271 (const char * _filename) {
	string argv_745;
	uint32_t size = strlen (_filename);
	uint32_t argv_764;
	for (argv_764=0 ; argv_764 < size ; argv_764++) {
		if (_filename[argv_764] == '.') {
			break;
		}
		else {
			argv_745 += _filename[argv_764];
		}
	}
	return (argv_745);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_749			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to work on.
// @@ 
// @@ _type: uint32_t: determine what to retrieve out of :
// @@ - argv_219	: retrieve creation time and date
// @@ - argv_786	: retrieve last write time and date
// @@ - argv_736		: retrieve last read time and date
// @@
// @@ OUTPUT		:	
// @@ _year: uint32_t: the year related to the file.
// @@ 
// @@ _month: uint32_t: the month related to the file.
// @@
// @@ _day: uint32_t: the day related to the file
// @@
// @@ _hour: uint32_t: the hour related to the file
// @@
// @@ _minute: uint32_t: the minute related to the file
// @@
// @@ _second: uint32_t: the second related to the file
// @@
// @@ _ercode: uint32_t: the error code if any error occured
// @@
// @@ _ersource: uint32_t: the error source if any error occured.
// @@ 
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract either the creation date and 
// @@ time, or the last read or write date and time, depending on the
// @@ '_type' parameter, of the file whose name is given by the 
// @@ '_filename' parameter. If any error occurs, the error reason
// @@ and location is returned via the arguments '_ercode' and
// @@ '_ersource'.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_749 (signed char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t _type, uint32_t& _ercode, uint32_t& _ersource) {
	bool bret = true;
    FILETIME ftCreate, ftAccess, ftWrite;
    SYSTEMTIME stUTC, stLocal;
	
	HANDLE argv_329 = CreateFileA((const char *)_filename,      // file to open
					   GENERIC_READ,          // open for reading
					   FILE_SHARE_READ,       // share for reading
					   NULL,                  // default security
					   OPEN_EXISTING,         // existing file only
					   FILE_ATTRIBUTE_NORMAL, // normal file
					   NULL);                 // no attr. template

	if (argv_329 == INVALID_HANDLE_VALUE) {
		_ersource = 1;
		_ercode = GetLastError ();
		bret = false;
	}
	else { // file opened succesfully
		// Retrieve the file times for the file.
		if (!GetFileTime(argv_329, &ftCreate, &ftAccess, &ftWrite)) {
			_ercode = GetLastError ();
			_ersource = 2;
			bret = false;
		}
		else { // retrieval succesfull, let's retrieve data depending on the access mode 
			switch (_type) {
				case argv_219:
					FileTimeToSystemTime(&ftCreate, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_786:
					FileTimeToSystemTime(&ftWrite, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				case argv_736:
					FileTimeToSystemTime(&ftAccess, &stUTC);
					SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
					break;

				default: // unknown file access type
					bret = false;
			}

			if (bret == true) {
				_year			= stLocal.wYear;
				_month			= stLocal.wMonth;
				_day			= stLocal.wDay;
				_hour			= stLocal.wHour;
				_minute			= stLocal.wMinute;
				_second			= stLocal.wSecond;
				_millisecond	= stLocal.wMilliseconds;
			}
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_746			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to work on.
// @@ 
// @@ OUTPUT		:	
// @@ _year: uint32_t: the year related to the file.
// @@ 
// @@ _month: uint32_t: the month related to the file.
// @@
// @@ _day: uint32_t: the day related to the file
// @@
// @@ _hour: uint32_t: the hour related to the file
// @@
// @@ _minute: uint32_t: the minute related to the file
// @@
// @@ _second: uint32_t: the second related to the file
// @@
// @@ _ercode: uint32_t: the error code if any error occured
// @@
// @@ _ersource: uint32_t: the error source if any error occured.
// @@ 
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the creation date and 
// @@ time, of the file whose name is given by the 
// @@ '_filename' parameter. If any error occurs, the error reason
// @@ and location is returned via the arguments '_ercode' and
// @@ '_ersource'.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_746 (signed char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_749 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_219, _retcode, _ersource));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_747			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to work on.
// @@ 
// @@ OUTPUT		:	
// @@ _year: uint32_t: the year related to the file.
// @@ 
// @@ _month: uint32_t: the month related to the file.
// @@
// @@ _day: uint32_t: the day related to the file
// @@
// @@ _hour: uint32_t: the hour related to the file
// @@
// @@ _minute: uint32_t: the minute related to the file
// @@
// @@ _second: uint32_t: the second related to the file
// @@
// @@ _ercode: uint32_t: the error code if any error occured
// @@
// @@ _ersource: uint32_t: the error source if any error occured.
// @@ 
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the last read date and 
// @@ time, of the file whose name is given by the 
// @@ '_filename' parameter. If any error occurs, the error reason
// @@ and location is returned via the arguments '_ercode' and
// @@ '_ersource'.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_747 (signed char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_749 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_736, _retcode, _ersource));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_748			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to work on.
// @@ 
// @@ OUTPUT		:	
// @@ _year: uint32_t: the year related to the file.
// @@ 
// @@ _month: uint32_t: the month related to the file.
// @@
// @@ _day: uint32_t: the day related to the file
// @@
// @@ _hour: uint32_t: the hour related to the file
// @@
// @@ _minute: uint32_t: the minute related to the file
// @@
// @@ _second: uint32_t: the second related to the file
// @@
// @@ _ercode: uint32_t: the error code if any error occured
// @@
// @@ _ersource: uint32_t: the error source if any error occured.
// @@ 
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if operation was succesful,
// @@       false otherwise.
// @@	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the last write date and 
// @@ time, of the file whose name is given by the 
// @@ '_filename' parameter. If any error occurs, the error reason
// @@ and location is returned via the arguments '_ercode' and
// @@ '_ersource'.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_748 (signed char * _filename, uint32_t& _year, uint32_t& _month, uint32_t& _day, uint32_t& _hour, uint32_t& _minute, uint32_t& _second, uint32_t& _millisecond, uint32_t& _retcode, uint32_t& _ersource) {
	return (argv_749 (_filename, _year, _month, _day, _hour, _minute, _second, _millisecond, argv_786, _retcode, _ersource));
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_255			
// @@
// @@ INPUT			:	
// @@ _hwnd: HWND: the handler of the window of the control.
// @@
// @@ _idc: long: the unique identifier of the control in it's window. 
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
// @@ This function permits to enable the control whose unique
// @@ identifier is given by the '_idc' parameter, and which
// @@ pertains to the window whose handle is given by the '_hwnd'
// @@ parameter. The control is then enabled, and thus the user 
// @@ can interact with it.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_255 (HWND _hwnd, long _idc) {
	HWND button_hwnd = GetDlgItem (_hwnd, _idc); 
	EnableWindow (button_hwnd, TRUE);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_235			
// @@
// @@ INPUT			:	
// @@ _hwnd: HWND: the handler of the window of the control.
// @@
// @@ _idc: long: the unique identifier of the control in it's window. 
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
// @@ This function permits to disable the control whose unique
// @@ identifier is given by the '_idc' parameter, and which
// @@ pertains to the window whose handle is given by the '_hwnd'
// @@ parameter. The control is then disabled, and thus the user 
// @@ can not interact with it, even though it is visible.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_235 (HWND _hwnd, long _idc) {
	HWND button_hwnd = GetDlgItem (_hwnd, _idc); 
	EnableWindow (button_hwnd, FALSE);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_253			
// @@
// @@ INPUT			:	
// @@ _dump_filename: const char *: name of the dump file to create.
// @@
// @@ _ptr: uint8_t *: address of the first byte of the mmapped file.
// @@ 
// @@ _size: uint32_t: size of the mmaped file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the dump was succesful, false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to dump the content of a mmapped file
// @@ to a file on the file system.
// @@ The address of the first byte of the mmapped file is given
// @@ by the '_ptr' parameter, the size of the mmaped file is given
// @@ by the '_size' parameter, and the dump must be saved into the 
// @@ file whose name is given by the '_dump_filename' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_253 (const char * _dump_filename, uint8_t * _ptr, uint32_t _size) {
	bool bret = true;
	FILE * argv_307 = fopen (_dump_filename, "wb");
	if (! argv_307) {
		bret = false;
	}
	else {
		if (fwrite (_ptr, 1, _size, argv_307) != _size) {
			bret = false;
		}
		fclose (argv_307);
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_273			
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to use for extraction.	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the argv_745 of the extraction.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the folder of a given argv_302.
// @@ For example : "C:\\abc\\cde\\toto.txt" -> "C:\\abc\\cde\\"
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_273 (const char * _filename) {
	string argv_745;
	uint32_t size = strlen (_filename);
	if (size > 0) {
		uint32_t argv_762;
		for (argv_762=size-1 ; argv_762>=0 ; argv_762--) {
			if (_filename[argv_762] == '\\') {
				break;		
			}
		}

		for (uint32_t i=0 ; i<=argv_762 ; i++) {
			argv_745 += _filename[i];	
		}
	}
	return (argv_745);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_644			
// @@
// @@ INPUT			:
// @@ _root: const char *: folder from where to create the md5 folder.
// @@
// @@ _md5: md5 sum of the file whose folder is to be created.
// @@
// @@ OUTPUT		:	
// @@ _abs_folder_name: string: the name of the absolute folder created.
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the MD5 folder creation was succesful,	
// @@	    false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to create the MD5 folder of a file whose 
// @@ md5 sum is given by the '_md5' parameter, the md5 folder should
// @@ be created from the '_root' folder, and the absolute name of
// @@ the folder created is saved into the '_abs_folder_name' 
// @@ parameter.
// @@ The MD5 folder is the ventilated folder as follows 
// @@ (for the example we use a shorter MD5 sum) :
// @@ "F46A6" -> F/4/6/A/6
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_644 (const char * _root, const char * _md5, string& _abs_folder_name) {
	bool bret = true;
	if (strlen (_md5) != 32) {
		bret = false;
	}
	else {
		if (argv_303 (_root) == false) {
			if (argv_222(_root) == false) {
				bret = false;
			}
		}

		if (bret == true) {
			uint32_t i=0;
			_abs_folder_name = _root;
			for (i=0 ; i<32 ; i=i+1) {
				_abs_folder_name = _abs_folder_name + "\\" + _md5[i];
				if (argv_303 (_abs_folder_name.c_str()) == false) {
					if (argv_222 (_abs_folder_name.c_str()) == false) {
						bret = false;
						break;
					}
				}
			}
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_220			
// @@
// @@ INPUT			:
// @@ _path: const char *: name of the path to create.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the folders were succesfuly created, 
// @@       false otherwise.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to create all the folders along
// @@ the path that is given as the '_path' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_220 (const char * _path) {
	bool bret = true;
	uint32_t size = strlen (_path);
	string argv_226;
	uint32_t i;
	uint32_t last_size = 0;
	uint32_t current_size;
	if ((size < 3) || (_path[1] != ':') || (_path[2] != '\\')) {
		bret = false;
	}
	else {	
		for (i=0 ; i<size ; i++) {
			if (i < 3) {
				argv_226 += _path[i];
			}
			else {
				if ((_path[i] == '\\') || (_path[i] == '/')) {
					current_size = argv_226.size();
					if ((current_size > 0) && (current_size > last_size)) {
						bret = argv_222 (argv_226.c_str());
						if (bret == false) {
							break;
						}
						else {
							last_size = current_size;
						}
					}
				}
				argv_226 += _path[i];
			}
		}
	}

	if ((bret == true) && (argv_226.size() > last_size)) {
		bret = argv_222 (argv_226.c_str());	
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_222			
// @@
// @@ INPUT			:
// @@ _folder_name: const char *: name of the folder to create.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the folder was succesfuly created, 
// @@       false otherwise.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to create the folder whose name
// @@ is given as the '_folder_name' parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_222 (const char * _folder_name) {
	bool bret = true;
	if (argv_303 (_folder_name) == false) {
		if (CreateDirectory (_folder_name, NULL) == 0) {
			bret = false;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_234			
// @@
// @@ INPUT			:
// @@ _abs_root: const char *: abolute folder name from where to argv_762
// @@
// @@ _rel_root: const char *: relative folder name from where to argv_762
// @@
// @@ _md5: const char *: md5 sum of the file whose folder is to be developped.
// @@
// @@ OUTPUT		:	
// @@ _rel_folder_name: string: developped relative folder name.	
// @@
// @@ _abs_folder_name: string: developped absolute folder name.	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to generate the developped md5 folder
// @@ name from the root folder whose absolute name is given by
// @@ the '_abs_root' parameter, and whose relative name is given
// @@ by the '_rel_root' parameter, the md5 sum being given by the
// @@ '_md5' parameter. 
// @@ The developped folder name is saved into the '_rel_folder_name'
// @@ for the relative version, and into the '_abs_folder_name' 
// @@ parameter for the absolute version. 
// @@ The MD5 folder is the ventilated folder as follows 
// @@ (for the example we use a shorter MD5 sum) :
// @@ "F46A6" -> F/4/6/A/6
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_234 (const char * _abs_root, const char * _rel_root, const char * _md5, string& _rel_folder_name, string& _abs_folder_name) {
	_abs_folder_name = _abs_root;
	_rel_folder_name = _rel_root;
	for (uint32_t i=0 ; i<32 ; i=i+1) {
		_abs_folder_name = _abs_folder_name + "\\" + _md5[i];
		_rel_folder_name = _rel_folder_name + "/" + _md5[i];
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_646			
// @@
// @@ INPUT			:
// @@ _abs_root: const char *: abolute folder name from where to argv_762
// @@
// @@ _rel_root: const char *: relative folder name from where to argv_762
// @@
// @@ _md5: const char *: md5 sum of the file whose folder is to be developped.
// @@
// @@ OUTPUT		:	
// @@ _rel_folder_name: string: developped relative folder name.	
// @@
// @@ _abs_folder_name: string: developped absolute folder name.	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if the developped MD5 folder exists,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to generate the developped md5 folder
// @@ name from the root folder whose absolute name is given by
// @@ the '_abs_root' parameter, and whose relative name is given
// @@ by the '_rel_root' parameter, the md5 sum being given by the
// @@ '_md5' parameter. 
// @@ The developped folder name is saved into the '_rel_folder_name'
// @@ for the relative version, and into the '_abs_folder_name' 
// @@ parameter for the absolute version. 
// @@ The MD5 folder is the ventilated folder as follows 
// @@ (for the example we use a shorter MD5 sum) :
// @@ "F46A6" -> F/4/6/A/6
// @@ Of course the function also permits to determine whether this
// @@ md5 folder exists or not.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_646 (const char * _abs_root, const char * _rel_root, const char * _md5, string& _rel_folder_name, string& _abs_folder_name) {
	bool bret = false;
	argv_234 (_abs_root, _rel_root, _md5, _rel_folder_name, _abs_folder_name);
	bret = argv_303 (_abs_folder_name.c_str());
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_188	
// @@
// @@ FUNCTION		:	argv_188			
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
// @@ Normal constructor of the 'argv_188' object.
// @@ it resets necessary fields to their initial value.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_188::argv_188() {
	hwnd	= 0;
	argv_639		= 0;
	argv_345		= 0;	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_188	
// @@
// @@ FUNCTION		:	init			
// @@
// @@ INPUT			:	
// @@ _hwnd: HWND: handle of the window where the bar is located.
// @@
// @@ _idc: int: unique identifier of the progress bar.
// @@ 
// @@ _max: int: maximum position of the progress bar.
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
// @@ This function permits to argv_723 the progress bar
// @@ before it's first use.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_188::init (HWND _hwnd, int _idc, int _max) {
	hwnd	= _hwnd;
	argv_639		= _max;
	argv_345		= _idc;
	argv_226	= 0;
	reset();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_188	
// @@
// @@ FUNCTION		:	incr			
// @@
// @@ INPUT			:	
// @@ _nb_step: int32_t: the number of steps to use to increment
// @@                 the position of the progress bar.
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
// @@ This function permits to move the progress bar of 
// @@ '_nb_step' positions toward the right.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_188::incr (int32_t _nb_step) {
	argv_226 += _nb_step;
	SendDlgItemMessage (hwnd, argv_345, PBM_SETPOS, argv_226, 0);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_188	
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
// @@ This function permits to bring the progress bar back
// @@ to it's initial position on the left.
// @@ beware though that the bar is still useable even after
// @@ a reset (argv_345 and hwnd members are not reseted)
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_188::reset() {
	SendDlgItemMessage (hwnd, argv_345, PBM_SETRANGE32, 0, argv_639); 
	argv_226 = 0;
	SendDlgItemMessage (hwnd, argv_345, PBM_SETPOS, argv_226, 0);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_685			
// @@
// @@ INPUT			:
// @@ _opa_result: uint8_t: the argv_745 of the last operation.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the last operation as a human-readable string.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function converts the '_opa_result' parameter into
// @@ a human-readable string.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_685 (uint8_t _opa_result) {
	string s;
	switch (_opa_result) {
		case argv_682:		s = "Not Done";		break;
		case argv_678:			s = "Done";			break;
		case argv_679:		s = "Failed";		break;
		case argv_683:		s = "Not Found";	break;
		case argv_686:			s = "Used";			break;
		case argv_684:		s = "Not Used";		break;
		case argv_681:			s = "None";			break;
		case argv_687:			s = "Yes";			break;
		case argv_680:			s = "No";			break;

		default:				s = "<unknown case>";
	}
	return (s);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_284			
// @@
// @@ INPUT			:
// @@ _type: uint32_t: the type of the file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the type of the file converted into a 
// @@         human-readable string.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function converts the '_type' parameter into
// @@ a human-readable string. This parameter being the
// @@ numeric value that uniquely identifies a given file type.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_284 (uint32_t _type) {
	string s;
	switch (_type) {
		case argv_295:				s = "NOT_KNOWN";			break;
		case argv_291:						s = "JPG";					break;
		case argv_290:						s = "GIF";					break;	
		case argv_287:						s = "BMP";					break;
		case argv_294:					s = "MPEG";					break;
		case argv_293:						s = "MP3";					break;
		case argv_300:						s = "WMV";					break;
		case argv_296:						s = "TXT";					break;
		case argv_299:				s = "TXT_UTF8";				break;
		case argv_297:				s = "UNICODE";				break;
		case argv_298:	s = "UNICODE_BIG_ENDIAN";	break;
		case argv_289:						s = "EXE";					break;			
		case argv_301:						s = "ZIP";					break;	
		case argv_286:						s = "AVI";					break;
		case argv_285:						s = "ASF";					break;
		case argv_292:					s = "MICROSOFT";			break;

		default: s = "<undefined>";
	}
	return (s);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
