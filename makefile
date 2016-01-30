all:
	g++ -pthread -std=c++11 *.cpp -o server

db:
	g++ -pthread -g -std=c++11 *.cpp -o debug
