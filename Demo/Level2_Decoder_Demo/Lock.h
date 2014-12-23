/******************************************************************
@Դ��������: Lock.h
@�������Ȩ: �������ӹɷ����޹�˾ ��Ȩ����
@ϵͳ����: 
@ģ������: 
@����˵��: ������
@����ĵ�: 
@����:     
@���: (��ѡ��)

@�޸ļ�¼
@�޸�����: 2013-02-26
@�޸���Ա: ��ģ��
@�޸�˵��: ����
@�汾��   1.0

*******************************************************************/

#ifndef _H_LOCK_H_
#define _H_LOCK_H_

#ifdef _WIN32
#include <Windows.h>
#else
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#endif

class Lock
{
public:
	Lock()
	{
#ifdef _WIN32
		InitializeCriticalSection(&m_lock);
#else
		pthread_mutex_init(&m_lock,NULL);
#endif
	}

	~Lock()
	{
#ifdef _WIN32
		DeleteCriticalSection(&m_lock);
#else
		pthread_mutex_destroy(&m_lock);
#endif
	}

	void Acquire()
	{
#ifdef _WIN32
		EnterCriticalSection(&m_lock);
#else
		pthread_mutex_lock(&m_lock);
#endif

	}
	void Release()
	{
#ifdef _WIN32
		LeaveCriticalSection(&m_lock);
#else
		pthread_mutex_unlock(&m_lock);
#endif
	}
private:
#ifdef _WIN32
	CRITICAL_SECTION m_lock;
#else
	pthread_mutex_t m_lock;
#endif
};


class AutoLock
{
public:
	AutoLock(Lock * pMutex)
	{
		m_pMutex=pMutex;
		pMutex->Acquire();
	};
	~AutoLock()
	{
		m_pMutex->Release();
	};
private:
	Lock * m_pMutex;
};

#endif
