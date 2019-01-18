EXE = exe

LFLAGS = -lblas
CXX = c++
CXXFLAGS = -I include -std=c++11
SRC = src/src1.cc src/src2.cc main.cc
OBJ = ${SRC:.cc=.o}

all: $(EXE)

%.o: %.cc
	$(CXX) -g -c $< -o $@ $(CXXFLAGS)

$(EXE): $(OBJ)
	$(CXX) -g -o $@ $^

main.o: src/src1.o src/src2.o include/foo.h

src/src1.o: include/utility.h
src/src2.o: include/utility.h

clean:
	rm -rf src/*.o main.o $(EXE) */*~ *~

.PHONY: clean all


