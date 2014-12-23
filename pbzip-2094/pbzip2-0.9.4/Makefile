# Make file for parallel BZIP2

# Compiler to use
ifndef CXX
CXX=g++
endif

# Flags
CFLAGS=-g -O3 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64
CFLAGS_COMPAT=-g -O3 -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64

# Where you want pbzip2 installed when you do 'make install'
PREFIX=/opt/pbzip-2094

all: pbzip2

# Standard pbzip2 compile
pbzip2: pbzip2.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) -o pbzip2 pbzip2.cpp -pthread -lpthread -lbz2
	objdump -M intel -d pbzip2 > pbzip2.s
ifdef LLVM_BUILD
	llvm-dis pbzip2.bc
	opt -dot-cfg pbzip2.bc > /dev/null
	mkdir -p cfg; mv *.dot cfg; 
endif

# Choose this if you want to compile in a static version of the libbz2 library
pbzip2-static: libbz2.a pbzip2.cpp
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) -o pbzip2 pbzip2.cpp -pthread -lpthread -I. -L. -lbz2

# Compatability mode for 32bit file sizes (less than 2GB) and systems
# that have compilers that treat int as 64bit natively (ie: modern AIX)
pbzip2-compat: pbzip2.cpp
	$(CXX) $(CFLAGS_COMPAT) $(CXXFLAGS) $(LDFLAGS) -o pbzip2 pbzip2.cpp -pthread -lpthread -lbz2

# Install the binary pbzip2 program and man page
install: pbzip2
	if ( test ! -d $(PREFIX)/bin ) ; then mkdir -p $(PREFIX)/bin ; fi
	if ( test ! -d $(PREFIX)/man ) ; then mkdir -p $(PREFIX)/man ; fi
	if ( test ! -d $(PREFIX)/man/man1 ) ; then mkdir -p $(PREFIX)/man/man1 ; fi
	cp -f pbzip2 $(PREFIX)/bin/pbzip2
	chmod a+x $(PREFIX)/bin/pbzip2
	cp -f pbzip2.1 $(PREFIX)/man/man1
	chmod a+r $(PREFIX)/man/man1/pbzip2.1

clean:
	rm -f *.o pbzip2
