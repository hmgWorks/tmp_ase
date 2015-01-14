#pragma once

class cWayPoint : public cGameObject
{
protected:
	LPD3DXMESH		m_pMesh;
	D3DMATERIAL9	m_stMtl;
public:
	cWayPoint(void);
	virtual ~cWayPoint(void);

	void Setup(float fAngle, float fRadius);
	void Render();
};

