#include "Save.h"
#include "Grid.h"
#include"fstream"
#include "DEFS.h"
void Save::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Output* pOut = pGride->GetOutput();
	Input* pIn = pGride->GetInput();
	pOut->PrintMessage("Please Enter File Name: ");
	filename = pIn->GetSrting(pOut) + ".txt"; //to get the file from the user and change it the file to txt
	pOut->ClearStatusBar();
}
void Save::Execute()
{
	ReadActionParameters();     //to read the filename
	ofstream outfile(filename, ios::out);
	Grid* pGride = pManager->GetGrid();
	if (!outfile.is_open())    //to check if the file is opened or not
	{
		pGride->PrintErrorMessage("Error: Could not open file ");
		return;
	}
	pGride->SaveAll(outfile, filename, Flags);
	pGride->SaveAll(outfile, filename, WaterPits);
	pGride->SaveAll(outfile, filename, DangerZones);
	pGride->SaveAll(outfile, filename, Belts);
	pGride->SaveAll(outfile, filename, Workshops);
	pGride->SaveAll(outfile, filename, Antennas);
	pGride->SaveAll(outfile, filename, RotatingGears);
	outfile.close();
	pGride->GetOutput()->PrintMessage("Grid Has Been Saved Successfully");
}
Save::~Save()
{
}