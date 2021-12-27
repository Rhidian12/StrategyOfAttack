#include "Factories.h"

#include "../GameComponents/TileComponent/TileComponent.h"
#include "../GameComponents/PlayerComponent/PlayerComponent.h"
#include "../GameComponents/MapComponent/MapComponent.h"

#include <GameObject/GameObject.h>

#include <Components/TextureComponent/TextureComponent.h>
#include <Components/TransformComponent/TransformComponent.h>

#include <TextureManager/TextureManager.h>

namespace Factories
{
	Integrian2D::GameObject* CreateGrassTileWithSeeds(const Integrian2D::Point2f& location) noexcept
	{
		using namespace Integrian2D;

		GameObject* pTile{ new GameObject{} };

		pTile->AddComponent(new TileComponent{ pTile, TileMobility::Empty });
		pTile->AddComponent(new TextureComponent{ pTile, TextureManager::GetInstance()->GetTexture("GrassWithSeeds") });

		pTile->pTransform->SetPosition(location);

		return pTile;
	}

	Integrian2D::GameObject* CreateGrassTileWithRocks(const Integrian2D::Point2f& location) noexcept
	{
		using namespace Integrian2D;

		GameObject* pTile{ new GameObject{} };

		pTile->AddComponent(new TileComponent{ pTile, TileMobility::Empty });
		pTile->AddComponent(new TextureComponent{ pTile, TextureManager::GetInstance()->GetTexture("GrassWithRocks") });

		pTile->pTransform->SetPosition(location);

		return pTile;
	}

	Integrian2D::GameObject* CreateMap(const std::vector<TileComponent*>& tiles) noexcept
	{
		using namespace Integrian2D;

		GameObject* pMap{ new GameObject{} };

		pMap->AddComponent(new MapComponent{ pMap, tiles });

		return pMap;
	}

	Integrian2D::GameObject* CreatePlayer(const Integrian2D::Point2f& location) noexcept
	{
		using namespace Integrian2D;

		GameObject* pPlayer{ new GameObject{} };

		pPlayer->AddComponent(new PlayerComponent{ pPlayer, nullptr });

		pPlayer->pTransform->SetPosition(location);

		return nullptr;
	}
}