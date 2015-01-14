#pragma once

class cTeapot : public cGameObject
{
protected:
	LPD3DXMESH		m_pMesh;
	D3DMATERIAL9	m_stMtl;

public:
	cTeapot(void);
	~cTeapot(void);
	void Setup(D3DXCOLOR c);
	void Render();
};

