#include "MainLevel.h"

#include <GameObject/GameObject.h>
#include <TextureManager/TextureManager.h>
#include <Texture/Texture.h>

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

	AddGameObject("Tile", Factories::CreateGrassTileWithSeeds(Point2f{}));
}