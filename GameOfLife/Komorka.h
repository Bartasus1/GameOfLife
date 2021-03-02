#pragma once

class Plansza; 


class Komorka
{
private:

	bool bIsAlive = false;
	int AliveNeighbours = 0;

public:
	void SetIsAlive(bool IsAlive);
	bool GetIsAlive();

	void SetAliveNeighbours(int Value);
	int GetAliveNeighbours();

	int CountAliveNeighbours(Plansza* _Plansza, int ID);

	Komorka();
	~Komorka();

};

