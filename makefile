pagrindine:
	g++ -std=c++11 -c v2.cpp
funkcijos:
	g++ -std=c++11 -c funkcijos.cpp
prog:
	g++ -std=c++11 -o prog v2.o funkcijos.o
