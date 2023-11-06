/** \file maptype.h 
 * \brief Tile Identity Data Type
 *
 * ������ 8 8 4 8 8 4�� �ڸ� tile�� ����Ѵ�.
 *	top(�������� X) - [256�� x 256��]�� �����Ѵ�.
 *	level 6 - 32�� ���� [8 x 8]
 *	level 5 - 4 �� ���� [64 x 64]
 *	level 4 - 1 �� ���� [256 x 256]
 *	level 3 - 1/8 �� ���� [(256 x 8) x (256 x 8)]
 *	level 2 - 1/64 �� ���� [(256 x 64) x (256 x 64)]
 *	level 1 - 1/256 �� ���� [(256 x 256) x (256 x 256)]
 * Global�� ��ǥ�� level 1�� �� tile�� 2048�� ������ ������ �⺻������ ����Ѵ�.
 *	�⺻���� - 1 / (256 x 2048) ��
 */

#ifndef _MAPTYPE_H_
#define _MAPTYPE_H_

///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
#include "sgl_inc.h"

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


///���� : ������ ������ ������ ��Ȳ������ tile�� �ĺ���
class NcTileID {
public:
    NcTileID();
    NcTileID(Int8 mlevel, const DOUBLE_VERTEX& mapidx);

#ifdef USEINLINE
    inline bool operator == (const NcTileID &);
    inline const NcTileID & operator = (const NcTileID &);
#else // ! USEINLINE
    bool operator == (const NcTileID &);
    const NcTileID & operator = (const NcTileID &);
#endif // USEINLINE    

public:
    Int8		m_mlevel;	// �� tile�� level
    DOUBLE_VERTEX	m_mapidx;	// �� tile�� index (m_level ����)
};

/// ���� : tiled map�� �ĺ���
class NcTileIdentity {
public:
    NcTileIdentity();
    NcTileIdentity(UInt8, const NcTileID&);
    NcTileIdentity(UInt8, Int8, const DOUBLE_VERTEX&);

    void init(UInt8, const NcTileID&);
    void init(UInt8, Int8, const DOUBLE_VERTEX&);

#ifdef USEINLINE
    inline bool operator == (const NcTileIdentity &);
    inline const NcTileIdentity & operator = (const NcTileIdentity &);
#else // ! USEINLINE
    bool operator == (const NcTileIdentity &);
    const NcTileIdentity & operator = (const NcTileIdentity &);
#endif // USEINLINE    
    
public:
    UInt8		m_mtype;	// ������ type
    NcTileID		m_id;
};

#ifdef USEINLINE
#include "tileiden.inl"
#endif // USEINLINE

#endif // _MAPTYPE_H_
