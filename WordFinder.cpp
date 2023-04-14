
#include "WordFinder.h"
#include "sort_algorithms.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;



WordFinder::WordFinder() {
	numWords = 0;
	//words;
}

void WordFinder::readWords() {
	ifstream fin;
	string line;
	string text;
	fin.open("Glossary.txt");
	
	if (!fin) {
		cerr << "Cannot open 'Glossary.txt'" << endl;
		exit(1);
	}

	while (getline(fin, line)) {
		fin >> text;
		numWords += 1;
		words.push_back(text);
	}
	
	fin.close();
}

void WordFinder::sortWords() {
	//cout << "start";
	selectionSort(words);
	//cout << "end";
}	

void WordFinder::quickSortWords(){
	quickSort(words, 0, numWords-1);

}
void WordFinder::heapSortWords(){
	heapSort(words);

}

int WordFinder::lookupWords(string target) {
	int first = 0;
	int last = numWords-1;
	int mid = 0;

	while (first <= last) {
		mid = (first + last)/2;

		if (target < words.at(mid)) {
			last = mid - 1;
		}
		else if (target > words.at(mid)) {
			first = mid + 1;
		}	
		else {
			return (mid);
		}	
	}
	if (first > last) {
		return -1;
	}
}

ostream& operator<< (ostream& ostr, const WordFinder &x) {
	for (int i = 0; i < x.numWords; i++) {
		ostr << x.words.at(i) << endl;
	}
	return ostr;
}
