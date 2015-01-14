#pragma once
#include "cMtlTex.h"

//class cMtlTex;

class cGroup
{
private:
	/*cMtlTex*				m_pMtlTex;*/
	SYNTHESIZE_ADD_REF(cMtlTex*, m_pMtlTex, MtlTex);
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	int						m_nNumTri;
public:
	//std::vector<ST_PNT_VERTEX> m_vecVertex;

public:
	cGroup(void);
	~cGroup(void);
	/*void SetMtlTex(cMtlTex* pMtlTex);*/
	void Render();
	void BuildVB(std::vector<ST_PNT_VERTEX>& vecVertex);

};

