#include "Paste.h"
#include "Action.h"
#include "Grid.h"
#include "CellPosition.h"
#include "Flag.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "RotatingGear.h"
#include "Workshop.h"
#include "Antenna.h"
#include "Belt.h"

void Paste::ReadActionParameters()
{
	Grid* pGride = pManager->GetGrid();
	Input* pInp = pGride->GetInput();

	pGride->GetOutput()->PrintMessage("Click on Cell to Paste");
	pastecell = pInp->GetCellClicked();

	if (!pastecell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is Invalid");
		return;
	}
}

void Paste::Execute()
{
	Grid* pGride = pManager->GetGrid();
	ReadActionParameters();

	if (!pastecell.IsValidCell())
	{
		pGride->PrintErrorMessage("The Cell is Invalid");
		return;
	}

	if (pGride->GetClipboard() == nullptr)
	{
		pGride->PrintErrorMessage("Error: No object copied");
		return;
	}

	else 
	{
		GameObject* pasteOBJ = pGride->GetClipboard();
		//Flag
		if (dynamic_cast<Flag*>(pasteOBJ))
		{
			Flag* newFlag = new Flag(pastecell);
			bool added = pGride->AddObjectToCell(newFlag);
			if (!added)
			{
				delete newFlag;
				pGride->PrintErrorMessage("Cell has an object already");
			}
			else
			{
				pGride->GetOutput()->PrintMessage("Flag pasted successfully");
			}
		}
		//Water Pit
		else if (dynamic_cast<WaterPit*>(pasteOBJ))
		{
			WaterPit* newWaterPit = new WaterPit(pastecell);
			bool added = pGride->AddObjectToCell(newWaterPit);
			if (!added)
			{
				delete newWaterPit;
				pGride->PrintErrorMessage("Cell has an object already");
			}
			else
			{
				pGride->GetOutput()->PrintMessage("Water Pit pasted successfully");
			}
		}
		//Workshop
		else if (dynamic_cast<Workshop*>(pasteOBJ))
		{
			Workshop* newWorkshop = new Workshop(pastecell);
			bool added = pGride->AddObjectToCell(newWorkshop);
			if (!added)
			{
				delete newWorkshop;
				pGride->PrintErrorMessage("Cell has an object already");
			}
			else
			{
				pGride->GetOutput()->PrintMessage("Workshop pasted successfully");
			}
		}

		//Antenna
		else if (dynamic_cast<Antenna*>(pasteOBJ))
		{
			Antenna* newAntenna = new Antenna(pastecell);
			bool added = pGride->AddObjectToCell(newAntenna);
			if (!added)
			{
				delete newAntenna;
				pGride->PrintErrorMessage("Cell has an object already");
			}
			else
			{
				pGride->GetOutput()->PrintMessage("Antenna pasted successfully");
			}
		}
		//DangerZone
		else if (dynamic_cast<DangerZone*>(pasteOBJ))
		{
			DangerZone* newDangerZone = new DangerZone(pastecell);
			bool added = pGride->AddObjectToCell(newDangerZone);
			if (!added)
			{
				delete newDangerZone;
				pGride->PrintErrorMessage("Cell has an object already");
			}
			else
			{
				pGride->GetOutput()->PrintMessage("Danger Zone pasted successfully");
			}
		}
		//RotatingGear Clock wise
		else if (dynamic_cast<RotatingGear*>(pasteOBJ))
		{
			RotatingGear* copiedGear = dynamic_cast<RotatingGear*>(pasteOBJ);

			if (copiedGear)
			{

				bool isClockWise = copiedGear->GetisClockWise();

				RotatingGear* newRotatingGear = new RotatingGear(pastecell, isClockWise);
				bool added = pGride->AddObjectToCell(newRotatingGear);
				if (!added)
				{
					delete newRotatingGear;
					pGride->PrintErrorMessage("Cell has an object already");
				}
				else
				{
					pGride->GetOutput()->PrintMessage("Rotating Gear pasted successfully");
				}
			}
		}
		//#####BELT
		else if (dynamic_cast<Belt*>(pasteOBJ))
		{
			Belt* beltobj = dynamic_cast<Belt*>(pasteOBJ);

			if (beltobj)
			{
				CellPosition copiedStart = beltobj->GetPosition();
				CellPosition copiedEnd = beltobj->GetEndPosition();
				CellPosition pasteStart = pastecell;

				CellPosition pasteEnd((pastecell.VCell() + (copiedEnd.VCell() - copiedStart.VCell())), (pastecell.HCell() + (copiedEnd.HCell() - copiedStart.HCell())));

				
				Belt* newBelt = new Belt(pasteStart, pasteEnd);
				
				bool added = pGride->AddObjectToCell(newBelt);
				if (!added)
				{
					delete newBelt;
					pGride->PrintErrorMessage("Error:Cell already has an object!");
				}
				else
				{
					pGride->GetOutput()->PrintMessage("Belt pasted successfully!");
				}
			}
			else
			{
				pGride->PrintErrorMessage("Error: Failed");
			}
		}
		else
		{
			pGride->PrintErrorMessage("Object unknown");
		}
	}
}
	
Paste::~Paste()
{
}
