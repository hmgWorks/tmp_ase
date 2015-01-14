#include "StdAfx.h"
#include "cGameObject.h"
#include "cTransform.h"
#include "cAction.h"

cGameObject::cGameObject(void)
	: m_pAction(NULL)
	, m_vPrevPosition(0, 0, 0)
	, m_fAngle(0.0f)
{
	m_pTransform = new cTransform;
}


cGameObject::~cGameObject(void)
{
	SAFE_RELEASE(m_pTransform);
	SAFE_RELEASE(m_pAction);
}

void cGameObject::Update()
{
	if(m_pAction)
	{
		m_vPrevPosition = m_pTransform->GetPosition();
		m_pAction->Update();
		D3DXVECTOR3 vCurrPosition = m_pTransform->GetPosition();
		D3DXVECTOR3 vDeltaPosition = vCurrPosition - m_vPrevPosition;
		if(fabs(vDeltaPosition.x) > 0.0001f)
		{
			m_fAngle = -atan2(vDeltaPosition.z, vDeltaPosition.x);
		}
	}
}

cTransform* cGameObject::GetTransform()
{
	return m_pTransform;
}

D3DXMATRIXA16* cGameObject::GetTransformMatrix()
{
	return m_pTransform->GetTransformMatrix();
}

void cGameObject::SetAction( cAction* pAction )
{
	if (m_pAction != pAction) 
	{
		pAction->SetOwner(this);

		SAFE_ADD_REF(pAction);
		SAFE_RELEASE(m_pAction);
		m_pAction = pAction;
	}
}
