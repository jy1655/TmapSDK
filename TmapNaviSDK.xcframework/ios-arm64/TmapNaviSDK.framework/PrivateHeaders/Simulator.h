//////////////////////////////////////////////////////////////////////////
// Simulator.h

#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

enum NeSimulMoveType
{
	MOVETYPE_NORMAL = 0,
	MOVETYPE_GOSTART,
	MOVETYPE_GOEND,
	MOVETYPE_GOGP,
	MOVETYPE_NEXTGP,
	MOVETYPE_PRVGP,
	MOVETYPE_POS,
	MOVETYPE_PROGRESS,
	MOVETYPE_PAUSE,	
	Num_Of_SimulMoveType
};

enum NeSimulPosType
{
	POSTYPE_NORMAL = 0,
	POSTYPE_START,
	POSTYPE_END,
	Num_of_SimulPosType
};

typedef struct stSimulateResult
{
	UInt32 		nMMLinkIndex;
	UInt32 		nMMLengthToEnd;
	UInt32 		nMMAngle;
	Int32		idxVertex;		//wp�� n-1 �� n ��° Vertex�� �����Ұ�� n	(����ġ ���濡 �ִ� Index)
	DOUBLE_VERTEX	wptMM;

	NeSimulPosType	ePosType;
} SIMULATERESULT;

class CSimulator
{
public:
	CSimulator();
	virtual ~CSimulator();

	Bool	Initialize();
	void	UnInitialize();

	Bool	InitStartSimulator();
	void	ResetData();

	Bool	MakeRouteVertexData();
	void	SetMoveSpeed(Int32 nSpeed);

	Bool	GetSimulateMatchInfo(NeSimulMoveType eMoveType, SIMULATERESULT *pstSimulResult, Int32 nIndex = -1/*GP Index or ��������� �Ÿ�*/);
	Bool	GoStartPosition();
	Bool	GoEndPosition();
	Bool	NextGPPosition();
	Bool	PrvGPPosition();
	Bool	GoGPPosition(Int32 nGPIndex);
	Bool	MovePosition(Int32 nDist);
	
	Int32	GetSpeed() {return m_nMoveSpeed;};

	Int32	GetPrvVertexIndex() { return m_nPrvVertexIndex;};
	Int32	GetCurrentVertexIndex() { return m_nVertexIndex;};

protected:
	Int32	GetGPIndex(Int32 nLinkIndex, Int32 nLengthToEnd);
	Int32	GetLinkIndex(Int32 nVertexIndex);
	Bool	GetMatchPoint(DOUBLE_VERTEX * pVertex, Float m, Float n, DOUBLE_VERTEX wpt1, DOUBLE_VERTEX wpt2);

	Bool	UpdateCurrentMMData();
	Int32	GetLengthToEnd(Int32 nLinkIndex, Int32 nVertexIndex);
	Int32	GetCurentMMAngle();


protected:
	stGatheringData	*		m_pRGGatherData;
	stRoutePosDetailInfo *	m_pRGPosData;

	Int32					m_nLinkIndex;			// ���� ��ũ�� Index
	Int32					m_nPrvVertexIndex;			// n-1 �� n ��° �����Ұ�� n	(����ġ ���濡 �ִ� Index)
	Int32					m_nVertexIndex;			// n-1 �� n ��° �����Ұ�� n	(����ġ ���濡 �ִ� Index)
	Int32					m_nGPIndex;				// n-1 �� n ��° �����Ұ�� n	(����ġ ���濡 �ִ� GP Index : ���� �ȳ� �ؾ� �Ǵ� GP)
	DOUBLE_VERTEX				m_wptMM;				// ���� ��Ī�� ��ǥ.
	Int32					m_nLengthToEnd;			// ���� ��ġ(m_wptMM)���� ���� ��ũ�� �������� �Ÿ�

	NeSimulPosType			m_ePosType;

	SIMULATERESULT			m_stSimulResult;
	
	Int32					m_nMoveSpeed;			// �������� �ӵ�
	Int32					m_nMoveDist;			// �������� 1ȸ �̵� �Ÿ�

	Int32					m_nStartVertexIndex;
	Int32					m_nEndVertexIndex;
};

#endif // _SIMULATOR_H_