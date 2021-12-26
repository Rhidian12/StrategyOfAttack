#include "MapComponent.h"

#include "../TileComponent/TileComponent.h"

#include <GameObject/GameObject.h>
#include <Texture/Texture.h>
#include <Components/TextureComponent/TextureComponent.h>

MapComponent::MapComponent(Integrian2D::GameObject* const pOwner, const std::vector<TileComponent*>& tileComponents)
	: Component{ pOwner }
	, m_TileComponents{ tileComponents }
	, m_TileWidth{}
	, m_TileHeight{}
{
	const Integrian2D::Texture* const pTexture{ tileComponents[0]->GetOwner()->GetComponentByType<Integrian2D::TextureComponent>()->GetTexture()};

	m_TileWidth = pTexture->GetWidth();
	m_TileHeight = pTexture->GetHeight();
}

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
