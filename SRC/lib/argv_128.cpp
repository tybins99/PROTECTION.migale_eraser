// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_128.cpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains the object that permits
// @@ to mmap a given file on both win32 or Linux
// @@ OS.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../lib/argv_136.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_192		
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
// @@ Normal constructor of the argv_192 object.
// @@ it prepares the object to be used.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_192::argv_192() {
	argv_673		= 0;
#if defined (__WIN32_OS__) 
	argv_331	= NULL;
	argv_692		= NULL;
	argv_329		= NULL;
#endif // #if defined (__WIN32_OS__) 
#if defined (__LINUX_OS__)
	argv_661	= NULL;
	argv_662	= 0;
#endif // #if defined (__LINUX_OS__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	~argv_192		
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
// @@ destructor of the argv_192 object.
// @@ if a file was mmapped, then it is closed
// @@ and all opened descriptors are closed as well.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_192::~argv_192() {
	argv_208();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_208		
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
// @@ Destructor of the argv_192 object.
// @@ if a file was mmapped, then it is closed
// @@ and all opened descriptors are closed as well.
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_192::argv_208 () {
#if defined (__WIN32_OS__) 
		if (argv_692 != NULL) {
			UnmapViewOfFile (argv_692);
			argv_692 = NULL;
		}

		if ((argv_331 != NULL) && (argv_331 != INVALID_HANDLE_VALUE)) {
			CloseHandle (argv_331);
			argv_331 = NULL;
		}

		if ((argv_329 != NULL) && (argv_329 != INVALID_HANDLE_VALUE)) {
			CloseHandle (argv_329);
			argv_329 = NULL;
		}	
#endif // #if defined (__WIN32_OS__) 

#if defined (__LINUX_OS__)
		if (argv_661 != NULL) {    
			munmap (argv_661, argv_662);
			argv_661	= NULL;
			argv_662	= 0;
		}
#endif // #if defined (__LINUX_OS__)}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_320		
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	
// @@ _ercode: uint32_t& : the last error code.
// @@ _ersource: uint32_t&: the location of the last error (see source code).
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to retrieve the last error related data
// @@ - the error code (often obtained with errno or GetLastError)
// @@ - the error source permitting to know the exact location in
// @@   the source code where the error occured.
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_192::argv_320 (uint32_t& _ercode, uint32_t& _ersource) {
	_ercode		= argv_261;
	_ersource	= argv_264;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_321		
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ uint32_t: the number of ticks	that spent before the CreateFile
// @@       function returned, a tick being 250 millisecond.
// @@		This is necessary because sometimes, when a file has
// @@       just been closed and then reopened immediately, the 
// @@       has not finished yet to unmap the previous mapping, and
// @@       thus the mmap fails, the only thing we have to do is 
// @@       retry later, so this function permits to know how many
// @@       ticks it took before the mapping succeeded.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint32_t argv_192::argv_321 () {
	return (argv_673);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_656 (win32 version)		
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to map to memory
// @@ _open_mode: uint32_t: can be either 
// @@    - argv_658: file will be read only
// @@    - argv_659 : file will have read/write privilege.
// @@    - argv_660 : file will have read/execution privileges.
// @@
// @@ OUTPUT		:
// @@ _pBuf: uint8_t *&: address of the first byte of the file 
// @@                 after it was projected to memory.
// @@ 	
// @@ _file_size: uint32_t&: size of the file after it was projected 
// @@                    to memory.
// @@
// @@ IO			:	none	
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if success,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @2 This function permits to map to memory the file whose name
// @@ is given as the '_filename' parameter. 
// @@
// @@ CONTRACT 		: 
// @@ - no file should be currently mapped to memory (or ensure that
// @@   you call 'argv_208' before. 
// @@ - '_filename' parameter must not be a NULL pointer.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if defined (__WIN32_OS__) 
	bool argv_192::argv_656 (const char * _filename, uint32_t _open_mode, uint8_t *& _pBuf, uint32_t& _file_size, bool _fail_safe) {
		bool bret			= true;
		bool usage_error	= false;
		
		if (_filename == NULL) {
			argv_261		= 0;
			argv_264	= 99;
			bret			= false;
			usage_error		= true;
		}
		// if a file is already being mmapped, then we consider it as an error.
		else if (argv_329 != NULL) {
			argv_261		= 0;
			argv_264	= 100;
			bret			= false;
			usage_error		= true;
		}
		else if (argv_331 != NULL) {
			argv_261		= 0;
			argv_264	= 101;
			bret			= false;
			usage_error		= true;
		}
		else if (argv_692 != NULL) {
			argv_261		= 0;
			argv_264	= 102;
			bret			= false;
			usage_error		= true;
		}
		else { // file was not already opened
			DWORD access_mode_CreateFile;
			DWORD access_mode_CreateFileMapping;
			DWORD access_mode_MapViewOfFile;
			DWORD create_disposition;

			if (_open_mode == argv_658) {
				access_mode_CreateFile			= GENERIC_READ;	
				access_mode_CreateFileMapping	= PAGE_READONLY;
				access_mode_MapViewOfFile		= FILE_MAP_READ;
				create_disposition				= OPEN_EXISTING;
			}
			else if (_open_mode == argv_659) {
				access_mode_CreateFile			= GENERIC_READ | GENERIC_WRITE;
				access_mode_CreateFileMapping	= PAGE_READWRITE;
				access_mode_MapViewOfFile		= FILE_MAP_ALL_ACCESS;
				create_disposition				= OPEN_ALWAYS;
			}
			else if (_open_mode == argv_660) {
				access_mode_CreateFile			= GENERIC_READ | GENERIC_EXECUTE;	
				access_mode_CreateFileMapping	= PAGE_READONLY;
				access_mode_MapViewOfFile		= FILE_MAP_READ;
				create_disposition				= OPEN_ALWAYS;
			}

			if (_fail_safe == false) {
				argv_329 = CreateFile (_filename, access_mode_CreateFile,0,NULL,create_disposition,FILE_ATTRIBUTE_NORMAL,NULL);
			}
			else {
				argv_673 = 0;
				do {
					argv_329 = CreateFile (_filename, access_mode_CreateFile,0,NULL,create_disposition,FILE_ATTRIBUTE_NORMAL,NULL);
					if ((argv_329 != INVALID_HANDLE_VALUE) || (argv_673 > 50)) {
						break;
					}
					else {
						argv_673++;
						Sleep(250);
					}
				}
				while (argv_329 == INVALID_HANDLE_VALUE); 
			}
 
			if (argv_329 == INVALID_HANDLE_VALUE)  {
				argv_329			= NULL;
				argv_261		= GetLastError ();
				argv_264	= 2;
				bret			= false;
			}
			else { // CreateFile was succesfull
				// retrieve the file size
				//if ((_open_mode == argv_658) || (_open_mode == argv_660)) {
					_file_size = GetFileSize (argv_329, NULL);
				//}
				if (_file_size == 0) { // illegal to mmap a file with a size of zero
					argv_261		= GetLastError ();
					argv_264	= 74;
					bret = false;
				}
				else if (_file_size < 0) {
					argv_261		= GetLastError ();
					argv_264	= 6;
					bret			= false;
				}
				else if (_file_size == 0xFFFFFFFF) {
					argv_261		= GetLastError ();
					argv_264	= 3;
					bret			= false;
				}
				else {
					if ((_open_mode == argv_658) || (_open_mode==argv_660)) {
						argv_331 = CreateFileMapping (argv_329,NULL,access_mode_CreateFileMapping,0,0,NULL);
					}
					else {
						argv_331 = CreateFileMapping (argv_329,NULL,access_mode_CreateFileMapping,0,_file_size,NULL);
					}
					if (argv_331 == NULL/* || argv_331 == INVALID_HANDLE_VALUE*/)  { // failed
						argv_331		= NULL;
						argv_261		= GetLastError ();
						argv_264	= 4;
						bret			= false;			
					}
					else { // CreateFileMapping was succesfull
						argv_692 = (LPTSTR) MapViewOfFile (argv_331,	   // handle to map object
											access_mode_MapViewOfFile, // read/write permission
											0,                   
											0,                   
											0/* MMAP_BUF_SIZE */);           

						if (argv_692 == NULL) {
							argv_261		= GetLastError ();
							argv_264	= 5;
							bret			= false;	
						}
						else { // all succeeded, copy obtained pointer to caller's variable
							_pBuf = (uint8_t *) argv_692;
						}
					}
				}
			}
		}

		if ((usage_error == false) && (bret == false)) {
			argv_208 ();	
		}
		return (bret);
	}
#endif // #if defined (__WIN32_OS__) 



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_192
// @@
// @@ FUNCTION		:	argv_656 (Linux version)		
// @@
// @@ INPUT			:
// @@ _filename: const char *: name of the file to map to memory
// @@ _open_mode: uint32_t: can be either 
// @@    - argv_658: file will be read only
// @@    - argv_659 : file will have read/write privilege.
// @@    - argv_660 : file will have read/execution privileges.
// @@
// @@ OUTPUT		:
// @@ _pBuf: uint8_t *&: address of the first byte of the file 
// @@                 after it was projected to memory.
// @@ 	
// @@ _file_size: uint32_t&: size of the file after it was projected 
// @@                    to memory.
// @@
// @@ IO			:	none	
// @@	
// @@ RETURN VALUE	:	
// @@ bool: true if success,
// @@       false otherwise.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @2 This function permits to map to memory the file whose name
// @@ is given as the '_filename' parameter. 
// @@
// @@ CONTRACT 		: 
// @@ - no file should be currently mapped to memory (or ensure that
// @@   you call 'argv_208' before. 
// @@ - '_filename' parameter must not be a NULL pointer.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#if defined (__LINUX_OS__)
		bool argv_192::argv_656 (const char * _filename, uint32_t _open_mode, uint8_t *& _pBuf, uint32_t& _file_size) {
		bool bret = true;

		if (_filename == NULL) {
			argv_264	= 1;
			argv_261		= 100;
			bret = false;	
		}
		else {
			argv_638 = _filename;
			int fd = open (_filename, O_RDONLY);
			if (fd < 0) {
				argv_261		= errno;
				argv_264	= 2;
				bret			= false;
			}
			else { // file opened succesfully
				struct stat sbuf;
				if (stat (_filename, &sbuf) == -1) {
					argv_261		= errno;
					argv_264	= 3;
					bret			= false;
				}
				else { // file size retrieved succesfully
					_file_size = sbuf.st_size;
					void * ptrtmp = mmap ((caddr_t)0, sbuf.st_size, PROT_READ, MAP_SHARED, fd, 0);
					if (ptrtmp == (caddr_t)(-1)) {
						_pBuf			= NULL;    
						argv_261		= errno;
						argv_264	= 4;
						bret			= false;
					}
					else {
						argv_661	= (uint8_t *)ptrtmp;
						argv_662	= _file_size;    
						_pBuf		= argv_661;
					}
				}
				
				if (close (fd) == -1) {
					argv_261		= errno;
					argv_264	= 5;
					bret			= false;
				}
			}
		}
		return (bret);
	}
#endif // #if defined (__LINUX_OS__)



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
