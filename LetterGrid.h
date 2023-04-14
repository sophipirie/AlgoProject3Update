#ifndef LETTERGRID
#define LETTERGRID

//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;

class LetterGrid {
	private:
		int num;
		int row;
		int col;
		char **mat; 
	public:
		LetterGrid() { row = col = 0; };
		void readGrid(string file);
		void printGrid();
		int getRow();
		int getCol();
		char **getMat();
};

#include "LetterGrid.cpp"
#endif
