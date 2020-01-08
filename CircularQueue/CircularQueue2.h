#pragma once

constexpr int MAX_BUFFER_LENGTH = 2048;
constexpr int MAX_QUEUE_LENGTH2 = 1024;

typedef struct _QUEUE_DATA
{
    BYTE  data[MAX_BUFFER_LENGTH];
    DWORD dataLength;
} QUEUE_DATA;

class CircularQueue2
{
public:
    CircularQueue2();
    ~CircularQueue2() = default;

private:
    QUEUE_DATA mQueue[MAX_BUFFER_LENGTH];
    DWORD mQueueHead;
    DWORD mQueueTail;

public:
    BYTE* Push(BYTE* data, DWORD dataLength);
    BOOL  Pop(BYTE* data, DWORD& dataLength);
    BOOL  IsEmpty();
};