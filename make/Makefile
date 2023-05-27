# TARGETS

DEBUG = ON
OUTPUT_NAME = main


# Use variables allows to change them in the command line : make CXX_STANDARD=14
CXX_STANDARD = 17
CXX_WARNINGS = -Wall

CXXFLAGS = $(CXX_WARNINGS) -std=c++$(CXX_STANDARD)

ifeq ($(DEBUG), ON)
	CXXFLAGS += -g -O0 # -O0: no optimisation
else
	CXXFLAGS += -O3
endif

COMPILER_CALL = $(CXX) $(CXXFLAGS)

# build:
# 	$(COMPILER_CALL) lib/my_lib.cpp main.cpp -o $(OUTPUT_NAME)

build: lib.o
	$(COMPILER_CALL) my_lib.o main.cpp -o $(OUTPUT_NAME)

lib.o:
	$(COMPILER_CALL) lib/my_lib.cpp -c

execute:
	./$(OUTPUT_NAME)

clean:
	rm -f *.o lib/*.o $(OUTPUT_NAME)
