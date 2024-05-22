pagrindine:
	g++ -std=c++11 -c v3.cpp
funkcijos:
	g++ -std=c++11 -c funkcijos.cpp
prog:
	g++ -std=c++11 -o prog v3.o funkcijos.o
