#pragma once
#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <queue>

using namespace std;

class Product {
protected:
    string name = "";
    double price = 0.0;
public:
    virtual void get_info() = 0;
    virtual void input_from_file(ifstream& in) = 0;
    virtual void console_input() = 0;
    virtual void info_to_file(ofstream& out) = 0;
    double get_price();
};
class Milk : public Product {
    string sort = "";
    string fat_percentage = "";
    double volume = 0.0;
public:
    Milk() {};
    Milk(string path);
    
    void get_info() override;
    void input_from_file(ifstream& in) override;
    void console_input() override;
    void info_to_file(ofstream& out) override;
};
class Bread : public Product {
    string color = "";
    double mass = 0;
public:
    Bread() {};
    Bread(string path);
    
    void get_info() override;
    void input_from_file(ifstream& in) override;
    void console_input() override;
    void info_to_file(ofstream& out) override;
};
class Cake : public Product {
    string filling = "";
    string base = "";
public:
    Cake() {};
    Cake(string path);
    
    void get_info() override;
    void input_from_file(ifstream& in) override;
    void console_input() override;
    void info_to_file(ofstream& out) override;
};


