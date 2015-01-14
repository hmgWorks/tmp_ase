#include "stdafx.h"
#include "cAnimation.h"


cAnimation::cAnimation()
{
	D3DXMatrixIdentity(&m_matCurrentPos);
	D3DXMatrixIdentity(&m_matCurrentRot);
}

cAnimation::~cAnimation()
{
}

void cAnimation::Setup(D3DXMATRIXA16& matLocla)
{
	m_matPervLocal = matLocla;
}

void cAnimation::AddPos(int key, float x, float z, float y)
{
	D3DXMatrixTranslation(&m_mapControlPos[key], x, y, z);
}

void cAnimation::AddRot(int key, float x, float y, float z, float w)
{	
	float fQx = x *sinf(w / 2);
	float fQy = y *sinf(w / 2);
	float fQz = z *sinf(w / 2);
	float fQw = cosf(w / 2);

	auto check = [&](float qx, float qz, float qy, float qw)->D3DXQUATERNION
	{
		if (m_mapControlRot.find(2560) != m_mapControlRot.end())
		{
			return m_mapControlRot.find(2560)->second * D3DXQUATERNION(qx, qy, qz, qw);
		}
		else if (m_mapControlRot.find(1920) != m_mapControlRot.end())
		{
			return m_mapControlRot.find(1920)->second * D3DXQUATERNION(qx, qy, qz, qw);
		}
		else if (m_mapControlRot.find(1280) != m_mapControlRot.end())
		{
			return m_mapControlRot.find(1280)->second * D3DXQUATERNION(qx, qy, qz, qw);
		}
		else if (m_mapControlRot.find(640) != m_mapControlRot.end())
		{
			return m_mapControlRot.find(640)->second * D3DXQUATERNION(qx, qy, qz, qw);
		}
		else
		{
			return D3DXQUATERNION(qx, qy, qz, qw);
		}
	};
	//보간을 쿼터니온 으로 하는듯 하니 메트릭스로 변환 하는건 나중으로 미뤄둠.
	m_mapControlRot[key] = check(fQx, fQy, fQz, fQw);
	int n = 0;
}

void cAnimation::Update()
{
	//from = 640;
	//to = 1280;
	//t = deltatime / (1280 - 640);
	//if (t < 1.0f)
	//{
	//	//에니메이션 진행
	//	D3DXVec3Lerp(&oup, &in, t);
	//	

	//}

//	return m_matCurrentRot * m_matCurrentPos;
	
}
