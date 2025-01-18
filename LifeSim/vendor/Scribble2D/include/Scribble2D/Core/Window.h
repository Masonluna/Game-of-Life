#pragma once

#include "../Events/Event.h"
#include <functional>

namespace Scribble {

	struct WindowSpecs
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowSpecs(const std::string& title = "Scribble2D Rendering Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{}
	};

	class Window
	{
	public:
		using EventCallbackFunc = std::function<void(Event&)>;

		virtual~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunc& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
		virtual bool OnWindowResize(unsigned int x, unsigned int y) = 0;
		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowSpecs& specs = WindowSpecs());

	};

}