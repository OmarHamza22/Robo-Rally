#include "Delete.h"
#include "Action.h"
#include "Grid.h"
#include "CellPosition.h"

void Delete::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Input* pInput = pGride->GetInput();

	pGride->GetOutput()->PrintMessage("Click on Cell to Delete");
	deletedcell = pInput->GetCellClicked();

	if (!deletedcell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is invalid");
		return;
	}
	
}

void Delete::Execute()
{
	Grid* pGride = pManager->GetGrid();
	ReadActionParameters();

	if (!deletedcell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is invalid");
		return;
	}
	
	if (pGride->RemoveObjectFromCell(deletedcell))
	{
		pGride->GetOutput()->PrintMessage("The Object deleted successfully");
	}
	else
	{
		pGride->PrintErrorMessage("The Object deleted Failed");
	}
}

Delete::~Delete()
{
}
