/******************************************************************
@Դ��������: DynBuffer.h
@�������Ȩ: �������ӹɷ����޹�˾ ��Ȩ����
@ϵͳ����: 
@ģ������: 
@����˵��: 
@����ĵ�: 
@����:     
@���: (��ѡ��)

@�޸ļ�¼
@�޸�����: 20130304
@�޸���Ա: ��ģ��
@�޸�˵��: ����
@�汾��   1.0

*******************************************************************/

#ifndef _H_DYNBUFFER_H_
#define _H_DYNBUFFER_H_
#include <iostream>
#include <string>

struct FastMsgInfo
{
	const char*  lpMsgData ;
	int          nMsgLen ;
	int          nDate ;
	int          nTimeStamp ;
	int          nSeqNum ;
	std::string      strMsgType ;

	FastMsgInfo ()
	{
		lpMsgData  = 0 ;
		nMsgLen    = 0 ;
		nDate      = 0 ;
		nTimeStamp = 0 ;
		nSeqNum    = -1 ;
	}
} ;

class DynBuffer
{
public:
	DynBuffer(void);
	~DynBuffer(void);

	unsigned int    GetBuffSize () ;
	unsigned int    GetCapacity () ;
	unsigned int    GetFreeSize () ;

	const char* GetReadData () ;
	void MoveRead (int nOffset) ;
	char* GetWriteData () ;
	void AddData (const char* lpData, int nLen) ;

	void Clear () ;

protected:
	char*              m_lpBuff ;
	unsigned int               m_nCapacity ;
	unsigned int               m_nRead ;
	unsigned int               m_nWrite ;

	int ExpandFreeTo (unsigned int nSize) ;
};
#endif
