#pragma once
#include "../Events/Event.h"
#include "../Events/ApplicationEvent.h"
#include "LayerStack.h"
#include "Window.h"

namespace Scribble {

	class Application
	{
	public:
		Application();
		Application(WindowSpecs specs);
		virtual ~Application();

		void Run();

		Window& GetWindow() { return *m_Window; }

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		static Application& Get() { return *s_Instance; }


	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
		bool m_Minimized = false;

		static Application* s_Instance;

	};

	// Should be defined by the client
	Application* CreateApplication();

}