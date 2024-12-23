#include "DangerZone.h"

#include "Player.h"


DangerZone::DangerZone(const CellPosition & dangerZonePosition): GameObject(dangerZonePosition)
{
}

void DangerZone::Draw(Output * pOut) const
{
	pOut->DrawDangerZone(position);
}

void DangerZone::Apply(Grid * pGrid, Player * pPlayer)
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// 1- Print a message to inform the player about the danger zone
	pGrid->GetOutput()->PrintMessage("You have reached a danger zone. Click to continue...");
	pGrid->GetInput()->GetCellClicked(); // Wait for user acknowledgment

	// 2- Reduce the health of the player by 1
	pPlayer->SetHealth(pPlayer->GetHealth() - 1);

	// 3- Update the player's information displayed on the grid
	pGrid->UpdateInterface();
}

void DangerZone::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile << position.GetCellNum() << endl;

}

void DangerZone::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int cellNum;
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}


DangerZone::~DangerZone()
{
}
