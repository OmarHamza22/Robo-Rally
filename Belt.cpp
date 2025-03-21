#include "Belt.h"


Belt::Belt(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;

	///TODO: Do the needed validation
}
void Belt::Draw(Output* pOut) const
{
	pOut->DrawBelt(position, endCellPos);
}

void Belt::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a belt. Click to continue ..." and wait mouse click

	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	pOut->PrintMessage("You have reached a belt. Click to continue ...");
	int x, y;
	pIn->GetPointClicked(x, y);

	// 2- Apply the belt's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer , endCellPos);
	
	pGrid->UpdateInterface();
}
CellPosition Belt::GetEndPosition() const
{
	return endCellPos;
}

void Belt::Save(ofstream& OutFile, string file)
{
	if (!OutFile.is_open())
		OutFile.open(file, ios::out);

	OutFile << position.GetCellNum() << " " << endCellPos.GetCellNum() << endl;
}

void Belt::Load(ifstream& Infile, string file)
{
	if (!Infile.is_open())
		Infile.open(file, ios::in);

	int EndcellNum,StartcellNum;
	Infile >> StartcellNum>>EndcellNum;
	position = CellPosition::GetCellPositionFromNum(StartcellNum);
	endCellPos = CellPosition::GetCellPositionFromNum(EndcellNum);
}


Belt::~Belt()
{
}
