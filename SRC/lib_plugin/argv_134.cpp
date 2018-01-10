// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: inthepicture.cpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains all functions and
// @@ data structures that are necessary for the
// @@ plugin 'inThePicture' to perform it's task.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../lib_plugin/argv_142.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_742				
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
// @@ This function permits to clear the plugin debug log file
// @@ by reseting it's content.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_742 () {
	// reset log file
	FILE * fp_log = fopen ("C:\\inthepicture_log.txt", "wb");
	if (fp_log) {
		fclose (fp_log);
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_625				
// @@
// @@ INPUT			:	
// @@ _msg: const char *: the text message to save into the log file.
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
// @@ This function permits to save the '_msg' ascii string
// @@ into the debug file whose location and name are:
// @@ "C:\\inthepicture_log.txt"
// @@ Notice that the log file is opened and closed everytime 
// @@ this function is called so that debug is possible even
// @@ when a crash occurs.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_625 (const char * _msg) {
	FILE * fp_log = fopen ("C:\\inthepicture_log.txt", "ab");
	if (fp_log) {
		fprintf (fp_log, "%s\r\n", _msg);
		fclose (fp_log);
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_628				
// @@
// @@ INPUT			:	
// @@ _msg: const char *: the text message to save into the log file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	
// @@ _v: vector<uint8_t> : the vector to save to log file.
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to save the content of the
// @@ byte vector given by the parameter '_v'
// @@ into the debug file whose location and name are:
// @@ "C:\\inthepicture_log.txt"
// @@
// @@ Notice that the log file is opened and closed everytime 
// @@ this function is called so that debug is possible even
// @@ when a crash occurs.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_628 (const char * _msg, vector<uint8_t>& _v) {
	FILE * fp_log = fopen ("C:\\inthepicture_log.txt", "ab");
	if (fp_log) {
		uint32_t size, i;
		size = _v.size ();
		fprintf (fp_log, "%s: [", _msg);
		for (i=0 ; i<size ; i++) {
			fprintf (fp_log, "%02X ", _v[i]);	
		}
		fprintf (fp_log, "]\r\n");
		fclose (fp_log);
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_628				
// @@
// @@ INPUT			:	
// @@ _msg: const char *: the text message to save into the log file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	
// @@ _v_extracted: vector<uint8_t> : the first vector to save to log file.
// @@ _v_remaining: vector<uint8_t> : the second vector to save to log file.
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to save the content of the
// @@ byte vector given by the parameter '_v_extracted'
// @@ and '_v_remaining' in the file whose location and name are:
// @@ "C:\\inthepicture_log.txt"
// @@
// @@ Notice that the log file is opened and closed everytime 
// @@ this function is called so that debug is possible even
// @@ when a crash occurs.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void log_vectors (const char * _msg, vector<uint8_t>& _v_extracted, vector<uint8_t>& _v_remaining) {
	FILE * fp_log = fopen ("C:\\inthepicture_log.txt", "ab");
	if (fp_log) {
		uint32_t size, i;
		fprintf (fp_log, "%s: v_extracted=[", _msg);
		size = _v_extracted.size ();
		for (i=0 ; i<size ; i++) {
			fprintf (fp_log, "%02X ", _v_extracted[i]);
		}
		fprintf (fp_log, "] , v_remaining=[");
		size = _v_remaining.size ();
		for (i=0 ; i<size ; i++) {
			fprintf (fp_log, "%02X ", _v_remaining[i]);	
		}
		fprintf (fp_log, "]\r\n");
		fclose (fp_log);
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_317			
// @@
// @@ INPUT			:
// @@ _filename: name of the text file whose number of lines is to
// @@            be computed.
// @@
// @@ OUTPUT		:
// @@ _nb_line: uint32_t: number of lines contained in the file whose
// @@       name is given by the '_filename' parameter.	
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
// @@ This function permits to compute the number of lines 
// @@ of the file whose name is given as the '_filename' parameter,
// @@ the argv_745 being stored into the '_nb_line' argument.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@	
bool argv_317 (const char * _filename, uint32_t& _nb_line) {
	bool bret	= true;
	_nb_line	= 0;
	FILE * argv_307 = fopen (_filename, "rb");
	if (! argv_307) {
		bret = false;
	}
	else {
		char argv_186[1024];
		char * cptr = fgets (argv_186, 1024, argv_307);
		while (cptr != NULL) {
			_nb_line++;
			cptr = fgets (argv_186, 1024, argv_307);
		}
		fclose (argv_307);
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_313			
// @@
// @@ INPUT			:	
// @@ _ptr: uint8_t *: address of the first byte of the mmapped file
// @@               to analyze.
// @@
// @@ _size: uint32_t: size of the mmapped file.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ uint32_t: the depth of the BMP file being under analysis.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to retrieve the color depth of the
// @@ BMP file that was previously mmapped, the first byte of the
// @@ mmapped file being stored into the '_ptr' parameter, and the
// @@ size of the mmapped file being stored into the '_size' 
// @@ parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
uint32_t argv_313 (uint8_t * _ptr, uint32_t _size) {
	uint32_t depth = 0;
	union Atype_tmp {
		unsigned short argv_176;
		unsigned char argv_768[2];
	};

	Atype_tmp argv_178;
	argv_178.argv_768[0] = _ptr[28];
	argv_178.argv_768[1] = _ptr[29];
	depth = argv_178.argv_176;
	return(depth);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_272			
// @@
// @@ INPUT			:
// @@ _path: const char *: the full argv_302 (absolute).	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the argv_302 whose folder has been removed.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to extract the argv_302 from an
// @@ absolute argv_302 composed of both folder and argv_302.
// @@ Thus this function permits to remove the folder's name.
// @@
// @@ CONTRACT 		:	
// @@ - '_path' parameter must not be an empty string.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_272 (const char * _path) {
	string argv_302;
	uint32_t size = strlen (_path);
	if (size > 0) {
		uint32_t argv_762 = size - 1;
		while ((argv_762 > 0) && (_path[argv_762] != '/') && (_path[argv_762] != '\\')) {
			argv_762--;
		}

		for (uint32_t i=argv_762+1 ; i<size ; i++) {
			argv_302 += _path[i];	
		}
	}
	return (argv_302);
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-	
// @@
// @@ FUNCTION		:	argv_700			
// @@
// @@ INPUT			:
// @@ _ercode: uint32_t: the error code to convert.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ string: the error code converted into a 
// @@         human-readable string.	
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function converts the '_ercode' parameter into
// @@ a human-readable string. This parameter being the
// @@ numeric value that uniquely identifies a given return value.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_700 (int32_t _ercode) {
	string s;
	switch (_ercode) {
		// === plugins related error codes === 
		case argv_716:					s = "argv_716";					break;
		case argv_714:		s = "argv_714";		break;
		case argv_712:		s = "argv_712";		break;
		case argv_708:			s = "argv_708";			break;
		case argv_715:				s = "argv_715";				break;
		case argv_709:			s = "argv_709";			break;
		case argv_718:		s = "argv_718";		break;
		case argv_701:		s = "argv_701";		break;
		case argv_707:	s = "argv_707";	break;
		case argv_705:			s = "argv_705";			break;
		case argv_704:			s = "argv_704";		break;
		case argv_703:	s = "argv_703";break;
		case argv_710:				s = "argv_710";				break;
		case argv_706:	s = "argv_706";	break;
		case argv_713:			s = "argv_713";			break;
		case argv_699:		s = "argv_699";		break;
		case argv_711:	s = "argv_711";	break;
		case argv_698:			s = "argv_698"; break;

		// ==== analysis argv_745 related errors =====
		case argv_171:			s = "argv_171";			break;
		case argv_168:		s = "argv_168";		break;
		case argv_169:s = "argv_169";break;
		case argv_170:		s = "argv_170";		break;
		case argv_172:		s = "argv_172";		break;

		default: s = "<unknown_error>";		
	}
	return (s);
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
