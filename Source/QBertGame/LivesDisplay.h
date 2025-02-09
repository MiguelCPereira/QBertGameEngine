#pragma once
#include <vector>
#include "BaseComponent.h"
#include "Observer.h"

class QBert;

namespace dae
{
	class GraphicsComponent;
}

class LivesDisplay final : public dae::BaseComponent, public dae::Observer
{
public:
	explicit LivesDisplay(QBert* qBertComp, std::vector<dae::GraphicsComponent*>* heartGraphics);
	~LivesDisplay() override;

	LivesDisplay(const LivesDisplay& other) = delete;
	LivesDisplay(LivesDisplay&& other) noexcept = delete;
	LivesDisplay& operator=(const LivesDisplay& other) = delete;
	LivesDisplay& operator=(LivesDisplay&& other) noexcept = delete;

	void SetQBert(QBert* qBertComp);
	
	void Initialize() override;
	void Update(const float deltaTime) override;
	void OnNotify(const dae::Event& event) override;

private:
	QBert* m_QBertComp;
	std::vector<dae::GraphicsComponent*>* m_Graphics;
};

