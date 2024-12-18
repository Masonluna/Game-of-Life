#include "Model/World.h"
#include "Model/Cell.h"
#include <iostream>

int main()
{
	Life::World world(10, 10);
	int index = 0;
	for (std::vector<Life::Cell> column : world.GetGrid()) {
		for (Life::Cell cell : column) {
			std::cout << index++ << ".  " << cell.ToString();
		}
	}

	//world.GetGrid()[0][0].setAlive(true);
}


// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
bool CheckForLife(unsigned int xPos, unsigned int yPos, Life::World world)
{
	Life::Cell cell = world.GetCellAt(xPos, yPos);
	int liveNeighbors = 0;
	// ======== CORNERS ==========
	// ===========================
	// Top Left
	if (xPos == 0 && yPos == 0) {
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
	}
	// Bottom Left
	else if (xPos == 0 && yPos == 9) {
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
	}
	// Top Right
	else if (xPos == 9 && yPos == 0) {
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
	}
	// Bottom Right
	else if (xPos == 9 && yPos == 9) {
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
	}

	// ======== EDGES =============
	// ============================

	// Left Edge
	else if (xPos == 0) {
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos - 1).isAlive())
			liveNeighbors++;
	}
	// Top Edge
	else if (yPos == 0) {
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
	}
	// Right Edge
	else if (xPos == 9) {
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos - 1).isAlive())
			liveNeighbors++;
	}
	
	// Bottom Edge
	else if (yPos == 9) {
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
	}

	// Anywhere else
	else {
		if (world.GetCellAt(xPos, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos - 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos, yPos + 1).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos + 1, yPos).isAlive())
			liveNeighbors++;
		if (world.GetCellAt(xPos - 1, yPos + 1).isAlive())
			liveNeighbors++;
	}

	if ((liveNeighbors == 2 && cell.isAlive()) || liveNeighbors == 3)
		return true;
	else
		return false;

}