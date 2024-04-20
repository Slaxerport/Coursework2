#pragma once
#include "Salesman.h"

using namespace std;

class Administrator :
    public Salesman
{
    
    void print_salesmen(list<Salesman>& l);
    void add_salesman(list <Salesman>& l);
    void change_salesman(list<Salesman>& l, int index);
    void fire(list<Salesman>& l);
    void assign_bonus(list<Salesman>& l);
    
public:
    void file_input(string path);
    static Administrator* administrator_enter(Administrator& admin);
    void menu(list<Salesman>& l);
};

