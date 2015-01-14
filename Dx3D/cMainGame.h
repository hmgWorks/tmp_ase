#pragma once

class cCube;
class cGrid;
class cCamera;
class cCubeMan;
class cGroup;
class iMap;
class cIndexCube;
class cMtlTex;
class cFrame;
class cTeapot;
class cWayPoint;

class cMainGame : public cObject, iActionDelegate
{
private:
	cGrid*					m_pGrid;
	cCamera*				m_pCamera;
	cCubeMan*				m_pCubeMan;
	iMap*					m_pMap;
	cIndexCube*				m_pIndexCube;
	cFrame*					m_pAseRoot;
	cTeapot*				m_pTeapot;
	LPD3DXFONT				m_pFont;
	std::vector<cGroup*>	m_vecGroup;
	LPD3DXMESH				m_pMesh;
	std::vector<cMtlTex*>	m_vecMtlTex;
	std::vector<cWayPoint*>	m_vecWayPoint;

public:
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void OnActionFinish(cAction* pSender);
};

