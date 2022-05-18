#include "skpch.h"
#include "Application.h"

#include "Skull/Events/ApplicationEvent.h"
#include "Skull/Log.h"

namespace Skull
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		SK_TRACE(e);
		while (true);
	}
}
