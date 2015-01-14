#include "StdAfx.h"
#include "cAction.h"



cAction::cAction()
	: m_fActionTime(0.0f)
	, m_fPassedTime(0.0f)
	, m_pOwner(NULL)
	, m_pDelegate(NULL)
{

}

cAction::~cAction()
{

}
