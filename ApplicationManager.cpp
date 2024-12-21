#include "ApplicationManager.h"
#include"Save.h"
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
#include <iostream>
///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
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

	case EXIT:
		break;

	case TO_PLAY_MODE:					//TODO:
		pAct = new switchtoplaymode(this ,pOut); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	

	case TO_DESIGN_MODE:				//TODO:
		pAct = new switchtodesignmode(this, pOut); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case NEW_GAME :
		pAct = new newgame(this, pOut);
		break;
	case REPOOT_AND_REPAIR :
		pAct = new repotandrepair(this, pOut);
		break;
		///TODO: Add a case for EACH Action type in the Design mode or Play mode



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
}
