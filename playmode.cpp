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
	string CommandItemImages[COMMANDS_COUNT];
	CommandItemImages[NO_COMMAND] = "images\\CommandSlot-grey.jpg";
	CommandItemImages[MOVE_FORWARD_ONE_STEP] = "images\\MoveForwardCard.jpg";
	CommandItemImages[MOVE_BACKWARD_ONE_STEP] = "images\\MoveBackwardCard.jpg";

	// TODO: Prepare images for more items with .jpg extensions and add them to the list 

	CommandItemImages[MOVE_FORWARD_TWO_STEPS] = "images\\MoveForward_2S_Card.jpg";
	CommandItemImages[MOVE_BACKWARD_TWO_STEPS] = "images\\MoveBackward_2S_Card.jpg";
	CommandItemImages[MOVE_FORWARD_THREE_STEPS] = "images\\MoveForward_3S_Card.jpg";
	CommandItemImages[MOVE_BACKWARD_THREE_STEPS] = "images\\MoveC_ClockwiseCard.jpg";

	CommandItemImages[ROTATE_CLOCKWISE] = "images\\MoveClockwiseCard.jpg";
	CommandItemImages[ROTATE_COUNTERCLOCKWISE] = "images\\MoveC_ClockwiseCard.jpg";


	randomcommandss();
	pGrid->GetOutput()->CreateCommandsBar(x, 9, randomcommands, size);
	


};
void playmode::randomcommandss() { 
	size = max(1, (pGrid->GetCurrentPlayer()->GetHealth()) / 2);  // Ensure size is at least 1
	randomcommands = new Command[size];
	srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 0; i < size; i++) {
		randomcommands[i] = static_cast<Command>(std::rand() % (COMMANDS_COUNT));
	}

}