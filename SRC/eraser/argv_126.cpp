#include "argv_122.h"
#include "argv_124.h"

using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  CONSTANTS
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
const uint32_t argv_669	= 35; // number of times the file is erased
const uint32_t argv_668	= 18; // number of times the file is erased
const uint32_t argv_667	= 1; // number of times the file is erased
const uint32_t argv_778			= 256000;
const int32_t argv_604			= 1974;

char argv_787[argv_778];


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@  GLOBAL VARIABLE
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
argv_194 argv_326;
HWND argv_738;
unsigned long argv_515	= argv_516;
unsigned long argv_488	= argv_489;
unsigned long argv_490	= argv_491;


argv_194::argv_194 () {
	argv_737				= false;
	argv_326.argv_666			= argv_669;
	argv_305	= false;
	argv_753			= false;
}


int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
	MSG msg;
	HACCEL hAccelTable;
	LoadString(hInstance, argv_602, argv_326.argv_766, argv_642);
	LoadString(hInstance, argv_577, argv_326.argv_767, argv_642);
	argv_664(hInstance);

	if (!argv_605 (hInstance, nCmdShow))  {
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)argv_577);
	while (GetMessage(&msg, NULL, 0, 0))  {
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))  {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return msg.wParam;
}

ATOM argv_664(HINSTANCE hInstance) {
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)argv_785;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)argv_596);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= (LPCSTR)argv_577;
	wcex.lpszClassName	= argv_326.argv_767;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)argv_594);
	return RegisterClassEx(&wcex);
}

string argv_688 () {
   OPENFILENAME ofn;
    char szFileName[MAX_PATH] = "";
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner	= argv_326.argv_755;
	ofn.lpstrFilter = "All Files (*.*)\0*.*\0";
    ofn.lpstrFile	= szFileName;
    ofn.nMaxFile	= MAX_PATH;
    ofn.Flags		= OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
    ofn.lpstrDefExt = "txt";
    GetOpenFileName(&ofn);
	return(szFileName);	
}

//=============================================================
//=============================================================
bool argv_280 (const string& _filename) {
	bool bret = true;

	FILE * argv_307 = fopen (_filename.c_str(), "rb");
	if (!argv_307) {
		bret = false;
	}
	else {
		fclose(argv_307);
	}	

	return(bret);
}

BOOL argv_605(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;
	argv_326.argv_330 = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(argv_326.argv_767, argv_326.argv_766, WS_VISIBLE | WS_OVERLAPPEDWINDOW,
	  CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd) {
	  return FALSE;
	}

	ShowWindow(hWnd, SW_SHOWMINIMIZED);
	UpdateWindow(hWnd);
	argv_326.argv_755 = hWnd;

	DialogBox(argv_326.argv_330, (LPCTSTR)argv_578, hWnd, (DLGPROC)argv_160);
	DestroyWindow(hWnd);
	return TRUE;
}


