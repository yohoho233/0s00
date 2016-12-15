Clean:Reversi
#	clear
#	rm *.o
#	./Reversi
Reversi:Main.o  Reversi.o Node.o
	g++ -o Reversi Main.o Reversi.o Node.o

Reversi.o:Reversi.cpp Reversi.h
	g++ -c Reversi.cpp
Main.o:Main.cpp Reversi.h Node.h
	g++ -c Main.cpp
Node.o:Node.cpp Node.h Reversi.h
	g++ -c Node.cpp
