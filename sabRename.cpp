#include <string>
#include <Windows.h>
#include <cstdio>
#include <iostream>

using namespace std;

//No need for a header in this program
string biggestFile(string);
void frename(string,string);

//Handles arguments, sets variables, calls the find-the-biggest-file function and the rename function.
int main( int argc, char* argv[] ) {
	cout << endl << "{" << endl;
	for(int i = 0 ; i<argc ; i++){
		cout << "  " << argv[i] << "," << endl;
	}
	cout << "}" << endl;

	string file = biggestFile(argv[1]);
	string old, ren, newname = argv[3], path = argv[1];
	old = path;
	old.append("\\").append(file);
	ren = path;
	ren.append("\\").append(newname);
	cout << "Old name: " << old << endl;
	frename(old, ren);

	cout << ren << endl;
	return 0;
}

//Find biggest file in folder.
string biggestFile(string dir){
	cout << "Searching in dir: " << dir << endl;
	WIN32_FIND_DATA ffd;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	LARGE_INTEGER fSize;
	fSize.HighPart = 0;
	fSize.LowPart = 0;
	string t;

	if(dir.length() > (MAX_PATH - 3)){
		return "-";
	}

	dir.append("\\*");

	hFind = FindFirstFile(TEXT(dir.c_str()), &ffd);

	if (INVALID_HANDLE_VALUE == hFind) {
		return "-";
	}
	
	do {
		if (ffd.nFileSizeHigh > fSize.HighPart) {
			fSize.HighPart = ffd.nFileSizeHigh;
			fSize.LowPart = ffd.nFileSizeLow;
			t = ffd.cFileName;
		} else if((ffd.nFileSizeHigh == fSize.HighPart) && (ffd.nFileSizeLow > fSize.LowPart)){
			fSize.HighPart = ffd.nFileSizeHigh;
			fSize.LowPart = ffd.nFileSizeLow;
			t = ffd.cFileName;
		}
	} while (FindNextFile(hFind, &ffd) != 0);

	cout << "Found: " << t << endl;

	return t;
}

//Find extention to use and rename the file
void frename(string o, string n){
	string ext = o.substr(o.find_last_of("."));
	cout << "Found extention! (" << ext << ")" << endl;
	n.append(ext);
	cout << "New name: " << n << endl;
	rename(o.c_str(), n.c_str());
}