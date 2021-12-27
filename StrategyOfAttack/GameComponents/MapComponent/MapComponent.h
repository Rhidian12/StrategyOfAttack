#pragma once

#include "../../PlayerDirection/PlayerDirection.h"

#include <Components/Component/Component.h>

#include <vector>

class TileComponent;

class MapComponent final : public Integrian2D::Component
{
public:
	MapComponent(Integrian2D::GameObject* const pOwner, const std::vector<TileComponent*>& tileComponents);

	virtual Component* Clone(Integrian2D::GameObject* const pOwner) noexcept override;

	bool IsMovementLegal(const int tileIndex, const PlayerDirection direction) const noexcept;
	int GetTileIndex(const Integrian2D::Point2f& location) const noexcept;

	float GetTileWidth() const noexcept;
	float GetTileHeight() const noexcept;

private:
	std::vector<TileComponent*> m_TileComponents;
	float m_TileWidth;
	float m_TileHeight;
};