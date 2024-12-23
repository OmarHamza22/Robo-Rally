#pragma once
#include "GameObject.h"
#include < fstream >

class Flag :public GameObject
{
public:
	Flag(const CellPosition & flagposition); // A constructor for initialization
	virtual void Draw(Output* pOut) const; // Draws a flag in a selected cell
	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the flag

	virtual void Save(ofstream& OutFile, string file);
	virtual void Load(ifstream& Infile, string file);

	virtual ~Flag(); // Virtual destructor
};