#include "World.h"
#include "Scribble2D/Core/Log.h"
#include <iostream>
#include <algorithm>

Life::World::World(unsigned int width, unsigned int height)
	: m_Width(width), m_Height(height), m_Grid(width * height)
{
    m_Grid.resize(m_Width * m_Height);
    m_Backbuffer.resize(m_Width * m_Height);
}



void Life::World::Update()
{
    for (int i = 0; i < m_Width; i++) {
        for (int j = 0; j < m_Height; j++) {
            Cell cell;
            cell.setAlive(CheckForLife(i, j));
            m_Backbuffer[i + j * m_Width] = cell;
        }
    }

    m_Grid = m_Backbuffer;
}

// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
// Any live cell with two or three live neighbours lives on to the next generation.
// Any live cell with more than three live neighbours dies, as if by overpopulation.
// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
bool Life::World::CheckForLife(unsigned int xPos, unsigned int yPos)
{
    const int neighbors[8][2] = {
        {-1, -1}, {0, -1}, {1, -1},
        {-1,  0},          {1,  0},
        {-1,  1}, {0,  1}, {1,  1}
    };

    int liveNeighbors = 0;
    unsigned int maxX = m_Width - 1;
    unsigned int maxY = m_Height - 1;

    // Loop through all 8 possible neighbors
    for (const auto& offset : neighbors) {
        int neighborX = xPos + offset[0];
        int neighborY = yPos + offset[1];

        // Check if the neighbor is within bounds
        if (neighborX >= 0 && neighborX <= maxX && neighborY >= 0 && neighborY <= maxY) {
            const Life::Cell& neighborCell = GetCellAt(neighborX, neighborY);
            if (neighborCell.isAlive()) {
                liveNeighbors++;
            }
        }
    }

    const Life::Cell& cell = GetCellAt(xPos, yPos);
    if ((liveNeighbors == 2 && cell.isAlive()) || liveNeighbors == 3) {
        return true;
    }
    else {
        return false;
    }
}
