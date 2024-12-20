#include "Copy.h"
#include "Action.h"
#include "Grid.h"
#include "CellPosition.h"

void Copy::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Input* Pinp = pGride->GetInput();

	pGride->GetOutput()->PrintMessage("Click on Cell to Copy");
	copiedCELL = Pinp->GetCellClicked();

	if (!copiedCELL.IsValidCell())
	{
		pGride->PrintErrorMessage("Invalid Cell");
		return;
	}
}

void Copy::Execute()
{
	Grid* pGride = pManager->GetGrid();

	ReadActionParameters();
	if (!copiedCELL.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is Invalid");
		return;
	}

	GameObject* copiedOBJ = pGride->getGameobject(copiedCELL);
	
	if (copiedOBJ == nullptr)
	{
		pGride->PrintErrorMessage("The Cell doesnt contain any Object");
		return;
	}
	pGride->SetClipboard(copiedOBJ);
	pGride->GetOutput()->PrintMessage("Object copied successfully");

}

Copy::~Copy()
{
}
