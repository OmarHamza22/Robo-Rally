#include "AddWorkshopAction.h"

AddWorkshopAction::AddWorkshopAction(ApplicationManager * pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}
void AddWorkshopAction::ReadActionParameters()
{
	// Get a pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Work Shop: Click on its Cell ...");
	Workshippos = pIn->GetCellClicked();

	if (!Workshippos.IsValidCell()) {
		pOut->PrintMessage("Invalid cell! Click anywhere to continue.");
		pIn->GetCellClicked();
		return;
	}

	pOut->ClearStatusBar();

}

void AddWorkshopAction::Execute()
{
	ReadActionParameters();

	Workshop* pWorkshop = new Workshop(Workshippos);
	Grid* pGrid = pManager->GetGrid();
	bool added = pGrid->AddObjectToCell(pWorkshop);
	// if the GameObject cannot be added
	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		;
		// Print an appropriate message
	}

}

AddWorkshopAction::~AddWorkshopAction()
{
}