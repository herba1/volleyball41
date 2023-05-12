all: client server

client: client.cc common.h
	g++ -pthread -O3 -std=c++2a -g -o client client.cc

battleship: battleship.cc common.h
	g++ -pthread -O3 -std=c++2a -g -o battleship battleship.cc

volley: volley.cc common.h
	g++ -pthread -O3 -std=c++2a -g -o volley volley.cc

server: server.cc common.h
	g++ -pthread -O3 -std=c++2a -g -o server server.cc

clean:
	rm -f *.o a.out client server volley battleship core
