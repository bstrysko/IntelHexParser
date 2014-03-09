#include "../include/IntelHexFile.h"

#include <iostream>
#include <assert.h>

using namespace std;

void usage(string name);

#define PAGE_SIZE 255

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		usage(argv[0]);
	}

	IntelHexFile file(argv[1]);

	cout << "File: " << file << endl;

	Program program = file.getProgram();
	
	cout << "Program: " << program << endl;

	vector<ProgramPage> programPages = program.getPages(PAGE_SIZE);

	for(vector<ProgramPage>::iterator it = programPages.begin(); it != programPages.end(); ++it)
	{
		ProgramPage page = (*it);
		cout << "Page: " << page << endl;
	}

	return 0;
}

void usage(string name)
{
	cout << name << ": [*.hex]" << endl;
}
