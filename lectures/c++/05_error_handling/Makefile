SRC = 00_errno.cc            \
      01_exceptions.cc       \
      02_exceptions.cc       \
      03_error.cc            \
      04_assert.cc           \
      05_stack_unwinding.cc  \
      06_smart_pointers.cc   

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

EXE = $(SRC:.cc=.x) # defines all the executable files used for all make

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE) # the default rule executed by "make", equivalent to "make all"

.PHONY: all # represents the fact that all rule doesn't make a file named all

%.x: %.cc # equivalent to "for each file.x, it depends on file.cc"
	$(CXX) $< -o $@ $(CXXFLAGS) #$@ represents the target (%.x), $< represents the specific first dependency matched (%.cc)

format: $(SRC) #used to format source files following the clang format rules
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command" #$^ represents the dependencies

.PHONY: format  # represents the fact that the format rule doesn't produce a file named format.
# It's just a good practice, since 

clean:
	rm -f $(EXE) *~ # call "make clean" to remove all the executable created

.PHONY: clean

03_error.x: ap_error.h
04_assert.x: ap_error.h
05_stack_unwinding.x: ap_error.h
06_smart_pointers.x: ap_error.h

format: ap_error.h

# make -j nproc+1 is used to compile in parallel

