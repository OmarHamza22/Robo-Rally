#include "newgame.h"

newgame::newgame(ApplicationManager* pApp, Output* x) :Action(pApp), pOut(x) {};

void newgame::Execute() {
	pOut->ClearGridArea();
	pOut->CreateDesignModeToolBar();

}
void newgame::ReadActionParameters() {}