#pragma once

#include <Components/Component/Component.h>

class PlayerComponent final : public Integrian2D::Component
{
public:
	PlayerComponent(Integrian2D::GameObject* const pOwner);

	virtual Component* Clone(Integrian2D::GameObject* const pOwner) noexcept override;

	virtual void Start() override;

	virtual void Update() override;

private:
};