#include "StdAfx.h"
#include "cTransform.h"


cTransform::cTransform(void)
	: m_vPosition(0, 0, 0)
{
	D3DXMatrixIdentity(&m_matTransform);
}


cTransform::~cTransform(void)
{
}