LRESULT CALLBACK argv_785(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	
	TCHAR szHello[argv_642];
	LoadString(argv_326.argv_330, argv_603, szHello, argv_642);

	switch (message) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case argv_598:
				   DialogBox(argv_326.argv_330, (LPCTSTR)argv_578, hWnd, (DLGPROC)argv_160);
				   break;
				case argv_599:
				   DestroyWindow(hWnd);
				   break;

				case argv_600:
					argv_688();
					break;

				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			argv_326.argv_327 = hdc;
			// TODO: Add any drawing code here...
			RECT rt;
			GetClientRect(hWnd, &rt);
			DrawText(hdc, szHello, strlen(szHello), &rt, DT_CENTER);
			EndPaint(hWnd, &ps);
			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

//====================================================================
// just for a pretty display
//====================================================================
void argv_191 (HWND _hDlg) {
	if (_hDlg) {
		RECT rect; 
		GetWindowRect (_hDlg,&rect); 
		int x = (GetSystemMetrics(SM_CXSCREEN)-rect.right)/2;
		int y = (GetSystemMetrics(SM_CYSCREEN)-rect.bottom)/2;
		SetWindowPos (_hDlg, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);
	}
	else {
		MessageBox(argv_326.argv_755, "cant center window", "",MB_OK);
	}	
}



//-------------------------------------------------------------
string argv_205 () {
	OleInitialize (NULL);
	CoInitialize (NULL);

	string argv_745 = "";
	BROWSEINFO bi;
	memset(&bi,0,sizeof(BROWSEINFO));
	char buffer[MAX_PATH];
	bi.hwndOwner=argv_326.argv_755;
	// Contient le repertoire initial ou NULL
	bi.pidlRoot=NULL;
	bi.pszDisplayName=buffer;
	bi.lpszTitle="Current directory";
	bi.ulFlags= argv_180;
	bi.lParam=NULL;

	LPITEMIDLIST li = SHBrowseForFolder(&bi);

	if (li) {
		SHGetPathFromIDList(li, buffer);
		argv_745 = buffer;
	}
	return (argv_745);
}

//============================================================
bool argv_260 (const char * _filename) {
	bool bret = true;
	argv_188 file_bar;

	// extract file size
	uint32_t file_size = 0;
	bret = argv_318 (_filename, file_size);
	if (bret == true) {
		uint32_t nb_unit		= file_size / argv_778;
		uint32_t real_nb_unit	= nb_unit;
		uint32_t nb_remaining	= file_size - (nb_unit * argv_778); 
		if (nb_remaining > 0) {
			real_nb_unit++;	
		}

		file_bar.init (argv_326.argv_755, argv_489, real_nb_unit * argv_326.argv_666);
		char tmp[256];

		for (argv_326.argv_228=0 ; argv_326.argv_228<argv_326.argv_666 ; argv_326.argv_228++) {
			argv_760 (tmp, 256, "erasing content (pass %u)", argv_326.argv_228+1);
			tmp[256 - 1] = '\0';
			SendDlgItemMessage (argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) tmp);
			bret = argv_258 (_filename, file_size, file_bar);
			if (bret == false) {
				break;
			}
			if (argv_326.argv_305 == true) {
				break;
			}	
		}
	}
	return (bret);
}

void argv_312 (char * _buf, uint32_t _size) {
	for (uint32_t z=0 ; z<_size ; z++) {
		//_buf[z] = rand ();
		_buf[z] = argv_326.argv_731.argv_323 ();
	}
}

void argv_743 (char * _buf, uint32_t _size) {
	for (uint32_t z=0 ; z<_size ; z++) {
		_buf[z] = 0x00;
	}
}

bool argv_258 (const char * _filename, uint32_t _file_size, argv_188& file_bar) {
	bool bret = true;
	uint32_t size = _file_size;
	FILE * argv_307 = fopen (_filename, "wb");
	if (! argv_307) {
		char * str = strerror (errno);
		MessageBox (NULL, str, _filename, MB_ICONERROR);
		bret = false;
	}
	else {
		uint32_t nb_unit		= size / argv_778;
		uint32_t real_nb_unit	= nb_unit;
		uint32_t nb_remaining	= size - (nb_unit * argv_778); 
		if (nb_remaining > 0) {
			real_nb_unit++;	
		}

		fseek (argv_307, 0, SEEK_SET);

		if (argv_787 == NULL) {
			bret = false;
		}
		else {
			argv_312 (argv_787, argv_778);
			uint32_t nb_done = 0;

			for (uint32_t i=0 ; i<nb_unit ; i++) {
				argv_312 (argv_787, argv_778); 

				if (fwrite (argv_787, 1, argv_778, argv_307) != argv_778) {
					bret = false;
					break;
				}
				file_bar.incr (1);
				nb_done += argv_778;
				// cancel when erasing file is too dangerous !
				/*
				if (argv_326.argv_305 == true) {
					break;
				}*/
			}

			if (argv_326.argv_305 == false) {
				if ((bret == true) && (nb_remaining > 0)) {
					argv_312 (argv_787, argv_778);
					if (fwrite (argv_787, 1, nb_remaining, argv_307) != nb_remaining) {
						bret = false;
					}
					file_bar.incr (1);
				}
			}

			if (fclose (argv_307) != 0) {
				bret = false;
			}
		}
	}
	argv_743 (argv_787, argv_778);
	return (bret);
}

