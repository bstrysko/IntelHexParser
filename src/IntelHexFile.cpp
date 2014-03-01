#include <IntelHexFile.h>

IntelHexFile::IntelHexFile()
{

}

IntelHexFile::~IntelHexFile()
{

}

void IntelHexFile::load(string filename)
{
	ifstream file(filename.c_str());

	if(!file.is_open())
	{
		stringstream o;
		o << "Cannot load file ";
		o << filename;
		throw ios_base::failure(o.str());
	}

	char buffer[INTEL_HEX_FILE_MAX_ENTRY_SIZE];

	while(true)
	{
		file.getline(buffer, INTEL_HEX_FILE_MAX_ENTRY_SIZE);

		/*
		 * End of file
		 */
		if(!file)
		{
			break;
		}

		IntelHexFileEntry entry;
		entry.parseEntry(buffer);
		addressToFileEntries.insert(pair<uint16_t, IntelHexFileEntry>(entry.getAddress(), entry));
	}
}

Program IntelHexFile::getProgram(size_t pageSize)
{
	return Program(pageSize, addressToFileEntries);
}
