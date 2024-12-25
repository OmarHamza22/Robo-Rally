#include "Copy.h"
#include "Action.h"
#include "Grid.h"
#include "CellPosition.h"
#include "Flag.h"
#include "Antenna.h"

void Copy::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Input* Pinp = pGride->GetInput();

	pGride->GetOutput()->PrintMessage("Click on Cell to Copy");
	copiedCELL = Pinp->GetCellClicked();

	if (!copiedCELL.IsValidCell()) //checks if the cell is valid
	{
		pGride->PrintErrorMessage("Invalid Cell");
		return;
	}
}

void Copy::Execute()
{
	Grid* pGride = pManager->GetGrid();

	ReadActionParameters(); 
	if (!copiedCELL.IsValidCell()) //checks if the cell is valid
	{
		pGride->PrintErrorMessage("The Cell is Invalid");
		return;
	}

	GameObject* copiedOBJ = pGride->getGameobject(copiedCELL);
	
	if (copiedOBJ == nullptr) //checks if the cell contains any object
	{
		pGride->PrintErrorMessage("The Cell doesnt contain any Object");
		return;
	}

	if (dynamic_cast<Flag*>(copiedOBJ) != nullptr) //if it's a flag reject to copy
	{
		pGride->PrintErrorMessage("Error: The Cell contains a Flag object, copying is not allowed.");
		return;
	}

	if (dynamic_cast<Antenna*>(copiedOBJ) != nullptr) //if it's a flag reject to copy
	{
		pGride->PrintErrorMessage("Error: The Cell contains an Antenna object, copying is not allowed.");
		return;
	}

	pGride->SetClipboard(copiedOBJ); //setting clipboard
	pGride->GetOutput()->PrintMessage("Object copied successfully");


}


Copy::~Copy()
{
}
