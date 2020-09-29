//
// Created by 14035 on 2020/9/29.
//

#ifndef UNTITLED53_SIMLINK_H
#define UNTITLED53_SIMLINK_H
#include "Link.h"
template <class ElemType>
class SimLink {
protected:
    Link<ElemType>* head;//Í·½áµã
    Link<ElemType>* GetElemPtr(int position) const;

public:
    SimLink();
    ~SimLink();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void (*visit)(const ElemType&)) const;
    bool GetElem(int position, ElemType& e) const;
    bool SetElem(int position, const ElemType& e);
    bool Delete(int position, ElemType& e);
    bool Insert(int position, const ElemType& e);
};
template <class ElemType>
Link<ElemType>* SimLink<ElemType>::GetElemPtr(int position) const
{
    Link<ElemType>* tmPtr = head;
    int pos = 0;
    while (tmPtr != NULL && pos < position)
    {
        tmPtr = tmPtr->next;
        pos++;
    }
    if (tmPtr != NULL && pos == position)
    {
        return tmPtr;
    }
    else
    {
        return NULL;
    }
}
template <class ElemType>
SimLink<ElemType>::SimLink()
{
    head = new Link<ElemType>;
}
template <class ElemType>
SimLink<ElemType>::~SimLink()
{
    Clear();
    delete head;
}
template <class ElemType>
int SimLink<ElemType>::Length() const
{
    int count = 0;
    for (Link<ElemType>* tmPtr = head->next; tmPtr != NULL; tmPtr = tmPtr->next)
    {
        count++;
    }
    return count;
}
template <class ElemType>
bool SimLink<ElemType>::Empty() const
{
    return head->next == NULL;
}
template <class ElemType>
void SimLink<ElemType>::Clear()
{
    ElemType tmp;
    while (!Empty())
    {
        Delete(1, tmp);
    }
}
template <class ElemType>
void SimLink<ElemType>::Traverse(void (*visit)(const ElemType&)) const
{
    for (Link<ElemType>* tmPtr = head->next; tmPtr != NULL; tmPtr = tmPtr->next)
    {
        (*visit)(tmPtr->data);
    }
}
template <class ElemType>
bool SimLink<ElemType>::GetElem(int position, ElemType& e)const
{
    if (position<1 || position>Length())
    {
        return false;
    }
    else
    {
        Link<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position);
        e = tmpPtr->data;
        return true;
    }
}
template <class ElemType>
bool SimLink<ElemType>::SetElem(int position, const ElemType& e)
{
    if (position<1 || position>Length())
    {
        return false;
    }
    else
    {
        Link<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position);
        tmpPtr->data = e;
        return true;
    }
}
template <class ElemType>
bool SimLink<ElemType>::Insert(int position, const ElemType& e)
{
    if (position<1 || position>Length() + 1)
    {
        return false;
    }
    else
    {
        Link<ElemType>* tmp;
        tmp = GetElemPtr(position - 1);
        Link<ElemType>* newPtr;
        newPtr = new Link<ElemType>(e, tmp->next);
        tmp->next = newPtr;
        return true;
    }
}

template <class ElemType>
bool SimLink<ElemType>::Delete(int position, ElemType& e)
{
    if (position<1 || position>Length() + 1)
    {
        return false;
    }
    else
    {
        Link<ElemType>* tmp;
        tmp = GetElemPtr(position - 1);
        Link<ElemType>* nextPtr;
        nextPtr = tmp->next;
        tmp->next = nextPtr->next;
        e = nextPtr->data;
        delete nextPtr;
        return true;
    }
}

#endif // UNTITLED53_SIMLINK_H
