#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Skull {
	class SKULL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	//to be defined in client
	Application* CreateApplication();
}

