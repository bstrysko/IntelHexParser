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
	uint8_t hAddress = asciiHexTo64(entry.substr(3,2));
	uint8_t lAddress = asciiHexTo64(entry.substr(5,2));
	address = ((hAddress << 8) | lAddress);
	recordType = asciiHexTo64(entry.substr(7,2));	

	uint8_t cChecksum = (count/2) + lAddress + hAddress + recordType;

	if(count != entry.length()-(9+2+1))
	{
		stringstream o;
		o << "length provided != length of data | ";
		o << (size_t)(count);
		o << " != ";
		o << (entry.length()-(9+2+1));

		throw ios_base::failure(o.str());
	}

	for(uint8_t i = 0; i < count; i+=2)
	{
		uint8_t v = asciiHexTo64(entry.substr(9+i,2));
		cChecksum += v;
		data.push_back(v);
	}

	uint8_t checksum = asciiHexTo64(entry.substr(entry.length()-3,2));

	if(((uint8_t)(cChecksum + checksum)) != ((uint8_t)0))
	{
		cout << hex << (size_t)address << endl;
		cout << dec;

		stringstream o;
		o << "(cChecksum + checksum) != 0 | 0x";
		o << hex;
		o << (size_t)(cChecksum + checksum);
		o << " != 0 | cChecksum = 0x";
		o << (size_t)cChecksum;
		o << ", checksum = 0x";
		o << (size_t)checksum;

		throw ios_base::failure(o.str());
	}
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
