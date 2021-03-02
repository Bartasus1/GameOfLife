#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>


using namespace std;

class Komorka;

class Plansza
{
public:
	const int Width;
	const int Height;

	std::vector<Komorka> Cells;

public:
	Plansza(int W, int H);
	~Plansza();

	void Render();
	void MakeStep();
	void SetAliveCells(vector<string> &Table);
	void SetAliveCells(map<int,string> &Table);
};

