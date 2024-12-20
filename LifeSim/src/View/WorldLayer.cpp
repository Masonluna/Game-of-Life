#include "WorldLayer.h"

Life::WorldLayer::WorldLayer(int windowWidth, int windowHeight, int width, int height)
	: Scribble::Layer("World"), m_World(width, height)
{
	m_Renderer.Init();

	float scaleFactor = windowHeight / static_cast<float>(height);
	float cellSize = scaleFactor * 0.7;
	SCB_INFO("Tile Size: {0}", scaleFactor);
	SCB_INFO("Cell Size: {0}", cellSize);

	SCB_INFO("Window Height: {0}", windowHeight);
	SCB_INFO("Window Width: {0}", windowWidth);



	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			m_World.InitCell(
				i,
				j,
				20 + i * scaleFactor,
				20 + j * scaleFactor,
				cellSize,
				cellSize,
				0.0f,
				glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}

	m_World.GetCellAt(28, 29).SetAlive(true);
	m_World.GetCellAt(28, 30).SetAlive(true);
	m_World.GetCellAt(27, 29).SetAlive(true);
	m_World.GetCellAt(28, 28).SetAlive(true);
	m_World.GetCellAt(29, 30).SetAlive(true);


}

void Life::WorldLayer::OnUpdate(Scribble::Timestep ts)
{
	m_TimeElapsed += ts.GetSeconds();

	while (m_TimeElapsed >= 0.20f) {
		OncePerSecond();
		m_TimeElapsed -= 0.20f;
	}

	for (const Cell& cell : *m_World.GetGrid()) {
		cell.Draw(m_Renderer);
	}
}



