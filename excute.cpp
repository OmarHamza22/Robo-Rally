#include "excute.h"
excute::excute(ApplicationManager* pApp, Output* x) :Action(pApp), pOut(x) {
	current = pApp->GetGrid()->GetCurrentPlayer();
	currentplayer = pApp->GetGrid();

};
void excute::Execute() {
	current->Move(currentplayer, x);


}
void excute::ReadActionParameters(Command moveCommands[]) {
	x = moveCommands;

}
void excute::ReadActionParameters() {};