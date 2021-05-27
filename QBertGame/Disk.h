#pragma once
#include <memory>
#include "BaseComponent.h"

namespace dae
{
	class GraphicsComponent;
}

class QBert;

class Disk final : public dae::BaseComponent
{
public:
	explicit Disk(const std::shared_ptr<dae::GameObject>& gameObject, int rowIdx, bool isLeft,
		float finalPosX, float finalPosY, float finalQbertPosY);
	~Disk();

	Disk(const Disk& other) = delete;
	Disk(Disk&& other) noexcept = delete;
	Disk& operator=(const Disk& other) = delete;
	Disk& operator=(Disk&& other) noexcept = delete;

	void Activate(QBert* qBertComp, dae::GraphicsComponent* qBertGraphics);
	void GetDeleted() const;
	
	int GetRow() const { return m_RowIdx; }
	bool GetHasBeenUsed() const { return m_HasBeenUsed; }
	bool GetIsLeft() const{ return m_IsLeft; }
	
	void Update(const float deltaTime) override;

private:
	std::shared_ptr<dae::GameObject> m_GameObject{};
	QBert* m_QBertComp;
	dae::GraphicsComponent* m_QBertGraphics;
	const int m_RowIdx;
	const bool m_IsLeft;
	bool m_Activated;
	const float m_MovingSpeed;
	const float m_InitialPosX, m_InitialPosY;
	const float m_FinalPosX, m_FinalPosY, m_FinalQBertPosY;
	float m_MidFlightPosX, m_MidFlightPosY;
	float m_QBertGraphAdjustmentX, m_QBertGraphAdjustmentY;
	bool m_MovementXIncomplete, m_MovementYIncomplete;
	bool m_HasBeenUsed;
};
