#main Makefile

output: main.o WordFinder.o LetterGrid.o
	g++ -Wall main.o WordFinder.o LetterGrid.o -o output

main.o: main.cpp
	g++ -c -Wall main.cpp

WordFinder.o: WordFinder.cpp
	g++ -c -Wall WordFinder.cpp

LetterGrid.o: LetterGrid.cpp
	g++ -c -Wall LetterGrid.cpp

clean:
	rm*.o output
