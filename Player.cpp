#include "Player.h"

#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), health(10), playerNum(playerNum), currDirection(RIGHT)
{
	this->pCell = pCell;
    hasToolkit = false;
    hasHackDevice = false;
	
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
Direction Player::GetCurrentDirection() {
    return currDirection;
}

void Player::SetDirection(Direction direction)
{
	currDirection = direction;
}

// ====== Game Functions ======

void Player::Move(Grid* pGrid, Command moveCommands[])
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
			ClearDrawing(pGrid->GetOutput());
			currDirection = (Direction)((currDirection + 1) % 4);
			break;
		case ROTATE_COUNTERCLOCKWISE:
			ClearDrawing(pGrid->GetOutput());
			currDirection = (Direction)((currDirection + 3) % 4);
			break;
		default:
			break;
		
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
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
	playersInfo += "Player H"+ to_string(health) + ")";

}
int Player::getplayernum() {
	return playerNum;
}