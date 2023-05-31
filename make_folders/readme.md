# Cpp Makefile Tutorial

Copy from: [franneck94](https://github.com/franneck94/UdemyMakefile/tree/master/2_Makefile)  
Usefull tuto: [learn Makefiles](https://makefiletutorial.com/#-wildcard)

## GCC/Clang Compiler Steps

### Compilation (Assembling)

- Checks the C/C++ language syntax for error
- Generates object files
- Command: g++ main.cc -c
- Produces: main.o

### Linker

- Linking all the source files together, that is all the other object codes in the project.
- Generates the executable file
- Command: g++ main.o -o main
- Produces: main.out

### Compiler Flags

- Debug: `-g`
- Release: `-O0 -O1 -O2 -O3 -Og`
- Includes: `-I`
- Warnings: `-Wall -Wextra -Wpedantic -Wconversion`

## Makefile Commands of the Template

### Makefile Variables

Convention is naming in upper snake_case.

```make
  VARIABLE_NAME = Value
```

Variables can be called by ${VARIABLE_NAME}

```make
  ${VARIABLE_NAME}
```

### Makefile Targets

Convention is naming in snake_case or camelCase.

```make
  targetName: Dependecies
    Command
```

Targets can be called by the `make` command.

```bash
  make targetName
```

### Makefile Phony Target

Sometimes you want your Makefile to run commands that do not represent files, for example the "clean" target. You may potentially have a file named clean in your main directory. In such a case Make will be confused because by default the clean target would be associated with this file and Make will only run it when the file doesn't appear to be up-to-date.

```make
.PHONY: clean
clean:
  rm -rf *.o
```

In terms of Make, a phony target is simply a target that is always out-of-date, so whenever you ask make <phony_target>, it will run, independent from the state of the file system.

### Build the Executable

Create the executable in either Debug or Release mode.

```bash
  make build           # Build type is debug
  make build DEBUG=OFF # Build type is release
```

### Run the Executable

Run the executable in either Debug or Release mode.

```bash
  make execute           # Build type is debug
  make execute DEBUG=OFF # Build type is release
```

### Variables of the Makefile Template

- Debug Mode: ON (True)
- CPP_STANDARD: c++11, c++14, c++17, etc.

### Important Shortcuts of the Makefile Template

- `$@`: the file name of the target
- `$<`: the name of the first dependency
- `$^`: the names of all dependencies
