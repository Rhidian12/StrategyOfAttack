#include "MainLevel.h"

#include <GameObject/GameObject.h>
#include <TextureManager/TextureManager.h>
#include <Texture/Texture.h>
#include <Core/Core.h>
#include <Utils/Utils.h>

#include "../../Factories/Factories.h"
#include "../../GameComponents/TileComponent/TileComponent.h"
#include "../../GameComponents/MapComponent/MapComponent.h"

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

	const float amountOfTexturesHorizontally{ Utils::RoundDecimalUp(pCore->GetWindowWidth() / textureWidth) };
	const float amountOfTexturesVertically{ Utils::RoundDecimalUp(pCore->GetWindowHeight() / textureHeight) };

	std::vector<TileComponent*> tiles{};

	for (int x{}; x < amountOfTexturesHorizontally; ++x)
	{
		for (int y{}; y < amountOfTexturesVertically; ++y)
		{
			GameObject* pTile{};

			if (Utils::RandomNumber(0, 2) == 0)
				pTile = Factories::CreateGrassTileWithSeeds(Point2f{ x * textureWidth, y * textureHeight });
			else
				pTile = Factories::CreateGrassTileWithRocks(Point2f{ x * textureWidth, y * textureHeight });

			tiles.push_back(pTile->GetComponentByType<TileComponent>());

			AddGameObject("Tile", pTile);
		}
	}

	AddGameObject("Map", Factories::CreateMap(tiles));
	AddGameObject("Player", Factories::CreatePlayer(Point2f{}, GetGameObject("Map")->GetComponentByType<MapComponent>()));
}