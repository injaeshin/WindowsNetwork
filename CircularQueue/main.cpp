#include <iostream>
#include <memory>
#include <Windows.h>

#include "CircularQueue1.h"
#include "CircularQueue2.h"

int main(void)
{
    auto pQueue1 = std::make_shared<CircularQueue1<INT32>>();

    pQueue1->Push(10);
    pQueue1->Push(11);
    pQueue1->Push(12);

    INT32 data = 0;
    pQueue1->Pop(data);

    std::cout << data << std::endl;

    ////////////////////////////////////////////

    auto pQueue2 = std::make_shared<CircularQueue2>();

    CHAR pMsg[] = "Hello World";
    pQueue2->Push((BYTE*)(pMsg), strlen(pMsg));

    BYTE data2[MAX_BUFFER_LENGTH] = { 0, };
    DWORD dataLength = 0;
    pQueue2->Pop(data2, dataLength);

    printf("%s", data2);

    return 0;
}