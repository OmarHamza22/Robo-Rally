#include "WaterPit.h"
#include"Player.h" 


WaterPit::WaterPit(const CellPosition & waterPitPosition):GameObject(waterPitPosition)
{
}

void WaterPit::Draw(Output * pOut) const
{
	pOut->DrawWaterPit(position);
}

void WaterPit::Apply(Grid * pGrid, Player * pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message informing the player about drowning
	pGrid->GetOutput()->PrintMessage("You drowned in a water pit. Player loses All health points. Click to continue...");
	pGrid->GetInput()->GetCellClicked(); // Wait for user acknowledgment

	// 2- Reduce the player's health by 10
	pPlayer->SetHealth(pPlayer->GetHealth() - 10);

	// 3- Update the interface to reflect changes
	pGrid->UpdateInterface();
}

void WaterPit::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile << position.GetCellNum() << endl;

}

void WaterPit::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int cellNum;
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}


WaterPit::~WaterPit()
{
}
