#include "shotingphase.h"

shootingphase::shootingphase(ApplicationManager* pApp) :Action(pApp) {
	player0 = pApp->GetGrid()->GetCurrentPlayer();
	pGrid = pApp->GetGrid();
	pGrid->AdvanceCurrentPlayer();
	player1 = pGrid->GetCurrentPlayer();
	pGrid->AdvanceCurrentPlayer();

}
void shootingphase::Execute() {
	int x, y;
	pGrid->GetOutput()->PrintMessage("this is the shooting phase");
	pGrid->GetInput()->GetPointClicked(x, y);

	Cell* p0cell = player0->GetCell();
	Cell* p1cell = player1->GetCell();
	CellPosition p0 = p0cell->GetCellPosition();
	CellPosition p1 = p1cell->GetCellPosition();
	if (p0.VCell() == p1.VCell()) {
		if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == RIGHT) {
			if (p0.HCell() < p1.HCell()) {
				player1->getshot();
				pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

			}
			if (p0.HCell() > p1.HCell()) {
				player0->getshot();
				pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));
			}
			if (player0->GetCurrentDirection() == UP && player1->GetCurrentDirection() == RIGHT) {
				if (p0.HCell() > p1.HCell()) {
					player0->getshot();
					pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));

				}
				if (p0.HCell() < p1.HCell()) {

					pGrid->GetOutput()->PrintMessage("No one got hurt ");
				}
			}
		}
		if (player0->GetCurrentDirection() == DOWN && player1->GetCurrentDirection() == RIGHT) {
			if (p0.HCell() > p1.HCell()) {
				player0->getshot();
				pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));

			}
			if (p0.HCell() > p1.HCell()) {
				pGrid->GetOutput()->PrintMessage("No one got hurt ");
			}
		}
		if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == UP) {
			if (p0.HCell() < p1.HCell()) {
				player1->getshot();
				pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

			}
			if (p0.HCell() > p1.HCell()) {
				pGrid->GetOutput()->PrintMessage("No one got hurt ");
			}
		}
	}
	if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == DOWN) {
		if (p0.HCell() < p1.HCell()) {
			player1->getshot();
			pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

		}
		if (p0.HCell() > p1.HCell()) {

			pGrid->GetOutput()->PrintMessage("No one got hurt ");
		}
	}
	if (player0->GetCurrentDirection() == LEFT && player1->GetCurrentDirection() == LEFT) {
		if (p0.HCell() > p1.HCell()) {
			player1->getshot();
			pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

		}
		if (p0.HCell() < p1.HCell()) {
			player0->getshot();
			pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));
		}
	}
	if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == LEFT) {
		if (p0.HCell() < p1.HCell()) {
			player1->getshot();
			player0->getshot();
			pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
			pGrid->GetInput()->GetPointClicked(x, y);
			pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

		}
		if (p0.HCell() > p1.HCell()) {
			pGrid->GetOutput()->PrintMessage("No one got shot");
		}

	}
	if (player0->GetCurrentDirection() == LEFT && player1->GetCurrentDirection() == RIGHT) {
		if (p0.HCell() > p1.HCell()) {
			player1->getshot();
			player0->getshot();
			pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
			pGrid->GetInput()->GetPointClicked(x, y);
			pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

		}
		if (p0.HCell() < p1.HCell()) {
			pGrid->GetOutput()->PrintMessage("No one got shot");
		}

	}
	if (p0.HCell() == p1.HCell()) {
		if (player0->GetCurrentDirection() == UP && player1->GetCurrentDirection() == UP) {
			if (p0.VCell() > p1.VCell()) {
				player1->getshot();
				pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

			}
			if (p0.VCell() < p1.VCell()) {
				player0->getshot();
				pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));
			}
		}
		if (player0->GetCurrentDirection() == DOWN && player1->GetCurrentDirection() == DOWN) {
			if (p0.VCell() < p1.VCell()) {
				player1->getshot();
				pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

			}
			if (p0.VCell() > p1.VCell()) {
				player0->getshot();
				pGrid->GetOutput()->PrintMessage("Player0 HP: " + to_string(player0->GetHealth()));
			}
		}
		if (player0->GetCurrentDirection() == UP && player1->GetCurrentDirection() == DOWN) {
			if (p0.VCell() > p1.VCell()) {
				player1->getshot();
				player0->getshot();
				pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
				pGrid->GetInput()->GetPointClicked(x, y);
				pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

			}
			if (p0.VCell() < p1.VCell()) {
				pGrid->GetOutput()->PrintMessage("No one got shot");
			}
			if (player0->GetCurrentDirection() == DOWN && player1->GetCurrentDirection() == UP) {
				if (p0.VCell() < p1.VCell()) {
					player1->getshot();
					player0->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() > p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}








			}
			if (player0->GetCurrentDirection() == DOWN && player1->GetCurrentDirection() == RIGHT) {
				if (p0.VCell() < p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() > p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == DOWN && player1->GetCurrentDirection() == LEFT) {
				if (p0.VCell() < p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() > p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}


			}
			if (player0->GetCurrentDirection() == UP && player1->GetCurrentDirection() == RIGHT) {
				if (p0.VCell() > p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() < p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == UP && player1->GetCurrentDirection() == LEFT) {
				if (p0.VCell() > p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() < p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == UP) {
				if (p0.VCell() < p1.VCell()) {
					player0->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() > p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == LEFT && player1->GetCurrentDirection() == UP) {
				if (p0.VCell() < p1.VCell()) {
					player0->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() > p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == RIGHT && player1->GetCurrentDirection() == DOWN) {
				if (p0.VCell() > p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() < p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}
			if (player0->GetCurrentDirection() == LEFT && player1->GetCurrentDirection() == DOWN) {
				if (p0.VCell() > p1.VCell()) {
					player1->getshot();
					pGrid->GetOutput()->PrintMessage("Player HP: " + to_string(player0->GetHealth()));
					pGrid->GetInput()->GetPointClicked(x, y);
					pGrid->GetOutput()->PrintMessage("Player1 HP: " + to_string(player1->GetHealth()));

				}
				if (p0.VCell() < p1.VCell()) {
					pGrid->GetOutput()->PrintMessage("No one got shot");
				}

			}








		}

	}
}



void shootingphase::ReadActionParameters() {};