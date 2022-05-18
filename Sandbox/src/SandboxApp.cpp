#include "skpch.h"
#include <Skull.h>

class Sandbox : public Skull::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Skull::Application* Skull::CreateApplication()
{
	return new Sandbox();
}