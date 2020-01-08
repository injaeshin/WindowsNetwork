#include <Windows.h>
#include "CircularQueue2.h"

CircularQueue2::CircularQueue2()
    : mQueueHead(0),
      mQueueTail(0)
{
    ZeroMemory(&mQueue, sizeof(mQueue));
}

BYTE* CircularQueue2::Push(BYTE* data, DWORD dataLength)
{
    if (nullptr == data || dataLength <= 0)
        return nullptr;

    DWORD tail = (mQueueTail + 1) % MAX_QUEUE_LENGTH2;
    if (tail == mQueueHead)
        return nullptr;

    CopyMemory(mQueue[tail].data, data, dataLength);
    mQueue[tail].dataLength = dataLength;

    mQueueTail = tail;

    return mQueue[tail].data;
}

BOOL CircularQueue2::Pop(BYTE* data, DWORD& dataLength)
{
    if (nullptr == data)
        return FALSE;

    if (mQueueHead == mQueueTail)
        return FALSE;

    DWORD head = (mQueueHead + 1) % MAX_QUEUE_LENGTH2;
    dataLength = mQueue[head].dataLength;
    CopyMemory(data, mQueue[head].data, mQueue[head].dataLength);

    mQueueHead = head;

    return TRUE;
}

BOOL CircularQueue2::IsEmpty()
{
    if (mQueueHead == mQueueTail)
        return TRUE;

    return FALSE;
}

