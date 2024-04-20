#pragma once

#include "Buyer.h"

struct Node {
    Buyer* info = new Buyer;
    Node* next;
    Node* prev;
};
class Queue
{
    Node* head;
    Node* tail;
    void pop_front();
    int size();
    Node* end();
public:
    Queue();
    
    void push(Buyer* buyer);
    int length();
    void service();
    void print();
    void service_all();
};

