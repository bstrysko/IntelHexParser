#include <IntelHexFile.h>

#include <iostream>

IntelHexFile::IntelHexFile(string filename)
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

		IntelHexFileEntry entry(buffer);

		if((entry.getRecordType() != 0x0) && (entry.getRecordType() != 0x1))
		{
			stringstream o;
			o << "Unsupported record type: 0x";
			o << hex << (uint32_t)entry.getRecordType();
			throw ios_base::failure(o.str());
		}

		addressToFileEntries.insert(pair<uint16_t, IntelHexFileEntry>(entry.getAddress(), entry));
	}
}

IntelHexFile::~IntelHexFile()
{
}

Program IntelHexFile::getProgram()
{
	return Program((const map<uint16_t, IntelHexFileEntry>)addressToFileEntries);
}

ostream& operator<<(ostream& os, const IntelHexFile& rhs)
{
	size_t lAddress = (rhs.addressToFileEntries.begin())->first;	
	size_t hAddress = ((rhs.addressToFileEntries.rbegin())->second).getEndAddress();
	size_t size = rhs.addressToFileEntries.size();

	os << "[Address Range: 0x" << hex << (size_t)lAddress << "-0x" << hex << (size_t)hAddress << ", Number of HexFileEntries: " << dec << size << "]";
}

