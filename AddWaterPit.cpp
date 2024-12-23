#include "AddWaterPit.h"
#include "WaterPit.h"  // Ensure WaterPit definition is included

AddWaterPit::AddWaterPit(ApplicationManager* pApp) : Action(pApp) {}

void AddWaterPit::ReadActionParameters() {
    Grid* pGrid = pManager->GetGrid();
    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("New Water Pit: Click on its Cell ...");
    WaterPitpos = pIn->GetCellClicked();

    if (!WaterPitpos.IsValidCell()) {
        pOut->PrintMessage("Invalid cell! Click anywhere to continue.");
        pIn->GetCellClicked();
        return;
    }

    pOut->ClearStatusBar();
}

void AddWaterPit::Execute() {
    ReadActionParameters();

    WaterPit* pWaterPit = new WaterPit(WaterPitpos);  // Instantiate WaterPit
    Grid* pGrid = pManager->GetGrid();
    bool added = pGrid->AddObjectToCell(pWaterPit);  // Pass to AddObjectToCell

    if (!added) {
        delete pWaterPit;  // Avoid memory leak
        pGrid->PrintErrorMessage("Error: Cell already has an object! Click to continue ...");
    }
}

AddWaterPit::~AddWaterPit() {}
