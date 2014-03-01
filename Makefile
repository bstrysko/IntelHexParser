# Source Files
SRC = \
	src/I2CBus.cpp \
	src/I2CDevice.cpp

OBJ = $(SRC:.cpp=.o)
LIBNAME = libI2CMaster.so
OUT = $(LIBNAME).1
REALNAME = $(OUT)

# Include Directories
INCLUDES = -I./include/

CCFLAGS = -g -fPIC
CCC = g++

#Library Paths
LIBS =
 
# compile flags
LDFLAGS = -g
 
.SUFFIXES: .cpp
 
all: build

build: $(OUT)
 
.cpp.o:
	$(CCC) $(INCLUDES) $(CCFLAGS) -c $< -o $@
 
$(LIB_OUT): $(OBJ)
	$(CCC) -shared -Wl,-soname,$(OUT) -o $(REALNAME) $(OBJ) 

install: build
	mkdir -p /usr/include/I2CMaster/
	cp include/* /usr/include/I2CMaster/
	cp $(REALNAME) /usr/lib/
	ln -sf /usr/lib/$(REALNAME) /usr/lib/$(LIBNAME)

clean:
	rm -f $(OBJ) $(OUT)
