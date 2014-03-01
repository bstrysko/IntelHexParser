#include <IntelHexFileEntry.h>

IntelHexFileEntry::IntelHexFileEntry()
{
	parsed = false;
}

IntelHexFileEntry::~IntelHexFileEntry()
{
}

uint64_t IntelHexFileEntry::asciiHexTo64(string s)
{
	stringstream o;
	o << s;
	uint16_t v;
	o >> hex >> v;
	return v;
}

void IntelHexFileEntry::parseEntry(string entry)
{
	if(parsed)
	{
		throw ios_base::failure(
			"This IntelHexFileEntry already holds parsed data"
		);
	}

	if(entry[0] != ':')
	{
		stringstream o;
		o << "Invalid hex entry: ";
		o << entry;
		throw ios_base::failure(o.str());
	}

	uint8_t count = asciiHexTo64(entry.substr(1,2));
	address = asciiHexTo64(entry.substr(3,4));
	recordType = asciiHexTo64(entry.substr(7,2));	

	if(count != entry.length()-(9+2))
	{
		throw ios_base::failure(
			"length provided != length of data"
		);
	}

	for(uint8_t i = 0; i < count; i+=2)
	{
		data.push_back(asciiHexTo64(entry.substr(9+i,2)));
	}

	uint8_t checksum = asciiHexTo64(entry.substr(entry.length()-2,2));

	//TODO: compute checksum	

	parsed = true;
}

uint8_t IntelHexFileEntry::getByteCount()
{
	return data.size();
}

uint16_t IntelHexFileEntry::getAddress()
{
	return address;
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
