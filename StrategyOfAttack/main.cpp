#include <iostream>

#include <Core/Core.h>
#include <SceneManager/SceneManager.h>

#include "Scenes/MainLevel/MainLevel.h"

int main()
{
    using namespace Integrian2D;

    Core* pEngine{ Core::CreateEngine(1080, 720, "StrategyOfAttack") };

    SceneManager::GetInstance()->AddScene(new MainLevel{ "MainLevel" });

    pEngine->Run();

    pEngine->Cleanup();

    return 0;
}