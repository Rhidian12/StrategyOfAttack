#include "PlayerComponent.h"

#include "../MapComponent/MapComponent.h"

#include <GameObject/GameObject.h>
#include <Components/TransformComponent/TransformComponent.h>
#include <Input/InputManager/InputManager.h>
/* [TODO] Get rid of this include when Texture is added */
#include <Renderer/Renderer.h>

PlayerComponent::PlayerComponent(Integrian2D::GameObject* const pOwner, MapComponent* const pMapComponent)
	: Component{ pOwner }
	, m_pMapComponent{ pMapComponent }
{}

Integrian2D::Component* PlayerComponent::Clone(Integrian2D::GameObject* const pOwner) noexcept
{
	return new PlayerComponent{ pOwner, static_cast<MapComponent*>(m_pMapComponent->Clone(pOwner)) };
}

void PlayerComponent::Start()
{
	using namespace Integrian2D;

	InputManager* const pInputManager{ InputManager::GetInstance() };

	pInputManager->AddAxis(InputAxis{ "VerticalMovement", GameInput{ KeyboardInput::W }, GameInput{ KeyboardInput::S } });
	pInputManager->AddAxis(InputAxis{ "HorizontalMovement", GameInput{ KeyboardInput::D }, GameInput{ KeyboardInput::A } });

	const Point2f& pos{ m_pOwner->pTransform->GetWorldPosition() };
	m_pOwner->pTransform->SetPosition(Point2f{ pos.x + m_pMapComponent->GetTileWidth() / 2.f - 10.f,
		pos.y + m_pMapComponent->GetTileHeight() / 2.f - 10.f });
}

void PlayerComponent::Update()
{
	using namespace Integrian2D;

	InputManager* const pInputManager{ InputManager::GetInstance() };

	if (const int8_t value{ pInputManager->GetAxis("VerticalMovement") }; value != 0)
	{
		if (value == 1)
		{
			if (m_pMapComponent->IsMovementLegal(m_pMapComponent->GetTileIndex(m_pOwner->pTransform->GetWorldPosition()), PlayerDirection::Up))
				m_pOwner->pTransform->SetPosition(Point2f{ m_pOwner->pTransform->GetWorldPosition() + Point2f{ 0.f, value * m_pMapComponent->GetTileHeight() } });
		}
		else /* it's either 1 or -1 */
		{
			if (m_pMapComponent->IsMovementLegal(m_pMapComponent->GetTileIndex(m_pOwner->pTransform->GetWorldPosition()), PlayerDirection::Down))
				m_pOwner->pTransform->SetPosition(Point2f{ m_pOwner->pTransform->GetWorldPosition() + Point2f{ 0.f, value * m_pMapComponent->GetTileHeight() } });
		}
	}

	if (const int8_t value{ pInputManager->GetAxis("HorizontalMovement") }; value != 0)
	{
		if (value == 1)
		{
			if (m_pMapComponent->IsMovementLegal(m_pMapComponent->GetTileIndex(m_pOwner->pTransform->GetWorldPosition()), PlayerDirection::Right))
				m_pOwner->pTransform->SetPosition(Point2f{ m_pOwner->pTransform->GetWorldPosition() + Point2f{ value * m_pMapComponent->GetTileWidth(), 0.f  } });
		}
		else /* it's either 1 or -1 */
		{
			if (m_pMapComponent->IsMovementLegal(m_pMapComponent->GetTileIndex(m_pOwner->pTransform->GetWorldPosition()), PlayerDirection::Left))
				m_pOwner->pTransform->SetPosition(Point2f{ m_pOwner->pTransform->GetWorldPosition() + Point2f{ value * m_pMapComponent->GetTileWidth(), 0.f  } });
		}
	}
}

void PlayerComponent::Render() const
{
	Integrian2D::Renderer::GetInstance()->RenderFilledRectangle(Integrian2D::Rectf{ m_pOwner->pTransform->GetWorldPosition(), 20.f, 20.f });
}
