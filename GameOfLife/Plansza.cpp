#include "Plansza.h"
#include "Komorka.h"
#include <algorithm>

Plansza::Plansza(int W, int H) : Width(W), Height(H)
{
	int Size = Width * Height;

	Cells.resize(Size);
	for (int i = 0; i < Size; i++)
	{
		Cells[i] = Komorka();
	}
}



void Plansza::Render()
{
	for (int i = 0; i < Cells.size(); i++)
	{
		if (i % Width == 0)
			cout << endl;

		if (Cells[i].GetIsAlive())
			cout << "#" << " ";
		else
			cout << "." << " ";
	}
	cout << endl;
}

void Plansza::MakeStep()
{
	vector<Komorka> NewCells;

	for (int i = 0; i < Cells.size(); i++)
	{
		NewCells.push_back(Cells[i]);

		int AliveNeighbours = Cells[i].CountAliveNeighbours(this, i);
		NewCells[i].SetAliveNeighbours(AliveNeighbours);
	}
	for (int i = 0; i < Cells.size(); i++)
	{
		Cells[i] = NewCells[i];
	}
}

void Plansza::SetAliveCells(vector<string> &Table)
{
	for (int i = 0; i < Cells.size(); i++)
	{
		if (i < Table.size())
		{
			if (Table[i] == "#")
			{
				Cells[i].SetIsAlive(true);
			}
		}
	}

}

void Plansza::SetAliveCells(map<int, string> &Table)
{
	for (auto Pair : Table)
	{
		int Index = clamp(Pair.first, 0, (int)Cells.size());
		Cells[Index].SetIsAlive(true);
	}
}

int Plansza::CountAliveCells()
{
	int AliveCells = 0;
	for (auto &Cell : Cells)
	{
		if (Cell.GetIsAlive())
			AliveCells++;
	}

	return AliveCells;
}

Plansza::~Plansza()
{
}