bool argv_246 (const char * _filename) {
	bool bret = true;
	bool silent_mode = false;

	string chosen_file;
	if (_filename == NULL) {
		chosen_file = argv_688 ();
	}
	else {
		chosen_file = _filename;
		silent_mode	= true;
	}
	bool content_erased = false;
	bool mmap_failed	= false;

	if (chosen_file != "") {
		argv_741 (chosen_file.c_str());		// ok if it fails
		argv_739 (chosen_file.c_str());		// ok if it fails
		argv_740 (chosen_file.c_str());	// ok if it fails

		argv_192 mapper;
		uint8_t * buf_ptr = NULL;
		uint32_t size;
		if (silent_mode == false) {
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "erasing content...");
		}
		if (1==1) {
		//if (mapper.argv_656 (chosen_file.c_str(), argv_659, buf_ptr, size) == false) {
			/*
			uint32_t ercode, ersource;
			mapper.argv_320 (ercode, ersource);
			if (silent_mode == false) {
				argv_760 (tmp, MAX_PATH, "failed to encode file (mmap failed - ercode=%u,ersource=%u)\nfile: %s", ercode, ersource, chosen_file.c_str());
				tmp[MAX_PATH - 1] = '\0';
				MessageBox (NULL, tmp, "Encode Error", MB_ICONERROR);
			}*/
			mmap_failed = true;
		}
		else {
			argv_188 file_bar;
			uint32_t nb_unit		= size / argv_778;
			uint32_t real_nb_unit	= nb_unit;
			uint32_t nb_remaining	= size - (nb_unit * argv_778); 
			if (nb_remaining > 0) {
				real_nb_unit++;	
			}/*
			{
				char tmp[MAX_PATH];
				argv_760 (tmp, MAX_PATH, "nb_unit=%u|nb_remaining=%u|real_nb_unit=%u", nb_unit, nb_remaining, real_nb_unit);
				tmp[MAX_PATH - 1] = '\0';
				MessageBox (NULL, tmp, "", MB_OK);
			}*/
			file_bar.init (argv_326.argv_755, argv_489, real_nb_unit);
			uint32_t nb_done = 0;

			for (uint32_t i=0 ; i<nb_unit ; i++) {
				memset (&buf_ptr[nb_done], 0x00, argv_778);
				file_bar.incr (1);
				nb_done += argv_778;
			}

			if (nb_remaining > 0) {
				memset (&buf_ptr[nb_done], 0x00, nb_remaining);
				file_bar.incr (1);
			}
			mapper.argv_208 ();
			content_erased = true;
		}
 
		if (mmap_failed == true) { // attempt with fopen
			bret = argv_260 (chosen_file.c_str());
			if (bret == true) {
				content_erased = true;	
			}
			else {
				char tmp[MAX_PATH];
				argv_760 (tmp, MAX_PATH, "failed to erase file content :\n%s", chosen_file.c_str());
				tmp[MAX_PATH - 1] = '\0';
				MessageBox (NULL, tmp, "", MB_ICONERROR);
			}
		}


		if ((argv_326.argv_305 == false) && (content_erased == true)) {
			//MessageBox (NULL, "step 1 - content erased...[CHECK]", "", MB_OK);
			string new_filename = argv_273 (chosen_file.c_str());
			new_filename = new_filename + "a";
			//MessageBox (NULL, new_filename.c_str(), "", MB_OK);
			if (silent_mode == false) {
				SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "moving file...");
			}
			bret = argv_663 (chosen_file.c_str(), new_filename.c_str());
			if (bret == false) {
				char tmp[MAX_PATH];
				argv_760 (tmp, MAX_PATH, "Failed to move file :\n%s -> %s", chosen_file.c_str(), new_filename.c_str());
				tmp[MAX_PATH - 1] = '\0';
				MessageBox (NULL, tmp, "", MB_ICONERROR);
			}
			else {
				//MessageBox (NULL, "step 2 - file moved...[CHECK]", "", MB_OK);
				SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "deleting file...");
				if (DeleteFile (new_filename.c_str()) == 0) {
					char tmp[MAX_PATH];
					argv_760 (tmp, MAX_PATH, "Failed to delete file :\n%s", new_filename.c_str());
					tmp[MAX_PATH - 1] = '\0';
					MessageBox (NULL, tmp, "", MB_ICONERROR);
				}
				else {
					//MessageBox (NULL, "step 3 - file erased...[CHECK]", "", MB_OK);
				}
			}
		}
	}

	if (silent_mode == false) {
		if (argv_326.argv_305 == true) {
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Operation cancelled !");
			argv_188 file_bar, argv_770; // reset all progress bars
			file_bar.init	(argv_326.argv_755, argv_489, argv_665);
			argv_770.init (argv_326.argv_755, argv_491, argv_665);
			HWND hwnd_std = GetDlgItem (argv_326.argv_755, argv_413); 
			SetWindowText (hwnd_std, "Erase File");
		}
		else if (bret == true) {
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Erased succesfully");
		}
		else {
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Erase Failed !");
		}
	}
	return (bret);
}

