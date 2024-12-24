#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"
class shootingphase :public Action {
	Player* player0;
	Player* player1;
	Grid* pGrid;
public:
	shootingphase(ApplicationManager* pApp);
	void ReadActionParameters();
	void Execute();








};