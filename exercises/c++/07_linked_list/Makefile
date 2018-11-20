CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++11 -O3

SRC=linked_list.cc
EXE=$(SRC:.cc=.x)

default: $(EXE)

%.x: %.cc
		$(CXX) $(CXXFLAGS) $< -o $@

clean: 
		rm -rf *~ $(EXE)

.PHONY: clean default