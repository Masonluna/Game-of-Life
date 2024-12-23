#include "Model/World.h"
#include "Model/Cell.h"
#include "View/WorldLayer.h"
#include <Scribble2D/Scribble2D.h>
#include <Scribble2D/Core/Window.h>
#include <iostream>

namespace Life {
    class Sim : public Scribble::Application
    {
    public:
        Sim(Scribble::WindowSpecs specs)
            : Scribble::Application(specs)
        {
            // TODO: This should be a 16:9 ratio, then a buffer should be added from WorldLayer constructor
            PushLayer(new WorldLayer(320, 180));
        }
        ~Sim() {}

    };
}

Scribble::Application* Scribble::CreateApplication()
{
    Scribble::WindowSpecs specs("Conway's Game of Life", 1920, 1080);
    return new Life::Sim(specs);
}