#pragma once
#include "Action.h"
class Paste :
    public Action
{
private:
    CellPosition pastecell;
public:
    Paste(ApplicationManager* pApp) :Action(pApp)
    {
    };
    void ReadActionParameters() override;

    void Execute() override;

    virtual ~Paste();


};

