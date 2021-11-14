all: exe_arq

exe_arq: main.o imread.o
	g++ -o exe_arq main.o imread.o `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --libs --cflags opencv`

main.o: main.cpp imread.h
	g++ -o main.o main.cpp -c `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --libs --cflags opencv`

imread.o: imread.cpp 
	g++ -o imread.o imread.cpp -c `pkg-config gtkmm-3.0 --cflags --libs` `pkg-config --libs --cflags opencv`