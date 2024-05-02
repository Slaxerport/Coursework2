#pragma once

#include "Queue.h"

using namespace std;

class List {
    Product** purshaces_list = nullptr;
    int size = 0;
public:
    void push(Product* temp);
    void push(string path);
    void print();
    void erase(int index);
    double get_sum();
    Product** get_purshaces_list();
    int get_size();

    ~List();
};
class Buyer
{
protected:
    string name = "";
    double money = 0;
    List* p_list = new List;
public:
    
    Buyer() {};
    Buyer(string path);
    
    void set_name(const string& name);
    void set_money(const int& money);
    void set_list(List* list); 
    string get_name();
    double get_money();
    List* get_list();
    double get_sum();
    static void service(Queue& queue);
    static void service_all(Queue& queue);
    static void print_queue(Queue& queue);
    void menu(Queue& queue, string path); 
    
    bool operator ==(const Buyer& b);
};

