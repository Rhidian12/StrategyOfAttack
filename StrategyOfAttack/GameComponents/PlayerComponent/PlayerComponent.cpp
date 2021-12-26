#include "PlayerComponent.h"

#include <GameObject/GameObject.h>
#include <Components/TransformComponent/TransformComponent.h>
#include <Input/InputManager/InputManager.h>

PlayerComponent::PlayerComponent(Integrian2D::GameObject* const pOwner)
	: Component{ pOwner }
{}

Integrian2D::Component* PlayerComponent::Clone(Integrian2D::GameObject* const pOwner) noexcept
{
	return new PlayerComponent{ pOwner };
}

void PlayerComponent::Start()
{
	using namespace Integrian2D;

	InputManager* const pInputManager{ InputManager::GetInstance() };

	pInputManager->AddAxis(InputAxis{ "VerticalMovement", GameInput{ KeyboardInput::W }, GameInput{ KeyboardInput::S } });
	pInputManager->AddAxis(InputAxis{ "HorizontalMovement", GameInput{ KeyboardInput::D }, GameInput{ KeyboardInput::A } });
}

void PlayerComponent::Update()
{
	using namespace Integrian2D;

	InputManager* const pInputManager{ InputManager::GetInstance() };

	if (const int8_t value{ pInputManager->GetAxis("VerticalMovement") }; value != 0)
		m_pOwner->pTransform->Translate(Vector2f{ 0.f, value * 50.f });

	if (const int8_t value{ pInputManager->GetAxis("HorizontalMovement") }; value != 0)
		m_pOwner->pTransform->Translate(Vector2f{ value * 50.f, 0.f });
}