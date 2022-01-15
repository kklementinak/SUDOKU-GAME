# include <iostream>
# include <cstdio>
using namespace std;
# define N 9

	const int TWO_ROWS = 1;
	const int TWO_COLUMNS = 2;
	const int THREE_ROWS = 3;
	const int THREE_COLUMNS = 4;



	int secondVariable(int second, int first) {
		
		// For easier math operations we will add 1 to the 'first' so it would be devisible by 3
		int typeOfOPeration;
		if (1<(first + 1) < 3 || 4 < (first + 1) < 6 || 7 < (first + 1) < 9) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first + 1;
			}
			else {
				second = first - 1;
			}

		}
		if ((first + 1) == 3 || (first + 1) == 6 || (first + 1) == 9) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first - 2;
			}
			else {
				second = first - 1;
			}
		}
		if ((first + 1) == 1 || (first + 1) == 4 || (first + 1) == 7) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first + 1;
			}
			else {
				second = first + 2;
			}
		}
		return second;
}

	int secondVariable2(int second, int first) {

		int typeOfOPeration;
		if (first==1) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first + 1;
			}
			else {
				second = first - 1;
			}

		}
		if (first == 2) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first - 2;
			}
			else {
				second = first - 1;
			}
		}
		if (first == 0) {
			typeOfOPeration = rand() % (N + 1) + 1;
			if (typeOfOPeration % 2 == 0) {
				second = first + 1;
			}
			else {
				second = first + 2;
			}
		}
		return second;
	}
    //how to print cool sudoku
	void printSudoku(int display[N][N]) {
			
		for (int hh = 0; hh < N; hh++) {
			for (int gg = 0; gg < N; gg++) {
				if (hh == 0 && gg == 0) {
					cout << " ";
				}
				if (display[hh][gg] == 0) {
					cout << "_ ";
				}
				else cout << display[hh][gg] << " ";
				if (gg == 2 || gg == 5) {
					cout << "|";
				}

				if (gg == N - 1) {
					cout << "\n" << " ";
					if (hh == 2 || hh == 5) {
						for (int vv = 0; vv < N; vv++) {
							cout << "--";
						}
						cout << "\n" << " ";
					}
				}

			}
		}
		cout << "\n";
	}	

