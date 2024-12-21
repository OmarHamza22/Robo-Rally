#pragma once
#include "Action.h"
class Save :
    public Action
{
private:



public:

    void ReadActionParameters() override;

    void Execute() override;

};

