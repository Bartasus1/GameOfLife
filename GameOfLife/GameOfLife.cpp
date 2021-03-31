#include <conio.h>
#include <cstdlib>
#include <time.h>
#include "Plansza.h"
#include "Komorka.h"

void Show();
void Zadanie2(float p0=0.6, int Width = 100, int Height = 100);
void Zadanie3();

int main()
{
	srand(time(NULL));

	Zadanie2();
	//Show();

	return 0;
}




void Show()
{
	Plansza _Plansza(10, 10); // Width & Height

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
	//for (int i = 0; i < _Plansza.Cells.size(); i++)
	//{
	//	
	//	if (i % _Plansza.Width == 0)
	//		cout << endl;
	//	cout << i << "\t";
	//	//int r = rand()%2;
	//	//if (r == 0)
	//	//	_Plansza.Cells[i].SetIsAlive(true);
	//	//else
	//	//	_Plansza.Cells[i].SetIsAlive(false);
	//}
	//int i = 0;
	while (true)
	{
		cout << "\x1b[3J";

		_Plansza.Render();

		unsigned char Key = _getch();
		if (Key == 'q')
			_Plansza.MakeStep();
		//i++;
	}
}
void Zadanie2(float p0, int Width , int Height)
{
	Plansza _Plansza(Width, Height);

	for (auto &Cell : _Plansza.Cells)
	{
		float random = rand() / (float)RAND_MAX;
		if (random > p0)
		{
			Cell.SetIsAlive(true);
		}
		else
		{
			Cell.SetIsAlive(false);
		}
	}
	_Plansza.Render();
	int t = 0;
	while (t < 2000)
	{
		_Plansza.MakeStep();
		cout << _Plansza.CountAliveCells() << endl;
		//_Plansza.Render();
		t++;
	}

	//_Plansza.Render();
	cout << endl;
	cout << _Plansza.CountAliveCells() << endl;
}

void Zadanie3()
{
	const int SizeL = 5;
	int L[5] = { 10, 20, 50, 100, 200 };

	for (int i = 0; i < SizeL; i++)
	{
		for (int N = 0; N <= 100; N++)
		{
			Zadanie2(0.8,i, i);
		}
		cout << endl;
	}

}