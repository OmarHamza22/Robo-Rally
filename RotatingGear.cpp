#include "RotatingGear.h"

#include "Player.h"


RotatingGear::RotatingGear(const CellPosition & gearposition,bool clockwise) : GameObject(gearposition)
{
	isClockWise = clockwise;
}

void RotatingGear::Draw(Output* pOut) const
{
	pOut->DrawRotatingGear(position, isClockWise);
}

void RotatingGear::Apply(Grid* pGrid, Player* pPlayer)
{

	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message and change the message according to direction of rotation "You have reached a rotating gear, you will rotate (clockwise/ anti-clockwise) Click to continue ..." and wait mouse click
	if (isClockWise) {
		pGrid->GetOutput()->PrintMessage("You have reached a rotating gear. Rotating clockwise. Click to continue...");
	}
	else {
		pGrid->GetOutput()->PrintMessage("You have reached a rotating gear. Rotating anti-clockwise. Click to continue...");
	}
	pGrid->GetInput()->GetCellClicked(); // Wait for user acknowledgment
	//2- Apply the roating gear's effect by rotating the player according to the direction
	Direction currDirection = pPlayer->GetCurrentDirection();
	Direction newDirection;

	switch (currDirection) {
	case RIGHT:
		newDirection = isClockWise ? DOWN : UP;
		break;
	case LEFT:
		newDirection = isClockWise ? UP : DOWN;
		break;
	case UP:
		newDirection = isClockWise ? RIGHT : LEFT;
		break;
	case DOWN:
		newDirection = isClockWise ? LEFT : RIGHT;
		break;
	}
	pPlayer->SetDirection(newDirection); // Update the player's direction

}
bool RotatingGear::GetisClockWise() const
{
	return isClockWise;
}

void RotatingGear::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile << position.GetCellNum() << " " << isClockWise << endl;

}

void RotatingGear::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int cellNum, dierc;
	Infile >> cellNum >> dierc;
	position = CellPosition::GetCellPositionFromNum(cellNum);
	isClockWise = dierc;
}

RotatingGear::~RotatingGear()
{
}
