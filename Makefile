a.out: main.o
	g++ main.o -o a.out

main.o: main.cpp
	g++ -c main.cpp

clear:
	rm main.o a.out
