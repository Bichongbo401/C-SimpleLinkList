//
// Created by 14035 on 2020/9/29.
//

#ifndef UNTITLED53_LINK_H
#define UNTITLED53_LINK_H
#include<iostream>
template <class T>
class Link
{
public:
    T data;
    Link<T>* next;
    Link(T item, Link<T>* link = NULL)
    {
        data = item;
        next = link;
    }
    Link()
    {
        next = NULL;
    }
};

#endif // UNTITLED53_LINK_H
