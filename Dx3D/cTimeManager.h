#pragma once

#define g_pTimeManager cTimeManager::GetInstance()

class cTimeManager
{
private:
	DWORD m_dwLastUpdateTime;
	DWORD m_dwDeltaTime;
	SINGLETONE(cTimeManager);
	
public:
	void Update();
	float GetDeltaTime()
	{
		return m_dwDeltaTime / 1000.f;
	}
};

