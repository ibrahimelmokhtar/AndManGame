#include <iostream>
#include <conio.h>		// to use _getch() function
#include <ctime>		// to generate random number every time you start the game

using namespace std;

// ********************************************************************************************************************
// The Variables ::

// 1. The 2-D Array :
const int rows = 15;								// Rows for the frame
const int columns = 35;								// Columns for the frame
char Total_Array[rows][columns];					// the Frame of the Game.

// 2. And_Man :
int And_Man_Position_Row;							// Row	
int And_Man_Position_Column;						// Column
char Current_And_Man_Letter_Value = 'A';			// Current Letter
// 3. And :
int The_And_Position_Row;							// Row
int The_And_Position_Column;						// Column

// ********************************************************************************************************************
// The frame functions
void print_2D_array()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			Total_Array[i][j] = '#';
	}
}
void initialize_with_spaces()
{
	for (int i = 1; i < rows - 1; i++)
	{
		for (int j = 1; j < columns - 1; j++)
			Total_Array[i][j] = ' ';
	}
}

// ********************************************************************************************************************
// The initialization functions .. for ANDs , AND_MAN
void add_random_food()
{
	srand(time(0));
	The_And_Position_Row = (rand() % (rows - 2)) + 1;
	The_And_Position_Column = (rand() % (columns - 2)) + 1;

	Total_Array[The_And_Position_Row][The_And_Position_Column] = '&';
}
void initialize_and_man()
{
	And_Man_Position_Row = (rand() % (rows - 2)) + 1;
	And_Man_Position_Column = (rand() % (columns - 2)) + 1;

	Total_Array[And_Man_Position_Row][And_Man_Position_Column] = Current_And_Man_Letter_Value;
}

// ********************************************************************************************************************
// Other functions ...
void show_game()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << Total_Array[i][j];
		cout << endl;
	}
}

// ********************************************************************************************************************
// The main function
int main()
{
	// the following TWO functions are to make the frame of the game.
	print_2D_array();
	initialize_with_spaces();

	// the following TWO functions are to initialize (the And) and (the And_Man)
	add_random_food();
	initialize_and_man();

	show_game();

	return 0;
}
