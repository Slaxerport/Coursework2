#pragma once

#include "Product.h"

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

    ~List();
};
class Buyer
{
    void print_purshaces();
    void push_to_list(Product* temp);
protected:
    string name = "";
    double money = 0;
    List* p_list = nullptr;
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

    void menu(int queue, string path); // solve a queue problem
    
};

