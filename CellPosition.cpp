#include "CellPosition.h"
#include "UI_Info.h"
#include "DEFS.h"
#include "iostream"
using namespace std;

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v >= 0 && v < NumVerticalCells)
	{
		vCell = v;
		return true;
	}
	else
	{
		vCell = -1;
		return false;
	}

}

bool CellPosition::SetHCell(int h) 
{
	//TODO: Implement this function as described in the .h file (don't forget the validation)
	if (h >= 0 && h < NumHorizontalCells)
	{
		hCell = h;
		return true;
	}
	else
	{
		hCell = -1;
		return false;
	}
}

int CellPosition::VCell() const
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if ((vCell < NumVerticalCells && vCell >=0) && (hCell< NumHorizontalCells && hCell>=0) )
	{
		return true;
	}
	return false; // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int h,v;
	h = cellPosition.HCell()+1;
	v = (cellPosition.VCell() - 4 ) *-1;

	int cellnum= (v* NumHorizontalCells)+h;

	return cellnum; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file

	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it
	int h;
	int v;
	if ((cellNum % 11) == 0)
	{
		v = ((cellNum / 11)-5)*-1;
	}
	else
	{
		v = ((cellNum / 11) - 4) * -1;
	}
	if ((cellNum % 11 ) == 0) 
	{
		h = 10;
	}
	else 
	{
		h = (cellNum % 11)-1;
	}


	if (position.SetVCell(v) && position.SetHCell(h))
	{
		CellPosition position(v, h);
	}

	return position;

}


void CellPosition::AddCellNum(int addedNum, Direction direction)
{
	int cellnum;

	cellnum = GetCellNum();
	///TODO: Implement this function as described in the .h file
	if (direction == UP )
	{
		if (vCell==0)
		{
			vCell = -1;
		}
		else
		{
			cellnum += (addedNum * 11);
			if(vCell-addedNum >=0)
			vCell -= addedNum;
			else { vCell = -1; }
		}
		
		
	}
	if (direction == DOWN)
	{
		if (vCell == 4)
		{
			vCell = -1;
		}
		else 
		{
		cellnum -= (addedNum * 11);
		if (vCell + addedNum <= 4)
			vCell += addedNum;
		else { vCell = -1; }
		}
		
		
	}
	if (direction == RIGHT)
	{
		if (hCell == 10)
		{
			hCell = -1;
		} 
		else
		{
			cellnum += (addedNum);
			if(hCell + addedNum<= 10 )
			hCell += addedNum;
			else { hCell = -1; }
		}
		
		
	}


	if (direction == LEFT)
	{	
		if (hCell == 0)
		{
			hCell = -1;
		}
		else
		{

			cellnum -= (addedNum);
			if (hCell - addedNum >= 0)
				hCell -= addedNum;
			else { hCell = -1; }
			
		}
	
		
	}
	// Note: this function updates the data members (vCell and hCell) of the calling object

}