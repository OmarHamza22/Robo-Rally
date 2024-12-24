#include "AddFlagAction.h"



AddFlagAction::AddFlagAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}


void AddFlagAction::ReadActionParameters()
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Get a Pointer to the Input / Output Interfaces

	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// 2- Read the flagPos

	pOut->PrintMessage(" Click on the cell where you want to place the flag... ");
	flagPos = pIn->GetCellClicked();

	// 4- Make the needed validations on the read parameters

	if (!flagPos.IsValidCell()||flagPos.GetCellNum()==1)
	{
		pOut->PrintMessage("Invalid cell position! Operation cancelled.");
		flagPos = CellPosition(-1, -1); // Reset the position to invalid
		return;
	}

	// 5- Clear status bar
	pOut->ClearStatusBar();
}

void AddFlagAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1-Create a flag object

	Flag * pFlag = new Flag(flagPos);

	// 2-get a pointer to the Grid from the ApplicationManager

	   Grid* pGrid = pManager->GetGrid();

	// 3- check if there is a flag in the grid and if true print error massage 

         if (pGrid->HasFlag()) {
           pGrid->PrintErrorMessage("Error: A flag already exists on the grid! Cannot add another one.");
           return;
	}


	// 4-Add the flag object to the GameObject of its Cell:

	   bool added = pGrid->AddObjectToCell(pFlag);

	// 5-Check if the flag was added and print an errror message if flag couldn't be added

	   if (!added)
	   {
		   // Print an appropriate message
		   pGrid->PrintErrorMessage("Error: Cell already has an object ! Click to continue ...");
		   return;
	   }
}

AddFlagAction::~AddFlagAction()
{
}