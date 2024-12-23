#include "Workshop.h"
#include"Player.h"

Workshop::Workshop(const CellPosition & workshopPosition):GameObject( workshopPosition)
{

}


void Workshop::Draw(Output * pOut) const
{
	pOut->DrawWorkshop(position);
}

void Workshop::Apply(Grid * pGrid, Player * pPlayer)
{
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    // 1- Repair the player's health to full
    pPlayer->SetHealth(10); // Assuming full health is 100
    pOut->PrintMessage("Your robot is repaired to full health! Click to continue...");
    pIn->GetCellClicked(); // Wait for user acknowledgment

    // 2- Provide options to buy one tool only
    pOut->PrintMessage("Choose an item to buy: 1. Toolkit (-2 health) or 2. Hack Device (-2 health). Click to continue...");
    pIn->GetCellClicked();

    int choice;
    do {
        pOut->PrintMessage("Enter your choice (1 or 2): Toolkit (1) or Hack Device (2). Click to confirm...");
        choice = pIn->GetInteger(pOut);
    } while (choice != 1 && choice != 2);

    // 3- Deduct health and provide the chosen item
    if (choice == 1) {
        pPlayer->SetHealth(pPlayer->GetHealth() - 2);
        pPlayer->SetHasToolkit(true); // Assuming Player has a boolean for toolkit
        pOut->PrintMessage("You bought a Toolkit. Click to continue...");
    }
    else if (choice == 2) {
        pPlayer->SetHealth(pPlayer->GetHealth() - 2);
        pPlayer->SetHasHackDevice(true); // Assuming Player has a boolean for hack device
        pOut->PrintMessage("You bought a Hack Device. Click to continue...");
    }
    else {
        pOut->PrintMessage("You don't have enough health to buy any item. Click to continue...");
    }

    pIn->GetCellClicked(); // Wait for user acknowledgment

}

void Workshop::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile <<position.GetCellNum()<<endl;

}

void Workshop::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int cellNum;
	Infile >> cellNum;
	position = CellPosition::GetCellPositionFromNum(cellNum);
}



Workshop::~Workshop()
{
}
