OUTPUT := main
DEBUG = ON

ifeq (${DEBUG}, ON)
	CXX_FLAGS += -g -O0
	OUTPUT := ${OUTPUT}_debug
else
	CXX_FLAGS += -O3
endif

CXX_SOURCES = $(wildcard *.cpp) $(wildcard lib/*.cpp)
CXX_OBJECTS = $(patsubst %.cpp, %.o, $(CXX_SOURCES))

build: ${CXX_OBJECTS}
	@echo "Sources : " ${CXX_SOURCES}
	@echo "Objects : " ${CXX_OBJECTS}
	${CXX} ${CXX_OBJECTS} ${CXX_FLAGS} -o ${OUTPUT}

%.o: %.cpp
	@echo "    Next file : "$<
	@${CXX} -c $< -o $@

execute:
	./${OUTPUT}

clean:
	rm -f *.o lib/*.o ${OUTPUT}
