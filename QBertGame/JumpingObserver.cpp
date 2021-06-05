#include "JumpingObserver.h"

#include "Coily.h"
#include "GraphicsComponent.h"
#include "QBert.h"
#include "SlickSam.h"
#include "UggWrongway.h"

JumpingObserver::JumpingObserver(QBert* qBertComp, dae::GraphicsComponent* graphicsComp, float cubesWidth, float cubesHeight)
	: m_QBertComp(qBertComp)
	, m_CoilyComp()
	, m_SlickSamComp()
	, m_UggWrongComp()
	, m_GraphicsComp(graphicsComp)
	, m_CubesWidth(cubesWidth)
	, m_CubesHeight(cubesHeight)
	, m_Jumping(false)
	, m_LiftoffPosX()
	, m_LiftoffPosY()
	, m_LandingPosX()
	, m_LandingPosY()
	, m_MidFlightPosX()
	, m_MidFlightPosY()
	, m_FPS(50)
	, m_JumpTime(0.3f)
	, m_MidFlightTime(0.f)
	, m_TimeSinceLastFrame(0.f)
	, m_Frozen(false)
{}

JumpingObserver::JumpingObserver(Coily* coilyComp, dae::GraphicsComponent* graphicsComp, float cubesWidth, float cubesHeight)
	: m_QBertComp()
	, m_CoilyComp(coilyComp)
	, m_SlickSamComp()
	, m_UggWrongComp()
	, m_GraphicsComp(graphicsComp)
	, m_CubesWidth(cubesWidth)
	, m_CubesHeight(cubesHeight)
	, m_Jumping(false)
	, m_LiftoffPosX()
	, m_LiftoffPosY()
	, m_LandingPosX()
	, m_LandingPosY()
	, m_MidFlightPosX()
	, m_MidFlightPosY()
	, m_FPS(50)
	, m_JumpTime(0.3f)
	, m_MidFlightTime(0.f)
	, m_TimeSinceLastFrame(0.f)
	, m_Frozen(false)
{}

JumpingObserver::JumpingObserver(SlickSam* slickSamComp, dae::GraphicsComponent* graphicsComp, float cubesWidth, float cubesHeight)
	: m_QBertComp()
	, m_CoilyComp()
	, m_SlickSamComp(slickSamComp)
	, m_UggWrongComp()
	, m_GraphicsComp(graphicsComp)
	, m_CubesWidth(cubesWidth)
	, m_CubesHeight(cubesHeight)
	, m_Jumping(false)
	, m_LiftoffPosX()
	, m_LiftoffPosY()
	, m_LandingPosX()
	, m_LandingPosY()
	, m_MidFlightPosX()
	, m_MidFlightPosY()
	, m_FPS(50)
	, m_JumpTime(0.3f)
	, m_MidFlightTime(0.f)
	, m_TimeSinceLastFrame(0.f)
	, m_Frozen(false)
{}

JumpingObserver::JumpingObserver(UggWrongway* uggWrongComp, dae::GraphicsComponent* graphicsComp, float cubesWidth, float cubesHeight)
	: m_QBertComp()
	, m_CoilyComp()
	, m_SlickSamComp()
	, m_UggWrongComp(uggWrongComp)
	, m_GraphicsComp(graphicsComp)
	, m_CubesWidth(cubesWidth)
	, m_CubesHeight(cubesHeight)
	, m_Jumping(false)
	, m_LiftoffPosX()
	, m_LiftoffPosY()
	, m_LandingPosX()
	, m_LandingPosY()
	, m_MidFlightPosX()
	, m_MidFlightPosY()
	, m_FPS(50)
	, m_JumpTime(0.3f)
	, m_MidFlightTime(0.f)
	, m_TimeSinceLastFrame(0.f)
	, m_Frozen(false)
{}

JumpingObserver::~JumpingObserver()
{
	if (m_QBertComp != nullptr)
		m_QBertComp->GetSubject()->RemoveObserver(this);

	if (m_CoilyComp != nullptr)
		m_CoilyComp->GetSubject()->RemoveObserver(this);

	if (m_SlickSamComp != nullptr)
		m_SlickSamComp->GetSubject()->RemoveObserver(this);

	if (m_UggWrongComp != nullptr)
		m_UggWrongComp->GetSubject()->RemoveObserver(this);

	m_GraphicsComp = nullptr;
}

void JumpingObserver::Initialize()
{
	if (m_QBertComp != nullptr)
		m_QBertComp->GetSubject()->AddObserver(this);
	
	if (m_CoilyComp != nullptr)
		m_CoilyComp->GetSubject()->AddObserver(this);

	if (m_SlickSamComp != nullptr)
		m_SlickSamComp->GetSubject()->AddObserver(this);

	if (m_UggWrongComp != nullptr)
		m_UggWrongComp->GetSubject()->AddObserver(this);
}

void JumpingObserver::SetQBert(QBert* qBertComp)
{
	if (m_QBertComp != nullptr)
		m_QBertComp->GetSubject()->RemoveObserver(this);

	m_QBertComp = qBertComp;

	if (m_QBertComp != nullptr)
		m_QBertComp->GetSubject()->AddObserver(this);
}

