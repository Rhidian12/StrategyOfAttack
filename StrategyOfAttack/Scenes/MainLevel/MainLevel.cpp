#include "MainLevel.h"

#include <GameObject/GameObject.h>
#include <TextureManager/TextureManager.h>
#include <Texture/Texture.h>
#include <Core/Core.h>

#include "../../Factories/Factories.h"

MainLevel::MainLevel(const std::string& sceneName)
	: Scene{ sceneName.c_str() }
{}

void MainLevel::Start()
{
	using namespace Integrian2D;

	TextureManager* const pTextureManager{ TextureManager::GetInstance() };

	pTextureManager->AddTexture("GrassWithSeeds", new Texture{ "Resources/GroundTextures/GrassWithSeeds.jpg" });
	pTextureManager->AddTexture("GrassWithRocks", new Texture{ "Resources/GroundTextures/GrassWithRocks.jpg" });

	InitializeLevel();
}

void MainLevel::InitializeLevel() noexcept
{
	using namespace Integrian2D;

	const TextureManager* const pTextureManager{ TextureManager::GetInstance() };
	const Texture* const pTexture{ pTextureManager->GetTexture("GrassWithSeeds") };
	const Core* const pCore{ Core::GetInstance() };

	const float textureWidth{ pTexture->GetWidth() };
	const float textureHeight{ pTexture->GetHeight() };

	const float amountOfTexturesHorizontally{ pCore->GetWindowWidth() / textureWidth };
	const float amountOfTexturesVertically{ pCore->GetWindowHeight() / textureHeight };
}