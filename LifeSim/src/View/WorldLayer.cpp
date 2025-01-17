#include "WorldLayer.h"
#include <Scribble2D/Core/Application.h>
#include <Scribble2D/Events/KeyEvent.h>


// TODO: As of now, width and height are hardcoded, including the off-screen portion.
//	A buffer offset should be decided on and added to width and height in m_World constructor.
Life::WorldLayer::WorldLayer(int width, int height)
	: Scribble::Layer("World"), m_World(width + GRID_OFFSET_X, height + GRID_OFFSET_Y)
{
	m_Renderer.Init();
	m_TextRenderer.Init();
	m_TextRenderer.LoadFont("fonts/ocraext.TTF", 18);
	Reset();
}

void Life::WorldLayer::OnUpdate(Scribble::Timestep ts)
{
	m_TimeElapsed += ts.GetSeconds();

	float tickTime = 0.1f;

	while (m_TimeElapsed >= tickTime) {
		OncePerTick();
		m_TimeElapsed -= tickTime;
	}

	for (const Cell& cell : *m_World.GetGrid()) {
		cell.Draw(m_Renderer);
	}

	m_TextRenderer.DrawString("Enter: Play/Pause", glm::vec2(5.0f, 5.0f), 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	m_TextRenderer.DrawString("Left Click while paused to place a Cell!", glm::vec2(5.0f, 25.0f), 1.0f, glm::vec3(0.0f, 1.0f, 0.0f));

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
	if (Scribble::Input::IsKeyPressed(Scribble::Enter) || Scribble::Input::IsKeyPressed(Scribble::KPEnter))
	{
		SCB_TRACE("WorldLayer::PauseButtonPressed");
		OnPauseButtonPressed();
	}
	return false;
}

bool Life::WorldLayer::OnMouseButtonPressed(Scribble::MouseButtonPressedEvent& e)
{
	SCB_TRACE(e);

	if (!m_StartedSim) {
		SCB_TRACE("Placing Cell");
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
	SCB_TRACE("OnWindowResize: {0}, {1}", e.GetWidth(), e.GetHeight());
	ResetSize();
	return false;
}

const glm::vec2 Life::WorldLayer::GetCellCoords(float xPos, float yPos) const
{
	float x = (xPos / m_ScaleFactor) + (GRID_OFFSET_X / 2);
	float y = (yPos / m_ScaleFactor) + (GRID_OFFSET_Y / 2);

	return { x, y };
	
}
glm::vec2 Life::WorldLayer::GetCellCoords(float xPos, float yPos)
{
	float x = (xPos / m_ScaleFactor) + (GRID_OFFSET_X / 2);
	float y = (yPos / m_ScaleFactor) + (GRID_OFFSET_Y / 2);

	return { x, y };

}

void Life::WorldLayer::Reset()
{

	unsigned int windowHeight = Scribble::Application::Get().GetWindow().GetHeight();
	unsigned int windowWidth = Scribble::Application::Get().GetWindow().GetWidth();
	SCB_INFO("Window Size: ({0} x {1})", windowWidth, windowHeight);


	m_ScaleFactor = windowHeight / (m_World.GetHeight() - GRID_OFFSET_Y);
	float cellSize = m_ScaleFactor * 0.7;
	SCB_INFO("Tile Size: {0}", m_ScaleFactor);
	SCB_INFO("Cell Size: {0}", cellSize);

	for (int i = -GRID_OFFSET_X / 2; i < (int)m_World.GetWidth() - GRID_OFFSET_X / 2; i++) {
		for (int j = -GRID_OFFSET_Y / 2; j < (int)m_World.GetHeight() - GRID_OFFSET_Y / 2; j++) {
			m_World.InitCell(
				i + GRID_OFFSET_X / 2,
				j + GRID_OFFSET_Y / 2,
				i * m_ScaleFactor, // = xPos
				j * m_ScaleFactor, // = yPos
				cellSize,
				cellSize,
				0.0f,
				glm::vec3(1.0f, 1.0f, 1.0f));
		}
	}

	m_World.GetCellAt(90, 55).SetAlive(true);
	m_World.GetCellAt(90, 56).SetAlive(true);
	m_World.GetCellAt(89, 55).SetAlive(true);
	m_World.GetCellAt(90, 54).SetAlive(true);
	m_World.GetCellAt(91, 56).SetAlive(true);
}

void Life::WorldLayer::ResetSize()
{

	unsigned int windowHeight = Scribble::Application::Get().GetWindow().GetHeight();
	unsigned int windowWidth = Scribble::Application::Get().GetWindow().GetWidth();
	SCB_INFO("Window Size: ({0} x {1})", windowWidth, windowHeight);

	m_ScaleFactor = (float)windowHeight / (m_World.GetHeight() - GRID_OFFSET_Y);
	float cellSize = m_ScaleFactor * 0.7;
	SCB_INFO("Tile Size: {0}", m_ScaleFactor);
	SCB_INFO("Cell Size: {0}", cellSize);


	//TODO: Needs to be updated to cooperate with off-screen buffer.
	for (int i = -GRID_OFFSET_X / 2; i < (int)m_World.GetWidth() - (GRID_OFFSET_X / 2); i++) {
		for (int j = -GRID_OFFSET_Y / 2; j < (int)m_World.GetHeight() - (GRID_OFFSET_Y / 2); j++) {
			m_World.ResetCell(
				i + GRID_OFFSET_X / 2,
				j + GRID_OFFSET_Y / 2,
				i * m_ScaleFactor, // = xPos
				j * m_ScaleFactor, // = yPos
				cellSize,
				cellSize,
				0.0f,
				glm::vec3(1.0f, 1.0f, 1.0f),
				m_World.GetCellAt(i + (GRID_OFFSET_X / 2), j + (GRID_OFFSET_Y / 2)).IsAlive()
			);
		}
	}
}