#include <ProgramPage.h>

ProgramPage::ProgramPage(size_t address, size_t pageSize, const vector<uint8_t>& pageData)
{
	this->address = address;
	this->pageSize = pageSize;
	data.resize(pageData.size());
	
	size_t startAddress = address % pageSize;

	for(size_t i = startAddress; i < (startAddress + pageData.size()); i++)
	{
		data[i] = pageData[i - startAddress];
	}
}

ProgramPage::~ProgramPage()
{
}

size_t ProgramPage::getAddress()
{
	return address;
}

size_t ProgramPage::getSize()
{
	return data.size();
}

size_t ProgramPage::getPageSize()
{
	return pageSize;
}

size_t ProgramPage::getEndAddress()
{
	return address + data.size();
}

vector<uint8_t> ProgramPage::getData()
{
	return data;
}

ostream& operator<<(ostream& os, const ProgramPage& rhs)
{
	os << "[Start Address: 0x" << hex << rhs.address;
	os << ", End Address: 0x" << hex << (rhs.address+rhs.data.size());
	os << ", Size: " << rhs.data.size();
	os << ", Page Size: " << dec << rhs.pageSize;
	os << ", Data: ";

	for(vector<uint8_t>::const_iterator it = rhs.data.begin(); it != rhs.data.end(); ++it)
	{
		uint8_t v = *it;
		os << hex << (size_t)v;
	} 

	os << dec << "]";
}

