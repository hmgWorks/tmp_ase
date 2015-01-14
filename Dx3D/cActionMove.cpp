#include "StdAfx.h"
#include "cActionMove.h"
#include "cTransform.h"

cActionMove::cActionMove(void)
{
}


cActionMove::~cActionMove(void)
{
}

void cActionMove::Start()
{
	m_fPassedTime = 0.0f;
	if (m_pOwner)
	{
		cTransform* pTransform = m_pOwner->GetTransform();
		pTransform->SetPosition(m_vFrom);
	}
}

void cActionMove::Update()
{
	m_fPassedTime += g_pTimeManager->GetDeltaTime();

	float t = m_fPassedTime / m_fActionTime;
	if(t < 1.0f)
	{
		D3DXVECTOR3 v;
		//p = (1 - t) * p0 + t * p1
		D3DXVec3Lerp(&v, &m_vFrom, &m_vTo, t);
		cTransform* pTransform = m_pOwner->GetTransform();
		pTransform->SetPosition(v);
	}
	else
	{
		cTransform* pTransform = m_pOwner->GetTransform();
		pTransform->SetPosition(m_vTo);
		if(m_pDelegate)
			m_pDelegate->OnActionFinish(this);
	}
}
