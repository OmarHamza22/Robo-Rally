#include"Antenna.h" 
#include "Input.h"
#include "Output.h"
#include "Player.h"
#include <cmath>

Antenna::Antenna(const CellPosition& antennaPosition) :GameObject(antennaPosition)
{
}

void Antenna::Draw(Output* pOut) const
{
    pOut->DrawAntenna(position);
}

void Antenna::Apply(Grid* pGrid, Player* pPlayer)
{

    ///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


    // == Here are some guideline steps (numbered below) to implement this function ==

    // 1- Print a message "the antenna will decide the turn of players. Click to continue ..." and wait mouse click

    Output* pOut = pGrid->GetOutput();
    Input* pIn = pGrid->GetInput();

    pOut->PrintMessage("The antenna will decide the turn of players. Click to continue ...");
    int x, y;
    pIn->GetPointClicked(x, y);


    // 2- Apply the antenna effect by following these notes, check grid class and decide which function to use
    //The antenna determines the turn order for players.
    //The distance of each player from the antenna determines his turn order in each rount.
    //Player with the minimum distance[ from the antenna will have the first turn in that round.
    //If there is a tie, player number will break it, for example if player 1 & 2 are in the same cell and they have the same distance from the antenna, player 1 will play first in that round.
    // 3- After deciding the turn of player Print a message indicating which player will play first example: "Player 1 will play first"

   // Step 1: Identify the current and other players using GetCurrentPlayer
    Player* currentPlayer = pPlayer;
    pGrid->AdvanceCurrentPlayer(); // Move to the next player
    Player* otherPlayer = pGrid->GetCurrentPlayer();
    pGrid->AdvanceCurrentPlayer(); // Reset to the original player

    // Step 2: Get player positions
    CellPosition player1Pos = currentPlayer->GetCell()->GetCellPosition();
    CellPosition player2Pos = otherPlayer->GetCell()->GetCellPosition();

    int v1 = position.VCell(); // Antenna's vertical position
    int h1 = position.HCell(); // Antenna's horizontal position

    int v2_1 = player1Pos.VCell(); // Current player's vertical position
    int h2_1 = player1Pos.HCell(); // Current player's horizontal position

    int v2_2 = player2Pos.VCell(); // Other player's vertical position
    int h2_2 = player2Pos.HCell(); // Other player's horizontal position

    // Step 3: Calculate distances
    double distance1 = sqrt(pow(v1 - v2_1, 2) + pow(h1 - h2_1, 2));
    double distance2 = sqrt(pow(v1 - v2_2, 2) + pow(h1 - h2_2, 2));

    // Step 4: Determine the turn order
    int firstPlayer;
    if (distance1 < distance2) {
        if (currentPlayer == pPlayer) {
            firstPlayer = 0; // Current player is closer
        }
        else {
            firstPlayer = 1; // Other player is closer
        }
    }
    else if (distance1 > distance2) {
        if (currentPlayer == pPlayer) {
            firstPlayer = 1; // Other player is closer
        }
        else {
            firstPlayer = 0; // Current player is closer
        }
    }
    else if (distance1 == distance2) { // Distances are equal
        if (currentPlayer == pPlayer) {
            firstPlayer = 0; // Current player wins the tie
        }
        else {
            firstPlayer = 1; // Other player wins the tie
        }
    }

    // Step 5: Display the result

    pOut->PrintMessage("Player " + to_string(firstPlayer + 1) + " will play first.");
}

void Antenna::Save(ofstream& OutFile, string file)
{
    if (!OutFile.is_open())
        OutFile.open(file, ios::out);

    OutFile << "Antenna" << " " << position.GetCellNum() << endl;

}


Antenna::~Antenna()
{
}