#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"
class excute :public Action {
	ApplicationManager* pManager;
	Player* current;
	Command* x;
	Grid* currentplayer;
public:
	excute(ApplicationManager* pApp, Output* x);

	Input* pIn;
	Output* pOut;

	void ReadActionParameters(Command moveCommands[]);
	void Execute();
	void ReadActionParameters();

};
