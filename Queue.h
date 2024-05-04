#pragma once
#include "Product.h"

template<typename T>
struct Node {
    T* info;
    Node<T>* next;
    Node<T>* prev;
};
template<typename T>
class Queue
{
    Node<T>* head;
    Node<T>* tail;
    
    bool find(const T& b);
public:
    Queue();
    void pop_front();
    void push(T* buyer);
    int length();
    Node<T>* get_head();
    Node<T>* get_tail();
};

