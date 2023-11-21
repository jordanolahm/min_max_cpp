parametrosCompilacao=-Wall #-Wshadow
nomePrograma=MIN_MAX

all: $(nomePrograma)

$(nomePrograma): main.o MinMax.o
	g++ -o $(nomePrograma) main.o MinMax.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

MinMax.o: MinMax.hpp MinMax.cpp
	g++ -c MinMax.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)