#include "playmode.h"
playmode::playmode(ApplicationManager* pApp, Output* x) :Action(pApp), pOut(x) {
	pCell1 = new Cell(CellPosition(1));
	pCell2 = new Cell(CellPosition(1));
	ptrp1 = new Player(pCell1, 1);
	ptrp2 = new Player(pCell2, 2);
	distance = pCell1->HasAntenna();
	pGrid = pApp->GetGrid();
	test = ptrp1->GetCell()->GetCellPosition();

};
void playmode::ReadActionParameters() {};
void playmode::Execute() {
	pOut->CreatePlayModeToolBar();
	pOut->PrintMessage("You are now in play mode ");



};