#include "repotandrepair.h"


repotandrepair::repotandrepair(ApplicationManager* pApp, Output* x) :Action(pApp), pOut(x) {

    z = pApp->GetGrid()->GetCurrentPlayer();
    know = z->GetCell();

};
void repotandrepair::Execute() {
    if (know->HasWorkshop() == nullptr)
        return;
    z->SetHealth(10);
    

}

void repotandrepair::ReadActionParameters() {

}