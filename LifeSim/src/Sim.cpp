#include "Model/World.h"
#include "Model/Cell.h"
#include "View/WorldLayer.h"
#include <Scribble2D.h>
#include <Scribble2D/Core/Window.h>
#include <iostream>

namespace Life {
    class Sim : public Scribble::Application
    {
    public:
        Sim()
        {
            PushLayer(new WorldLayer(this->GetWindow().GetWidth(), this->GetWindow().GetHeight(), 50, 50));
        }
        ~Sim() {}

    };




    // Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    // Any live cell with two or three live neighbours lives on to the next generation.
    // Any live cell with more than three live neighbours dies, as if by overpopulation.
    // Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
    bool CheckForLife(unsigned int xPos, unsigned int yPos, const Life::World& world)
    {
        const int neighbors[8][2] = {
            {-1, -1}, {0, -1}, {1, -1},
            {-1,  0},          {1,  0},
            {-1,  1}, {0,  1}, {1,  1}
        };

        int liveNeighbors = 0;
        unsigned int maxX = world.GetWidth() - 1;
        unsigned int maxY = world.GetHeight() - 1;

        // Loop through all 8 possible neighbors
        for (const auto& offset : neighbors) {
            int neighborX = xPos + offset[0];
            int neighborY = yPos + offset[1];

            // Check if the neighbor is within bounds
            if (neighborX >= 0 && neighborX <= maxX && neighborY >= 0 && neighborY <= maxY) {
                const Life::Cell& neighborCell = world.GetCellAt(neighborX, neighborY);
                if (neighborCell.isAlive()) {
                    liveNeighbors++;
                }
            }
        }

        const Life::Cell& cell = world.GetCellAt(xPos, yPos);
        if ((liveNeighbors == 2 && cell.isAlive()) || liveNeighbors == 3) {
            return true;
        }
        else {
            return false;
        }
    }
}

Scribble::Application* Scribble::CreateApplication()
{
    return new Life::Sim();
}