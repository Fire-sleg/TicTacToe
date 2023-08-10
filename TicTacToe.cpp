#include "Header.h"

void print(string* array)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << array[i][j];
		}
		cout << "\n";
	}
}

void TicTacToe(string* array, char elem)
{
	char key;
	int x = 5, y = 5;
	int checkx, checky;


	do {
		array[y][x] = elem;
		checkx = x, checky = y;

		system("cls");
		print(array);
		array[checky][checkx] = ' ';
		cout << "\nPress e to set x or o\n";
		key = _getch();

		if (key == 'w')
		{
			y -= 4;
		}

		if (key == 's')
		{
			y += 4;
		}
		if (key == 'a')
		{
			x -= 4;
		}
		if (key == 'd')
		{
			x += 4;
		}

		if (x < 0 || y < 0 || x > 11 || y > 11)
		{
			x = checkx;
			y = checky;
		}

	} while (key != 'e');
}

