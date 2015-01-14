#include "StdAfx.h"
#include "cWayPoint.h"


cWayPoint::cWayPoint(void)
	: m_pMesh(NULL)
{
}


cWayPoint::~cWayPoint(void)
{
	SAFE_RELEASE(m_pMesh);
}

void cWayPoint::Setup( float fAngle, float fRadius )
{
	D3DXCreateSphere(g_pD3DDevice, 0.1f, 10, 10, &m_pMesh, NULL);

	D3DXVECTOR3 v(0, 0, 0);
	v.x = cosf(fAngle) * fRadius;
	v.z = sinf(fAngle) * fRadius;
	m_pTransform->SetPosition(v);

	ZeroMemory(&m_stMtl, sizeof(m_stMtl));

	m_stMtl.Ambient = D3DXCOLOR(1, 0, 0, 1);
	m_stMtl.Diffuse = D3DXCOLOR(1, 0, 0, 1);
	m_stMtl.Specular = D3DXCOLOR(1, 0, 0, 1);
}

void cWayPoint::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, GetTransformMatrix());
	g_pD3DDevice->SetMaterial(&m_stMtl);
	g_pD3DDevice->SetTexture(0, NULL);
	m_pMesh->DrawSubset(0);
}
