#pragma once


const int TWO_ROWS = 1;
const int TWO_COLUMNS = 2;
const int THREE_ROWS = 3;
const int THREE_COLUMNS = 4;
const int MAX_SIZE = 1024;

//This function checks if the answers are correct, if they are not correct it allows to reenter the value.
char isDataValid(char text);


//Openeing the sudoku rules if necessarily.
void rules();


//Opening the sudoku file.
int** getSudoku();


//Deleting the dynamic memory.
void deleteMemory(int** sudoku);


//Creating the second variable due to the first variable characteristics.
int secondVariable(int second, int first);


//Creating the second variable due to the first variable characteristics.
int secondVariable2(int second, int first);


//Sudoku mixer
int** mixSudoku(int** sudoku);


//Random delete of the sudoku munbers.
int** randomDeleter(int** sudoku, int count);


//How to print cool sudoku
void printSudoku(int** display);


//The bool function checks if tha data that the user enters is valid.
bool isDataCorrect(char row, char column, char number, int** sudokuMatrix);


//Converting the data from char to int.
int convertCharToInt(char data);


//Solving the soduku, all validations od the data the user has eneterd, all converting operation ect.
int solveSudoku(int counter, char row0, char column0, char number0, char answer, int row, int column, int number, int** sudokuGame, int** sudokuTemplate, int** sudokuKey);


//Checking if the sudoku enetered by the ueser is the same as the generated one.
bool isSudokuCorrect(int** sudokuGame, int** sudokuKey);


//One more game after the user finishes the first one and validation of the entered data.
char oneMoreGame(char answer);

