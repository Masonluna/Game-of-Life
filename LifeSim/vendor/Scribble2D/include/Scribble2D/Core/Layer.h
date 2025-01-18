#pragma once

#include "Scribble2D/Events/Event.h"
#include "Scribble2D/Core/Timestep.h"


namespace Scribble {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& e) {}

	protected:
		std::string m_DebugName;
	};

}