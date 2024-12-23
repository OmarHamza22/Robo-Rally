#pragma once
#include "GameObject.h"
#include < fstream >

class Antenna :public GameObject
{
public:
	Antenna(const CellPosition & antennaPosition);
	virtual void Draw(Output* pOut) const; // Draws an antenna

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the antenna by deciding the players turns

	virtual void Save(ofstream& OutFile, string file);
	virtual void Load(ifstream& Infile, string file);


	virtual ~Antenna();
};

