#include "excute.h"

excute::excute(ApplicationManager* pApp, Output* x) : Action(pApp), pOut(x) {
    current = pApp->GetGrid()->GetCurrentPlayer();
    currentplayer = pApp->GetGrid();
}

void excute::Execute() {
    Command* x = currentplayer->getcommands();
    current->ClearDrawing(pOut);
    current->Move(currentplayer, x);
    currentplayer->AdvanceCurrentPlayer();
}

void excute::ReadActionParameters() {


}