#pragma once
#include "Action.h" 
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Cell.h"
#include "Grid.h"
#include "Player.h"
#include "playmode.h"
#include <cstdlib>  
#include <ctime>
#include <cmath>
class selectcommand :public Action {
	ApplicationManager* pManager;
	Command* savedcommands;
	Grid* pGrid;
	Output* pOut;
	Player* current;
	Command* randomcommands;
	int size;
	Command x[9] = { NO_COMMAND,
	MOVE_FORWARD_ONE_STEP,
	MOVE_BACKWARD_ONE_STEP,
	MOVE_FORWARD_TWO_STEPS,
	MOVE_BACKWARD_TWO_STEPS,
	MOVE_FORWARD_THREE_STEPS,
	MOVE_BACKWARD_THREE_STEPS,
	ROTATE_CLOCKWISE,
	ROTATE_COUNTERCLOCKWISE, };
public:
	selectcommand(ApplicationManager* pApp, Output* x);
	void ReadActionParameters();

	void Execute();
	void randomcommandss();





};