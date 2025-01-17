#pragma once

#include "Model/World.h"
#include "Scribble2D/Core/Layer.h"
#include "Scribble2D/Renderer/Renderer.h"
#include "Scribble2D/Core/Log.h"
#include "Scribble2D/Events/KeyEvent.h"
#include "Scribble2D/Events/MouseEvent.h"
#include "Scribble2D/Core/Input.h"
#include "Scribble2D/Renderer/TextRenderer.h"



namespace Life {

#define GRID_OFFSET_X 40
#define GRID_OFFSET_Y 40

	class WorldLayer : public Scribble::Layer
	{
	public:
		WorldLayer(int width, int height);

		// Engine update and event handling
		void OnUpdate(Scribble::Timestep ts) override;
		void OnEvent(Scribble::Event& e) override;


		bool OnEnterKeyPressed(Scribble::KeyPressedEvent& e);
		bool OnMouseButtonPressed(Scribble::MouseButtonPressedEvent& e);
		bool OnSpacebarKeyPressed(Scribble::KeyPressedEvent& e);
		bool OnWindowResize(Scribble::WindowResizeEvent& e);


		// Coordinate Accessors
		const glm::vec2 GetCellCoords(float xPos, float yPos) const;
		glm::vec2 GetCellCoords(float xPos, float yPos);


	private:
		void OnPauseButtonPressed() { m_StartedSim = !m_StartedSim; }
		void Reset();
		void ResetSize();
		void OncePerSecond()
		{
			if (m_StartedSim) {
				m_World.Update();
			}
		}

	private:
		bool m_StartedSim = false;
		Scribble::Renderer m_Renderer;
		Scribble::TextRenderer m_TextRenderer;
		World m_World;
		float m_TimeElapsed = 0.0f;
		float m_ScaleFactor = 0.0f;
	};

}