#pragma once

#include <Math/TypeDefines.h>

namespace Integrian2D
{
	class GameObject;
}

namespace Factories
{
	[[nodiscard]] Integrian2D::GameObject* CreateGrassTileWithSeeds(const Integrian2D::Point2f& location) noexcept;
	[[nodiscard]] Integrian2D::GameObject* CreateGrassTileWithRocks(const Integrian2D::Point2f& location) noexcept;
}