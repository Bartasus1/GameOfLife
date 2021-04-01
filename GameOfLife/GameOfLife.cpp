#include <conio.h>
#include <cstdlib>
#include <time.h>
#include "Plansza.h"
#include "Komorka.h"

void Show();
void Zadanie2(float p0=0.3, int Width = 100, int Height = 100);
void Zadanie3(int Size);

int main()
{
	srand(time(NULL));

	//Zadanie2(0.05)
	//Zadanie3(10);
	Show();

	return 0;
}




void Show()
{
	Plansza _Plansza(10,10); // Width & Height

	vector<string> Table1 = { // Heart 10x10
		".", ".", ".", ".",".", ".", ".", ".", ".", ".",
		".", ".", ".", ".",".", ".", ".", ".", ".", ".",
		".", ".", "#", "#",".", "#", "#", ".", ".", ".",
		".", "#", ".", ".","#", ".", ".", "#", ".", ".",
		".", "#", ".", ".",".", ".", ".", "#", ".", ".",
		".", "#", ".", ".",".", ".", ".", "#", ".", ".",
		".", ".", "#", ".",".", ".", "#", ".", ".", ".",
		".", ".", ".", "#",".", "#", ".", ".", ".", ".",
		".", ".", ".", ".","#", ".", ".", ".", ".", ".",
		".", ".", ".", ".",".", ".", ".", ".", ".", ".",
	};

	map<int, string> Table = {
		{33,"#"},
		{34,"#"},
		{35,"#"},
		{44,"#"}
	};

	_Plansza.SetAliveCells(Table);

	while (true)
	{
		cout << "\x1b[2J";

		_Plansza.Render();

		unsigned char Key = _getch();
		if (Key == 'q')
			_Plansza.MakeStep();
	}
}
void Zadanie2(float p0, int Width , int Height)
{
	Plansza _Plansza(Width, Height);

	for (auto &Cell : _Plansza.Cells)
	{
		float random = rand() / (float)RAND_MAX;
		if (random < p0)
		{
			Cell.SetIsAlive(true);
		}
		else
		{
			Cell.SetIsAlive(false);
		}
	}
	//_Plansza.Render();

	int t = 0;
	while (t < 1000)
	{
		_Plansza.MakeStep();
		//_Plansza.Render();
		t++;
	}
	cout << (_Plansza.CountAliveCells() / float(_Plansza.Cells.size())) << endl;

	//_Plansza.Render();

}

void Zadanie3(int Size)
{
	for (int N = 0; N <= 100; N++)
	{
		Zadanie2(0.3, Size, Size);
	}
}