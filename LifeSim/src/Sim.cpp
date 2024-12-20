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
            : Scribble::Application()
        {
            PushLayer(new WorldLayer(this->GetWindow().GetWidth(), this->GetWindow().GetHeight(), 50, 50));
        }
        ~Sim() {}

    };
}

Scribble::Application* Scribble::CreateApplication()
{
    return new Life::Sim();
}