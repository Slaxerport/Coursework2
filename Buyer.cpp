#include "Buyer.h"

Buyer::Buyer(string path)
{
	ifstream in(path);
	string ignore;
	p_list = new List;
	while (!in.eof()) {
		in >> ignore >> name; // ignoring name-sign
		in >> ignore >> money; // ignoring money-sign
		in >> ignore;
		if (ignore == "Milk") {
			Milk* n_product = new Milk;
			n_product->input_from_file(in);
			p_list->push(n_product);
		}
		else if (ignore == "Bread") {
			Bread* n_product = new Bread;
			n_product->input_from_file(in);
			p_list->push(n_product);
		}
		else if (ignore == "Cake") {
			Cake* n_product = new Cake;
			n_product->input_from_file(in);
			p_list->push(n_product);
		}
	}
	in.close();
}

void Buyer::set_name(const string& name)
{
	this->name = name;
}

void Buyer::set_money(const int& money)
{
	this->money = money;
}

void Buyer::set_list(List* list)
{
	this->p_list = list;
}

string Buyer::get_name()
{
	return name;
}

double Buyer::get_money()
{
	return money;
}

List* Buyer::get_list()
{
	return p_list; 
}

double Buyer::get_sum()
{
	return p_list->get_sum();
}

void Buyer::print_purshaces()
{
	p_list->print();
}

void Buyer::push_to_list(Product* temp)
{
	p_list->push(temp);
}

void List::push(Product* temp)
{
	Product** list = new Product* [size + 1];
	if (purshaces_list != nullptr) {
		Product** del = purshaces_list;
		for (int i = 0; i < size; i++) {
			list[i] = purshaces_list[i];
		}
		delete del;
	}
	list[size] = temp;
	purshaces_list = list;
	size++;
}

void List::push(string path)
{
	int j;
	string type;
	ifstream in(path);
	cout << "Enter number of products: ";
	cin >> j;
	for (int i = 0; i < j; i++) {
		cout << "Enter type of product: ";
		cin >> type;
		if (type == "Milk") {
			Milk* m = new Milk;
			m->console_input();
			push(m);
		}
		else if (type == "Bread") {
			Bread* b = new Bread;
			b->console_input();
			push(b);
		}
		else if (type == "Cake") {
			Cake* c = new Cake;
			c->console_input();
			push(c);
		}
	}
}

void List::print()
{
	for (int i = 0; i < size; i++) {
		purshaces_list[i]->get_info();
	}
}

void List::erase(int index)
{
	Product** del = purshaces_list;
	Product** list = new Product*[size + 1];
	int i = 0;
	for (; i < index; i++) {
		list[i] = purshaces_list[i];
	}
	for (; i < size - 1; i++) {
		list[i] = purshaces_list[i + 1];
	}
	purshaces_list = list;
	delete del;
	size--;
}

double List::get_sum()
{
	double total = 0.0;
	for (int i = 0; i < size; i++) {
		total += purshaces_list[i]->get_price();
	}
	return total;
}

Product** List::get_purshaces_list()
{
	return purshaces_list;
}

//void Buyer::menu(int queue, string path)
//{
//	int flag = 1;
//	cout << "1.Get in queue\n"
//		<< "2.Get length of queue\n"
//		<< "3.Print list of purshaces\n"
//		<< "4.Add product from file\n"
//		<< "5.Add product from console\n"
//		<< "5.Delete product\n"
//		<< "6.Get a sum of purshaces prices\n"
//		<< "0.Exit\n";
//	while (flag) {
//		cout << "Choose menu item: ";
//		cin >> flag;
//		switch (flag) {
//		case 1:
//			queue.push(this);
//			break;
//		}
//		case 2:
//			queue.length();
//			break;
//		case 3:
//			print_purshaces();
//			break;
//		case 4:
//			ifstream in(path);
//			Product* temp = new Product;
//			temp->input_from_file(in);
//			push_to_list(temp);
//			break;
//		case 5:
//			Product * temp = new Product;
//			temp->console_input();
//			push_to_list(temp);
//			break;
//		case 6:
//			int x;
//			cout << "Enter index of deleting product";
//			cin >> x;
//			p_list->erase(x);
//			break;
//		case 7:
//			cout << "Sum of purshaces list is: ";
//			p_list->get_sum();
//			break;
//		case 0:
//			break;
//		default:
//			cout << "Entered index is incorrect" << endl;
//	}
//
//}

List::~List()
{
	for (int i = 0; i < size; i++) {
		delete purshaces_list[i];
	}
	delete purshaces_list;
}

