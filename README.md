@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@ MIGALE ERASER PROJECT    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


Document Title	: MIGALE ANTIVIRUS PROJECT DESCRIPTION
Author			: tybins99@hotmail.com
Date			: 2009/06/07
Revision		: 1.0 


1. Migale Eraser Brief description
---------------------------------------
Migale Eraser is a tool permitting to erase securely any file or
folder of your hard-drive, preventing from any undelete or recovery
using forensic tools.


2. Migale Security Suite Project
---------------------------------------
Migale Eraser is a part of the "Migale Security Software Suite"
available on SourceForge at the following URL:
http://sourceforge.net/projects/migaleantivirus

The original homepage of the project can be found here:
http://tybins99.tripod.com

Migale Antivirus is a security software suite that uses Clamav signatures.
Migale Antivirus is a win32 software containing:
- an antivirus capable of recognizing about 50'000 viruses
- an update tool (based on HTTP).
- a PE files analyzer
- a PE simple packer for packers techniques study.
- a PE encryption & protection tool
- a tool permitting to generate automatically signatures for polymorphic viruses.
- a recovery database daemon
- a tool that permits to dysinfect unknown viruses
- a tool permitting to detect and gather all potential viruses on a system 
  without using signature scheme (useful for honeypot).
- a control center to launch any of these applications.  

2. Developement environment
-----------------------------------------
Migale software was compiled on:
OS: Windows XP - SP2
Compiler: Microsoft Visual Studio 6.0



2. Migale Eraser detailed description
-----------------------------------------
Migale Eraser has several working modes:
- delete safely a chosen file
- delete safely a chosen folder considering only the files of this folder.
- delete safely all files and sub-folders of the chosen folder (recursive mode).

	2.1 Random number generator initialization
	------------------------------------------
	In order to be able to erase safely the file's content, we need a strong pseudo-ramdom
	generator. To do so, we use a modified version of RC4 and Data Encryption Standard algorithms
	and the keys for these algorithms are generated using 16 bootlegs that are initialized using
	the non-deterministic properties of the thread scheduling on a given operating system.

	2.2 Entropy strength selection
	------------------------------
	Due to magnetic remanance, even if you overwrite the file's content with a constant value,
	it is still possible to retrieve the original file's content to some extent using advanced
	forensic tools.
	To countermeasure this threat, Migale Eraser has several possible entropy modes:
	- one pass (the weakest security, but the fastest mode)	
	- 18 passes (better than one pass, and faster than the next mode)
	- 35 pass (Gutmann method, the strongest, but the slowest mode).

	The 35-pass Gutmann method is recognized as the most secure erasing option available. 
	The 7-Pass and 3-Pass DOD methods are based on standards outlined in the Department of Defense Manual 5220.22 M . 
	You can feel secure with these methods. 
	The Gutmann is in a class by itself though. The data area (or freespace) is overwritten 35 times. 
	This method uses pseudorandom data to overwrite the drive and then overwrites the drive based on the different 
	and unique encoding algorithms.
	
	2.3 Erasure Cancellation
	------------------------
	You can decide to stop the erasure procedure by clicking on the "stop" button.
	However stopping a file erasure in the middle of the file is very dangerous because it will
	truncate the file and thus leave important data available for forensic tools.
	Thus the cancellation will not stop immediately the erasure procedure, instead, Migale Eraser
	will finish the current pass of the current file, and then will stop, thus ensuring that the
	file currently being erased will be safely erased.


3. Bug report
-------------
You can report any bug or problem at the following email:
tybins99@hotmail.com


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@ MIGALE ERASER PROJECT    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Document Title	: compile_howto.txt
Author			: tybins99@hotmail.com
Date			: 2009/06/07
Revision		: 1.0 


How to compile any of the project of the Migale Eraser software ?
----------------------------------------------------------

First, all the project has been compiled using Visual Studio 6.0
Thus it is not guaranteed that it will compile using other compiler.

To open the source code, double-click on the file ~SRC/zor.dsw
this is the first file to open with Visual Studio to browse the source 
code and compile it.

Notice that the project is compiled in release mode only
(thus it is not guaranteed that it will compile in debug mode).



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
@@ MIGALE ERASER PROJECT    @@
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

Document Title	: description.txt
Author			: tybins99@hotmail.com
Date			: 2009/06/07
Revision		: 1.0 



1. How to install Migale Eraser on your computer ?
----------------------------------------------------------
The software does not need any installation.
You just have to go to the BIN directory and double-click
on the "migale_eraser.exe" file to execute the program.







