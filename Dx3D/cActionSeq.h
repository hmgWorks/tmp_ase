#pragma once
#include "cAction.h"

class cActionSeq : public cAction, iActionDelegate
{
protected:
	std::list<cAction*>				m_lstAction;
	std::list<cAction*>::iterator	m_itCurrAction;

public:
	cActionSeq(void);
	virtual ~cActionSeq(void);

	virtual void AddAction(cAction* pAction);

	// cAction override
	virtual void Start() override;
	virtual void Update() override;

	// iActionDelegate override
	virtual void OnActionFinish(cAction* pSender) override;
};

