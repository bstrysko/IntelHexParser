#include <Program.h>

Program::Program(const map<uint16_t, IntelHexFileEntry>& addressToFileEntries)
{
	size_t hAddress = ((addressToFileEntries.rbegin())->second).getEndAddress();
	data.resize(hAddress);

	for(map<uint16_t, IntelHexFileEntry>::const_iterator it = addressToFileEntries.begin(); it != addressToFileEntries.end(); ++it)
	{
		size_t address = (size_t)it->first;
		IntelHexFileEntry entry = it->second;
		vector<uint8_t> entryData = entry.getData();

		for(size_t i = 0; i < entryData.size(); i++)
		{
			uint8_t v = entryData[i];
			data[address + i] = v;
		}
	}
}

Program::~Program()
{
}

vector<ProgramPage> Program::getPages(size_t pageSize)
{
	vector<ProgramPage> pages;

	for(size_t i = 0; i < data.size(); i+= pageSize)
	{
		size_t pageEndAddress = min(i + pageSize, data.size());

		vector<uint8_t> pageData(data.begin() +i, data.begin() + pageEndAddress);
		ProgramPage p(i, pageSize, pageData);
		pages.push_back(p);
	}

	return pages;
}

ostream& operator<<(ostream& os, const Program& rhs)
{
	os << "[Num Bytes: " << rhs.data.size() << ", Data: ";
	
	for(vector<uint8_t>::const_iterator it = rhs.data.begin(); it != rhs.data.end(); ++it)
	{
		uint8_t v = (*it);
		os << hex << (size_t)v;
	}

	os << dec << "]";
}

