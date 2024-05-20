# source files
# no need to explain a wildcard in name and sign
files = $(wildcard *.cpp)
# object files instead of listing them.
# this way we have our make file always working,
# so long as files are in the same folder
# then substitute the .cpp part of $(files) with .o
objects = $(patsubst %.cpp,%.o,$(files))



# executable file
BIN = carrental   # ATTENTION !!!!!!!! this is the only thing that I change,
  				# I can make it the name of the program like carrental , robot, zoo ..etc

#g++ commands
# g++
CFLAG = g++

# C++ version to compile to
# this can be eg. -std=c++11, -std=c++2a or -std=c++23
# but some times Jupyter I think lags behind on compiler, so only up to -std=c++2a work
VFLAG = -std=c++2a
# error handling flags
WFLAG = -Wall -Werror

# rules
all: $(BIN)

# create executable from object files
$(BIN): $(objects)
	$(CFLAG) $(VFLAG) $(WFLAG) -g -o $(BIN) $(objects)

# create object files from source files
%.o: %.cpp
	$(CFLAG) $(VFLAG) $(WFLAG) -g -c $< -o $@

# run the program
run: $(BIN)
	./${BIN}
# clean
.PHONY:clean
clean:
	rm -f $(BIN) *.o