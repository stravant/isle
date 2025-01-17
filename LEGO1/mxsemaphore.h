#ifndef MX_SEMAPHORE_H
#define MX_SEMAPHORE_H

#include "mxtypes.h"

#include <windows.h>

class MxSemaphore {
public:
	MxSemaphore();

	// Inlined only, no offset
	~MxSemaphore() { CloseHandle(m_hSemaphore); }

	virtual MxResult Init(MxU32 p_initialCount, MxU32 p_maxCount);

	void Wait(MxU32 p_timeoutMS);
	void Release(MxU32 p_releaseCount);

private:
	HANDLE m_hSemaphore;
};

#endif // MX_SEMAPHORE_H
