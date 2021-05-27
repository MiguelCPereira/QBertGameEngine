#pragma once
#include <memory>
#include <vector>

class Disk;
const int g_NrRows = 7;
const float g_CubesActualWidth = 64.f;
const float g_CubesActualHeight = 64.f;
const int g_EnemiesLeftSpawnPosX = 284;
const float g_EnemiesRightSpawnPosX = 349;
const float g_EnemiesSpawnPosY = 110;
const float g_MapCenterX = 332.f;
const float g_DiskTopRowY = 40;
const auto g_InitialQbertPosY = 60.f;

class QBert;

namespace dae
{
	class GameObject;
}

std::vector<std::shared_ptr<dae::GameObject>> MakeQBert();

std::shared_ptr<dae::GameObject> MakeCoily(QBert* qBertComp, bool isLeft, float  moveInterval);

std::shared_ptr<dae::GameObject> MakeSlickSam(bool isSlick, bool isLeft, float  moveInterval);

std::shared_ptr<dae::GameObject> MakeUggWrongway(bool isUgg, bool isLeft, float  moveInterval);

std::shared_ptr<dae::GameObject> MakeLevelTitle(int lvlNr);

std::shared_ptr<dae::GameObject> MakeVictoryTitle();

std::shared_ptr<dae::GameObject> MakeLevelTransition(QBert* qBertComp);

std::shared_ptr<dae::GameObject> MakeFPSCounter();

std::shared_ptr<dae::GameObject> MakeHeartForDisplay(bool playerOne, float posY);

std::shared_ptr<dae::GameObject> MakeScoreDisplay(bool playerOne);

std::shared_ptr<dae::GameObject> MakeLevelDisplay(bool coOpOn); // This is used to make the actual RoundLevelDisplay

std::shared_ptr<dae::GameObject> MakeRoundDisplay(bool coOpOn); // This is used to make the actual RoundLevelDisplay

std::shared_ptr<dae::GameObject> MakeRoundLevelDisplayGO(QBert* qBertComp, bool coOpOn);

std::shared_ptr<dae::GameObject> MakeDiskGO(int row, bool isLeft);

std::vector<std::shared_ptr<dae::GameObject>>* MakeDiskGOsVector(int level);
