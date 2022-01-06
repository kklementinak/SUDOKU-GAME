#include <iostream>
# include <cstdio>
using namespace std;
# define N 9

int main()
{
	int sudoku[N][N] = { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
		 { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
		 { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
		 { 2, 6, 3, 4, 1, 5, 9, 8, 7 },
		 { 9, 7, 4, 8, 6, 3, 1, 2, 5 },
		 { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
		 { 1, 3, 8, 9, 4, 7, 2, 5, 6 },
		 { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
		 { 7, 4, 5, 2, 8, 6, 3, 1, 9 } };



	int sudokuTemplate[N][N];
	for (int x = 0; x < N; x++) {
		for (int c = 0; c < N; c++) {
			sudokuTemplate[x][c] = sudoku[x][c];
		}
	}
	//how to print cool sudoku
	for (int xx = 0;xx < N;xx++) {
		for (int cc = 0;cc < N;cc++) {
			if (xx == 0 && cc == 0) {
				cout << " ";
			}
			cout << sudokuTemplate[xx][cc] << " ";
			if (cc == 2 || cc == 5) {
				cout << "|";
			}

			if (cc == N - 1) {
				cout << "\n" << " ";
				if (xx == 2 || xx == 5) {
					for (int vv = 0;vv < N;vv++) {
						cout << "--";
					}
					cout << "\n" << " ";
				}
			}

		}
	}
	cout << "\n";



	char level;
	cout << "Choose level of difficulty: B-beginner; E-easy; M-medium; H-hard; U-ultimate" << "\n" << "type only the capital letter of the level" << "\n" << "Please enter which level you want: ";
	cin >> level;

	srand((unsigned)time(NULL));
	int count = 0;
	//while (level != 'B' || level != 'E' || level != 'M' || level != 'H' || level != 'U') {
	//	cout << "Please enter valid level: ";
	//	cin >> level;
	//}
	//TOVA NESHTO NE BA4KA KAKTO TRQBVA
	if (level == 'B') {
		count = rand() % 10 + 21;
	}
	if (level == 'E') {
		count = rand() % (26 - 15) + 10;
	}
	if (level == 'M') {
		count = rand() % 5;
	}
	if (level == 'H') {
		count = rand() % (26 - 15) + 10;
	}
	if (level == 'U') {
		count = rand() % (26 - 15) + 10;
	}

	cout << "\n";
	int counter = count;
	cout << count << "\n";
	//random delete of the sudoku munbers
	int ii = rand() % 8;
	int jj = rand() % 8;
	while (count > 0)//trqbva mi do while
	{
		if (sudokuTemplate[ii][jj] != 0) {
			sudokuTemplate[ii][jj] = 0;
			count--;
			ii = rand() % 8;
			jj = rand() % 8;
		}
		else {
			ii = rand() % 8;
			jj = rand() % 8;
		}
	}


	//how to print cool sudoku
	for (int hh = 0; hh < N; hh++) {
		for (int gg = 0; gg < N; gg++) {
			if (hh == 0 && gg == 0) {
				cout << " ";
			}
			if (sudokuTemplate[hh][gg] == 0) {
				cout << "_ ";
			}
			else cout << sudokuTemplate[hh][gg] << " ";
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
	cout << "The first cooridnates digits are 1." << "\n";
	//TAQ RABOTA TRQBVA A E S REKURSIQ CHE INA4E SI E EBAN*
	while (counter > 0) {
		cout << "\n" << "Please enter the missing digits: ";
		cin >> row >> column >> number;

		//because the matrix indices star from 0 to 8 so we devide 1
		row--;
		column--;


		while ((row < 0 || row >= 9) || (column >= 9 || column < 0 )|| (number>9 || number <= 0)) {
			cout << "Invalid operation. There is no such number with these cordinates. Try anather one: ";
			cin >> row >> column >> number;
		}
		while(sudokuTemplate[row][column] != 0){
				cout << "Invalid operation. You can't change this number. Try anather one: ";
				cin >> row >> column >> number;
		}
		if (sudokuGame[row][column] == 0) {
			sudokuGame[row][column] = number;
			counter--;
		}
		else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
			sudokuGame[row][column] = number;
		}
		
		cout << "Do you want to validate you solution?" << "\n" << "type Y-yes N-no" <<"\n"<< " Please enter your desicion: ";
		cin >> answer;
		if (answer == 'Y') {
			
			if (sudokuGame[row][column] == sudoku[row][column]) {
				cout << "Your answer is right."<<"\n";
			}
			else {
				cout << "Your answer is wrong." << "\n";
			}
		}
		

	}
	bool isSudokuRight = 1;

	for (int d = 0; d < N; d++) {
		for (int f = 0; f < N; f++) {
			if (sudokuGame[d][f] != sudoku[d][f]) {
				isSudokuRight = 0;
			}
		}
	}


	char response;
	if (isSudokuRight == 1) {
		cout << "You won!";
	}
	else {
		cout << "Your sudoku is incorrect!"<<"\n"<<"Do you want to end the game or continue trying?"<<"\n"<<"Type E- end C-continue: ";
		cin >> response;
		if (response == 'E') {
			cout << "This was the correct sudoku:" << "\n";
			for (int z = 0; z < N; z++) {
				for (int a = 0; a < N; a++) {
					
					if (z == 0 && a == 0) {
						cout << " ";
					}
					cout << sudokuTemplate[z][a] << " ";
					if (a == 2 || a == 5) {
						cout << "|";
					}

					if (a == N - 1) {
						cout << "\n" << " ";
						if (z == 2 || z == 5) {
							for (int w = 0; w < N; w++) {
								cout << "--";
							}
							cout << "\n" << " ";
						}
					}
				}
			}
		}

		bool check = 1;
		
		
		if (response == 'C') {

			while (isSudokuRight == 0) {

				cout << "\n" << "Please enter the missing digits: ";
				cin >> row >> column >> number;

				//because the matrix indices star from 0 to 8 so we devide 1
				row--;
				column--;


				while ((row < 0 || row >= 9) || (column >= 9 || column < 0) || (number > 9 || number <= 0)) {
					cout << "Invalid operation. There is no such number with these cordinates. Try anather one: ";
					cin >> row >> column >> number;
				}
				while (sudokuTemplate[row][column] != 0) {
					cout << "Invalid operation. You can't change this number. Try anather one: ";
					cin >> row >> column >> number;
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
						if (sudokuGame[dd][ff] != sudoku[dd][ff]) {
							isSudokuRight = 0;
						}
						else {
							isSudokuRight == 1;
						}
					}
				}
			}

		}
	}










	return 0;
}