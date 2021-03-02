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

	int X = ID % _Plansza->Height;
	int Y = ID / _Plansza->Width;
	int FoundAliveNeighbours = 0;
	
	for (int i = X - 1; i <= X + 1; i++) // from left to right
	{
		if (i >= 0)
		{
			for (int j = Y - 1; j <= Y + 1; j++) // from up to bottom
			{
				if (j >= 0)
				{
					int Number = i + j * _Plansza->Height;
					int MaxSize = static_cast<int>(_Plansza->Cells.size());
					
					Number = clamp(Number, 0, MaxSize - 1);

					if (_Plansza->Cells[Number].bIsAlive)
					{
						FoundAliveNeighbours++;
					}
					
				}
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