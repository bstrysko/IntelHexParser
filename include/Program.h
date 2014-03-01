/*
 * Program.h
 * Created by Brent Strysko
 *
 * A Program represents the data
 * stored by a Intel Hex File
 * organized in increasing page address
 * order.
 */

#ifndef _INTEL_HEX_PARSER_PROGRAM_H_
#define _INTEL_HEX_PARSER_PROGRAM_H_

#include <sstream>
#include <map>
#include <vector>
#include <stdint.h>

#include "ProgramPage.h"
#include "IntelHexFileEntry.h"

using namespace std;

class Program
{
  private:
    size_t pageSize;
    vector<ProgramPage> pages;
  public:
    Program(size_t pageSize, map<uint16_t, IntelHexFileEntry> addressToFileEntries);
    ~Program();

    size_t getPageSize();

    vector<ProgramPage> getPages();
};

#endif
