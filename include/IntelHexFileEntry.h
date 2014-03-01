/*
 * IntelHexFileEntry.h
 * Created by Brent Strysko
 *
 * A IntelHexFileEntry represents a
 * textually parsed entry in a Intel hex file.
 */

#ifndef _INTEL_HEX_PARSER_INTEL_HEX_FILE_ENTRY_H_
#define _INTEL_HEX_PARSER_INTEL_HEX_FILE_ENTRY_H_

#include <sstream>
#include <vector>
#include <stdint.h>

using namespace std;

class IntelHexFileEntry
{
  private:
    uint16_t address;
    uint8_t recordType;
    vector<uint8_t> data;
    uint8_t checksum;
  public:
    IntelHexFileEntry();
    ~IntelHexFileEntry();

    void parseEntry(string entry);

    uint8_t getByteCount();
    uint16_t getAddress();
    uint8_t getRecordType();
    vector<uint8_t> getData();
    uint8_t getChecksum();
};

#endif
