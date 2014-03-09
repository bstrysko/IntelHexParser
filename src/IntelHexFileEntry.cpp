#include <IntelHexFileEntry.h>

#include <iostream>

IntelHexFileEntry::IntelHexFileEntry()
{

}

IntelHexFileEntry::IntelHexFileEntry(string entry)
{
	if(entry[0] != ':')
	{
		stringstream o;
		o << "Invalid hex entry: ";
		o << entry;
		throw ios_base::failure(o.str());
	}

	uint8_t count = 2*asciiHexTo64(entry.substr(1,2));
	address = asciiHexTo64(entry.substr(3,4));
	recordType = asciiHexTo64(entry.substr(7,2));	

	if(count != entry.length()-(9+2+1))
	{
		stringstream o;
		o << "length provided != length of data | ";
		o << (uint32_t)(count);
		o << " != ";
		o << (entry.length()-(9+2+1));

		throw ios_base::failure(o.str());
	}

	for(uint8_t i = 0; i < count; i+=2)
	{
		data.push_back(asciiHexTo64(entry.substr(9+i,2)));
	}

	uint8_t checksum = asciiHexTo64(entry.substr(entry.length()-3,2));

	//TODO: compute checksum
}

IntelHexFileEntry::~IntelHexFileEntry()
{
}

uint64_t IntelHexFileEntry::asciiHexTo64(string s)
{
	stringstream o;
	o << hex << s;
	uint64_t v;
	o >> v;
	return v;
}

uint8_t IntelHexFileEntry::getByteCount()
{
	return data.size();
}

uint16_t IntelHexFileEntry::getAddress()
{
	return address;
}

uint16_t IntelHexFileEntry::getEndAddress() const
{
	return address + data.size();
}

uint8_t IntelHexFileEntry::getRecordType()
{
	return recordType;
}

vector<uint8_t> IntelHexFileEntry::getData()
{
	return data;
}

uint8_t IntelHexFileEntry::getChecksum()
{
	return checksum;
}
