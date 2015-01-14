#pragma once
class cObject
{
protected:
	int m_nRefCount;
	std::string m_sDesc;
public:
	cObject(void);
	cObject(std::string& sDesc);
	virtual ~cObject(void);

	virtual void AddRef()
	{
		assert(m_nRefCount > 0);
		m_nRefCount++;
	}

	virtual void Release()
	{
		assert(m_nRefCount > 0);
		m_nRefCount--;
		if (m_nRefCount <= 0)
		{
			delete this;
		}
	}

	virtual void SetDesc(std::string& s)
	{
		m_sDesc = s;
	}

	virtual std::string GetDesc()
	{
		return m_sDesc;
	}
};

