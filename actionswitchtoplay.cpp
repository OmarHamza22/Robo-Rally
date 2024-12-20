#include "actionswitchtoplay.h" 



 switchtoplaymode::switchtoplaymode(ApplicationManager* pApp, Output* x):Action(pApp), pOut(x) {};

 
 
 void switchtoplaymode::ReadActionParameters() {
}
  
 void switchtoplaymode::Execute() {
	pOut->CreatePlayModeToolBar();
	pOut->PrintMessage("You are now in game mode");
	pOut->PrintPlayersInfo("");
}