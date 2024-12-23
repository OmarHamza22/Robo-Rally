#pragma once
#include "Action.h"
class Load :
    public Action
{
private:
    string filname;
public:
    Load(ApplicationManager* pApp) :Action(pApp)
    {
    };

    void ReadActionParameters() override;

    void Execute() override;

    virtual ~Load();



};

