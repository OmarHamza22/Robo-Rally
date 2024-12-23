#pragma once
#include "GameObject.h"
#include < fstream >

class DangerZone:public GameObject
{
public:
	DangerZone(const CellPosition & dangerZonePosition);
	virtual void Draw(Output* pOut) const; // Draws a danger zone in the cell

	virtual void Apply(Grid* pGrid, Player* pPlayer); // Applys the effect of the danger zone by reducing the robot's health by 1

	virtual void Save(ofstream& OutFile, string file);
	virtual void Load(ifstream& Infile, string file);


	virtual ~DangerZone();
};

