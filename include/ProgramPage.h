/*
 * ProgramPage.h
 * Created by Brent Strysko
 *
 * A ProgramPage represents the data
 * that a processor with a page of size
 * pageSize would hold at address.
 */

#ifndef _INTEL_HEX_PARSER_PROGRAM_PAGE_H_
#define _INTEL_HEX_PARSER_PROGRAM_PAGE_H_

#include "IntelHexFileEntry.h"

#include <sstream>
#include <vector>
#include <stdint.h>
#include <string.h>

using namespace std;

class ProgramPage
{
  private:
    size_t address;
    size_t pageSize;
    vector<uint8_t> data;
  public:
    ProgramPage(size_t address, size_t pageSize, const vector<uint8_t>& pageData);
    ~ProgramPage();

    size_t getAddress();
    size_t getPageSize();
    size_t getSize();
    size_t getEndAddress();

    vector<uint8_t> getData();

    friend ostream& operator<<(ostream& os, const ProgramPage& rhs);
};

#endif
