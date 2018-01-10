// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ FILE: argv_130.cpp
// @@ 
// @@ DESCRIPTION:
// @@ This file contains the definition of the 
// @@ log facility that permits to log events and
// @@ to associate a time and date, coming along
// @@ with a severity level for each event.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@ includes
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#include "../LIB/argv_138.hpp"



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_212
// @@
// @@ FUNCTION		:	insert_date
// @@
// @@ INPUT			:	
// @@ - _fp: FILE * : pointer on an opened valid file.
// @@ - _date: CCPTR: pointer on a string containing the argv_226 date
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
// @@ This function permits to insert the date in a fixed
// @@ format into the argv_226 line.
// @@
// @@ CONTRACT		: 
// @@ - '_fp' must be a valid opened file's pointer
// @@ - '_date' must not be a NULL pointer
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_212::insert_date (FILE * _fp, CCPTR _date) {
	int nb_2_do = strlen (_date);
	if (nb_2_do > argv_230) {
		nb_2_do = argv_230;	
	}
	fwrite (_date, 1, nb_2_do, _fp);
	fflush (_fp);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_212
// @@
// @@ FUNCTION		:	insert_level
// @@
// @@ INPUT			:	
// @@ - _fp: FILE * : pointer on an opened valid file.
// @@ - _level: CCPTR: pointer on a string containing the argv_226 date
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	public	
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to insert the severity level in a fixed
// @@ format into the argv_226 line.
// @@ Notice that the severity level may be chosen out of :
// @@ - argv_675
// @@ - argv_783
// @@ - argv_262
// @@ - argv_162
// @@ - argv_231
// @@ - argv_674
// @@
// @@ CONTRACT		:
// @@ - '_fp' must be a valid opened file's pointer
// @@ - '_level' must not be a NULL pointer
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_212::insert_level (FILE * _fp, CCPTR _level) {
	int nb_2_do = strlen (_level);
	if (nb_2_do > argv_615) {
		nb_2_do = argv_615;	
	}
	fwrite (_level, 1, nb_2_do, _fp);
	fflush (_fp);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_212
// @@
// @@ FUNCTION		:	insert_body
// @@
// @@ INPUT			:	
// @@ - _fp: FILE * : pointer on an opened valid file.
// @@ - _level: CCPTR: pointer on a string containing the argv_226 date
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
// @@ This function permits to insert the severity level in a fixed
// @@ format into the argv_226 line.
// @@
// @@ CONTRACT		:
// @@ - '_fp' must be a valid opened file's pointer
// @@ - '_level' must not be a NULL pointer
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_212::insert_body (FILE * _fp, CCPTR _body) {
	int nb_2_do = strlen (_body);
	if (nb_2_do > argv_618) {
		nb_2_do = argv_618;
	}
	fwrite (_body, 1, nb_2_do, _fp);
	fflush (_fp);
	int remaining = argv_618 - nb_2_do;
	if (remaining > 0) {
		char vide = ' ';
		for (int i=0 ; i<remaining ; i++) {
			fwrite (&vide, 1, 1, _fp);
		}
		fflush (_fp);
	}
	insert_terminator (_fp);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_212
// @@
// @@ FUNCTION		:	insert_terminator
// @@
// @@ INPUT			:	
// @@ - _fp: FILE * : pointer on an opened valid file.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none	
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	private
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to end the argv_226 line by inserting
// @@ an end of line character sequence, that is OS dependant.
// @@
// @@ CONTRACT		: 
// @@ - '_fp' must be a valid opened file's pointer
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_212::insert_terminator (FILE * _fp) {
	fwrite (argv_769.c_str(), 1, argv_769.size (), _fp);
	fflush (_fp);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	-
// @@
// @@ FUNCTION		:	argv_239	
// @@
// @@ INPUT			:
// @@ - _filename: CCPTR: name of the destination file.
// @@
// @@ OUTPUT		:	
// @@
// @@ IO			:	
// @@ - _logger: argv_206 : instance of the log facility to use.
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	-
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to dump the content of a given file
// @@ into the argv_226 log file using the log facility given as
// @@ a parameter.
// @@
// @@ CONTRACT 		: 
// @@ - '_filename' must not be a NULL pointer
// @@ - '_filename' must be the name of a valid and existing file.
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_239 (CCPTR _filename, argv_206& _logger) {
	int ic;
	FILE * argv_307 = fopen (_filename, "rb");
	if (! argv_307) {
		_logger.argv_625 (argv_262, "+++ failed to visualize file (fopen failed) : ", _filename);	
	}
	else {
		string total = "";
		ic = fgetc (argv_307);
		while (ic != EOF) {
			total += ic;
			ic = fgetc (argv_307);
		}
		fclose (argv_307);
		_logger.argv_625 (argv_231, "file content : ", total.c_str());
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_206		
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
// @@ Normal constructor of the argv_206 object.
// @@
// @@ CONTRACT 		:	none	 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_206::argv_206() {
	reset ();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	~argv_206		
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
// @@ destructor of the argv_206 object.
// @@
// @@ CONTRACT 		:	none	 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_206::~argv_206() {
	argv_207 ();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_197	
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	private
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to determine whether the argv_226 line
// @@ is the last line of the rolling log file. If it is the case
// @@ then the file is rewinded so that the next line logged will
// @@ be located at the top of the log file.
// @@
// @@ CONTRACT 		: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_197 () {
	argv_227++;
	if (argv_227 >= argv_624) {
		rewind (argv_307);
		argv_227 = 1;
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_689	
// @@
// @@ INPUT			:
// @@ _filename: string : name of the log file to open.
// @@ _error_log_ptr: address of the error log, can be NULL if
// @@    error log is not used.
// @@ - _credential: string: symbolic name of the log.
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
// @@ This function permits to open the log file whose name is given
// @@ as a parameter.
// @@ Notice that as soon as the log file was opened, the opening date
// @@ and time is logged to this log file automatically.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
bool argv_206::argv_689 (string _filename, argv_206 * _error_log_ptr, string _credential) {
	bool bret = true;

	if (argv_307 != NULL) { // file already opened
		bret = false;
	}
	else {
		argv_302 = _filename;
		argv_307 = fopen (_filename.c_str(), "wb");

		if (!argv_307) {
			bret = false;
		}
		else { // log opened ok
			argv_779 (true);
			string stmp = "Log file creation date : ";
			stmp = stmp + argv_768;
			//argv_625 (argv_162, stmp.c_str());

			argv_225 = _credential;
			// the error log
			argv_263 = _error_log_ptr;
		}
	}
	return (bret);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_779	
// @@
// @@ INPUT			:
// @@ _large_mode: bool: true if we want a large display of argv_226 date and time
// @@                    false otherwise.
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none
// @@	
// @@ DISCLOSURE	:	private
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to obtain the argv_226 date and time
// @@ formatted to either a condensed string, or to a developped
// @@ string.
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_779 (bool _large_mode) {
	#if defined (__WIN32_OS__)
		GetLocalTime (&argv_771);
		if (_large_mode == false) {
			argv_760 (argv_768, MAX_PATH, "%02d/%02d-%02dh%02dm%02ds ", argv_771.wMonth, argv_771.wDay, argv_771.wHour, argv_771.wMinute, argv_771.wSecond);
		}
		else {
			argv_760 (argv_768, MAX_PATH, "month %d the %dth at %d hour %d minutes and %d seconds", argv_771.wMonth, argv_771.wDay, argv_771.wHour, argv_771.wMinute, argv_771.wSecond);
		}
	#endif // #if defined (__WIN32_OS__)
	#if defined (__LINUX_OS__)
		argv_229 = time (NULL);
		argv_772 = localtime (&argv_229);
		if (_large_mode == false) {
			argv_760 (argv_768, MAX_PATH, "%02d/%02d-%02dh%02dm%02ds ", argv_772->tm_mon, argv_772->tm_mday, argv_772->tm_hour, argv_772->tm_min, argv_772->tm_sec);
		}
		else {
			argv_760 (argv_768, MAX_PATH, "month %d the %dth at %d hour %d minutes and %d seconds", argv_772->tm_mon, argv_772->tm_mday, argv_772->tm_hour, argv_772->tm_min, argv_772->tm_sec);
		}
	#endif // #if defined (__LINUX_OS__)
	argv_768[MAX_PATH - 1] = '\0';
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	insert_date		
// @@
// @@ INPUT			:	none
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none	
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	private
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to update the argv_226 time and to
// @@ insert it into the header of a new line of the log file.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::insert_date () {
    if (argv_307) {
        argv_779 ();
		argv_676.insert_date (argv_307, argv_768);
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	insert_level	
// @@
// @@ INPUT			:
// @@ _level: UI32: level to be displayed.
// @@
// @@ OUTPUT		:	none	
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	none	
// @@	
// @@ DISCLOSURE	:	private
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to insert the level given as a parameter
// @@ to the header of a new line of the log file.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::insert_level (UI32 _level) {
    string level = "|???| ";
    switch (_level) {
        case argv_675:
            level = "|NOR| ";
            break;
        case argv_783:
            level = "|WRN| ";
            break;
        case argv_262:
            level = "|ERR| ";
            break;
        case argv_162:
            level = "|ADM| ";
            break;
        case argv_231:
            level = "|DBG| ";
            break;
        case argv_674:
            level = "     ";
            break;
    }
    if (argv_307) {
		argv_676.insert_level (argv_307, level.c_str());
    }
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS				: argv_206
// @@
// @@ FUNCTION			: argv_207
// @@
// @@ INPUT				: none
// @@
// @@ OUTPUT			: none
// @@
// @@ IO				: none
// @@
// @@ RETURN VALUE		: none
// @@	
// @@ DISCLOSURE		: public	
// @@
// @@ DESCRIPTION:
// @@ This function just flushes the data and close the previously
// @@ opened log file.
// @@
// @@ CONTRACT			: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_207() {
	if ((argv_623 == true) && (argv_307)) {
		fclose (argv_307);
		argv_307 = NULL;
	}
	reset ();
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS				: argv_206
// @@
// @@ FUNCTION			: reset
// @@
// @@ INPUT				: none
// @@
// @@ OUTPUT			: none
// @@
// @@ IO				: none
// @@
// @@ RETURN VALUE		: none
// @@	
// @@ DISCLOSURE		: public	
// @@
// @@ DESCRIPTION:
// @@ This function permits to set all fields of the
// @@ object to an initial state.
// @@
// @@ CONTRACT			: none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::reset () {
	argv_302		= "";
	argv_225		= "";
	argv_307				= NULL;
	argv_263	= NULL;
	argv_227	= 1;
	argv_623		= true;
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625		
// @@
// @@ INPUT			:
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: char *: the message to log
// @@ _no_eol: bool: true if an end of line should be appended at the end of the
// @@                message, false otherwise.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			argv_676.insert_body (argv_307, _cptr);
			argv_197 ();
		}
	}
#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str());	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_319		
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
// @@ This function permits to retrieve the name of the file
// @@ that is currently opened.
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
string argv_206::argv_319 () {
	return (argv_302);
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625		
// @@
// @@ INPUT			:
// @@ _level: UI32  :	the severity level associated with the message to log.
// @@ _cptr: char * :	the first message to log
// @@ _cptr2: char *:	the second message to log
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none 
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, CCPTR _cptr2) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			string stmp = _cptr;
			stmp = stmp + _cptr2;
			argv_676.insert_body (argv_307, stmp.c_str());
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _cptr2);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625		
// @@
// @@ INPUT			:
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, CCPTR _cptr2, CCPTR _cptr3) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			string stmp = _cptr;
			stmp = stmp + _cptr2;
			stmp = stmp + _cptr3;
			argv_676.insert_body (argv_307, stmp.c_str());
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _cptr2, _cptr3);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625	
// @@
// @@ INPUT			:
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: char * : the first message to log
// @@ _cptr2: char *: the second message to log
// @@ _cptr3: char *: the third message to log
// @@ _cptr4: char *: the fourth message to log
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, CCPTR _cptr2, CCPTR _cptr3, CCPTR _cptr4) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			string stmp = _cptr;
			stmp = stmp + _cptr2;
			stmp = stmp + _cptr3;
			stmp = stmp + _cptr4;
			argv_676.insert_body (argv_307, stmp.c_str());
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _cptr2, _cptr3, _cptr4);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: SI32: the value to log after the message.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, SI32 _val) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "%s %d", _cptr, _val);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _val);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: char *: the message to write to log file.
// @@ _val: UI32: the value to log after the message.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, UI32 _val) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "%s %u", _cptr, _val);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _val);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _val_zero: UI32: the first value to log.
// @@ _val_un  : UI32: the second value to log.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, UI32 _val_zero, UI32 _val_un) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "%u %u", _val_zero, _val_un);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		char tmp[MAX_PATH];
		argv_760 (tmp, MAX_PATH, "%s%u %u", argv_225.c_str(), _val_zero, _val_un);
		tmp[MAX_PATH - 1] = '\0';
		argv_263->argv_625 (_level, tmp);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_625	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: CCPTR: the message to log to file.
