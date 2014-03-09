/*
 * IntelHexFile.h
 * Created by Brent Strysko
 *
 * A IntelHexFile represents the
 * *.hex file provided to the library.
 */

#ifndef _INTEL_HEX_PARSER_INTEL_HEX_FILE_H_
#define _INTEL_HEX_PARSER_INTEL_HEX_FILE_H_

#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <stdint.h>

#include "IntelHexFileEntry.h"
#include "Program.h"

using namespace std;

#define INTEL_HEX_FILE_MAX_ENTRY_SIZE 524

class IntelHexFile
{
  private:
    map<uint16_t, IntelHexFileEntry> addressToFileEntries;
  public:
    IntelHexFile(string filename);
    ~IntelHexFile();

    Program getProgram();

    friend ostream& operator<<(ostream& os, const IntelHexFile& rhs);
};

#endif
