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


	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const
{
	///TODO: Modify the cellColor to draw the correct cellColor (hint: if cell contains non-default cellColor)
	color cellColor = UI.CellColor;
	
	
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

//void Player::Move(Grid * pGrid, Command moveCommands[])
//{
//
//	///TODO: Implement this function using the guidelines mentioned below
//
//	// - If a player has 5 (could have less) saved moveCommands, the robot will execute the first saved command,
//	//		then wait for a mouse click (display a message "Click anywhere to execute the next command").
//	//		After executing all the 5 saved commands, the game object effect at the final destination cell will
//	//		be applied.
//	// 
//	// - Use the CellPosition class to help you calculate the destination cell using the current cell
//	// - Use the Grid class to update pCell
//	// - Don't forget to apply game objects at the final destination cell and check for game ending
//
//}
void Player::Move(Grid* pGrid, Command moveCommands[])
{
    CellPosition currentPosition = pCell->GetCellPosition();

    for (int i = 0; i < 5; ++i) // Assume 5 commands
    {
        if (moveCommands[i] == NO_COMMAND) break;

        CellPosition newPosition = currentPosition;
        switch (moveCommands[i]) {
        case MOVE_FORWARD_ONE_STEP:
            newPosition.AddCellNum(1, currDirection);
            break;
        case MOVE_BACKWARD_ONE_STEP:
            newPosition.AddCellNum(-1, currDirection);
            break;
        case ROTATE_CLOCKWISE:
            currDirection = (Direction)((currDirection + 1) % 4);
            break;
        case ROTATE_COUNTERCLOCKWISE:
            currDirection = (Direction)((currDirection + 3) % 4);
            break;
        default:
            break;
        }

        if (newPosition.IsValidCell()) {
            pGrid->UpdatePlayerCell(this, newPosition);
            currentPosition = newPosition;
        }

        pGrid->PrintErrorMessage("Click anywhere to execute the next command.");
        int x, y;
        pGrid->GetInput()->GetPointClicked(x, y);
    }

    // Apply game object effect
    GameObject* pGameObject = pGrid->getGameobject(currentPosition);
    if (pGameObject) {
        pGameObject->Apply(pGrid, this);
    }

    // Check for game ending conditions
    if (health <= 0 || pGrid->GetEndGame()) {
        pGrid->SetEndGame(true);
    }
}



void Player::AppendPlayerInfo(string & playersInfo) const
{
	// TODO: Modify the Info as needed
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(currDirection) + ", ";
    playersInfo += "HP: " + to_string(health) + ")";
}
