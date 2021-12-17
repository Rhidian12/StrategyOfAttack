#include <iostream>

#include <Core/Core.h>
#include <SceneManager/SceneManager.h>

#include "TestScene.h"

int main()
{
    Integrian2D::Core* pEngine{ Integrian2D::Core::CreateEngine(640, 480, "StrategyOfAttack") };

    Integrian2D::SceneManager::GetInstance()->AddScene(new TestScene{ "TestScene" });

    pEngine->Run();

    pEngine->Cleanup();

    return 0;
}