# source files
# no need to explain a wildcard in name and sign
files = $(wildcard *.cpp)
# object files instead of listing them.
# this way we have our make file always working,
# so long as files are in the same folder
# then substitute the .cpp part of $(files) with .o
objects = $(patsubst %.cpp,%.o,$(files))

#g++ commands
# g++
CPPFLAG = g++
# C++ version to compile to
CVFLAG = -std=c++23
# error handling flags
CEFLAG = -Wall -Werror

# rules
all: carrental

# create executable from object files
# as we have said a while ago. here is an issue - there is going to be error here since there is no rule to create carrental
# the below line should be bchanged to carrental instead of robot. but you already know the solution.
robot: $(objects)
	$(CPPFLAG) $(CVFLAG) $(CEFLAG) -g -o carrental $(objects)

# create object files from source files
%.o: %.cpp
	$(CPPFLAG) $(CVFLAG) $(CEFLAG) -g -c $< -o $@

# clean 
.PHONY:clean
clean:
	rm -f carrental *.o



#\ my make file looks like below. see that I make minimal changes to it in any project environment.
# source files
# no need to explain a wildcard in name and sign
files = $(wildcard *.cpp)
# object files instead of listing them.
# this way we have our make file always working,
# so long as files are in the same folder
# then substitute the .cpp part of $(files) with .o
objects = $(patsubst %.cpp,%.o,$(files))



# executable file
BIN = factory     \# <- ### ATENTION !!!!!!!! this is the only thing that I change, I can make it the name of the program like carrental , robot, zoo ..etc



#g++ commands
# g++
CFLAG = g++
# C++ version to compile to
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
