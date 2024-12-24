#include "excute.h"

excute::excute(ApplicationManager* pApp, Output* x) : Action(pApp), pOut(x) {
    current = pApp->GetGrid()->GetCurrentPlayer();
    currentplayer = pApp->GetGrid();
}

void excute::Execute() {
    int z, y;
    Command* x = currentplayer->getcommands();
    current->ClearDrawing(pOut);
    currentplayer->GetOutput()->PrintMessage("your commands are being executed , click anywhere");
    currentplayer->GetInput()->GetPointClicked(z, y);
    current->Move(currentplayer, x);
    currentplayer->AdvanceCurrentPlayer();
}

void excute::ReadActionParameters() {


}