#include "Tile.h"

TileComponent::TileComponent(Integrian2D::GameObject* const pOwner, const TileMobility tileMobility)
	: Component{ pOwner }
	, m_TileMobility{ tileMobility }
{
}

Integrian2D::Component* TileComponent::Clone(Integrian2D::GameObject* pOwner) noexcept
{
	return new TileComponent{ pOwner, m_TileMobility };
}
