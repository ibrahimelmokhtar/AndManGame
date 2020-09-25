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
// 4. Pressed Key :
char c;												// pressed key from the USER.
// 5. Setting the Score :
int Score = 0;										// Score of the game


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
// The control functions 
void man_go_right()
{
	char temp = Total_Array[And_Man_Position_Row][And_Man_Position_Column];
	Total_Array[And_Man_Position_Row][And_Man_Position_Column] = ' ';

	if (And_Man_Position_Column != (columns - 2))
		Total_Array[And_Man_Position_Row][++And_Man_Position_Column] = temp;
	else
	{
		And_Man_Position_Column = 1;
		Total_Array[And_Man_Position_Row][And_Man_Position_Column] = temp;
	}
}

void man_go_left()
{
	char temp = Total_Array[And_Man_Position_Row][And_Man_Position_Column];
	Total_Array[And_Man_Position_Row][And_Man_Position_Column] = ' ';

	if (And_Man_Position_Column != 1)
		Total_Array[And_Man_Position_Row][--And_Man_Position_Column] = temp;
	else
	{
		And_Man_Position_Column = columns - 2;
		Total_Array[And_Man_Position_Row][And_Man_Position_Column] = temp;
	}
}

void man_go_up()
{
	char temp = Total_Array[And_Man_Position_Row][And_Man_Position_Column];
	Total_Array[And_Man_Position_Row][And_Man_Position_Column] = ' ';

	if (And_Man_Position_Row != 1)
		Total_Array[--And_Man_Position_Row][And_Man_Position_Column] = temp;
	else
	{
		And_Man_Position_Row = rows - 2;
		Total_Array[And_Man_Position_Row][And_Man_Position_Column] = temp;
	}
}

void man_go_down()
{
	char temp = Total_Array[And_Man_Position_Row][And_Man_Position_Column];
	Total_Array[And_Man_Position_Row][And_Man_Position_Column] = ' ';

	if (And_Man_Position_Row != (rows - 2))
		Total_Array[++And_Man_Position_Row][And_Man_Position_Column] = temp;
	else
	{
		And_Man_Position_Row = 1;
		Total_Array[And_Man_Position_Row][And_Man_Position_Column] = temp;
	}
}

void check_pressed_key()
{
	if (c == 'D' || c == 'd')
		man_go_right();
	if (c == 'A' || c == 'a')
		man_go_left();
	if (c == 'W' || c == 'w')
		man_go_up();
	if (c == 'S' || c == 's')
		man_go_down();
}


// ********************************************************************************************************************
// Other functions ...
void check_food_eaten()
{
	if ((And_Man_Position_Row == The_And_Position_Row) && (And_Man_Position_Column == The_And_Position_Column))
	{
		Score++;
		Total_Array[And_Man_Position_Row][And_Man_Position_Column] = ++Current_And_Man_Letter_Value;
		add_random_food();
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

void clear_console()
{
	system("cls");
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

	// now we can start playing ...
	while (Current_And_Man_Letter_Value != 'E')
	{
		show_game();
		c = _getch();
		check_pressed_key();
		check_food_eaten();

		clear_console();
	}

	cout << "Game over!\n";


	return 0;
}
