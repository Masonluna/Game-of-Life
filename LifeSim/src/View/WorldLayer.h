#pragma once

#include "Model/World.h"
#include "CellView.h"
#include "Scribble2D/Core/Layer.h"
#include "Scribble2D/Renderer/Renderer.h"
#include "Scribble2D/Core/Log.h"



namespace Life {

	class WorldLayer : public Scribble::Layer
	{
	public:
		WorldLayer(int windowWidth, int windowHeight, int width, int height)
			: Scribble::Layer("World"), m_World(width, height)
		{
			m_Renderer.Init();

			float cellFactor = windowHeight / static_cast<float>(height);
			float cellSize = cellFactor * 0.7;
			SCB_INFO("Cell Size: {0}", cellFactor);

			SCB_INFO("Window Height: {0}", windowHeight);
			SCB_INFO("Window Width: {0}", windowWidth);

			m_World.GetCellAt(28, 29).setAlive(true);
			m_World.GetCellAt(28, 30).setAlive(true);
			m_World.GetCellAt(28, 31).setAlive(true);



			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					m_WorldView.emplace_back(CellView(
						i,
						j,
						20 + i * cellFactor,
						20 + j * cellFactor,
						cellSize,
						cellSize,
						0.0f,
						glm::vec3(1.0f, 1.0f, 1.0f),
						m_World.GetCellAt(i, j)));
				}
			}
		}

		void OnUpdate(Scribble::Timestep ts) override
		{
			m_TimeElapsed += ts.GetSeconds();
			
			while (m_TimeElapsed >= 0.20f) {
				OncePerSecond();

				m_TimeElapsed -= 0.20f;
			}

			for (CellView cellView : m_WorldView) {
				cellView.Draw(m_Renderer);
			}
		}



	private:
		Scribble::Renderer m_Renderer;
		World m_World;
		std::vector<CellView> m_WorldView;
		float m_TimeElapsed = 0.0f;

		void OncePerSecond()
		{
			m_World.Update();
		}
	};

}