#include "playmode.h"
playmode::playmode(ApplicationManager* pApp, Output* x) :Action(pApp), pOut(x) {
	pCell1 = new Cell(CellPosition(1));
	pCell2 = new Cell(CellPosition(1));
	ptrp1 = new Player(pCell1, 1);
	ptrp2 = new Player(pCell2, 2);
};
void playmode::ReadActionParameters() {};
void playmode::Execute() {
	pOut->CreatePlayModeToolBar();
  //  pOut->DrawPlayer(pCell1->GetCellPosition(), 0, RED, RIGHT);
	//ptrp1->Draw(pOut);
	//ptrp2->Draw(pOut);
//	pOut->DrawPlayer(pCell2->GetCellPosition(), 1, BLACK, RIGHT); 
	pOut->PrintMessage("You are now in play mode ");


};