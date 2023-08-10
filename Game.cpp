#include "Game.h"

int Game::start(char elem)
{
	char key;
	int x = 5, y = 5;
	int checkx, checky;
	if ((
		(((this->array[1][1] == this->array[1][5]) && (this->array[1][5] == this->array[1][9])) && this->array[1][1] != ' ')
		|| (((this->array[5][1] == this->array[5][5]) && (this->array[5][5] == this->array[5][9])) && this->array[5][1] != ' ')
		|| (((this->array[9][1] == this->array[9][5]) && (this->array[9][5] == this->array[9][9])) && this->array[9][1] != ' ')
		) || ((((this->array[1][1] == this->array[5][1]) && (this->array[5][1] == this->array[9][1])) && this->array[1][1] != ' ')
			|| (((this->array[1][5] == this->array[5][5]) && (this->array[5][5] == this->array[9][5])) && this->array[1][5] != ' ')
			|| (((this->array[1][9] == this->array[5][9]) && (this->array[5][9] == this->array[9][9])) && this->array[1][9] != ' ')
			) || ((((this->array[1][1] == this->array[5][5]) && (this->array[5][5] == this->array[9][9])) && this->array[1][1] != ' ')
				|| (((this->array[9][1] == this->array[5][5]) && (this->array[5][5] == this->array[1][9])) && this->array[9][1] != ' ')
				))
	{
		return 1;
	}
	if (this->array[1][1] != ' ' && this->array[1][5] != ' ' && this->array[1][9] != ' '
		&& this->array[5][1] != ' ' && this->array[5][5] != ' ' && this->array[5][9] != ' '
		&& this->array[9][1] != ' ' && this->array[9][5] != ' ' && this->array[9][9] != ' ')
	{
		return 0;
	}
	for (int i = 1; i < 11; i += 4)
	{
		for (int j = 1; j < 11; j += 4)
		{
			if (this->array[i][j] == ' ')
			{
				x = j;
				y = i;
			}
		}
	}




	do {
		this->array[y][x] = elem;
		checkx = x, checky = y;

		system("cls");
		cout << *this;
		this->array[checky][checkx] = ' ';
		cout << "\nPress e to set x or o\n";
		cout << "Press c to go the center\n";
		cout << "Press r to go the random place\n";
		key = _getch();
		if (this->array[5][5] == ' ' && key == 'c')
		{
			x = 5;
			y = 5;
		}
		else if (key == 'r')
		{

			bool check = true;
			while (check)
			{
				int randomx = rand() % 3;
				int randomy = rand() % 3;
				switch (randomx)
				{
				case 0:
					x = 1;
					break;
				case 1:
					x = 5;
					break;
				case 2:
					x = 9;
					break;
				}
				switch (randomy)
				{
				case 0:
					y = 1;
					break;
				case 1:
					y = 5;
					break;
				case 2:
					y = 9;
					break;
				}
				if (this->array[y][x] == ' ')
				{
					check = false;
				}


			}
		}
		else if (x == 1 && this->array[y][5] != ' ' && this->array[y][9] == ' ' && key == 'd')
		{
			x += 8;

		}
		else if (x == 9 && this->array[y][5] != ' ' && this->array[y][9] == ' ' && key == 'a')
		{
			x -= 8;
		}
		else if (y == 1 && this->array[5][x] != ' ' && this->array[9][x] == ' ' && key == 's')
		{
			y += 8;
		}
		else if (y == 9 && this->array[5][x] != ' ' && this->array[9][x] == ' ' && key == 'w')
		{
			y -= 8;
		}

		else if (x == 5 && y == 1 && this->array[1][1] != ' ' && this->array[5][5] != ' ' && this->array[5][1] == ' ' && key == 'a')
		{
			x = 1;
			y = 5;
		}
		else if (x == 5 && y == 1 && this->array[1][9] != ' ' && this->array[5][5] != ' ' && this->array[5][9] == ' ' && key == 'd')
		{
			x = 9;
			y = 5;
		}

		else if (x == 1 && y == 5 && this->array[1][1] != ' ' && this->array[5][5] != ' ' && this->array[1][5] == ' ' && key == 'w')
		{
			x = 5;
			y = 1;
		}
		else if (x == 1 && y == 5 && this->array[5][5] != ' ' && this->array[9][1] != ' ' && this->array[9][5] == ' ' && key == 's')
		{
			x = 5;
			y = 9;
		}



		else if (x == 9 && y == 5 && this->array[1][9] != ' ' && this->array[5][5] != ' ' && this->array[1][5] == ' ' && key == 'w')
		{
			x = 5;
			y = 1;
		}
		else if (x == 9 && y == 5 && this->array[5][5] != ' ' && this->array[9][9] != ' ' && this->array[9][5] == ' ' && key == 's')
		{
			x = 5;
			y = 9;
		}

		else if (x == 5 && y == 9 && this->array[5][5] != ' ' && this->array[9][1] != ' ' && this->array[5][1] == ' ' && key == 'a')
		{
			x = 1;
			y = 5;
		}
		else if (x == 5 && y == 9 && this->array[5][5] != ' ' && this->array[9][9] != ' ' && this->array[5][9] == ' ' && key == 'd')
		{
			x = 9;
			y = 5;
		}

		else
		{
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
		}

		if (x < 0 || y < 0 || x > 11 || y > 11 || this->array[y][x] != ' ')
		{
			x = checkx;
			y = checky;
		}

	} while (key != 'e');
	this->array[y][x] = elem;
	return 5;
}

ostream& operator<< (ostream& out, Game& obj)
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << obj.array[i][j];
		}
		cout << "\n";
	}
	return out;
}
