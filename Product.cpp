#include "Product.h"

Milk::Milk(string path)
{
    ifstream in(path);
    input_from_file(in);
}

void Milk::get_info()
{
    cout << "Name: " << name << endl
        << "Price: " << price << endl
        << "Sort: " << sort << endl
        << "Fat percentage: " << fat_percentage << endl
        << "Volume: " << volume << endl;
}

void Milk::input_from_file(ifstream& in)
{
    string parameter;
    for (int i = 0; i < 5; i++) {
        in >> parameter;
        if (parameter == "Name:") in >> name;
        else if (parameter == "Price:") in >> price;
        else if (parameter == "Sort:") in >> sort;
        else if (parameter == "Fat") in >> parameter >> fat_percentage;
        else if (parameter == "Volume:") in >> volume;
    }
}

void Milk::console_input()
{
    cout << "Name: ";
    cin >> name;
    cout << "Price: ";
    cin >> price;
    cout << "Sort: ";
    cin >> sort;
    cout << "Fat percentage: ";
    cin >> fat_percentage;
    cout << "Volume: ";
    cin >> volume;
}

void Milk::info_to_file(ofstream& out)
{
    out << "Name: " << name
        << " Price: " << price
        << " Sort: " << sort
        << " Fat percentage: " << fat_percentage
        << " Volume: " << volume << ' ';
}

Bread::Bread(string path)
{
    ifstream in(path);
    input_from_file(in);
}

void Bread::get_info()
{
    cout << "Name: " << name << endl
        << "Price: " << price << endl
        << "Color: " << color << endl
        << "Mass: " << mass << endl;
}

void Bread::input_from_file(ifstream& in)
{
    string parameter;
    for (int i = 0; i < 4; i++) {
        in >> parameter;
        if (parameter == "Name:") in >> name;
        else if (parameter == "Price:") in >> price;
        else if (parameter == "Color:") in >> color;
        else if (parameter == "Mass:") in >> mass;
    }
}

void Bread::console_input()
{
    cout << "Name: ";
    cin >> name;
    cout << "Price: ";
    cin >> price;
    cout << "Color: ";
    cin >> color;
    cout << "Mass: ";
    cin >> mass;
}

void Bread::info_to_file(ofstream& out)
{
    out << "Name: " << name
        << " Price: " << price
        << " Color: " << color
        << " Mass: " << mass << ' ';
}

Cake::Cake(string path)
{
    ifstream in(path);
    input_from_file(in);
}

void Cake::get_info()
{
    cout << "Name: " << name << endl
        << "Price: " << price << endl
        << "Filling: " << filling << endl
        << "Base: " << base << endl;
}

void Cake::input_from_file(ifstream& in)
{
    string parameter;
    for (int i = 0; i < 4; i++) {
        in >> parameter;
        if (parameter == "Name:") in >> name;
        else if (parameter == "Price:") in >> price;
        else if (parameter == "Filling:") in >> filling;
        else if (parameter == "Base:") in >> base;
    }
}

void Cake::console_input()
{
    cout << "Name: ";
    cin >> name;
    cout << "Price: ";
    cin >> price;
    cout << "Filling: ";
    cin >> filling;
    cout << "Base: ";
    cin >> base;
}

void Cake::info_to_file(ofstream& out)
{
    out << "Name: " << name
        << " Price: " << price
        << " Filling: " << filling
        << " Base: " << base << ' ';
}

double Product::get_price()
{
    return price;
}

