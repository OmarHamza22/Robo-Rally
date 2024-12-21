#pragma once
#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
class repotandrepair :public Action {
private:
    ApplicationManager* pmanger;
    Player* z;
    Cell* know;

public:
    repotandrepair(ApplicationManager* pApp, Output* x);

    Input* pIn;
    Output* pOut;

    void ReadActionParameters();
    void Execute();
};