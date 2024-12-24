#include "Grid.h"
#include <iomanip>
#include"CellPosition.h"
#include "Cell.h"
#include "GameObject.h"
#include "Belt.h"
#include "Player.h"
#include "Flag.h"
#include "Action.h"
#include "WaterPit.h"
#include "DangerZone.h"
#include "RotatingGear.h"
#include "Workshop.h"
#include "Antenna.h"
#include "fstream"
#include "iostream"


Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition();
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	return false; // if not a valid position
}


// Note: You may need to change the return type of this function (Think)
bool Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed

		CellList[pos.VCell()][pos.HCell()]->SetGameObject(NULL);
		return true;
	}
	else
	{
		return false;
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's triangle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's triangle on the new cell position
	player->Draw(pOut);
}
bool Grid::HasFlag() const {
	for (int i = 0; i < NumVerticalCells; ++i) {
		for (int j = 0; j < NumHorizontalCells; ++j) {
			if (dynamic_cast<Flag*>(CellList[i][j]->GetGameObject())) {
				return true;
			}
		}
	}
	return false;
}

bool Grid::HasAntenna() const
{
	for (int i = 0; i < NumVerticalCells; ++i) {
		for (int j = 0; j < NumHorizontalCells; ++j) {
			if (dynamic_cast<Antenna*>(CellList[i][j]->GetGameObject())) {
				return true;
			}
		}
	}
	return false;
}

bool Grid::Beltsconflicts(CellPosition& startCell, CellPosition& endCell) const
{
	for (int i = 0; i < NumVerticalCells; i++) {
		for (int j = 0; j < NumHorizontalCells; j++) {
			GameObject* obj = CellList[i][j]->GetGameObject();
			Belt* belt = dynamic_cast<Belt*>(obj);
			if (belt) {
				CellPosition beltStart = belt->GetPosition();
				CellPosition beltEnd = belt->GetEndPosition();

				// Check if one belt's end is another's start 

				if ((startCell.GetCellNum() == beltEnd.GetCellNum() || endCell.GetCellNum() == beltStart.GetCellNum())) {

					return true;
				}
			}
		}
	}
	return false;
}

void Grid::setCurrentplayer(int num)
{
	currPlayerNumber = num;
}

bool Grid::isflag(CellPosition pos)
{
	if (CellList[pos.VCell()][pos.HCell()]->HasFlag())
	{

		return true;
	}
	return false;
}



// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(GameObject * gameObject) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = gameObject;
}

GameObject * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

GameObject* Grid::getGameobject(const CellPosition& CELL) const
{
	Cell* cell = CellList[CELL.VCell()][CELL.HCell()];

	if (cell!=nullptr)
	{
		return cell->GetGameObject();
	}
	return nullptr;
}

