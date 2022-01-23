# include <iostream>
# include <cstdio>
# include <fstream>
using namespace std;
# define N 9

const int TWO_ROWS = 1;
const int TWO_COLUMNS = 2;
const int THREE_ROWS = 3;
const int THREE_COLUMNS = 4;
const int MAX_SIZE = 1024;




int secondVariable(int second, int first) {

	// For easier math operations we will add 1 to the 'first' so it would be devisible by 3, easier to count ect.
	int typeOfOPeration;
	if (1 < (first + 1) < 3 || 4 < (first + 1) < 6 || 7 < (first + 1) < 9) {
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
	if (first == 1) {
		typeOfOPeration = rand() % (N + 1) + 1;
		if (typeOfOPeration % 2 == 0) {
			second = first + 1;
		}
		else {
			second = first + 2;
		}
	}
	if (first==2) {
		typeOfOPeration = rand() % (N + 1) + 1;
		if (typeOfOPeration % 2 == 0) {
			second = first + 1;
		}
		else {
			second = first - 1;
		}

	}
	if (first == 3) {
		typeOfOPeration = rand() % (N + 1) + 1;
		if (typeOfOPeration % 2 == 0) {
			second = first - 2;
		}
		else {
			second = first - 1;
		}
	}

	return second;
}



//How to print cool sudoku
void printSudoku(int** display) {

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


//The bool function checks if tha data that the user enters is valid.
bool isDataCorrect(char row, char column, char number, int** sudokuMatrix) {

	bool check = 0;

	//Here it checks if the data is within the borders of the sudoku indices.
	if ((row < '0' || row  > '9') || (column  > '9' || column  < '0') || (number  > '9' || number  < '0')) {
		cout << "Invalid operation. There is no such number with these cordinates. Try anather one: ";
		check = 0;
		return check;
	}
	else {
		check = 1;
	}
	//Here it checks if the entered number can replace the one in the template. 
	if (sudokuMatrix[row - '0' - 1][column - '0' - 1] != 0) {
		cout << "Invalid operation. You can't change this number. Try anather one: ";
		check = 0;

	}
	else {
		check = 1;
	}

	return check;
}

int convertCharToInt(char data) {
	return data - '0';
}

//This function checks if the answers are correct, if they are not correct it allows to reenter the value.
char isDataValid(char text) {
	while (text != 'N' && text != 'Y') {
		cout << "Please enter a valid answer: ";
		cin >> text;
		cout << "\n";
	}
	return text;
}

int main()
{
	srand((unsigned)time(NULL));
	

	cout << "Are you familiar with the sudoku rules?" << endl << "Type: Y - to continue or N - to see them: ";
	char rules;
	cin >> rules;
	cout << '\n';

	rules = isDataValid(rules);
	if (rules == 'N'){

		char* fileRules = new char[MAX_SIZE];
		ifstream sRules;

		sRules.open("SRules.txt");

		while (!sRules.eof()){

			sRules.getline(fileRules, 1024);
			cout << "" << fileRules << "\n";
		}
	}
	cout << '\n';


	char response='0';
	while (response != 'E' && response != 'C'){


		int fileNumber = rand() % N + 1;
		char fileNumber1 = fileNumber + 48;


		char* fileName = new char[7];
		fileName[0] = 'S';
		fileName[1] = fileNumber1;
		fileName[2] = '.';
		fileName[3] = 't';
		fileName[4] = 'x';
		fileName[5] = 't';
		fileName[6] = '\0';


		ifstream file;
		file.open(fileName, ios::in);


		int** sudoku = new int* [N];
		for (int i = 0; i < N; i++) {
			sudoku[i] = new int[N];
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				file >> sudoku[i][j];
			}
		}
		file.close();


		int** sudokuMixer = new int* [N];
		for (int i = 0; i < N; i++) {
			sudokuMixer[i] = new int[N];
			for (int j = 0; j < N; j++) {
				sudokuMixer[i][j] = sudoku[i][j];
			}
		}


		int numberOfChanges;
		numberOfChanges = rand() % (N * 2);


		int change;
		int** sudokuTemplate = new int* [N];
		for (int i = 0; i < N; i++) {
			sudokuTemplate[i] = new int[N];
		}

		//Here a few changes to sudoku are made it can be chaged by columns and rows depending on the random generated numbers which lead to certain operations
		for (int s = 0; s < numberOfChanges; s++) {
			change = rand() % 4 + 1;

			if (change == TWO_ROWS) {
				int row;
				row = rand() % N;
				int row2 = 0;
				row2 = secondVariable(row2, row);

				for (int c = 0; c < N; c++) {
					for (int s = 0; s < N; s++) {
						sudokuTemplate[c][s] = sudokuMixer[c][s];

						if (c == row) {
							sudokuTemplate[c][s] = sudokuMixer[row2][s];
						}
						if (c == row2) {
							sudokuTemplate[c][s] = sudokuMixer[row][s];
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
						sudokuTemplate[cc][ss] = sudokuMixer[cc][ss];

						if (ss == column) {
							sudokuTemplate[cc][ss] = sudokuMixer[cc][column2];
						}
						if (ss == column2) {
							sudokuTemplate[cc][ss] = sudokuMixer[cc][column];
						}

					}
				}
			}



			// At the following two we will use the numbers 1,2,3 to tell whitch whole three we will be taking.
			// That's why we use N/3 (9/3=3).


			if (change == THREE_ROWS) {
				int rows;
				rows = rand() % (N / 3) + 1;//for easier math operations;
				int rows2 = 0;
				rows2 = secondVariable2(rows2, rows);

				for (int c = 0; c < N; c++) {
					for (int s = 0; s < N; s++) {

						sudokuTemplate[c][s] = sudoku[c][s];

						//The third one will always be calculated by 3*row-1, so the following will be 3 * rows - 2, 3 * rows2 - 3.
						//We substract one because our matrx indices start from 0 and not 1.
						if (c == (3 * rows - 3)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows2 - 3][s];
						}
						if (c == (3 * rows - 2)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows2 - 2][s];
						}
						if (c == (3 * rows - 1)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows2 - 1][s];
						}
						if (c == (3 * rows2 - 3)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows - 3][s];
						}
						if (c == (3 * rows2 - 2)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows - 2][s];
						}
						if (c == (3 * rows2 - 1)) {
							sudokuTemplate[c][s] = sudokuMixer[3 * rows - 1][s];
						}
					}
				}
			}

			if (change == THREE_COLUMNS) {
				int columns;
				columns = rand() % (N / 3) + 1;
				int columns2 = 0;
				columns2 = secondVariable2(columns2, columns);


				for (int v = 0; v < N; v++) {
					for (int c = 0; c < N; c++) {
						sudokuTemplate[v][c] = sudokuMixer[v][c];

						//The third one will always be calculated by 3*columns-1, so the following will be 3 * columns - 2, 3 * columns - 3.
						//We substract one because our matrx indices start from 0 and not 1.
						if (c == (3 * columns - 3)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns2 - 3];
						}
						if (c == (3 * columns - 2)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns2 - 2];
						}
						if (c == (3 * columns - 1)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns2 - 1];
						}

						if (c == (3 * columns2 - 3)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns - 3];
						}
						if (c == (3 * columns2 - 2)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns - 2];
						}
						if (c == (3 * columns2 - 1)) {
							sudokuTemplate[v][c] = sudokuMixer[v][3 * columns - 1];
						}
					}
				}
			}

			for (int y = 0; y < N; y++) {
				for (int u = 0; u < N; u++) {
					sudokuMixer[y][u] = sudokuTemplate[y][u];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			delete[] sudokuMixer[i];
		}
		delete[] sudokuMixer;


		//If there are no changes the sudoku is the one from the text file.
		if (numberOfChanges == 0) {
			for (int y = 0; y < N; y++) {
				for (int u = 0; u < N; u++) {
					sudokuTemplate[y][u] = sudoku[y][u];
				}
			}
		}

		for (int i = 0; i < N; i++) {
			delete[] sudoku[i];
		}
		delete[] sudoku;


		int** sudokuKey = new int* [N];
		for (int i = 0; i < N; i++) {
			sudokuKey[i] = new int[N];
			for (int u = 0; u < N; u++) {
				sudokuKey[i][u] = sudokuTemplate[i][u];
			}
		}
		
		//uncomment for easier examination of the code
		//printSudoku(sudokuKey);


		// Here the user chooses which level to play. 
		char level;
		cout << "Choose level of difficulty: B-beginner; E-easy; M-medium; H-hard; U-ultimate" << "\n" << "type only the capital letter of the level" << "\n" << "Please enter which level you want: ";
		cin >> level;
		cout << "\n";


		int count = 0;

		//Validation of the data the user enters. 
		while (level != 'B' && level != 'E' && level != 'M' && level != 'H' && level != 'U') {
			cout << "please enter a valid level: ";
			cin >> level;
		}


		// Here are the possible levels and how they are dtertnmined:
			// | Level Name | Initial no.of Givens | Initial no. of Missing
			// 
			// | Begginer   | more than 50         | 17 - 31 //there is not a sudoku with less than 17 missing numbers
			// | Easy       | 36 - 40              | 40 - 45
			// | Medium     | 32 - 45              | 36 - 49
			// | Hard       | 28 - 31              | 50 - 53
			// | Ultimate   | 22 - 27              | 54 - 59
		//http://zhangroup.aporc.org/images/files/Paper_3485.pdf This is the resource i used for the information above. 

		if (level == 'B') {
			count = rand() % 14 + 17;
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

		//We make a new variable which we will use later on beacuse rom the first one we will extract numbers and the data will be lost.
		int counter = count;



		//Random delete of the sudoku munbers.
		int ii = rand() % N;
		int jj = rand() % N;
		while (count > 0) {
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

		//The matrix sudokuGame is the one that will be changed by the user, the sudokuTemplate - the one which tells if the numbers can be changed and the sudokuKey - the one that will validate the sudokuGame.
		int** sudokuGame = new int* [N];
		for (int i = 0; i < N; i++) {
			sudokuGame[i] = new int[N];
			for (int u = 0; u < N; u++) {
				sudokuGame[i][u] = sudokuTemplate[i][u];
			}
		}


		char row0 = '0';
		char column0 = '0';
		char number0 = '0';
		char answer = ' ';
		int row = 0;
		int column = 0;
		int number = 0;

		cout << "The first cooridnates digits are 1. The fist number is the row, then the column and the missing number at the end." << "\n" << "for example the coordinates of the tird number in the second row are: *2 3 number* " << "\n";

		while (counter > 0) {
			cout << "\n" << "Please enter the missing digits: ";
			cin >> row0 >> column0 >> number0;
			cout << "\n";
			//DALI E INT

			//Validataion of the data the user enters.
			bool check = 0;
			check = isDataCorrect(row0, column0, number0, sudokuTemplate);
			while (check == 0) {

				cin >> row0 >> column0 >> number0;
				check = isDataCorrect(row0, column0, number0, sudokuTemplate);
			}
			//TUK OT CHAR V INT

			row = convertCharToInt(row0);
			column = convertCharToInt(column0);
			number = convertCharToInt(number0);


			//Because the matrix indices start from 0 to 8 and we want to make it easier for the users we devide 1 from both
			row--;
			column--;



			if (sudokuGame[row][column] == 0) {
				sudokuGame[row][column] = number;
				counter--;
			}
			else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
				sudokuGame[row][column] = number;
			}

			cout << "Do you want to validate you solution?" << "\n" << "type: Y-yes N-no" << "\n" << "Please enter your desicion: ";
			cin >> answer;
			cout << "\n";

			answer = isDataValid(answer);
		

			if (answer == 'Y') {
				if (number == sudokuKey[row][column]) {
					cout << "Your answer is right." << "\n" << "\n";
				}
				else {
					cout << "Your answer is wrong." << "\n" << "\n";
				}
			}
			printSudoku(sudokuGame);

		}

		bool isSudokuRight = 1;

		for (int d = 0; d < N; d++) {
			for (int f = 0; f < N; f++) {
				if (sudokuGame[d][f] != sudokuKey[d][f]) {
					isSudokuRight = 0;
					break;
				}
			}
			if (isSudokuRight == 0) {
				break;
			}
		}
				

		if (isSudokuRight == 1) {
			cout << "You won!";
		}
		else {
			cout << "Your sudoku is incorrect!" << "\n" << "Do you want to end the game, continue trying or try another one?" << "\n" << "Type E - end, C - continue or A - another one: ";
			cin >> response;
			cout << "\n";

			//Validation of the data the user enters. 
			while (response != 'E' && response != 'C' && response != 'A') {
				cout << "Please enter a valid answer: ";
				cin >> response;
				cout << "\n";
			}


			if (response == 'E') {
				cout << "This was the correct sudoku:" << "\n";
				printSudoku(sudokuTemplate);
			}


			bool check = 1;

			if (response == 'C') {
				printSudoku(sudokuTemplate);
				printSudoku(sudokuGame);

				while (isSudokuRight == 0) {

					cout << "\n" << "Please enter the missing digits: ";
					cin >> row >> column >> number;
					cout << "\n";
					

					//Validataion of the data the user enters.
					check = isDataCorrect(row, column, number, sudokuTemplate);
					while (check == 0) {

						cin >> row >> column >> number;
						check = isDataCorrect(row, column, number, sudokuTemplate);
					}

					//Because the matrix indices start from 0 to 8 and we want to make it easier for the users we devide 1 from both
					row--;
					column--;


					if (sudokuGame[row][column] == 0) {
						sudokuGame[row][column] = number;
					}
					else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
						sudokuGame[row][column] = number;
					}
					

					for (int dd = 0; dd < N; dd++) {
						for (int ff = 0; ff < N; ff++) {
							if (sudokuGame[dd][ff] != sudokuKey[dd][ff]) {
								isSudokuRight = 0;
								break;
							}
							else {
								isSudokuRight = 1;
							}
						}
						if (isSudokuRight == 0) {
							break;
						}
					}
					printSudoku(sudokuGame);
					
					if (isSudokuRight == 1) {
					cout << "You won!";
					cout << "\n";
					}
					
					cout<<"Do you want one more game?" << "\n"<<"Type Y - yes or N -no:";
					cin >> answer;
					cout << "\n";
					answer = isDataValid(answer);

					if (answer == 'Y') {
						response = 'A';
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			delete[] sudokuTemplate[i];
		}
		delete[] sudokuTemplate;

		for (int i = 0; i < N; i++) {
			delete[] sudokuKey[i];
		}
		delete[] sudokuKey;

		for (int i = 0; i < N; i++) {
			delete[] sudokuGame[i];
		}
		delete[] sudokuGame;
	}
		
	return 0;
}