pagrindine:
	g++ -std=c++11 -c v1_1.cpp
funkcijos:
	g++ -std=c++11 -c funkcijos.cpp
prog:
	g++ -std=c++11 -o prog v1_1.o funkcijos.o
prog_O1:
	g++ -std=c++11 -O1 -o prog_O1 v1_1.o funkcijos.o
prog_O2:
	g++ -std=c++11 -O2 -o prog_O2 v1_1.o funkcijos.o
prog_O3:
	g++ -std=c++11 -O3 -o prog_O3 v1_1.o funkcijos.o

