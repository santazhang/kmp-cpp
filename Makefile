CXXFLAGS= -std=c++0x -Wall -Wextra -Wpedantic -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wredundant-decls -Wmissing-include-dirs

all: demo

demo: demo.cc kmp-cpp.h
	g++ ${CXXFLAGS} demo.cc -o demo

clean:
	rm -f demo
