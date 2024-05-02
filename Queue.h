#pragma once
#include "Product.h"

class Buyer;

struct Node {
    Buyer* info;
    Node* next;
    Node* prev;
};
class Queue
{
    Node* head;
    Node* tail;
    
    template <typename T>
    bool find(const T& b);
public:
    Queue();
    int size();
    void pop_front();
    void push(Buyer* buyer);
    int length();
    Node* get_head();
    Node* get_tail();
};