void Grid::SaveAll(ofstream& OutFile, string file, Type type)
{
	int Flags_num = 0, Antennas_num = 0, DangerZones_num = 0, RotatingGears_num = 0, WaterPits_num = 0, Workshops_num = 0, Belt_num = 0;

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j <= NumHorizontalCells - 1; j++)
		{
			if (dynamic_cast<Flag*>(CellList[i][j]->GetGameObject()))
				Flags_num++;
			if (dynamic_cast<Antenna*>(CellList[i][j]->GetGameObject()))
				Antennas_num++;
			if (dynamic_cast<DangerZone*>(CellList[i][j]->GetGameObject()))
				DangerZones_num++;
			if (dynamic_cast<RotatingGear*>(CellList[i][j]->GetGameObject()))
				RotatingGears_num++;
			if (dynamic_cast<WaterPit*>(CellList[i][j]->GetGameObject()))
				WaterPits_num++;
			if (dynamic_cast<Workshop*>(CellList[i][j]->GetGameObject()))
				Workshops_num++;
			if (dynamic_cast<Belt*>(CellList[i][j]->GetGameObject()))
				Belt_num++;
		}
	}

	switch (type)
	{
		case Flags:
			OutFile << left << "Number Of Flags: " << setw(2) << to_string(Flags_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (Flag* Object = dynamic_cast<Flag*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case WaterPits:
			OutFile << left << "Number Of WaterPits: " << setw(2) << to_string(WaterPits_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (WaterPit* Object = dynamic_cast<WaterPit*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case DangerZones:
			OutFile << left << "Number Of DangerZones: " << setw(2) << to_string(DangerZones_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (DangerZone* Object = dynamic_cast<DangerZone*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case Belts:
			OutFile << left << "Number Of Belts: " << setw(2) << to_string(Belt_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (Belt* Object = dynamic_cast<Belt*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case Workshops:
			OutFile << left << "Number Of Workshops: " << setw(2) << to_string(Workshops_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (Workshop* Object = dynamic_cast<Workshop*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case Antennas:
			OutFile << left << "Number Of Antennas: " << setw(2) << to_string(Antennas_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (Antenna* Object = dynamic_cast<Antenna*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;

		case RotatingGears:
			OutFile << left << "Number Of RotatingGears: " << setw(2) << to_string(RotatingGears_num) << endl;
			for (int i = NumVerticalCells - 1; i >= 0; i--)
			{
				for (int j = 0; j <= NumHorizontalCells - 1; j++)
				{
					if (RotatingGear* Object = dynamic_cast<RotatingGear*>(CellList[i][j]->GetGameObject()))
					{
						Object->Save(OutFile, file);
					}
				}
			}
			break;
	}
}

void Grid::LoadAll(ifstream& Infile, string file, Type type)
{
	int objectCount;
	string OBJtype;
	getline(Infile, OBJtype);
	objectCount = stoi(OBJtype.substr(OBJtype.find(":") + 1));
	switch (type)
	{

	case Flags:
	
		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;
			Flag* newFlag = new Flag(pos); 
			newFlag->Load(Infile, file);     
			AddObjectToCell(newFlag);    
		} 
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}

		break;

	case WaterPits:
		
		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;

			WaterPit* newWaterPit = new WaterPit(pos);  
			newWaterPit->Load(Infile, file);   
			AddObjectToCell(newWaterPit);   
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	case DangerZones:
		
		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;

			DangerZone* newDangerZone = new DangerZone(pos);  
			newDangerZone->Load(Infile, file);    
			AddObjectToCell(newDangerZone);    
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	case Belts:

		for (int i = 0; i < objectCount; i++)
		{
			CellPosition spos,epos;
			Belt* newBelt = new Belt(spos,epos);  
			newBelt->Load(Infile, file);     
			AddObjectToCell(newBelt);    
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	case Workshops:
		
		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;

			Workshop* newWorkshop = new Workshop(pos);  
			newWorkshop->Load(Infile, file);     
			AddObjectToCell(newWorkshop);    
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	case Antennas:

		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;

			Antenna* newAntenna = new Antenna(pos);
			newAntenna->Load(Infile, file);     
			AddObjectToCell(newAntenna);   
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	case RotatingGears:
		
		for (int i = 0; i < objectCount; i++)
		{
			CellPosition pos;
			int dierc = 0;
			RotatingGear* newRotatingGear = new RotatingGear(pos,dierc);  
			newRotatingGear->Load(Infile, file);  
			AddObjectToCell(newRotatingGear);   
		}
		if (objectCount != 0)
		{
			getline(Infile, OBJtype);
		}
		break;

	}
}

void Grid::removeGrid()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--) 
	{
		for (int j = 0; j <= NumHorizontalCells - 1; j++)
		{
			CellPosition pos(i, j);
			RemoveObjectFromCell(pos); // Remove object from the cell
		}
	}
}

void Grid::removeClipBoard()
{
	Clipboard = NULL;
}



// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

Belt * Grid::GetNextBelt(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the belt in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{


			///TODO: Check if CellList[i][j] has a belt, if yes return it
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without waterpits or dangerzone 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrWaterPitOrDangerZone(pOut);
			}
		}

		// 2- Draw other game objects(excluding waterpit and dangerzone)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawGameObject(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cgame objects do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}


Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}
void Grid::setcommand(Command* x, int size) {
	themovingcommands = x;
	themovingcommandsnum = size;

}
Command* Grid::getcommands() {
	return themovingcommands;

}
void Grid::setrandomcommands(Command* x, int size) {
	themovingcommands = x;
	themovingcommandsnum = size;


}
int Grid::getsize() {
	return themovingcommandsnum;
}