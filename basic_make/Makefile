OUTPUT = main

CXX_SOURCES = $(wildcard *.cpp) $(wildcard lib/*.cpp)
CXX_OBJECTS = $(patsubst %.cpp, %.o, $(CXX_SOURCES))

build: ${CXX_OBJECTS}
	@echo "Sources : " ${CXX_SOURCES}
	@echo "Objects : " ${CXX_OBJECTS}
	${CXX} ${CXX_OBJECTS} -o ${OUTPUT}

%.o: %.cpp
	@echo "    Next file : "$<
	@${CXX} -c $< -o $@

clean:
	rm -f *.o lib/*.o
