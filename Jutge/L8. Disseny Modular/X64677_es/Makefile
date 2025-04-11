G++ := g++ -g3 -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers
tar := tar -cvf

program.exe: Cubeta.cc Lavadora.cc Prenda.cc program.cc tar
	$(G++) -o program.exe *.cc

tar: Cubeta.cc Lavadora.cc Prenda.cc Makefile program.cc
	$(tar) files.tar "Cubeta.cc" "Lavadora.cc" "Prenda.cc" "Makefile" "program.cc"

clean:
	rm -f program files.tar

.PHONY: clean