#include "MapComponent.h"

#include "../TileComponent/TileComponent.h"

#include <GameObject/GameObject.h>
#include <Texture/Texture.h>
#include <Components/TextureComponent/TextureComponent.h>
#include <Components/TransformComponent/TransformComponent.h>

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
	using namespace Integrian2D;

	for (size_t i{}; i < m_TileComponents.size(); ++i)
	{
		const Point2f& pos{ m_TileComponents[i]->GetOwner()->pTransform->GetWorldPosition() };

		if (location.x > pos.x && location.x < pos.x + m_TileWidth)
			if (location.y > pos.y && location.y < pos.y + m_TileHeight)
				return static_cast<int>(i);
	}

	/* return error code */
	return -1;
}
