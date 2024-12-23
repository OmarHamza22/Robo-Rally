#include "AddDangerzoneAction.h"

AddDangerzoneAction::AddDangerzoneAction(ApplicationManager* pApp) : Action(pApp)
{

}

void AddDangerzoneAction::ReadActionParameters()
{
	// Get a pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("New Work Shop: Click on its Cell ...");
	Dangerpos = pIn->GetCellClicked();

	if (!Dangerpos.IsValidCell()) {
		pOut->PrintMessage("Invalid cell! Click anywhere to continue.");
		pIn->GetCellClicked();
		return;
	}

	pOut->ClearStatusBar();
}

void AddDangerzoneAction::Execute()
{
	ReadActionParameters();

	DangerZone* pDanger = new DangerZone(Dangerpos);
	Grid* pGrid = pManager->GetGrid();
	bool added = pGrid->AddObjectToCell(pDanger);
	// if the GameObject cannot be added
	if (!added)
	{
		pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		;
		// Print an appropriate message
	}
}

AddDangerzoneAction::~AddDangerzoneAction()
{
}
