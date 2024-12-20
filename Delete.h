#pragma once
#include "Action.h"
class Delete :
    public Action
{
private:
    CellPosition deletedcell;
public:
    Delete(ApplicationManager* pApp) :Action(pApp)
    {
    };
    void ReadActionParameters() override;

    void Execute() override;

    virtual ~Delete();

};