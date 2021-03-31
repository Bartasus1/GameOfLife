#include "Komorka.h"
#include "Plansza.h"
#include <algorithm>


void Komorka::SetIsAlive(bool IsAlive)
{
	bIsAlive = IsAlive;
}

bool Komorka::GetIsAlive()
{
	return bIsAlive;
}

void Komorka::SetAliveNeighbours(int Value)
{
	AliveNeighbours = Value;

	if (bIsAlive)
	{
		if (AliveNeighbours < 2 || AliveNeighbours > 3)
		{
			SetIsAlive(false);
		}
	}
	else
	{
		if (AliveNeighbours == 3)
		{
			SetIsAlive(true);
		}
	}
}

int Komorka::GetAliveNeighbours()
{
	return AliveNeighbours;
}

int Komorka::CountAliveNeighbours(Plansza* _Plansza, int ID)
{
	int X = ID % _Plansza->Width;
	int Y = ID / _Plansza->Height;
	int FoundAliveNeighbours = 0;
	
	for (int i = X - 1; i <= X + 1; i++) // from left to right
	{	
		for (int j = Y - 1; j <= Y + 1; j++) // from up to bottom
		{
			int x = i;
			int y = j;

			if (i == _Plansza->Width)		x = 0;
			if (i == -1)					x = _Plansza->Width - 1;
			
			if (j == _Plansza->Height)		y = 0;
			if (j == -1)					y = _Plansza->Height - 1;

			int Number = x + y * _Plansza->Height;	

			if (_Plansza->Cells[Number].bIsAlive)
			{
				FoundAliveNeighbours++;
			}	
		}
	}
	FoundAliveNeighbours = bIsAlive ? FoundAliveNeighbours - 1 : FoundAliveNeighbours;

	return FoundAliveNeighbours;
}

Komorka::Komorka()
{

}

Komorka::~Komorka()
{

}