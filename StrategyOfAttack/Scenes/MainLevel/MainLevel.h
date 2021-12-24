#pragma once

#include <Scene/Scene.h>

#include <string>

class MainLevel final : public Integrian2D::Scene
{
public:
	MainLevel(const std::string& sceneName);

	virtual void Start() override;

private:
};