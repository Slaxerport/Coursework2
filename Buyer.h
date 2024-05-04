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
    int get_size();

    ~List();
};
class Buyer
{
    Buyer(ifstream& in);
    static bool find(queue<Buyer>& q, Buyer& temp);
protected:
    string name = "";
    double money = 0;
    List* p_list = new List;
public:
    Buyer() {};
    
    void set_name(const string& name);
    void set_money(const double& money);
    void set_list(List* list); 
    string get_name();
    double get_money();
    List* get_list();
    double get_sum();
    static int service(queue<Buyer>& queue);
    static void service_all(queue<Buyer>& queue);
    static void print_queue(queue<Buyer>& queue);
    void menu(queue<Buyer>& q, string path);
    static void input_buyers(list<Buyer>& l, string path);
    static void buyer_enter(queue<Buyer>& queue, list<Buyer>& l, string path);
    static void output(list<Buyer> l, string path);

    bool operator ==(const Buyer& b);
};

