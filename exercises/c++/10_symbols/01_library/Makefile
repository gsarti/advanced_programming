EXE = main.o
CXX = c++
LIBSRC = source/hello.cc
LIBOBJ = $(LIBSRC:.cc=.o)
CXXFLAGS = -I include -std=c++11
LFLAGS = -lhello -L prefix -Wl,-rpath,prefix

all: $(EXE)

install: prefix/libhello.so

$(EXE): prefix/libhello.so main.cc
	$(CXX) main.cc -o $@ $(CXXFLAGS) $(LFLAGS)

prefix/libhello.so: $(LIBOBJ)
	mkdir prefix
	$(CXX) -shared -o $@ $^

%.o:%.cc
	$(CXX) -fpic -o $@ -c $< -I include

src/hello.o: include/hello.h

clean:
	@rm -rf *~ */*~ prefix main.o source/*.o

.PHONY: clean all install