bin/App: src/App.o
	g++ -o bin/App src/App.o src/MainWindow.o `pkg-config gtkmm-3.0 --libs`

src/App.o: src/App.cpp
	g++ -c src/App.cpp -o src/App.o

src/MainWindow.o: src/MainWindow.h src/Mainwindow.cpp
	g++ -c src/MainWindow.h src/MainWindow.cpp `pkg-config gtkmm-3.0 --cflags`


