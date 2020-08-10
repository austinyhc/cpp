#ifndef __LIST_H__
#define __LIST_H__

#include <cstdio>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif