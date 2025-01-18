#pragma once
#include "Scribble2D/Core/Window.h"

#include "Scribble2D/Renderer/RenderContext.h"
#include <GLFW/glfw3.h>
#include <glm-1.0.1/glm/glm.hpp>

namespace Scribble {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowSpecs& specs);
		virtual ~WindowsWindow();

		void OnUpdate() override;
		bool OnWindowResize(unsigned int width, unsigned int height) override;


		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFunc& callback) override 
		{ 
			m_Data.EventCallback = callback; 
		}

		void* GetNativeWindow() const { return m_Window; }
		
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	
	private:
		virtual void Init(const WindowSpecs& specs);
		virtual void Shutdown();

		GLFWwindow* m_Window;
		std::unique_ptr<RenderContext> m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFunc EventCallback;
		};

		WindowData m_Data;
	};

}


