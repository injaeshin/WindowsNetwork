#pragma once

constexpr int MAX_QUEUE_LENGTH1 = 1024;

template <class T>
class CircularQueue1
{
public:
    CircularQueue1() : mQueueHead(0), mQueueTail(0)
    {
        ZeroMemory(mQueue, sizeof(mQueue));
    }

private:
    T     mQueue[MAX_QUEUE_LENGTH1];
    DWORD mQueueHead;
    DWORD mQueueTail;

public:
    BOOL Push(T data)
    {
        DWORD tail = (mQueueTail + 1) % MAX_QUEUE_LENGTH1;
        if (tail == mQueueHead)
            return FALSE;

        CopyMemory(&mQueue[tail], &data, sizeof(T));

        mQueueTail = tail;

        return TRUE;
    }

    BOOL Pop(T& data)
    {
        if (mQueueHead == mQueueTail)
            return FALSE;

        DWORD head = (mQueueHead + 1) % MAX_QUEUE_LENGTH1;

        CopyMemory(&data, &mQueue[head], sizeof(T));

        mQueueHead = head;

        return TRUE;
    }

    BOOL IsEmpty()
    {
        if (mQueueHead == mQueueTail)
            return TRUE;

        return FALSE;
    }
};
