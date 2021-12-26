#include "MapComponent.h"

#include "../TileComponent/TileComponent.h"

MapComponent::MapComponent(Integrian2D::GameObject* const pOwner, const std::vector<TileComponent*>& tileComponents)
	: Component{ pOwner }
	, m_TileComponents{ tileComponents }
{}

Integrian2D::Component* MapComponent::Clone(Integrian2D::GameObject* const pOwner) noexcept
{
	return new MapComponent{ pOwner, m_TileComponents };
}

bool MapComponent::IsMovementLegal(const int tileIndex, const PlayerDirection direction) const noexcept
{
	return false;
}

int MapComponent::GetTileIndex(const Integrian2D::Point2f& location) const noexcept
{
	return 0;
}
