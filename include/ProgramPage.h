/*
 * ProgramPage.h
 * Created by Brent Strysko
 *
 * A ProgramPage represents the data
 * that a processor with a page of size
 * size would hold at address.
 */

#ifndef _INTEL_HEX_PARSER_PROGRAM_PAGE_H_
#define _INTEL_HEX_PARSER_PROGRAM_PAGE_H_

#include <sstream>
#include <stdint.h>

using namespace std;

class ProgramPage
{
  private:
    size_t address;
    size_t size;
    uint8_t* data;
  public:
    ProgramPage(size_t address, size_t size);
    ~ProgramPage();

    size_t getAddress();
    size_t getSize();

    void write8(size_t offset, uint8_t v);
    void write16(size_t offset, uint16_t v);

    uint8_t* getData();
};

#endif
