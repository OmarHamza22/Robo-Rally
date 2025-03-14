#include "ApplicationManager.h"
#include"Load.h"
#include "Save.h"
#include "Copy.h"
#include "Cut.h"
#include "Paste.h"
#include"Delete.h"
#include "Grid.h"
#include "AddBeltAction.h"
#include "AddRotatingGearAction.h"
#include "AddFlagAction.h"
#include "Switchtoplay.h"
#include "switchtodesignmode.h"
#include "newgame.h"
#include "repotandrepair.h"
#include "playmode.h"
///TODO: Add #include for all action types
#include"AddWorkshopAction.h"
#include "AddWaterPit.h"
#include "AddAntennaAction.h"
#include "AddDangerzoneAction.h"
#include "AddRotatingGearAction.h"
#include "shotingphase.h"
ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
	turn = 0;
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_BELT:
		pAct = new AddBeltAction(this);
		break;

	case ADD_ROTATINGGEAR:
		// create an object of AddRotatingGearAction here
		pAct = new AddRotatingGearAction(this);
		break;
	case ADD_FLAG:
		// create an object of AddFlagAction here
		pAct = new AddFlagAction(this);
		break;
	case SET_ANTENNA:
		// create an object of AddAntennaAction here
		pAct = new AddAntennaAction(this);
		break;
	case COPY_GAME_OBJECT:
		pAct = new Copy(this);
		break;
	case CUT_GAME_OBJECT:
		pAct = new Cut(this);
		break;
	case PASTE_GAME_OBJECT:
		pAct = new Paste(this);
		break;
	case DELETE_GAME_OBJECT:
		pAct = new Delete(this);
		break;
	case SAVE_GRID:
		pAct = new Save(this);
		break;
	case OPEN_GRID:
		pAct = new Load(this);
		break;
	case EXIT:
		break;

	case TO_PLAY_MODE:					//TODO:
		pAct = new playmode(this, pOut); // temporary till you made its action class (CHANGE THIS LATTER)
		break;
	case EXECUTE_COMMANDS:
		turn++;
		pAct = new excute(this, pOut);
		break;
	

	case TO_DESIGN_MODE:				//TODO:
		pAct = new switchtodesignmode(this, pOut); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case NEW_GAME:
		turn = 0;
		pAct = new newgame(this, pOut);
		break;
	case REPOOT_AND_REPAIR:
		turn++;
		pAct = new repotandrepair(this, pOut);
		break;
	case SELECT_COMMAND:
		pAct = new selectcommand(this, pOut);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode
	case SET_WORKSHOP:
		pAct = new AddWorkshopAction(this);
		break;
	case SET_WATER_PIT:
		pAct = new AddWaterPit(this);
		break;
	case SET_DANGER_ZONE:
		pAct = new AddDangerzoneAction(this);
		break;
	case SET_ROTATING_GEAR_CLOCK:
		pAct = new AddRotatingGearAction(this);
		static_cast<AddRotatingGearAction*>(pAct)->SetClockwise(true);
		break;
	case SET_ROTATING_GEAR_ANTI_CLOCK:
		pAct = new AddRotatingGearAction(this);
		static_cast<AddRotatingGearAction*>(pAct)->SetClockwise(false);
		break;

	case STATUS:	// a click on the status bar ==> no action
		return;

	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
	if (turn / 2 == 1.00 && ActType != NEW_GAME)
	{
		turn = 0;
		Action* shootingAction = new shootingphase(this);
		shootingAction->Execute();
		delete shootingAction;
	}
}
