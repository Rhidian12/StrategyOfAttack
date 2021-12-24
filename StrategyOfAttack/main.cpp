#include <iostream>

#include <Core/Core.h>
#include <SceneManager/SceneManager.h>

#include "TestScene.h"

int main()
{
    using namespace Integrian2D;

    Core* pEngine{ Core::CreateEngine(1080, 720, "StrategyOfAttack") };

    SceneManager::GetInstance()->AddScene(new TestScene{ "TestScene" });

    pEngine->Run();

    pEngine->Cleanup();

    return 0;
}