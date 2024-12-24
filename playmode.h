#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "excute.h"
#include "Antenna.h"
#include "Grid.h"
#include "CellPosition.h"
#include <cstdlib>  
#include <ctime>
#include <cmath>
class playmode : public Action {
private:

	Player* ptrp1;
	Player* ptrp2;
	ApplicationManager* pManager;
	Cell* pCell1;
	Cell* pCell2;
	Output* pOut;
	Input* pIn;
	Antenna* distance;
	Grid* pGrid;
	CellPosition test;
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
	playmode(ApplicationManager* pApp, Output* x);

	void ReadActionParameters();

	void Execute();


};