#include "WorldLayer.h"
#include <Scribble2D/Core/Application.h>
#include <Scribble2D/Events/KeyEvent.h>

Life::WorldLayer::WorldLayer(int width, int height)
	: Scribble::Layer("World"), m_World(width, height)
{
	m_Renderer.Init();
	Reset();
}

void Life::WorldLayer::OnUpdate(Scribble::Timestep ts)
{
	m_TimeElapsed += ts.GetSeconds();

	while (m_TimeElapsed >= 0.10f) {
		OncePerSecond();
		m_TimeElapsed -= 0.10f;
	}

	for (const Cell& cell : *m_World.GetGrid()) {
		cell.Draw(m_Renderer);
	}

}

void Life::WorldLayer::OnEvent(Scribble::Event& e)
{
	Scribble::EventDispatcher dispatcher(e);
	dispatcher.Dispatch<Scribble::KeyPressedEvent>(std::bind(&Life::WorldLayer::OnEnterKeyPressed, this, std::placeholders::_1));
	dispatcher.Dispatch<Scribble::MouseButtonPressedEvent>(std::bind(&Life::WorldLayer::OnMouseButtonPressed, this, std::placeholders::_1));
	dispatcher.Dispatch<Scribble::KeyPressedEvent>(std::bind(&Life::WorldLayer::OnSpacebarKeyPressed, this, std::placeholders::_1));
	dispatcher.Dispatch<Scribble::WindowResizeEvent>(std::bind(&Life::WorldLayer::OnWindowResize, this, std::placeholders::_1));
}

bool Life::WorldLayer::OnEnterKeyPressed(Scribble::KeyPressedEvent& e)
{
	if (Scribble::Input::IsKeyPressed(Scribble::Enter))
	{
		SCB_TRACE("WorldLayer::PauseButtonPressed");
		OnPauseButtonPressed();
	}
	return false;
}

bool Life::WorldLayer::OnMouseButtonPressed(Scribble::MouseButtonPressedEvent& e)
{
	SCB_TRACE(e);
	float mouseX = Scribble::Input::GetMouseX();
	float mouseY = Scribble::Input::GetMouseY();
	SCB_TRACE("Getting Cell at Position: ({0},{1})", mouseX, mouseY);
	glm::vec2 cellCoords = GetCellCoords(mouseX, mouseY);
	SCB_TRACE("Cell Coords under mouse: ({0}, {1})", cellCoords.x, cellCoords.y);

	if (cellCoords.x >= m_World.GetWidth() || cellCoords.y >= m_World.GetHeight()) {
		SCB_WARN("Clicking Out of Bounds");
		return false;
	}

	Cell& cell = m_World.GetCellAt(cellCoords.x, cellCoords.y);
	SCB_INFO("Recovered Cell Position: ({0}, {1})", cell.GetPosition().x, cell.GetPosition().y);

	if (!cell.IsAlive()) {
		cell.SetAlive(true);
	}
	else {
		cell.SetAlive(false);
	}
	return false;
}

bool Life::WorldLayer::OnSpacebarKeyPressed(Scribble::KeyPressedEvent& e)
{
	SCB_TRACE(e);
	if (Scribble::Input::IsKeyPressed(Scribble::Space)) {
		Reset();
	}
	return false;
}

bool Life::WorldLayer::OnWindowResize(Scribble::WindowResizeEvent& e)
{
	ResetSize();
	return false;
}

const glm::vec2 Life::WorldLayer::GetCellCoords(float xPos, float yPos) const
{
	float x = xPos / m_ScaleFactor;
	float y = yPos / m_ScaleFactor;

	return { x, y };
	
}
glm::vec2 Life::WorldLayer::GetCellCoords(float xPos, float yPos)
{
	float x = xPos / m_ScaleFactor;
	float y = yPos / m_ScaleFactor;

	return { x, y };

}

void Life::WorldLayer::Reset()
{

	unsigned int windowHeight = Scribble::Application::Get().GetWindow().GetHeight();
	unsigned int windowWidth = Scribble::Application::Get().GetWindow().GetWidth();
	SCB_INFO("Window Size: ({0} x {1})", windowWidth, windowHeight);

	m_ScaleFactor = windowHeight / m_World.GetHeight();
	float cellSize = m_ScaleFactor * 0.7;
	SCB_INFO("Tile Size: {0}", m_ScaleFactor);
	SCB_INFO("Cell Size: {0}", cellSize);



	for (int i = 0; i < m_World.GetWidth(); i++) {
		for (int j = 0; j < m_World.GetHeight(); j++) {
			m_World.InitCell(
				i,
				j,
				i * m_ScaleFactor, // = xPos
				j * m_ScaleFactor, // = yPos
				cellSize,
				cellSize,
				0.0f,
				glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}



	m_World.GetCellAt(160, 90).SetAlive(true);
	m_World.GetCellAt(160, 91).SetAlive(true);
	m_World.GetCellAt(159, 90).SetAlive(true);
	m_World.GetCellAt(160, 89).SetAlive(true);
	m_World.GetCellAt(161, 91).SetAlive(true);
}

void Life::WorldLayer::ResetSize()
{

	unsigned int windowHeight = Scribble::Application::Get().GetWindow().GetHeight();
	unsigned int windowWidth = Scribble::Application::Get().GetWindow().GetWidth();
	SCB_INFO("Window Size: ({0} x {1})", windowWidth, windowHeight);

	m_ScaleFactor = windowHeight / m_World.GetHeight();
	float cellSize = m_ScaleFactor * 0.7;
	SCB_INFO("Tile Size: {0}", m_ScaleFactor);
	SCB_INFO("Cell Size: {0}", cellSize);



	for (int i = 0; i < m_World.GetWidth(); i++) {
		for (int j = 0; j < m_World.GetHeight(); j++) {
			m_World.ResetCell(
				i,
				j,
				i * m_ScaleFactor, // = xPos
				j * m_ScaleFactor, // = yPos
				cellSize,
				cellSize,
				0.0f,
				glm::vec3(1.0f, 1.0f, 1.0f),
				m_World.GetCellAt(i, j).IsAlive()
			);
		}
	}
}


