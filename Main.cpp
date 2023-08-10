#include "Header.h"
#include "Game.h"


int main()
{
	srand(time(0));
	Game game;
	char elem, inelem;
	int check = 5;
	for (int i = 0;; i++)
	{
		if (i % 2 == 0)
		{
			elem = 'x';
			inelem = 'o';
		}
		else
		{
			elem = 'o';
			inelem = 'x';
		}
		check = game.start(elem);
		system("cls");
		switch (check)
		{
		case 0:
			cout << "\n\t\tDraw\n";
			break;
		case 1:
			cout << "\n\t\tWin " << inelem << "\n";
			break;
		}
		if (check != 5)
		{
			break;
		}

	}

	_getch();
	return 0;
}