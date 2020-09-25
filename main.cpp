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

	show_game();

	return 0;
}
