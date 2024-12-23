#include "AddRotatingGearAction.h"

AddRotatingGearAction::AddRotatingGearAction(ApplicationManager * pApp):Action(pApp)
{
}

void AddRotatingGearAction::ReadActionParameters()
{
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("Click on the cell to place the rotating gear...");
	gearPos = pIn->GetCellClicked();

	if (!gearPos.IsValidCell()) {
		pOut->PrintMessage("Invalid cell! Click anywhere to continue.");
		pIn->GetCellClicked();
		return;
	}

	pOut->ClearStatusBar();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	// 2- Read the gearPos
	// 3- Read whether the direction will be clockwise or not

	// 4- Make the needed validations on the read parameters

	// 5- Clear status bar
}

void AddRotatingGearAction::Execute()
{
	ReadActionParameters();

	RotatingGear* pGear = new RotatingGear(gearPos, clockwise);
	Grid* pGrid = pManager->GetGrid();
	bool added = pGrid->AddObjectToCell(pGear);

	if (!added) {
		delete pGear;
		pGrid->PrintErrorMessage("Error: Cell already has an object! Click to continue...");
	}
}

AddRotatingGearAction::~AddRotatingGearAction()
{
}
