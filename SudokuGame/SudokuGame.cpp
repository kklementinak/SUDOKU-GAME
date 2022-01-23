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
* <game code>
*
*/


# include <iostream>
# include <cstdio>
# include <fstream>
# include "sudokuFunctions.h"
using namespace std;
# define N 9




int main()
{
	srand((unsigned)time(NULL));
	
	//Openeing the sudoku rules if necessarily.
	rules();

	
	char response='0';
	while (response != 'E' && response != 'C'){

		//Opening the sudoku file.
		int** sudoku = getSudoku();

		//Creating a new sudoku from already existing one.
		int** sudokuTemplate = mixSudoku(sudoku);



		
		//The will help in the examination of the game (if the data is correct or else).
		int** sudokuKey = new int* [N];
		for (int i = 0; i < N; i++) {
			sudokuKey[i] = new int[N];
			for (int u = 0; u < N; u++) {
				sudokuKey[i][u] = sudokuTemplate[i][u];
			}
		}
		
		//uncomment for easier examination of the code
		//printSudoku(sudokuKey);


		//Here the user chooses which level to play. 
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
		randomDeleter(sudokuTemplate, count);

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

	

		cout << "The first cooridnates digits are 1. The first number is the row, then the column and the missing number at the end." << "\n" << "for example the coordinates of the tird number in the second row are: *2 3 number*. " << "\n" << "Note: if you want to delete a number you have entered type its coordinates then 0." << "\n";

		while (counter > 0) {

			//Solving the soduku, all validations od the data the user has eneterd, all converting operation ect.
			counter = solveSudoku(counter, row0, column0, number0, answer, row, column, number, sudokuGame, sudokuTemplate, sudokuKey);
		}

		//Checking if the sudoku is completly the same as the key.
		bool isSudokuRight = isSudokuCorrect(sudokuGame, sudokuKey);
				

		if (isSudokuRight == 1) {
			cout << "You won!";

			//Asking the user if they want another game.
			answer = oneMoreGame(answer);

			if (answer == 'Y') {
				response = 'A';
			}
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

				//Asking the user if they want another game.
				answer = oneMoreGame(answer);

				if (answer == 'Y') {
					response = 'A';
				}
			}


			if (response == 'C') {
				printSudoku(sudokuTemplate);
				printSudoku(sudokuGame);

				while (isSudokuRight == 0) {


					//Solving the soduku, all validations od the data the user has eneterd, all converting operation ect.
					solveSudoku(counter, row0, column0, number0, answer, row, column, number, sudokuGame, sudokuTemplate, sudokuKey);
					
					isSudokuRight = isSudokuCorrect(sudokuGame, sudokuKey);

					if (isSudokuRight == 1) {
					cout << "You won!";
					//Asking the user if they want another game.
					answer = oneMoreGame(answer);

					}
									
					if (answer == 'Y') {
						response = 'A';
					}
				}
			}
		}

		deleteMemory(sudokuGame);
		deleteMemory(sudokuKey);
		deleteMemory(sudokuTemplate);

	}
		
	return 0;
}