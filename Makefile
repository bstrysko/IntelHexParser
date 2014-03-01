# Source Files
SRC = \
	src/IntelHexFile.cpp \
	src/IntelHexFileEntry.cpp \
	src/Program.cpp \
	src/ProgramPage.cpp

OBJ = $(SRC:.cpp=.o)
OUT = libIntelHexParser.a

# Include Directories
INCLUDES = -I./include/

CCFLAGS = -g
CCC = g++

#Library Paths
LIBS =
 
# compile flags
LDFLAGS = -g
 
.SUFFIXES: .cpp
 
all: build

build: $(OUT)
 
$(OUT): $(OBJ)
	$(CCC) rcs $(OUT) $(OBJ)

.cpp.o:
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@ 

install: build
	echo "Not yet implemented"

clean:
	rm -f $(OBJ) $(OUT)
