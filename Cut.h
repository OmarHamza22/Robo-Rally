#pragma once
#include "Action.h"
class Cut :
    public Action
{
private:
    CellPosition cutcell;

public:
    Cut(ApplicationManager* pApp) :Action(pApp)
    {
    };
    void ReadActionParameters() override;

    void Execute() override;
    
    virtual ~Cut();

};

