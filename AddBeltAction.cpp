#include "AddBeltAction.h"

AddBeltAction::AddBeltAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddBeltAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// Read the startPos parameter
	pOut->PrintMessage("New Belt: Click on its Start Cell ...");
	startPos = pIn->GetCellClicked();

	// Read the endPos parameter
	pOut->PrintMessage("New Belt: Click on its End Cell ...");
	endPos = pIn->GetCellClicked();



	///TODO: Make the needed validations on the read parameters 

	if (!startPos.IsValidCell()&& !endPos.IsValidCell() || startPos.GetCellNum() == 1)
	{
		pOut->PrintMessage("Invalid cell position! Operation cancelled.");
		return;
	}

	// Clear messages
	pOut->ClearStatusBar();
}

void AddBeltAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();

	// Create a belt object with the parameters read from the user
	Belt * pBelt = new Belt(startPos, endPos);

	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager

	// Check for overlaps and conflicts

	 if (pGrid->getGameobject(startPos) || pGrid->getGameobject(endPos)) {
		pGrid->PrintErrorMessage("Error: Cells already has object! Operation cancelled.");
		return;
	}

	if (pGrid->Beltsconflicts(startPos, endPos)) {

		pGrid->PrintErrorMessage("Error: Belt will conflicts with existing belts! Operation cancelled.");
		return;
	}
	
										
	bool added = pGrid->AddObjectToCell(pBelt);

	// if the GameObject cannot be added
	if (!added)
	{
		// Print an appropriate message
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
	}
	// Here, the belt is created and added to the GameObject of its Cell, so we finished executing the AddBeltAction

	pGrid->UpdateInterface();
}

AddBeltAction::~AddBeltAction()
{
}
