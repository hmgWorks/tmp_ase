#include "StdAfx.h"
#include "cActionRepeat.h"


cActionRepeat::cActionRepeat(void)
	: m_pAction(NULL)
{
}


cActionRepeat::~cActionRepeat(void)
{
	SAFE_RELEASE(m_pAction);
}

void cActionRepeat::SetAction( cAction* pAction )
{
	if (m_pAction != pAction) 
	{
		pAction->SetDelegate(this);

		SAFE_ADD_REF(pAction);
		SAFE_RELEASE(m_pAction);
		m_pAction = pAction;
	}
}

void cActionRepeat::Start()
{
	if(m_pAction)
		m_pAction->Start();
}

void cActionRepeat::Update()
{
	if (m_pAction)
		m_pAction->Update();
}

void cActionRepeat::OnActionFinish( cAction* pSender )
{
	pSender->Start();
}
