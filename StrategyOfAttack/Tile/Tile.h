#pragma once

#include <Components/Component/Component.h>
#include <Math/TypeDefines.h>

enum class TileMobility
{
	Empty = 0,
	Impassable = 1
};

class TileComponent final : public Integrian2D::Component
{
public:
	TileComponent(Integrian2D::GameObject* const pOwner, const TileMobility tileMobility);

	virtual Component* Clone(Integrian2D::GameObject* pOwner) noexcept override;

private:
	TileMobility m_TileMobility;
};