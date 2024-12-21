#pragma once
#include "Action.h"
class Save :
    public Action
{
private:
    string filename;

public:
    
    Save(ApplicationManager* pApp) :Action(pApp)
    {
    };

    void ReadActionParameters() override;

    void Execute() override;

    virtual ~Save();
};

