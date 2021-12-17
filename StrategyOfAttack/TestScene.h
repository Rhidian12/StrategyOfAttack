#pragma once

#include <Scene/Scene.h>
#include <GameObject/GameObject.h>
#include <Texture/Texture.h>
#include <TextureManager/TextureManager.h>
#include <Components/TextureComponent/TextureComponent.h> 

#include <string>

class TestScene final : public Integrian2D::Scene
{
public:
	TestScene(const std::string& name)
		: Scene{ name.c_str() }
		, m_pGameObject{ new Integrian2D::GameObject{} }
	{}

	virtual void Start() override
	{
		using namespace Integrian2D;

		TextureManager::GetInstance()->AddTexture("Michael", new Texture{ "Resources/Michael_SoyakPoint2.png" });

		m_pGameObject->AddComponent(new TextureComponent{ m_pGameObject, TextureManager::GetInstance()->GetTexture("Michael") });

		AddGameObject("Michael", m_pGameObject);
	}

private:
	Integrian2D::GameObject* m_pGameObject;
};