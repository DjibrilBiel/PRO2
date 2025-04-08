
all: demo_fechas

demo_fechas: main.o fecha.o
	g++ -g3 -o demo_fechas main.o fecha.o

main.o: main.cc fecha.hh
	g++ -g3 -c main.cc

fecha.o: fecha.cc fecha.hh
	g++ -g3 -c fecha.cc

execute: demo_fechas
	./demo_fechas

clean:
	rm -f demo_fechas main.o fecha.o