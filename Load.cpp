#include "Load.h"
#include "Grid.h"
#include"fstream"
#include "DEFS.h"
void Load::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Output* pOut = pGride->GetOutput();
	Input* pIn = pGride->GetInput();
	pOut->PrintMessage("Please Enter File Name: ");
	filname = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

void Load::Execute()
{
	ReadActionParameters();
	ifstream infile(filname, ios::in);
	Grid* pGride = pManager->GetGrid();
	if (!infile.is_open())    //to check if the file is opened or not
	{
		pGride->PrintErrorMessage("Error: Could not open file ");
		return;
	}
	pGride->LoadAll(infile, filname, Flags);
	pGride->LoadAll(infile, filname, WaterPits);
	pGride->LoadAll(infile, filname, DangerZones);
	pGride->LoadAll(infile, filname, Belts);
	pGride->LoadAll(infile, filname, Workshops);
	pGride->LoadAll(infile, filname, Antennas);
	pGride->LoadAll(infile, filname, RotatingGears);
	infile.close();
	pGride->GetOutput()->PrintMessage("Grid Has Been Laded Successfully");
}

Load::~Load()
{

}
