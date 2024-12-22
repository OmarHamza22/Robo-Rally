#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "excute.h"
class playmode : public Action {
private:

	Player* ptrp1;
	Player* ptrp2;
	ApplicationManager* pManager;
	Cell* pCell1;
	Cell* pCell2;
	Output* pOut;
	Input* pIn;
public:
	playmode(ApplicationManager* pApp, Output* x);

	void ReadActionParameters();

	void Execute();

};