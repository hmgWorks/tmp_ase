#include "StdAfx.h"
#include "cActionSeq.h"


cActionSeq::cActionSeq(void)
{
}


cActionSeq::~cActionSeq(void)
{
	for each(auto p in m_lstAction)
	{
		SAFE_RELEASE(p);
	}
}

void cActionSeq::AddAction( cAction* pAction )
{
	if(pAction)
	{
		pAction->SetDelegate(this);
		pAction->AddRef();
		m_lstAction.push_back(pAction);
	}
}

void cActionSeq::Start()
{
	m_itCurrAction = m_lstAction.begin();
	if(*m_itCurrAction)
		(*m_itCurrAction)->Start();
}

void cActionSeq::Update()
{
	if(*m_itCurrAction)
		(*m_itCurrAction)->Update();
}

void cActionSeq::OnActionFinish( cAction* pSender )
{
	++m_itCurrAction;
	if(m_itCurrAction == m_lstAction.end())
	{
		if(m_pDelegate)
			m_pDelegate->OnActionFinish(this);
	}
	else
	{
		(*m_itCurrAction)->Start();
	}
}

