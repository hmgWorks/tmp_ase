#include "StdAfx.h"
#include "cObject.h"


cObject::cObject(void)
	: m_nRefCount(1)
{
	g_pObjectManager->AddObject(this);
}

cObject::cObject( std::string& sDesc )
	: m_nRefCount(1)
{
	m_sDesc = sDesc;
	g_pObjectManager->AddObject(this);
}


cObject::~cObject(void)
{
	assert(m_nRefCount <= 0);
	g_pObjectManager->RemoveObject(this);
}
