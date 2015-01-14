#pragma once
#include "cAction.h"
#include "cTransform.h"

class cGameObject : public cObject
{
protected:
	cTransform* m_pTransform;
	D3DXVECTOR3	m_vPrevPosition;
	float		m_fAngle;

	/*SYNTHESIZE_ADD_REF(cAction*, m_pAction, Action);*/
	cAction* m_pAction;
public:
	cGameObject(void);
	virtual ~cGameObject(void);

	virtual void Update();
	virtual cTransform* GetTransform();
	virtual D3DXMATRIXA16* GetTransformMatrix();
	virtual void SetAction(cAction* pAction);
};

