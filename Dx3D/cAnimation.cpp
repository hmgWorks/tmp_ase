#include "stdafx.h"
#include "cAnimation.h"


cAnimation::cAnimation()
	:m_nIndex_a(0)
	, m_nIndex_b(1)
	, tmptime(640)
{
	D3DXMatrixIdentity(&m_matCurrentPos);
	D3DXMatrixIdentity(&m_matCurrentRot);
	D3DXMatrixIdentity(&m_matWorldTM);
	
	m_vecIndex = { 640, 1280, 1920, 2560, 3200 };
	m_fPassTime = 0.0f;
}

cAnimation::~cAnimation()
{
}

void cAnimation::Setup(D3DXMATRIXA16& matLocla)
{
	m_matPervLocal = matLocla;
	m_fOldTime = 640.0f;
	
}

void cAnimation::AddPos(int key, float x, float y, float z)
{
	//D3DXMatrixTranslation(&m_mapControlPos[key], x, y, z);
	m_mapControlPos[key] = D3DXVECTOR3(x, y, z);
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

D3DXMATRIXA16& cAnimation::Update()
{
	/*		
		640부터 3200까지의 에니메이션
		*아무것도 없을경우 가지고 있는 로컬
		*'640' 이없고 '1280' 부터 일경우 '1280'으로 640~1280까지

		640 += gettickcount()/ 1280  - 640 = t
		640
	*/	
	float tmp = 1280.0f - 640.0f;
	m_fCurrentTime = g_pTimeManager->GetDeltaTime() + 640.0f;
	m_fPassTime += m_fCurrentTime - m_fOldTime;
	m_fOldTime = m_fCurrentTime;
	float t = m_fPassTime / tmp;
	
	if (t < 1.0f)
	{
		if (m_mapControlPos.find(640) != m_mapControlPos.end() &&
			m_mapControlPos.find(1280) != m_mapControlPos.end())
		{
			D3DXVECTOR3 v;
			D3DXVec3Lerp(&v, &m_mapControlPos[640], &m_mapControlPos[1280], t);

			D3DXMatrixTranslation(&m_matCurrentPos, v.x, v.y, v.z);
		}
		else
		{
			m_matCurrentPos = m_matPervLocal;
		}
	}
	else
		m_fPassTime = 640.0f;
	
	return m_matCurrentPos;
	
}
