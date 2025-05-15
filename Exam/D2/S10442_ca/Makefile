CXX := g++
CXXFLAGS := -std=c++17 -g3 -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -fno-extended-identifiers

program.exe: main.o
	$(CXX) $(CXXFLAGS) -o program.exe $^

main.o: *.cc *.hh

tar: finder.hh program.exe
	tar -cvf finder.tar finder.hh