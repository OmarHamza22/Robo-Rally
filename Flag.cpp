#include "Flag.h"
#include"Output.h"

Flag::Flag(const CellPosition& flagposition) : GameObject(flagposition)
{

}

void Flag::Draw(Output* pOut) const
{
		pOut->DrawFlag(position);	
}

void Flag::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a flag. Click to continue ..." and wait mouse click
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a flag. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);


	// 2- Apply the flag's effect by ending the game
	//    <Review the "pGrid" functions and decide which function can be used for that
	pGrid->SetEndGame(true);

	pGrid->UpdateInterface();
}

void Flag::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile << position.GetCellNum() << endl;

}

void Flag::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int cellNum;
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}

Flag::~Flag()
{	
}
