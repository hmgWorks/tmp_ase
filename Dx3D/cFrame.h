#pragma once

class cMtlTex;
class cAnimation;

class cFrame
{
	friend class cAseLoader;
private:
	std::string				m_sNodeName;
	std::string				m_sParentName;
	std::vector<cFrame*>	m_vecChildren;
	D3DXMATRIXA16			m_matLocalTM;
	D3DXMATRIXA16			m_matWorldTM;
	LPD3DXMESH				m_pMesh;
	cMtlTex*				m_pMtlTex;

	cAnimation*				m_pAnimation;

public:
	cFrame(void);
	~cFrame(void);

	void AddChild(cFrame* pChild);
	void CalcLocalTM(D3DXMATRIXA16* pParent);
	void BuidlMesh(std::vector<ST_PNT_VERTEX>& vecVertex);
	void SetMtlTex(cMtlTex* pMtlTex);
	void SetAni(cAnimation* pAni);
	cAnimation* GetAni(){ return m_pAnimation; }
	void Update(D3DXMATRIXA16* pmatParent);
	void Render();
	void Destroy();
};

