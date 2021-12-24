#include "Factories.h"

#include "../GameComponents/TileComponent/TileComponent.h"

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
}