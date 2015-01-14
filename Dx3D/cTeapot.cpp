#include "StdAfx.h"
#include "cTeapot.h"


cTeapot::cTeapot(void)
{
	D3DXCreateTeapot(g_pD3DDevice, &m_pMesh, NULL);
	ZeroMemory(&m_stMtl, sizeof(m_stMtl));
}


cTeapot::~cTeapot(void)
{
	SAFE_RELEASE(m_pMesh);
}

void cTeapot::Setup( D3DXCOLOR c )
{
	m_stMtl.Ambient = c;
	m_stMtl.Diffuse = c;
	m_stMtl.Specular = c;
}

void cTeapot::Render()
{
	D3DXMATRIXA16 matR, matT;
	matT = *GetTransformMatrix();
	D3DXMatrixRotationY(&matR, m_fAngle);
	D3DXMATRIXA16 matWorld = matR * matT;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetMaterial(&m_stMtl);
	g_pD3DDevice->SetTexture(0, NULL);
	m_pMesh->DrawSubset(0);
}
