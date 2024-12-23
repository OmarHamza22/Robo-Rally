#include  "Selectcommand.h"
selectcommand::selectcommand(ApplicationManager* pApp, Output* x) : Action(pApp), pOut(x) {
	pGrid = pApp->GetGrid();
	current = pGrid->GetCurrentPlayer();

};
void  selectcommand::ReadActionParameters() {

};
void  selectcommand::Execute() {
	Command amgad[5];
	for (int i = 0; i < 5; i++) {
		amgad[i] = NO_COMMAND;
	}

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
	pGrid->GetOutput()->CreateCommandsBar(amgad, 5, randomcommands, size);
	current->SetHealth(10);
	Command* now = new Command[size];
	now = randomcommands;
	savedcommands = new Command[5];
	for (int i = 0; i < size; i++) {
		pGrid->GetOutput()->PrintMessage("select command");
		int z = pGrid->GetInput()->GetSelectedCommandIndex();
		savedcommands[i] = now[z];

	}
	pGrid->GetOutput()->CreateCommandsBar(savedcommands, 5, randomcommands, size);
	pGrid->setcommand(savedcommands, size);


};
void selectcommand::randomcommandss() {
	size = max(1, (pGrid->GetCurrentPlayer()->GetHealth()) / 2);  // Ensure size is at least 1
	randomcommands = new Command[size];
	srand(static_cast<unsigned>(time(nullptr)));

	for (int i = 0; i < size; i++) {
		randomcommands[i] = static_cast<Command>(std::rand() % (COMMANDS_COUNT));
	}

}