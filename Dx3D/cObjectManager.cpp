#include "StdAfx.h"
#include "cObjectManager.h"


cObjectManager::cObjectManager(void)
{
}


cObjectManager::~cObjectManager(void)
{
}

void cObjectManager::AddObject( cObject* pObject )
{
	m_setObject.insert(pObject);
}

void cObjectManager::RemoveObject( cObject* pObject )
{
	m_setObject.erase(pObject);
}

void cObjectManager::Destroy()
{
	if(!m_setObject.empty())
	{
		for each(cObject* p in m_setObject)
		{
			OutputDebugString(p->GetDesc().c_str());
		}
		
		assert(false && "������ cObject�� �������� ���� ������Ʈ�� �ֽ��ϴ�.");
	}
}
