#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"DangerZone.h"
class AddDangerzoneAction :
    public Action
{
	CellPosition Dangerpos;
public:
	AddDangerzoneAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads AddBeltAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new belt Object 
	// then Sets this belt object to the GameObject Pointer of its Cell
	virtual ~AddDangerzoneAction();
};

