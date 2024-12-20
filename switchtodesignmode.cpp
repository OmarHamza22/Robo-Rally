#include "switchtodesignmode.h"

switchtodesignmode::switchtodesignmode(ApplicationManager* pApp,Output* x):Action(pApp),pOut(x){};



    void switchtodesignmode::Execute() {
	pOut->CreateDesignModeToolBar();

}

	void switchtodesignmode::ReadActionParameters() {
	
	}






