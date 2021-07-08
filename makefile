CURR=${PWD}

all:client

client: server client.o procedure.so
	g++ -o client client.o -L$(CURR) -lprocedure

server: server.o procedure.so
	g++ -o server server.o -L$(CURR) -lprocedure

procedure.so: monitor.o semafori.o procedure.o
	g++ -shared -Wl,-soname,libprocedure.so -o libprocedure.so monitor.o semafori.o procedure.o 

procedure.o: procedure.cpp procedure.h
	g++ -c -fpic procedure.cpp

monitor.o: monitor.c monitor.h
	g++ -c -fpic monitor.c

semafori.o:semafori.cpp semafori.h
	g++ -c -fpic semafori.cpp

client.o:client.cpp 
	g++ -c -g client.cpp

server.o:server.cpp
	g++ -c -g server.cpp

clear:
	rm -f *.o
	rm -f *.so
	rm -f ./client
	rm -f ./server
	rm -f *~
