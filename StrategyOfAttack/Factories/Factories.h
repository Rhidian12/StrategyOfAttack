#pragma once

#include <Math/TypeDefines.h>

namespace Integrian2D
{
	class GameObject;
}

class MapComponent;

namespace Factories
{
	[[nodiscard]] Integrian2D::GameObject* CreateGrassTileWithSeeds(const Integrian2D::Point2f& location) noexcept;
	[[nodiscard]] Integrian2D::GameObject* CreateGrassTileWithRocks(const Integrian2D::Point2f& location) noexcept;
	/* [TODO]: Use boundaries */
	[[nodiscard]] Integrian2D::GameObject* CreateMap(const std::vector<TileComponent*>& tiles) noexcept;
	[[nodiscard]] Integrian2D::GameObject* CreatePlayer(const Integrian2D::Point2f& location, MapComponent* const pMapComponent) noexcept;
}