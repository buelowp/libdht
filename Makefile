CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -pipe -std=gnu99 -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I.
LINK          = g++
LFLAGS        = -Wl,-O1 -shared -Wl,-soname,libdht22.so
LIBS          = -lrt 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = bbb_dht_read.c \
		bbb_mmio.c \
		common_dht_read.c 
OBJECTS       = bbb_dht_read.o \
		bbb_mmio.o \
		common_dht_read.o
QMAKE_TARGET  = dht22
DESTDIR       = 
TARGET        = libdht22.so
TARGETA       = libdht22.a

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: $(TARGET)

$(TARGET):  $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	-$(DEL_FILE) $(TARGET) 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)

staticlib: $(TARGETA)

$(TARGETA):  $(OBJECTS) $(OBJCOMP) 
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)

clean: 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core
	-$(DEL_FILE) $(TARGET)

####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) $(TARGETA)

check: first 

####### Compile

bbb_dht_read.o: bbb_dht_read.c bbb_dht_read.h \
		common_dht_read.h \
		bbb_mmio.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o bbb_dht_read.o bbb_dht_read.c

bbb_mmio.o: bbb_mmio.c bbb_mmio.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o bbb_mmio.o bbb_mmio.c

common_dht_read.o: common_dht_read.c common_dht_read.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o common_dht_read.o common_dht_read.c

####### Install

install:   FORCE
	install -m 0775 $(TARGET) $(DESTDIR)/usr/lib
	install -m 0644 bbb_dht_read.h $(DESTDIR)/usr/include

uninstall:   FORCE

FORCE:

