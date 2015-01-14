#pragma once
#include "cAction.h"

class cActionRepeat : public cAction, iActionDelegate
{
protected:
	cAction* m_pAction;

public:
	cActionRepeat(void);
	virtual ~cActionRepeat(void);

	virtual void SetAction(cAction* pAction);
	// cAction override
	virtual void Start() override;
	virtual void Update() override;

	// iActionDelegate override
	virtual void OnActionFinish(cAction* pSender) override;
};

