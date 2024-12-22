#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
	
	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======

void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetHealth(int h)
{
	this->health = h;
	///TODO: Do any needed validations
}

int Player::GetHealth()
{
	return this->health;
}

// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{

	color playerColor = UI.PlayerColors[playerNum];
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, playerColor, currDirection);
	
 
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	pOut->DrawPlayer(pCell->GetCellPosition(), playerNum, cellColor, currDirection);
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, Command moveCommands[])
{
	int x = 0;
	int y = 0;
	Output* pOut;
	Input* pIn;
	Player* current = pGrid->GetCurrentPlayer();
	Cell* known = current->GetCell();
	CellPosition place = known->GetCellPosition();
	for (int i = 0; i < sizeof(moveCommands) - 1;i++) {
		switch (moveCommands[i]) {
		case NO_COMMAND:
			break;
		case MOVE_FORWARD_ONE_STEP:
			place.AddCellNum(1, current->currDirection);
			break;
		case MOVE_BACKWARD_ONE_STEP:
			place.AddCellNum(-1, current->currDirection);
			break;
		case MOVE_FORWARD_TWO_STEPS:
			place.AddCellNum(2, current->currDirection);
			break;
		case MOVE_BACKWARD_TWO_STEPS:
			place.AddCellNum(-2, current->currDirection);
			break;
		case MOVE_FORWARD_THREE_STEPS:
			place.AddCellNum(3, current->currDirection);
			break;
		case MOVE_BACKWARD_THREE_STEPS:
			place.AddCellNum(-3, current->currDirection);
			break;
		case ROTATE_CLOCKWISE:
			if (current->currDirection == 0) {
				current->currDirection = DOWN;
			}
			else {
				current->currDirection - 1;

			}
			break;
		case ROTATE_COUNTERCLOCKWISE:
			if (current->currDirection == 3) {
				current->currDirection = RIGHT;

			}
			else {
				current->currDirection + 1;
			}

		default:
			break;

			//the rotating is still notdone 
		}

		pGrid->UpdatePlayerCell(current, place);
		pOut->PrintMessage("click anywhere to excute next command");
		pIn->GetPointClicked(x, y);



	}
	///TODO: Implement this function using the guidelines mentioned below
	if (current->GetCell()->GetGameObject() != nullptr) {
		current->GetCell()->GetGameObject()->Apply(pGrid, current);

	}
	if (pGrid->GetEndGame()) {
		pOut->PrintMessage("Game finished ,click anywhere ");
		pIn->GetPointClicked(x, y);
		return;
	}

	///TODO: Implement this function using the guidelines mentioned below

	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
	//		be applied.
	// 
	// - Use the CellPosition class to help you calculate the destination cell using the current cell
	// - Use the Grid class to update pCell
	// - Don't forget to apply game objects at the final destination cell and check for game ending

}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += to_string(health) + ")";

}
int Player::getplayernum() {
	return playerNum;
}