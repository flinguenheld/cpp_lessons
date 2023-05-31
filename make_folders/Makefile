INCLUDE_DIR = include
SOURCE_DIR = src
BUILD_DIR = build

# --
OUTPUT := main
DEBUG = ON
CXX_VERSION = 17

ifeq (${DEBUG}, ON)
CXX_FLAGS += -g -O0
OUTPUT := ${OUTPUT}_debug
else
CXX_FLAGS += -O3
endif

CXX_FLAGS += -std=c++${CXX_VERSION} -I ${INCLUDE_DIR}
CXX_COMPILER_CALL = ${CXX} ${CXX_FLAGS}

# --
CXX_SOURCES = $(wildcard ${SOURCE_DIR}/*.cpp)
CXX_OBJECTS = $(patsubst ${SOURCE_DIR}/%.cpp, ${BUILD_DIR}/%.o, $(CXX_SOURCES))

#############
## TARGETS ##
#############

# targets: prerequisites
# 	command
# 	command

build: mkdir ${CXX_OBJECTS}
	@echo "Sources : " ${CXX_SOURCES}
	@echo "Objects : " ${CXX_OBJECTS}
	${CXX_COMPILER_CALL} ${CXX_OBJECTS} -o ${BUILD_DIR}/${OUTPUT}

mkdir:
	mkdir -p ${BUILD_DIR}

execute:
	./${OUTPUT}

clean:
	rm -rf ${BUILD_DIR}
	# rm -f ${BUILD_DIR}/*.o ${BUILD_DIR}/${OUTPUT}

##############
## PATTERNS ##
##############
${BUILD_DIR}/%.o: ${SOURCE_DIR}/%.cpp
	@echo "    Next file : "$< " -> " $@
	@${CXX_COMPILER_CALL} -c $< -o $@

##############
## PHONY ##
##############
# It allows to prevent any mistake if a file is name with a target's name
.PHONY: build mkdir execute clean
