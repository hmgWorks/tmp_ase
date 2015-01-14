#pragma once
class cAnimation
	:public cObject
{
	//
	D3DXMATRIXA16	m_matCurrentPos;
	D3DXMATRIXA16	m_matCurrentRot;
	
	D3DXMATRIXA16	m_matPervLocal;
	
	std::map<int, D3DXMATRIXA16>	m_mapControlPos;
	std::map<int, D3DXQUATERNION>	m_mapControlRot;

public:
	cAnimation();
	~cAnimation();

	void AddPos(int key, float x, float z, float y);
	void AddRot(int key, float x, float z, float y, float w);
	void Setup(D3DXMATRIXA16& matLocla);
	void Update();
};

