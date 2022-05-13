#pragma once

#ifdef SK_PLATFORM_WINDOWS

extern Skull::Application* Skull::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Skull::CreateApplication();
	app->Run();
	delete app;
}

#endif