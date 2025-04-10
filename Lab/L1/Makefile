tar: demo_fechas rng
	tar -cvzf fecha.tar.gz fecha.cc fecha.hh main.cc fechas.dat rng.cc Makefile


demo_fechas: fecha.o main.o
	g++ -o demo_fechas fecha.o main.o

fecha.o: fecha.cc fecha.hh
	g++ -c fecha.cc

main.o: main.cc fecha.hh fechas.dat
	g++ -c main.cc


rng: rng.cc rng.hh
	g++ -o rng rng.cc


clean: 
	rm -f demo_fechas main.o fecha.o rng
.PHONY: clean