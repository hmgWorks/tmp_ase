#pragma once
class cAnimation
	:public cObject
{
	//
	D3DXMATRIXA16	m_matCurrentPos;
	D3DXMATRIXA16	m_matCurrentRot;
	D3DXMATRIXA16	m_matWorldTM;
	
	D3DXMATRIXA16	m_matPervLocal;
	
	std::map<int, D3DXVECTOR3>		m_mapControlPos;
	std::map<int, D3DXQUATERNION>	m_mapControlRot;
	std::vector<int>				m_vecIndex;

	D3DXMATRIXA16	m_matFromPos;
	D3DXMATRIXA16	m_matToPos;

	D3DXMATRIXA16	m_matFromRot;
	D3DXMATRIXA16	m_matToRot;
	
	//time
	float tmptime;
	float			m_fOldTime, m_fCurrentTime, m_fPassTime;
	int				m_nIndex_a, m_nIndex_b;

public:
	cAnimation();
	~cAnimation();

	void AddPos(int key, float x, float z, float y);
	void AddRot(int key, float x, float z, float y, float w);
	void Setup(D3DXMATRIXA16& matLocla);
	D3DXMATRIXA16& Update();
};

