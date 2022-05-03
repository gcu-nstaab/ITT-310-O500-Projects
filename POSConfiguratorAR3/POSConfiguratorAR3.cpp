/* POS Configurator - Release 3 - 0.3 - Nathan Staab - ITT-310-O500
 * This program is intended to streamline POS configuration for the Aloha POS - www.ncr.com - Works on all versions up to 12.3.
 * you COULD use this on v15 - but it would be awfully difficult as RAL is required, and v15 is least privlidged - running this would result in an error message.
 */


#include <stdio.h>
#include <iostream>
#include <fstream>
#include "userdefs.h" //New For Release #2 - User Definitions - Future Configurability
#include <ctime> // Goes with Chrono below.
#include <chrono> //Older implementations are prone to issues - ctime, and ctime_s is a pain - New for Release 2

 //Standard Namespace
using namespace std;


//Begin Main Routine
int main()
{
    //Initialize our Variables
    int numterms;
    int term_num;
    char yesno;
    time_t now = time(0);

    tm* ltm = localtime(&now);

    //Ask User for Number of Terminals - NUMTERMS
    cout << "Enter Number Of Terminals: ";
    cin >> numterms;
    //Ask User For The Actual POS Terminal's Number - TERM
    cout << "Enter This Terminals Number: ";
    cin >> term_num;
    //Can we write to this folder? if not - bail out
    ofstream outfile;
    outfile.open("Aloha.reg");
    if (!outfile)
    {
        cout << "Cannot open file.\n";
        system("PAUSE");
        return 1;
    }
    //We're generating IBERCFG.BAT here - with our variables.
    outfile << "Windows Registry Editor Version 5.00\n\n";
    outfile << "[HKEY_LOCAL_MACHINE\\SYSTEM\\ControlSet001\\Control\\Session Manager\\Environment]\n";
    outfile << "\"AUTOEXIT\"=\"TRUE\"\n";
    outfile << "\"EDCPATH\"=\"\\\\ALOHABOH\\BOOTDRV\\Aloha\\EDC\n";
    outfile << "\"IBERDIR\"=\"C:\\BOOTDRV\\Aloha\"\n";
    outfile << "\"IBERROOT\"=\"Aloha\"\n";
    outfile << "\"LOCALDIR\"=\"C:\\BOOTDRV\\Aloha\"\n";
    outfile << "\"MASTERCAPABLE\"=\"TRUE\"\n";
    outfile << "\"NUMTERMS\"=\"" << numterms << "\"\n";
    outfile << "\"REBOOTNT\"=\"FALSE\"\n";
    outfile << "\"ROBUST\"=\"TRUE\"\n";
    outfile << "\"SERVER\"=\"ALOHABOH""\"\n";
    outfile << "\"SERVERCAPABLE\"=\"TRUE\"\n";
    outfile << "\"TERM\"=\"" << term_num << "\"\n";
    outfile << "\"TERMSTR\"=\"TERM""\"\n";
    outfile << "\"CONCATTRNM\"=\"" << numterms << term_num << "\"\n"; //Here We've Created a union of two seperate variables. CONCATTRNM - both term number and numterms. not useful but proof of concept.

    outfile.close();
    //Close our Registry file - write to disk. & open new configuration file - ibercfg.bat
    outfile.open("IBERCFG.bat");
    if (!outfile)
    {
        cout << "Cannot open file.\n";
        system("PAUSE");
        return 1;
    }
    //Write these to ibercfg.bat.
    outfile << "@ECHO OFF\n";
    outfile << "SET LOCALDIR=C:\\BOOTDRV\\Aloha\n";
    outfile << "REM Delete HALT & Exiting Files\n";
    outfile << "IF EXIST %LOCALDIR%\\TMP\\EXITING DEL %LOCALDIR%\\TMP\\EXITING >NUL\n";
    outfile << "IF EXIST C:\\HALT DEL C:\\HALT >NUL\n\n";
    outfile << "REM Ensure Nothing In BIN, Data, BMP Are Read Only\n";
    outfile << "ATTRIB -R %LOCALDIR%\\BIN\\*.* >NUL\n";
    outfile << "ATTRIB -R %LOCALDIR%\\DATA\\*.* >NUL\n";
    outfile << "ATTRIB -R %LOCALDIR%\\BMP\\*.* >NUL\n\n";
    outfile << "REM Ensure Nothing In NEWBIN Is Read Only, Then If Files Exist, Copy Them Into Bin And Delete From Newbin\n";
    outfile << "IF EXIST %LOCALDIR%\\NEWBIN\\*.* ATTRIB -R %LOCALDIR%\\NEWBIN\\*.* >NUL\n";
    outfile << "IF EXIST %LOCALDIR%\\NEWBIN\\*.* COPY %LOCALDIR%\\NEWBIN\\*.* %LOCALDIR%\\BIN\n";
    outfile << "ECHO Y | DEL %LOCALDIR%\\NEWBIN\\*.*\n\n";
    outfile << "REM Ensure Terminal Has Aloha.INI\n";
    outfile << "IF NOT EXIST %LOCALDIR%\\DATA\\Aloha.INI COPY \\%SERVER%\\BOOTDRV\\Aloha\\DATA\\Aloha.INI %LOCALDIR%\\DATA\n";
    outfile << "REM Ensure If Terminal Has OCD, That It's Software Gets Loaded\n";
    outfile << "IF EXIST %LOCALDIR%\\BIN\\RSSLoad.EXE START %LOCALDIR%\\BIN\\RSSLoad.EXE\n\n";
    outfile << "REM Let's Sync the Time With the Aloha Server Before Starting Iber...\n";
    outfile << "NET TIME \\\\%SERVER% /SET /Y\n\n";
    outfile << "REM Now.. Finally, Start IBER!\n";
    outfile << "START %LOCALDIR%\\BIN\\IBER.EXE\n\n";

    outfile.close();
    //Close our file - ibercfg.bat & open the network config bat
    outfile.open("Network.bat");
    if (!outfile)
    {
        cout << "Cannot open file.\n";
        system("PAUSE");
        return 1;
    }
    //This is where we build the additional batch files to actually do the work
    outfile << "regedit /s aloha.reg\n";
    //We've found that this environment variable might NOT yet be set - but we require it for everything to work
    outfile << "set LOCALDIR=C:\\BOOTDRV\\Aloha\n";
    outfile << "ECHO Y | copy IBERCFG.bat C:\\BOOTDRV\\Aloha\\\n";
    //We're also finding that when imaging terminals - the network type might be different - and generate local area connection X - this could be cleaner, but this is easy to diagnose.
    outfile << "netsh interface ip set address name=\"local area connection\"  static 10.253.1.10"
        << term_num << " 255.255.255.0 10.253.1.100 \n";
    outfile << "netsh interface ip set address name=\"local area connection 2\" static 10.253.1.10"
        << term_num << " 255.255.255.0 10.253.1.100 \n";
    outfile << "netsh interface ip set address name=\"local area connection 3\" static 10.253.1.10"
        << term_num << " 255.255.255.0 10.253.1.100 \n";
    outfile << "netsh interface ip set address name=\"local area connection 4\" static 10.253.1.10"
        << term_num << " 255.255.255.0 10.253.1.100 \n";
    //WMI calls may soon be obsolete in non-IOT Windows 10 machines - we may have to wrap this into powershell later
    outfile << "wmic path win32_computersystem where \"Name='%computername%'\""
        " CALL rename name='TERM" << term_num << "'\n";
    outfile << "wmic path win32_computersystem where \"Name='%computername%'\""
        " CALL joindomainorworkgroup name='ALOHA""'\n";
    //Now we're going to write out a command to copy the files required.. note that the IP is hard-coded.
    outfile << "xcopy \\\\10.253.1.100\\BOOTDRV\\Aloha\\bin\\*.* /y/c %LOCALDIR%\\bin\\*.*\n";
    outfile << "xcopy \\\\10.253.1.100\\BOOTDRV\\Aloha\\data\\*.* /y/c %LOCALDIR%\\data\\*.*\n";
    outfile << "xcopy \\\\10.253.1.100\\BOOTDRV\\Aloha\\bmp\\*.* /y/c %LOCALDIR%\\bmp\\*.*\n";
    //Write out a reboot command after configuration
    outfile << "shutdown /r -f -t 5\n";

    outfile.close();
    wcout << "\n\Execution Called on " << ltm << ""; //Release 2 - learned something - cout is not WIDE enough - we must use WIDE cout - or wcout. cout just prints addresses! - Need to adjust in R3
    cout << "\n\You Defined the terminal number as " << term_num << ""; //Release 2 - Our carriage return had to be at the beginning to wrap these lines! - we also had to transition from printf to cout
    cout << "\n\You Defined the number of terminals as " << numterms << ""; // Release 2 - same issue

    cout << "\n\OK to apply changes? (Y/N): "; //Release 2 - Additional carriage return to make spacing correct.
    cin >> yesno;

    if (yesno == 'y' || yesno == 'Y')
    {
        //  system("start network.bat"); //Here we would call the batch files that run this. not time time.
    }

    return 0;
}