void JumpingObserver::SetCoily(Coily* coilyComp)
{
	if (m_CoilyComp != nullptr)
		m_CoilyComp->GetSubject()->RemoveObserver(this);

	m_CoilyComp = coilyComp;

	if (m_CoilyComp != nullptr)
		m_CoilyComp->GetSubject()->AddObserver(this);
}

void JumpingObserver::SetSlickSam(SlickSam* slickSamComp)
{
	if (m_SlickSamComp != nullptr)
		m_SlickSamComp->GetSubject()->RemoveObserver(this);

	m_SlickSamComp = slickSamComp;

	if (m_SlickSamComp != nullptr)
		m_SlickSamComp->GetSubject()->AddObserver(this);
}

void JumpingObserver::SetUggWrongway(UggWrongway* uggWrongComp)
{
	if (m_UggWrongComp != nullptr)
		m_UggWrongComp->GetSubject()->RemoveObserver(this);

	m_UggWrongComp = uggWrongComp;

	if (m_UggWrongComp != nullptr)
		m_UggWrongComp->GetSubject()->AddObserver(this);
}

void JumpingObserver::SetGraphics(dae::GraphicsComponent* graphicsComp)
{
	m_GraphicsComp = graphicsComp;
}

void JumpingObserver::OnNotify(const dae::Event& event)
{
	switch (event)
	{
	case dae::Event::EntityFrozen:
		m_Frozen = true;
		break;


	case dae::Event::EntityUnfrozen:
		m_Frozen = false;
		break;


	case dae::Event::EntityAnimationStopped:
		if (m_Jumping)
		{
			m_GraphicsComp->SetPosition(m_LiftoffPosX, m_LiftoffPosY);
			m_Jumping = false;
			m_MidFlightTime = 0.f;
		}
		break;

		
	case dae::Event::JumpUpRight:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX + m_CubesWidth / 2.f;
		m_LandingPosY = m_LiftoffPosY - m_CubesHeight * 0.75f;
		m_Jumping = true;
		break;


	case dae::Event::JumpUpLeft:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX - m_CubesWidth / 2.f;
		m_LandingPosY = m_LiftoffPosY - m_CubesHeight * 0.75f;
		m_Jumping = true;
		break;


	case dae::Event::JumpDownRight:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX + m_CubesWidth / 2.f;
		m_LandingPosY = m_LiftoffPosY + m_CubesHeight * 0.75f;
		m_Jumping = true;
		break;


	case dae::Event::JumpDownLeft:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX - m_CubesWidth / 2.f;
		m_LandingPosY = m_LiftoffPosY + m_CubesHeight * 0.75f;
		m_Jumping = true;
		break;


	case dae::Event::JumpLeft:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX - m_CubesWidth;
		m_LandingPosY = m_LiftoffPosY;
		m_Jumping = true;
		break;

		
	case dae::Event::JumpRight:
		m_LiftoffPosX = m_GraphicsComp->GetPosX();
		m_LiftoffPosY = m_GraphicsComp->GetPosY();
		m_MidFlightPosX = m_LiftoffPosX;
		m_MidFlightPosY = m_LiftoffPosY;
		m_LandingPosX = m_LiftoffPosX + m_CubesWidth;
		m_LandingPosY = m_LiftoffPosY;
		m_Jumping = true;
		break;
	}
}

void JumpingObserver::Update(const float deltaTime)
{
	if(m_Jumping == true && m_Frozen == false)
	{
		const auto toTravelInSecX = (m_LandingPosX - m_LiftoffPosX) / m_JumpTime;
		const auto toTravelInSecY = (m_LandingPosY - m_LiftoffPosY) / m_JumpTime;

		m_TimeSinceLastFrame += deltaTime;
		m_MidFlightTime += deltaTime;

		if (m_TimeSinceLastFrame >= 1.f / float(m_FPS) && m_MidFlightTime < m_JumpTime)
		{
			m_TimeSinceLastFrame -= 1.f / float(m_FPS);
			m_MidFlightPosX += toTravelInSecX / float(m_FPS);
			m_MidFlightPosY += toTravelInSecY / float(m_FPS);
		}

		
		// Actually move the graphics
		m_GraphicsComp->SetPosition(m_MidFlightPosX, m_MidFlightPosY);



		// Stop the animation if the movement is complete
		if (m_MidFlightTime >= m_JumpTime)
		{
			m_GraphicsComp->SetPosition(m_LandingPosX, m_LandingPosY);
			m_Jumping = false;
			m_MidFlightTime = 0.f;
			
			if (m_QBertComp != nullptr)
				m_QBertComp->JumpFinished();
			else if (m_CoilyComp != nullptr)
				m_CoilyComp->JumpFinished();
			else if (m_SlickSamComp != nullptr)
				m_SlickSamComp->JumpFinished();
			else if (m_UggWrongComp != nullptr)
				m_UggWrongComp->JumpFinished();
		}
	}
}







