#include "WordFinder.h"
#include "LetterGrid.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

void scanWord(string s, int r, int c, WordFinder &w) {
	string orig = s;
	string tmp;
	vector<string> currWords;

        //cout << "str: " << orig << endl;
	
	int whole_word = w.lookupWords(s);
	if (whole_word != -1 && s.size() >= 5) {
        	cout << "Found: pos_x(" << r << "), pos_y(" << c << ") --> " << s << endl;
        }  

	for (int i=0; i < s.size(); i++) {
		for (int j=0; j <s.size(); j++) {
		    tmp =  s.substr(i,j);
    		    int status = w.lookupWords(tmp);
	            if (status != -1 && tmp.size() >= 5) {
				
		    	    if (find(currWords.begin(), currWords.end(), tmp) == currWords.end()) {
			    	cout << "Found: pos_x(" << r+i << "), pos_y(" << c+j << ") --> " << tmp << endl;
			    	currWords.push_back(tmp);
			    }
		    }    
		}
	}	
}


int matchWords(WordFinder &word, LetterGrid &grid) {
	int row = grid.getRow();
	int col = grid.getCol();
	char **mat = grid.getMat();
	string find = "";
	vector<string> words;
	int count = 0;

	//horizontal forwards row
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			for (int start = j; start < col; start++) {
			
			find.push_back(mat[i][start]);
		
			if ((find.size() >= 5) && ((find.size() <= row) | (find.size() <= col))) {
				//cout << find << endl;
				int status = word.lookupWords(find);
				if (status != -1) {
					cout << "Found: pos_x(" << i << "), pos_y(" << j << ") --> " << find << endl;
				}
			}
			
			}
			find = "";
		}
		
	}

	//horizontal backwards row
	for (int i = row-1; i >= 0; i--) {
                for (int j = col-1; j >= 0; j--) {
                        for (int start = j; start >= 0; start--) {

                        find.push_back(mat[i][start]);

                        if ((find.size() >= 5) && ((find.size() <= row) | (find.size() <= col))) {
                                //cout << find << endl;
                                int status = word.lookupWords(find);
                                if (status != -1) {
                                        cout << "Found: pos_x(" << i << "), pos_y(" << j << ") --> " << find << endl;
                                }
                        }

                        }
                        find = "";
                }

        }

	//vertical foward columns
	for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                        for (int start = j; start < col; start++) {

                        find.push_back(mat[start][i]);

                        if ((find.size() >= 5) && ((find.size() <= row) | (find.size() <= col))) {
                                //cout << find << endl;
                                int status = word.lookupWords(find);
                                if (status != -1) {
                                        cout << "Found: pos_x(" << i << "), pos_y(" << j << ") --> " << find << endl;
                                }
                        }

                        }
                        find = "";
                }

        }

	//vertical backwards columns
	for (int i = row-1; i >= 0; i--) {
                for (int j = col-1; j >= 0; j--) {
                        for (int start = j; start >= 0; start--) {

                        find.push_back(mat[start][i]);

                        if ((find.size() >= 5) && ((find.size() <= row) | (find.size() <= col))) {
                                //cout << find << endl;
                                int status = word.lookupWords(find);
                                if (status != -1) {
                                        cout << "Found: pos_x(" << i << "), pos_y(" << j << ") --> " << find << endl;
                                }
                        }

                        }
                        find = "";
                }

        }
	
	//diagonal forwards	
	bool first = false;
	int first_x, first_y;
	int start, end;

	//cout << "Now scanning diagonal D1 \n";

	for (start = 0; start < row; start++) {
		for (end = 0; end < col; end++) {
			if (start < row && end < col && (start+end) < col) {
				//cout << find << endl;
				if (!first) {
					first_x = start;
					first_y = end;
					first = true;
				}

				find.push_back(mat[start+end][end]);
			}
		}
		if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }
		
		reverse(find.begin(), find.end());
		if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		find = "";
                first = false;
	}
	find = "";
	first = false;

	//cout << "Now scanning diagonal D2 \n";

	
	for (end=1; end < col; end++) {
		for (start=0; start < row; start++) {
			if (start < row && end < col && (start+end) < col) {
                                //cout << find << endl;
				if (!first) {
                                        first_x = start;
                                        first_y = end;
                                        first = true;
                                }

                                find.push_back(mat[start][start+end]);
                        }
                }
		if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		reverse(find.begin(), find.end());
                if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		find = "";
                first = false;
        }
	find = "";

	//right-to-left diagonal forwards
	first = false;
        start = 0;
	end = 0;
	
	//cout << "Now scanning diagonal D5 \n";
        for (start = 0; start < row; start++) {
                for (end = 0; end < col; end++) {
                        if (start < row && end < col && (start+end) < col) {
                                //cout << find << endl;
                                if (!first) {
                                        first_x = start;
                                        first_y = end;
                                        first = true;
                                }
                                find.push_back(mat[end][col-start-end-1]);
                        }
                }
		if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		reverse(find.begin(), find.end());
                if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }
		
		find = "";
                first = false;
        }
        find = "";
        first = false;

	//cout << "Now scanning diagonal D6 \n";
        for (start = 0; start < row; start++) {
                for (end = col-1; end >= 0; end--) {
                        if (start < row && end < col && (col+start-end) < col) {
                                //cout << find << endl;
                                if (!first) {
                                        first_x = start;
                                        first_y = end;
                                        first = true;
                                }

                                find.push_back(mat[col+start-end-1][end]);
                        }
                }
		if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		reverse(find.begin(), find.end());
                if (find.size() >=5 ) { scanWord(find, first_x, first_y, word); }

		find = "";
                first = false;
        }
        find = "";
	first = false;
}

void wordSearch() {
        string file;
        cout << "Name of Grid file? ";
        cin >> file;
	cout << endl;

        WordFinder word;
        word.readWords();
        
        
        cout << "Specify Sort Algorithm [1,2, or 3]: "<< endl;
	int sortNum;
	cin >> sortNum;
	cout << endl;
	if (sortNum == 1){
   time_t start, finish;    // Start and finish times
    time(&start);            // Note the start time
		word.sortWords();
		time(&finish);            // Note the finish time
		cout << "Using Selection Sort to Sort the list..." << endl;
		cout << "The time required is " << difftime(finish, start) << " seconds" << endl;
	  }
	 else if(sortNum == 2){
    time_t start, finish;    // Start and finish times
    time(&start);            // Note the start time
		word.quickSortWords();
		time(&finish);            // Note the finish time
		cout << "Using Selection Sort to Sort the list..." << endl;
		cout << "The time required is " << difftime(finish, start) << " seconds" << endl;
    
    }
	  else if(sortNum == 3){
    time_t start, finish;    // Start and finish times
    time(&start);            // Note the start time
		word.quickSortWords();
		time(&finish);            // Note the finish time
		cout << "Using Selection Sort to Sort the list..." << endl;
		cout << "The time required is " << difftime(finish, start) << " seconds" << endl;
     }
	  else {
    cout << "invalid sorting number" << endl;

     }

        LetterGrid grid;
        grid.readGrid(file);

        matchWords(word, grid);
}

int main() {
	
	wordSearch();

	return 0;
}


