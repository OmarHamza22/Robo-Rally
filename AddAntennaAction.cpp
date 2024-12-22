#include "AddAntennaAction.h"



AddAntennaAction::AddAntennaAction(ApplicationManager* pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddAntennaAction::ReadActionParameters()
{

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the Antenna Position

	pOut->PrintMessage(" Click on the cell where you want to place the Antenna... ");
	AntennaPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters

	if (!AntennaPos.IsValidCell() || AntennaPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Invalid cell position! Operation cancelled.");
		AntennaPos = CellPosition(-1, -1); // Reset the position to invalid
		return;
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddAntennaAction::Execute()
{
	//1-  initializes its data members :

	ReadActionParameters();

	// 2- Create a Antenna object :

	Antenna* pAntenna = new Antenna(AntennaPos);

	// 2-get a pointer to the Grid from the ApplicationManager

	Grid* pGrid = pManager->GetGrid();

	// 3- check if there is a Antenna in the grid and if true print error massage 

	if (pGrid->HasAntenna()) {
		pGrid->PrintErrorMessage("Error: A Antenna already exists on the grid! Cannot add another one.");
		return;
	}

	// 3-Add the Antenna object to the GameObject of its Cell:

	bool added = pGrid->AddObjectToCell(pAntenna);

	// 4-Check if the Antenna was added and print an errror message if Antenna couldn't be added

	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		return;
	}
	
	pGrid->UpdateInterface();

}

AddAntennaAction::~AddAntennaAction()
{
}