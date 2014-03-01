/*
 * IntelHexFile.h
 * Created by Brent Strysko
 *
 * A IntelHexFile represents the
 * *.hex file provided to the library.
 */

#ifndef _INTEL_HEX_PARSER_INTEL_HEX_FILE_H_
#define _INTEL_HEX_PARSER_INTEL_HEX_FILE_H_

#include <sstream>
#include <string>
#include <vector>
#include <stdint.h>

#include "Program.h"

using namespace std;

class IntelHexFile
{
  private:
  
  public:
    IntelHexFile();
    ~IntelHexFile();

    void load(string filename);

    Program getProgram(size_t pageSize);
};

#endif
