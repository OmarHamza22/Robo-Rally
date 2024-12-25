#include "Cut.h"
#include "Action.h"
#include "Grid.h"
#include "CellPosition.h"

void Cut::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Input* pInp = pGride->GetInput();
	
	pGride->GetOutput()->PrintMessage("Click on Cell to Cut");
	cutcell = pInp->GetCellClicked();

	if (!cutcell.IsValidCell()) //checks if the cell is valid
	{
		pGride->PrintErrorMessage("The Cell is Inavled");
		return;
	}

}

void Cut::Execute()
{
	Grid* pGride = pManager->GetGrid();
	ReadActionParameters();

	if (!cutcell.IsValidCell()) //checks if the cell is valid
	{
		pGride->PrintErrorMessage("The Cell is Inavled");
		return;
	}

	GameObject* cutOBJ = pGride->getGameobject(cutcell);
	if (cutOBJ == __nullptr) //checks if the cell contains any object
	{
		pGride->PrintErrorMessage("The Cell does not contain any objects");
		return;
	}
	pGride->SetClipboard(cutOBJ); //sets the clipboard
	pGride->RemoveObjectFromCell(cutcell); //delete the object from the cell
	pGride->GetOutput()->PrintMessage("Object cutted successfully");
}

Cut::~Cut()
{
}
