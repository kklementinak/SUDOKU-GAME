/**
*
* Solution to course project # 6
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Klementina Kartevska
* @idnumber 9MI0600060
* @compiler VS
*
* <cpp with helper functions>
*
*/

# include <iostream>
# include <cstdio>
# include <fstream>
# include "sudokuFunctions.h"
using namespace std;
# define N 9

//
const int TWO_ROWS = 1;
const int TWO_COLUMNS = 2;
const int THREE_ROWS = 3;
const int THREE_COLUMNS = 4;
const int MAX_SIZE = 1024;







//This function checks if the answers are correct, if they are not correct it allows to reenter the value.
char isDataValid(char text) {
	while (text != 'N' && text != 'Y') {
		cout << "Please enter a valid answer: ";
		cin >> text;
		cout << "\n";
	}
	return text;
}


//Openeing the sudoku rules if necessarily.
void rules() {
	cout << "Are you familiar with the sudoku rules?" << endl << "Type: Y - to continue or N - to see them: ";
	char rules;
	cin >> rules;
	cout << '\n';

	rules = isDataValid(rules);
	if (rules == 'N') {

		char* fileRules = new char[MAX_SIZE];
		ifstream sRules;

		sRules.open("SRules.txt");

		while (!sRules.eof()) {

			sRules.getline(fileRules, 1024);
			cout << "" << fileRules << "\n";
		}
	}
	cout << '\n';
}


//Opening the sudoku file.
int** getSudoku() {
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

	return sudoku;
}


//Deleting the dynamic memory.
void deleteMemory(int** sudoku) {
	for (int i = 0; i < N; i++) {
		delete[] sudoku[i];
	}
	delete[] sudoku;
}


//Creating the second variable due to the first variable characteristics.
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


//Creating the second variable due to the first variable characteristics.
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
	if (first == 2) {
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


//Sudoku mixer
int** mixSudoku(int** sudoku) {
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

					sudokuTemplate[c][s] = sudokuMixer[c][s];

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

		//Here we give the mixer the template values in order to be able to mix the following variations, beacuse if we don't do it it will be giving wrong output.
		for (int y = 0; y < N; y++) {
			for (int u = 0; u < N; u++) {
				sudokuMixer[y][u] = sudokuTemplate[y][u];
			}
		}
	}
	deleteMemory(sudokuMixer);
	//If there are no changes the sudoku is the one from the text file.
	if (numberOfChanges == 0) {
		for (int y = 0; y < N; y++) {
			for (int u = 0; u < N; u++) {
				sudokuTemplate[y][u] = sudoku[y][u];
			}
		}
	}

	deleteMemory(sudoku);

	return sudokuTemplate;
}


//Random delete of the sudoku munbers.
int** randomDeleter(int** sudoku, int count) {

	int ii = rand() % N;
	int jj = rand() % N;
	while (count > 0) {
		if (sudoku[ii][jj] != 0) {
			sudoku[ii][jj] = 0;
			count--;
			ii = rand() % N;
			jj = rand() % N;
		}
		else {
			ii = rand() % N;
			jj = rand() % N;
		}
	}
	return sudoku;
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
	if ((row < '0' || row  > '9') || (column > '9' || column < '0') || (number > '9' || number < '0')) {
		cout << "Invalid operation. There is no such number with these cordinates. Try another one: ";
		check = 0;
		return check;
	}
	else {
		check = 1;
	}
	//Here it checks if the entered number can replace the one in the template. 
	if (sudokuMatrix[row - '0' - 1][column - '0' - 1] != 0) {
		cout << "Invalid operation. You can't change this number. Try another one: ";
		check = 0;

	}
	else {
		check = 1;
	}

	return check;
}


//Converting the data from char to int.
int convertCharToInt(char data) {
	return data - '0';
}


//Solving the soduku, all validations od the data the user has eneterd, all converting operation ect.
int solveSudoku(int counter, char row0, char column0, char number0, char answer, int row, int column, int number, int** sudokuGame, int** sudokuTemplate, int** sudokuKey) {
	cout << "\n" << "Please enter the missing digits: ";
	cin >> row0 >> column0 >> number0;
	cout << "\n";


	//Validataion of the data the user enters.
	bool check = 0;
	check = isDataCorrect(row0, column0, number0, sudokuTemplate);
	while (check == 0) {
		cin >> row0 >> column0 >> number0;
		check = isDataCorrect(row0, column0, number0, sudokuTemplate);
	}

	//Converting the data from char to int.
	row = convertCharToInt(row0);
	column = convertCharToInt(column0);
	number = convertCharToInt(number0);


	//Because the matrix indices start from 0 to 8 and we want to make it easier for the users we substract 1 from both
	row--;
	column--;



	if (sudokuGame[row][column] == 0) {
		sudokuGame[row][column] = number;
		counter--;
	}
	else if (sudokuGame[row][column] != 0 && sudokuTemplate[row][column] == 0) {
		sudokuGame[row][column] = number;
	}

	cout << "Do you want to validate your solution?" << "\n" << "type: Y-yes N-no" << "\n" << "Please enter your decision: ";
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

	return counter;
}


//Checking if the sudoku enetered by the ueser is the same as the generated one.
bool isSudokuCorrect(int** sudokuGame, int** sudokuKey) {

	for (int d = 0; d < N; d++) {
		for (int f = 0; f < N; f++) {
			if (sudokuGame[d][f] != sudokuKey[d][f]) {
				return 0;
			}
		}
	}
	return 1;
}


//One more game after the user finishes the first one and validation of the entered data.
char oneMoreGame(char answer) {
	cout << "\n" << "Do you want one more game?" << "\n" << "Type Y - yes or N -no: ";
	cin >> answer;
	cout << "\n";
	answer = isDataValid(answer);
	return answer;
}


