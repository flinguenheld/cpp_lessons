DEBUG = ON
CXX_VERSION = 17
BUILD_FOLDER = build
OUTPUT_NAME = main

ifeq (${DEBUG}, ON)
	CXXFLAGS += -g -O0 
else
	CXXFLAGS += -O3
endif


CXX_COMPILER_CALL = ${CXX} ${CXXFLAGS} -std=c++${CXX_VERSION} -pthread

CXX_SOURCES = $(wildcard *.cpp)
CXX_OBJECTS = $(patsubst %.cpp, ${BUILD_FOLDER}/%.o, ${CXX_SOURCES})

build: mkdir ${CXX_OBJECTS}
	${CXX_COMPILER_CALL} ${CXX_OBJECTS} -o ${BUILD_FOLDER}/${OUTPUT_NAME}

mkdir:
	@mkdir -p ${BUILD_FOLDER}/

execute:
	@./${BUILD_FOLDER}/${OUTPUT_NAME}

clean:
	rm -rf ${BUILD_FOLDER}/

${BUILD_FOLDER}/%.o: %.cpp
	@${CXX_COMPILER_CALL} -c $< -o $@
