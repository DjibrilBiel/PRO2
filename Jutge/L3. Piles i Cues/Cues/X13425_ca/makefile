tar: program
	tar -cvf CuaIOParInt.tar CuaIOParInt.cc CuaIOParInt.hh program.cc

program: program.o CuaIOParInt.o
	g++ -o program CuaIOParInt.o program.o

program.o: program.cc CuaIOParInt.hh
	g++ -c program.cc

CuaIOParInt.o: CuaIOParInt.cc CuaIOParInt.hh
	g++ -c CuaIOParInt.cc


clean: 
	rm -f program program.o CuaIOParInt.o CuaIOParInt.tar
.PHONY: clean