all:static_lib debug optimize
static_lib:
	g++ -c IndianRailwaysLibrary.cpp -o IndianRailwaysLibrary.o

	ar rcs libIndianRailwaysLibrary.a IndianRailwaysLibrary.o
	g++ main.cpp -L. -lIndianRailwaysLibrary -o main

debug: static_lib
	g++ -g main.cpp -L. -lIndianRailwaysLibrary -o main_debug

optimize: static_lib
	g++ -O3 main.cpp -L. -lIndianRailwaysLibrary -o main_opt