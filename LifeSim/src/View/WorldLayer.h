#pragma once

#include "Model/World.h"
#include "Scribble2D/Core/Layer.h"
#include "Scribble2D/Renderer/Renderer.h"
#include "Scribble2D/Core/Log.h"
#include "Scribble2D/Events/KeyEvent.h"



namespace Life {

	class WorldLayer : public Scribble::Layer
	{
	public:
		WorldLayer(int windowWidth, int windowHeight, int width, int height);

		void OnUpdate(Scribble::Timestep ts) override;
		void OnEvent(Scribble::Event& e) override;
		bool OnEnterButtonPressed(Scribble::KeyPressedEvent& e);


		void StartSim() { if (!m_StartedSim) { m_StartedSim = true; } }

	private:
		bool m_StartedSim = false;
		Scribble::Renderer m_Renderer;
		World m_World;
		float m_TimeElapsed = 0.0f;

		void OncePerSecond()
		{
			if (m_StartedSim) {
				m_World.Update();
			}
		}
	};

}