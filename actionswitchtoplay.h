#pragma once
#include "Action.h" 
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"
#include "Cell.h"
using namespace std;
class switchtoplaymode : public Action {
        public :
        switchtoplaymode(ApplicationManager* pApp,Output* x);
        Input* pIn ;
        Output* pOut;

        void ReadActionParameters() ;

        void Execute();


    

};
