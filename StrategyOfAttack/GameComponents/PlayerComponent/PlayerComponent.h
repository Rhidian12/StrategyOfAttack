#pragma once

#include <Components/Component/Component.h>

class MapComponent;

class PlayerComponent final : public Integrian2D::Component
{
public:
	PlayerComponent(Integrian2D::GameObject* const pOwner, MapComponent* const pMapComponent);

	virtual Component* Clone(Integrian2D::GameObject* const pOwner) noexcept override;

	virtual void Start() override;

	virtual void Update() override;

	/* [TODO] Implement actual texture */
	virtual void Render() const override;

private:
	MapComponent* m_pMapComponent;
};