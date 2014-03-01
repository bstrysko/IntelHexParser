#include "../include/IntelHexFile.h"

#include <iostream>

using namespace std;

void usage(string name);

#define PAGE_SIZE 255

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		usage(argv[0]);
	}

	IntelHexFile file;

	file.load(argv[1]);

	cout << file << endl;

	Program program = file.getProgram(PAGE_SIZE);
	assert(program.getPageSize() == PAGE_SIZE);

	cout << program << endl;

	vector<ProgramPage> programPages = program.getPages();

	for(vector<ProgramPage>::iterator it = programPages.begin(); it != programPages.end(); ++it)
	{
		ProgramPage page = (*it);
		cout << page << endl;
	}

	return 0;
}

void usage(string name)
{
	cout << name << ": [*.hex]" << endl;
}
