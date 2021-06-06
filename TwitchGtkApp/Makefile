CFLAGS=-Wall `pkg-config gtkmm-3.0 --cflags`
LDFLAGS=`pkg-config gtkmm-3.0 --libs`

bin/App: src/App.o src/MainWindow.o
	g++ src/App.o src/MainWindow.o $(LDFLAGS) -o bin/App

src/App.o: src/App.cpp
	g++ -c src/App.cpp -o src/App.o $(CFLAGS) -o src/App.o

src/MainWindow.o: src/MainWindow.cpp src/MainWindow.h
	g++ -c src/MainWindow.cpp $(CFLAGS) -o src/MainWindow.o
