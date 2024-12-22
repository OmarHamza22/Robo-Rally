#pragma once
#include "Action.h"
#include "Input.h"
#include "Output.h"
#include"Workshop.h"
class AddWorkshopAction : public Action
{
	// [Action Parameters]
	CellPosition Workshippos;
public:
	AddWorkshopAction(ApplicationManager* pApp);
	virtual void ReadActionParameters(); // Reads AddBeltAction action parameters (startPos, endPos)

	virtual void Execute(); // Creates a new belt Object 
	// then Sets this belt object to the GameObject Pointer of its Cell
	virtual ~AddWorkshopAction();

};