DWORD WINAPI argv_247 (LPVOID lParam) {
	char * argv_302 = (char *) lParam;
	HWND hwnd_std = GetDlgItem (argv_326.argv_755, argv_414);	
	EnableWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_413); 
	SetWindowText (hwnd_std, "Stop");
	argv_326.argv_753 = true;

	int32_t iret = argv_246 (argv_302);

	if (argv_326.argv_305 == true) {
		MessageBox (NULL, "Operation Cancelled !", "", MB_ICONWARNING);
		argv_326.argv_305 = false;
	}

	argv_326.argv_753 = false;
	argv_744 ();
	argv_256 (true, true);
	return (iret);
}

bool argv_308 (const char * _chosen_folder) {
	bool bret = true;
	char old_dir[MAX_PATH];
	GetCurrentDirectory (MAX_PATH, old_dir);
	if (SetCurrentDirectory (_chosen_folder) == false) {
		char tmp[MAX_PATH];
		argv_760 (tmp, MAX_PATH, "SetCurrentDirectory failed :\n%s", _chosen_folder);
		tmp[MAX_PATH - 1] = '\0';
		MessageBox (NULL, tmp, "", MB_ICONERROR);
		bret = false;
	}
	else {
		SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "creating list...");
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile ("*", &FindData);

		if (hFind == INVALID_HANDLE_VALUE) { // no file found at all
			bret = false;
		}
		else {
			string	full_filename;
			do { // if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					full_filename = _chosen_folder;
					full_filename = full_filename + "\\" + FindData.cFileName;
					argv_326.argv_780.push_back (full_filename);
				}

				if (argv_326.argv_305 == true) {
					break;
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
		}
		FindClose (hFind);
	}
	SetCurrentDirectory (old_dir);
	return (bret);
}

bool argv_248 () {
	bool bret = true;
	uint32_t nb_done  = 0;
	uint32_t nb_error = 0;
	char tmp[MAX_PATH];
	argv_188 file_bar;
	uint32_t nb_elem = argv_326.argv_780.size ();

	file_bar.init (argv_326.argv_755, argv_491, nb_elem);
	for (uint32_t i=0 ; i<nb_elem ; i++) {
		bret = argv_246 (argv_326.argv_780[i].c_str());
		file_bar.incr ();
		if (bret == false) {
			nb_error++;
		}
		nb_done++;
		argv_760 (tmp, MAX_PATH, "%u done / %u failed", nb_done, nb_error);
		tmp[MAX_PATH - 1] = '\0';
		SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) tmp);
		if (argv_326.argv_305 == true) {
			break;
		}
	}

	if (nb_error > 0) {
		bret = false;
		MessageBox (NULL, "Operation Failed !", "", MB_ICONERROR);
	}
	else {
		if (nb_done == 0) {
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "no file found !");
			MessageBox (NULL, "no file found !", "", MB_ICONWARNING);
		}
		else if (argv_326.argv_305 == false) {
			MessageBox (NULL, "Operation finished", "", MB_OK);
		}
	}
	return (bret);
}

