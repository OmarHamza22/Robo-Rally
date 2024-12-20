#pragma once
#include "Action.h" 
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Cell.h"
class switchtodesignmode :public Action {

public:
    switchtodesignmode(ApplicationManager* pApp , Output* x);

    Input* pIn;
    Output* pOut;
    
   void ReadActionParameters();
   void Execute();
};