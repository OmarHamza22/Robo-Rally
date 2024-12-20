#pragma once
#include "Action.h"
class Copy :
    public Action
{
private:
    CellPosition copiedCELL;
public:
    Copy(ApplicationManager* pApp) :Action(pApp)
    {
    };

    void ReadActionParameters() override;

    void Execute() override;

    virtual ~Copy(); //to clean  the drived class


};