// @@ _val: unsigned long: the value to log to file after the message.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_625 (UI32 _level, CCPTR _cptr, unsigned long _val) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "%s %u", _cptr, (UI32) _val);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _cptr;
		argv_263->argv_625 (_level, total.c_str(), _val);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_626	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _cptr: CCPTR: the message to log to file.
// @@ _value: UI32: the value to log to file after the message.
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
// @@ This function logs the message(s) given as parameter(s) and associate
// @@ with them the argv_226 time and a severity level given as a parameter.
// @@ Notice that the '_value' parameter os logged in hexadecimal format.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_626 (UI32 _level, CCPTR _msg, UI32 _value) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "%s %X", _msg, _value);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();
		}
	}

#if defined (__REPORT_TO_ERROR_LOG__)
	if ((argv_263 != NULL) && (_level == argv_262)) {
		string total = argv_225 + _msg;
		argv_263->argv_626 (_level, total.c_str(), _value);	
	}
#endif // #if defined (__REPORT_TO_ERROR_LOG__)
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_621	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _buffer: UI08 *: the address of the first byte of the buffer to log.
// @@ _size: UI32: the size of the buffer to log.
// @@ _comment: CCPTR: the comment associated with the buffer to log.
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
// @@ This function is for debug purpose only.
// @@ it dump the content of the buffer '_buffer' into the 
// @@ file : C:\\binary.bin, the format of the file being
// @@ a readable sequence of hexadecimal values (a argv_182).
// @@ So it can be seen as an outbound save up function.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_621 (UI32 _level, UI08 * _buffer, UI32 _size, CCPTR _comment) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			char tmp2[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "=== BUFFER OF : %s ===", _comment);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();

			tmp[0]			= '\0';
			UI32 nb_byte	= 0;
			UI32 i			= 0;
			FILE * fpzx		= NULL;

			fpzx = fopen ("C:\\binary.bin", "wb");

			if (! fpzx) {
#if defined (__WIN32_OS__) 
				MessageBox (NULL, "failed to open bin log file !", "", MB_ICONERROR);
#endif // #if defined (__WIN32_OS__) 
			}

			for (i=0 ; i<_size ; i++) {
				fwrite ((char *) &_buffer[i], 1, 1, fpzx);
				fflush (fpzx);
				argv_760 (tmp2, MAX_PATH, "%02X ", _buffer[i]);
				tmp2[MAX_PATH - 1] = '\0';
				strcat (tmp, tmp2);
				nb_byte++;

				if (nb_byte >= 16) {
					insert_date ();
					insert_level (_level);
					argv_676.insert_body (argv_307, tmp);
					tmp[0] = '\0'; // reset the cumulative line
					nb_byte = 0;
				}
			}

			fclose (fpzx);

			// flush the remaining bytes (if any)
			if (nb_byte > 0) {
				insert_date ();
				insert_level (_level);
				argv_676.insert_body (argv_307, tmp);
			}
		}
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_621	
// @@
// @@ INPUT			:	
// @@ _level: UI32: the severity level associated with the message to log.
// @@ _buffer: UI08 *: the address of the first byte of the buffer to log.
// @@ _comment: CCPTR: the comment associated with the buffer to log.
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
// @@ This function is for debug purpose only.
// @@ it permits to dump to the log file the content of 
// @@ a given buffer containing the opcode of a given function.
// @@ Notice that this function stops to dump when it reaches
// @@ a RET (0x3C) or a NOP (0x90) instruction.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_622 (UI32 _level, UI08 * _buffer, CCPTR _comment) {
	if (argv_623 == true) {
		if (argv_307) {
			insert_date ();
			insert_level (_level);
			char tmp[MAX_PATH];
			char tmp2[MAX_PATH];
			argv_760 (tmp, MAX_PATH, "=== %s ===", _comment);
			tmp[MAX_PATH - 1] = '\0';
			argv_676.insert_body (argv_307, tmp);
			argv_197 ();

			tmp[0]			= '\0';
			UI32 nb_byte	= 0;
			UI32 i			= 0;

			for (i=0 ; ; i++) {
				argv_760 (tmp2, MAX_PATH, "%02X ", _buffer[i]);
				tmp2[MAX_PATH - 1] = '\0';
				strcat (tmp, tmp2);
				nb_byte++;

				if (nb_byte >= 32) {
					insert_date ();
					insert_level (_level);
					argv_676.insert_body (argv_307, tmp);
					tmp[0] = '\0'; // reset the cumulative line
					nb_byte = 0;
				}

				// functions finish by a RET + NOP instruction
				if ((i>256) || ((i > 0) && (_buffer[i] == 0x90) && (_buffer[i-1] == 0x3C))) { 
					break;
				}

			}

			// flush the remaining bytes (if any)
			if (nb_byte > 0) {
				insert_date ();
				insert_level (_level);
				argv_676.insert_body (argv_307, tmp);
			}
		}
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_316	
// @@
// @@ INPUT			:	none	
// @@
// @@ OUTPUT		:	none
// @@
// @@ IO			:	none
// @@	
// @@ RETURN VALUE	:	
// @@ FILE * : the file descriptor of the opened log file.
// @@	
// @@ DISCLOSURE	:	public
// @@	
// @@ DESCRIPTION	:
// @@ This function permits to retrieve the descriptor of
// @@ the log file (so that external functions can use this
// @@ descriptor to do their job if necessary).
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
FILE * argv_206::argv_316 () {
	return (argv_307);	
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@
// @@ CLASS			:	argv_206
// @@
// @@ FUNCTION		:	argv_306	
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
// @@ This function permits to ensure that all the data
// @@ are flushed to the log file by closing and reopening this
// @@ file. Notice That the performance decrease if you use this
// @@ function.
// @@
// @@ CONTRACT 		:	none
// @@
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void argv_206::argv_306 () {
	fflush (argv_307);	
}


void argv_241 (argv_206 * _log_ptr, CCPTR _fn_name, UI32 _success_iret, UI32 _actual_iret) {
	if (_log_ptr != NULL) {
		char tmp[MAX_PATH];
		if (_actual_iret == _success_iret) {
			argv_760 (tmp, MAX_PATH, "kernel_manager - function '%s'...[SUCCESS]", _fn_name);
			tmp[MAX_PATH - 1] = '\0';
			_log_ptr->argv_625 (argv_675, tmp);	
		}
		else {
			string serror = err_2_string (_actual_iret);
			argv_760 (tmp, MAX_PATH, "+++ ERROR: function '%s' failed ! (%s)", _fn_name, serror.c_str());
			tmp[MAX_PATH - 1] = '\0';
			_log_ptr->argv_625 (argv_262, tmp);	
		}
	}
}



// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
// @@  end of file
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
