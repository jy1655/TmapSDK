// EnvSet.h

// �ۼ��� : ������
// �ۼ��� : 2008.02.04
// ��  �� :

#ifndef __ENVSET_H
#define __ENVSET_H

class CEnvSet
{
//	NOT_INSTANCE(CEnvSet)
	NOT_COPYABLE(CEnvSet)
private:
	CEnvSet() {};
	~CEnvSet() {};

public :
	CPathEnv& GetPathEnv() { return m_pathEnv; }

private :
	CPathEnv		m_pathEnv;

	DECLARE_SINGLETON(CEnvSet);

};

#endif // __ENVSET_H