bool argv_249 () {
	bool bret = true;
	sort (argv_326.argv_781.begin(), argv_326.argv_781.end());
	uint32_t nb_folder = argv_326.argv_781.size ();
	for (uint32_t i=0 ; i<nb_folder ; i++) {
		if (RemoveDirectory (argv_326.argv_781[i].argv_636.c_str()) == 0) {
			DWORD ercode = GetLastError ();
			bret = false;
		}

		if (argv_326.argv_305 == true) {
			break;
		}
	}
	return (bret);
}

DWORD WINAPI argv_251 (LPVOID lParam) {
	string chosen_folder = argv_205 ();
	if (chosen_folder != "") {
		argv_326.argv_753 = true;
		HWND hwnd_std = GetDlgItem (argv_326.argv_755, argv_414); 
		SetWindowText (hwnd_std, "Stop");
		argv_236 (true, false);

		argv_326.argv_780.clear ();
		argv_326.argv_781.clear ();
		char orig_folder[argv_304];
		GetCurrentDirectory (argv_304, orig_folder);

		if (argv_326.argv_737 == true) {
			argv_309 (chosen_folder.c_str());
		}
		else {
			argv_308 (chosen_folder.c_str());
		}

		if (argv_326.argv_305 == false) {
			SetCurrentDirectory (orig_folder);
			argv_248 ();

			if (argv_326.argv_305 == false) {
				if (argv_326.argv_737 == true) {
					bool bret = argv_249 ();
					if (bret == false) {
						MessageBox (NULL, "One or more folders could not be erased !", "", MB_ICONERROR);
					}
				}
			}
		}
	}

	if (argv_326.argv_305 == true) {
		MessageBox (NULL, "Operation Cancelled !", "", MB_ICONWARNING);
		HWND hwnd_std = GetDlgItem (argv_326.argv_755, argv_414); 
		SetWindowText (hwnd_std, "Erase Folder");
		argv_326.argv_305 = false;
	}
	argv_326.argv_753 = false;
	argv_744 ();
	argv_256 (true, true);
	return (0);
}

