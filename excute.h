#pragma once
#include "Action.h"
#include "Cell.h"
#include "Output.h"
#include "Input.h"
#include "Player.h"
#include "Grid.h"
#include "Selectcommand.h"

class excute : public Action {
    Player* current;
    Command* x;
    Grid* currentplayer;


public:
    excute(ApplicationManager* pApp, Output* x);

    Input* pIn;
    Output* pOut;

    void ReadActionParameters();
    void Execute();
};