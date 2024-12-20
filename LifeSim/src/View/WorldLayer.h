#pragma once

#include "Model/World.h"
#include "Scribble2D/Core/Layer.h"
#include "Scribble2D/Renderer/Renderer.h"
#include "Scribble2D/Core/Log.h"



namespace Life {

	class WorldLayer : public Scribble::Layer
	{
	public:
		WorldLayer(int windowWidth, int windowHeight, int width, int height);

		void OnUpdate(Scribble::Timestep ts) override;

	private:
		bool m_StartedSim = true;
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