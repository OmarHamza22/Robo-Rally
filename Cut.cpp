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

	if (!cutcell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is Inavled");
		return;
	}

}

void Cut::Execute()
{
	Grid* pGride = pManager->GetGrid();
	ReadActionParameters();

	if (!cutcell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is Inavled");
		return;
	}

	GameObject* cutOBJ = pGride->getGameobject(cutcell);
	if (cutOBJ == __nullptr)
	{
		pGride->PrintErrorMessage("The Cell does not contain any objects");
		return;
	}
	pGride->SetClipboard(cutOBJ);
	pGride->RemoveObjectFromCell(cutcell);
	pGride->GetOutput()->PrintMessage("Object cutted successfully");
}

Cut::~Cut()
{
}