int main()
{
	srand((unsigned)time(NULL));

	//TUK DOBAVI TEKSTOV FAIL






	int sudoku[N][N] = { 
		 { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
		 { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
		 { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
		 { 2, 6, 3, 4, 1, 5, 9, 8, 7 },
		 { 9, 7, 4, 8, 6, 3, 1, 2, 5 },
		 { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
		 { 1, 3, 8, 9, 4, 7, 2, 5, 6 },
		 { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
		 { 7, 4, 5, 2, 8, 6, 3, 1, 9 } };



	// zna4i eamenqm koloni redove ili po 3

	

	int numberOfChanges;
	numberOfChanges = 5;

	int change;
	int sudokuTemplate[N][N];

	for (int s = 0; s < numberOfChanges; s++) {
		change = rand() % 2 + 1;
		if (change == TWO_ROWS) {
			int row;
			row = rand() % N;
			int row2 = 0;
			row2 = secondVariable(row2, row);
			for (int c = 0; c < N; c++) {
				for (int s = 0; s < N; s++) {
					sudokuTemplate[c][s] = sudoku[c][s];

					if (c == row) {
						sudokuTemplate[c][s] = sudoku[row2][s];
					}
					if (c == row2) {
						sudokuTemplate[c][s] = sudoku[row][s];
					}

				}
			}

		}
		if (change == TWO_COLUMNS) {
			int column;
			column = rand() % N;
			int column2 = 0;
			column2 = secondVariable(column2, column);
			for (int cc = 0; cc < N; cc++) {
				for (int ss = 0; ss < N; ss++) {
					sudokuTemplate[cc][ss] = sudoku[cc][ss];

					if (ss == column) {
						sudokuTemplate[cc][ss] = sudoku[cc][column2];
					}
					if (ss == column2) {
						sudokuTemplate[cc][ss] = sudoku[cc][column];
					}

				}
			}
		}
		// at the following two we will use the numbers 1,2,3 to tell whitch whole three we will be taking
		// That's why we use N/3 (9/3=3)
		
		
		
		/*if (change == THREE_ROWS) {
			int rows;
			rows = rand() % (N / 3);
			int rows2 = 0;
			rows2 = secondVariable2(rows2, rows);
			for (int c = 0; c < N; c++) {
				for (int v = 0; v < N; v++) {
					sudokuTemplate[c][s] = sudoku[c][s];
					if (c == (3 * rows - 2)) {
						sudokuTemplate[c][s] = sudoku[c][(3 * rows2 - 2)];
					}
					if (c == rows) {
						sudokuTemplate[c][s] = sudoku[c][rows2];
					}
					if (c == rows + 1) {
						sudokuTemplate[c][s] = sudoku[c][rows2];
					}
				}


			}
		}
		if (change == THREE_COLUMNS) {
			int columns;
			columns = rand() % (N / 3);
			int columns2 = 0;
			columns2 = secondVariable(columns2, columns);
			for (int c = 0; c < N; c++) {
				for (int v = 0; v < N; v++) {
					sudokuTemplate[c][s] = sudoku[c][s];
					if (c == (3 * columns - 2)) {
						sudokuTemplate[c][s] = sudoku[(3 * columns2 - 2)][s];
					}
					if (c == columns) {
						sudokuTemplate[c][s] = sudoku[columns2][s];
					}
					if (c == columns + 1) {
						sudokuTemplate[c][s] = sudoku[columns2][s];
					}

				}
			}
		}*/

	}
	if (numberOfChanges == 0) {
		for (int y = 0; y < N; y++) {
			for (int u = 0; u < N; u++) {
				sudokuTemplate[y][u] = sudoku[y][u];
			}
		}
	}


	printSudoku(sudokuTemplate);

	int sudokuKey[N][N];
	for (int y = 0; y < N; y++) {
		for (int u = 0; u < N; u++) {
			sudokuKey[y][u] = sudoku[y][u];
		}
	}




	char level;
	cout << "Choose level of difficulty: B-beginner; E-easy; M-medium; H-hard; U-ultimate" << "\n" << "type only the capital letter of the level" << "\n" << "Please enter which level you want: ";
	cin >> level;
	cout << "\n";

	
	int count = 0;


	while (level != 'B' && level != 'E' && level != 'M' && level != 'H' && level != 'U') {
		cout << "please enter valid level: ";
		cin >> level;
	}
	 


	// Here are the possible levels and how they are dtertnmined:
		// | Level Name | Initial no.of Givens | Initial no. of Missing
		// 
		// | Begginer   | more than 50         | less than 31
		// | Easy       | 36 - 40              | 40 - 45
		// | Medium     | 32 - 45              | 36 - 49
		// | Hard       | 28 - 31              | 50 - 53
		// | Ultimate   | 22 - 27              | 54 - 59
	//http://zhangroup.aporc.org/images/files/Paper_3485.pdf This is the resource i used for the information above.
	if (level == 'B') {
		count = rand() % 30 + 1;
	}
	if (level == 'E') {
		count = rand() % 5 + 40;
	}
	if (level == 'M') {
		count = rand() % 13 + 36;
	}
	if (level == 'H') {
		count = rand() % 3 + 50;
	}
	if (level == 'U') {
		count = rand() % 5 + 54;
	}

	cout << "\n";
	int counter = count;
	cout << count << "\n";
	//random delete of the sudoku munbers
	int ii = rand() % N;
	int jj = rand() % N;
	while (count > 0){
		if (sudokuTemplate[ii][jj] != 0) {
			sudokuTemplate[ii][jj] = 0;
			count--;
			ii = rand() % N;
			jj = rand() % N;
		}
		else {
			ii = rand() % N;
			jj = rand() % N;
		}
	}

	printSudoku(sudokuTemplate);


	int sudokuGame[N][N];
	for (int pp = 0; pp < N; pp++) {
		for (int oo = 0; oo < N; oo++) {
			sudokuGame[pp][oo] = sudokuTemplate[pp][oo];
		}
	}
	int row = 0;
	int column = 0;
	int number = 0;
	char answer;
	cout << "The first cooridnates digits are 1. The fist number is the row, then the column and the missing number at the end." << "\n";
	//TAQ RABOTA TRQBVA A E S REKURSIQ CHE INA4E SI E EBAN*
	while (counter > 0) {
		cout << "\n" << "Please enter the missing digits: ";
		cin >> row >> column >> number;
		cout << "\n";

		//Because the matrix indices start from 0 to 8 and we want to make it easier for the users we devide 1 from both
		row--;
		column--;

		//MOJE BI I TUK S R
		while ((row < 0 || row >= 9) || (column >= 9 || column < 0 ) || (number>9 || number < 0)) {
			cout << "Invalid operation. There is no such number with these cordinates. Try anather one: ";
			cin >> row >> column >> number;
			cout << "\n";
		}
		while(sudokuTemplate[row][column] != 0){
				cout << "Invalid operation. You can't change this number. Try anather one: ";
				cin >> row >> column >> number;
				cout << "\n";
		}
		if (sudokuGame[row][column] == 0) {
			sudokuGame[row][column] = number;
			counter--;
		}
		else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
			sudokuGame[row][column] = number;
		}
		
		cout << "Do you want to validate you solution?" << "\n" << "type: Y-yes N-no" <<"\n"<< "Please enter your desicion: ";
		cin >> answer;
		cout << "\n";
		if (answer == 'Y') {
			
			if (number == sudokuKey[row][column]) {
				cout << "Your answer is right."<<"\n";
			}
			else {
				cout << "Your answer is wrong." << "\n";
			}
		}
		printSudoku(sudokuGame);

	}
	bool isSudokuRight = 1;

	for (int d = 0; d < N; d++) {
		for (int f = 0; f < N; f++) {
			if (sudokuGame[d][f] != sudokuKey[d][f]) {
				isSudokuRight = 0;
			}
		}
	}


	char response;
	if (isSudokuRight == 1) {
		cout << "You won!";
	}
	else {
		cout << "Your sudoku is incorrect!"<<"\n"<<"Do you want to end the game or continue trying?"<<"\n"<<"Type E - end C - continue: ";
		cin >> response;
		cout << "\n";
		if (response == 'E') {
			cout << "This was the correct sudoku:" << "\n";
			printSudoku(sudokuTemplate);
		}

		bool check = 1;
		
		bool isSudokuRight = 0;
		
		if (response == 'C') {

			while (isSudokuRight == 0) {

				cout << "\n" << "Please enter the missing digits: ";
				cin >> row >> column >> number;
				cout << "\n";

				//Because the matrix indices start from 0 to 8 and we want to make it easier for the users we devide 1 from both
				row--;
				column--;


				while ((row < 0 || row >= 9) || (column >= 9 || column < 0) || (number > 9 || number <= 0)) {
					cout <<"\n "<<"Invalid operation.There is no such number with these cordinates.Try anather one: ";
					cin >> row >> column >> number;
					cout << "\n";
				}
				while (sudokuTemplate[row][column] != 0) {
					cout << "Invalid operation. You can't change this number. Try anather one: ";
					cin >> row >> column >> number;
					cout << "\n";
				}
				if (sudokuGame[row][column] == 0) {
					sudokuGame[row][column] = number;
					counter--;
				}
				else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
					sudokuGame[row][column] = number;
				}

				for (int dd = 0; dd < N; dd++) {
					for (int ff = 0; ff < N; ff++) {
						if (number != sudokuKey[dd][ff]) {
							isSudokuRight = 0;
						}
						else {
							isSudokuRight = 1;
						}
					}
				}
			}
			if (isSudokuRight == 1) {
				cout << "You won!";
			}
		}
	}
	return 0;
}