bool argv_223 () {
	bool bret = true;
	DWORD dwThreadId;
	HANDLE hThread; 
	hThread = CreateThread (NULL,0, argv_251, NULL,0,&dwThreadId);
	if (hThread == NULL)   {
		MessageBox (NULL, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}
	return (bret);
}

bool argv_221 (const char * _filename) {
	bool bret = true;
	DWORD dwThreadId;
	HANDLE hThread; 
	hThread = CreateThread (NULL,0, argv_247, (LPVOID)_filename,0,&dwThreadId);
	if (hThread == NULL)   {
		MessageBox (NULL, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}
	return (bret);
}

//--------------------------------------------------
bool argv_270 (string& dirname, vector<string>& v_dir) {
	bool bret = true;

	if (SetCurrentDirectory (dirname.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile ("*.*", &FindData);	

		if (hFind == INVALID_HANDLE_VALUE) {
			bret = false;
		}
		else {
			v_dir.clear ();
			int name_size;

			do  {
				if (FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
					if((strcmp(FindData.cFileName, ".")!=0) && (strcmp(FindData.cFileName, "..")!=0)) {
						name_size = dirname.size ();
						if (name_size > 0) {
							if (dirname[name_size - 1] != '\\') {
								v_dir.push_back (dirname + "\\" + FindData.cFileName);
							}
							else {
								v_dir.push_back (dirname + FindData.cFileName);
							}
						}
					}
				}

				if (argv_326.argv_305 == true) {
					break;
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
		}
		FindClose (hFind);
	}
	return (bret);
}

bool argv_269 (string dirname, string pattern_arg) {
	bool bret = true;
	if (SetCurrentDirectory (dirname.c_str()) == false) {
		bret = false;
	}
	else {
		WIN32_FIND_DATA FindData; 
		HANDLE hFind = FindFirstFile (pattern_arg.c_str(), &FindData);

		if (hFind == INVALID_HANDLE_VALUE) { // no file found at all
			bret = true;
		}
		else {
			string full_filename = "";
			do {
				// if it is not a directory
				if (!(FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
					 full_filename = dirname + "\\" + FindData.cFileName;
					 argv_326.argv_780.push_back (full_filename.c_str());
				}
				else if ((strcmp(FindData.cFileName, ".")!=0) && (strcmp(FindData.cFileName, "..")!=0)) {
					argv_193 unit;
					unit.argv_636 = dirname + "\\" + FindData.cFileName;
					argv_326.argv_781.push_back (unit);
				}
				if (argv_326.argv_305 == true) {
					break;
				}
			}
			while (FindNextFile (hFind, &FindData)) ;
			FindClose (hFind);
		}
	}
	return (bret);
}

void argv_268 (string root_arg) {
	bool bret;
	vector<string>	v_dir;
	bret = argv_269 (root_arg, "*");

	if (argv_326.argv_305 == false) {
		argv_270 (root_arg, v_dir);

		if (argv_326.argv_305 == false) {
			int32_t size = v_dir.size ();
			for (int32_t i=0 ; i<size ; i++) {
				argv_268 (v_dir[i]);
				if (argv_326.argv_305 == true) {
					break;
				}
			}
		}
	}
}

// folders are sorted so that the deepest are the first of the container
void argv_309 (const char * _folder_2_process) {
	SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Creating list...");
	argv_326.argv_305 = false;

	argv_268 (_folder_2_process);
	uint32_t nb_file = argv_326.argv_780.size ();
	SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "File List created");
}

//=============================================================

void argv_725 () {
	SendDlgItemMessage (argv_326.argv_755, argv_517, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)"Low");
	SendDlgItemMessage (argv_326.argv_755, argv_517, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)"Medium");
	SendDlgItemMessage (argv_326.argv_755, argv_517, CB_ADDSTRING, 0, (LPARAM)(LPCSTR)"High");
}

void argv_236 (bool _is_folder, bool _is_file) {
	HWND hwnd_std;
	if (_is_folder == true) {
		hwnd_std = GetDlgItem (argv_326.argv_755, argv_413);	EnableWindow (hwnd_std, FALSE);
	}
	if (_is_file == true) {
		hwnd_std = GetDlgItem (argv_326.argv_755, argv_414);	EnableWindow (hwnd_std, FALSE);
	}
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_517);		EnableWindow (hwnd_std, FALSE);
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_498);			EnableWindow (hwnd_std, FALSE);
}

void argv_256 (bool _is_folder, bool _is_file) {
	HWND hwnd_std;
	if (_is_folder == true) {
		hwnd_std = GetDlgItem (argv_326.argv_755, argv_413);	EnableWindow (hwnd_std, TRUE);
	}
	if (_is_file == true) {
		hwnd_std = GetDlgItem (argv_326.argv_755, argv_414);	EnableWindow (hwnd_std, TRUE);
	}
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_517);		EnableWindow (hwnd_std, TRUE);
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_498);			EnableWindow (hwnd_std, TRUE);
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_413); 
	SetWindowText (hwnd_std, "Erase File");
	hwnd_std = GetDlgItem (argv_326.argv_755, argv_414); 
	SetWindowText (hwnd_std, "Erase Folder");
}

bool argv_161 () {
	bool bret = true;
	argv_326.argv_666 = argv_669; 

	int cell_index = SendDlgItemMessage (argv_326.argv_755, argv_517, CB_GETCURSEL, 0, 0);
	char tmp[256];
	SendDlgItemMessage (argv_326.argv_755, argv_517, CB_GETLBTEXT, (WORD)cell_index, (LONG)tmp);

	if (strcmp (tmp, "High") == 0) {
		argv_326.argv_666 = argv_669;
		SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Ready (strong entropy: 35 pass)");
	}
	else if (strcmp (tmp, "Medium") == 0) {
		argv_326.argv_666 = argv_668;
		SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Ready (medium entropy: 18 pass)");
	}
	else if (strcmp (tmp, "Low") == 0) {
		SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Ready (Low entropy: 1 pass)");
		argv_326.argv_666 = argv_667;
	}
	else {
		MessageBox (NULL, "Please choose an entropy strength !", "Strength not chosen", MB_ICONERROR);
		bret = false;
	}
	return (bret);
}

void argv_744 () {
	argv_188 file_bar;
	file_bar.init (argv_326.argv_755, argv_489, 10);	
	file_bar.init (argv_326.argv_755, argv_491, 10);
	argv_161 ();
}

DWORD WINAPI argv_250 (LPVOID lParam) {
	SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "preparing random generator...");
	argv_326.argv_731.argv_728 ();
	SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Ready");
	return (0);
}

void argv_727 () {
	bool bret = true;
	DWORD dwThreadId;
	HANDLE hThread; 
	hThread = CreateThread (NULL,0, argv_250, NULL,0,&dwThreadId);
	if (hThread == NULL)   {
		MessageBox (NULL, "Thread creation failed", "Error", MB_OK | MB_ICONERROR);			
		bret = false;
	}
}

void argv_238 () {
	char tmp[argv_773];
	argv_760 (tmp, argv_773, "<CANCEL SCHEDULED> erasing content (pass %u)", argv_326.argv_228+1);
	tmp[argv_773 - 1] = '\0';
	SendDlgItemMessage (argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) tmp);
	argv_236 (true, true);
}

//-------------------------------------------------------------
LRESULT CALLBACK argv_160(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
			argv_326.argv_755	= hDlg;
			argv_738 = hDlg;
			argv_191 (hDlg);
			argv_725 ();
			SetTimer (hDlg, argv_604, 2000, (TIMERPROC) NULL);
			SendDlgItemMessage(argv_326.argv_755, argv_516, WM_SETTEXT, 0, (LPARAM) "Preparing...(please wait)");
			return TRUE;

		case WM_TIMER: // this message is sent automatically when timer expires
			if (wParam == argv_604) { // the identifier of the timer that has fired
				KillTimer (hDlg, argv_604);
				argv_727 ();
			}
			break;

		case WM_COMMAND:
			switch( HIWORD( wParam ) ) {
				case CBN_SELCHANGE:
					argv_161 ();
					break;
			}

			switch(LOWORD(wParam)) {
				case IDOK:
				case IDCANCEL:
					ShowWindow (hDlg, SW_SHOW);
					EndDialog(hDlg, LOWORD(wParam));
					return TRUE;
				break;

				case argv_498:
					if (IsDlgButtonChecked (hDlg, argv_498) == BST_CHECKED) {
						argv_326.argv_737 = true;
					}
					else {
						argv_326.argv_737 = false;
					}
					break;
				
				case argv_413:
					if (argv_326.argv_753 == false) {
						if (argv_161 () == true) {
							argv_221 (NULL);
						}
					}
					else if (MessageBox (hDlg, "Are you sure you want to abort operation ?", "Question", MB_YESNO | MB_ICONWARNING)==IDYES) {
						argv_238 ();
						argv_326.argv_305 = true;
						argv_326.argv_753 = false;
					}
					break;

				case argv_414: 
					if (argv_326.argv_753 == false) {
						if (argv_161 () == true) {
							argv_223 ();
						}
					}
					else if (MessageBox (hDlg, "Are you sure you want to abort operation ?", "Question", MB_YESNO | MB_ICONWARNING)==IDYES) { 
						argv_238 ();
						argv_326.argv_305 = true;
						argv_326.argv_753 = false;
						HWND hwnd_std = GetDlgItem (argv_326.argv_755, argv_414); 
						SetWindowText (hwnd_std, "Erase Folder");
					}
					break;
			}
	}
	return FALSE;
}
