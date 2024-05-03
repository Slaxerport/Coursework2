#include "Buyer.h"

bool Buyer::operator==(const Buyer& b)
{
	return name == b.name && money == b.money && p_list == b.p_list;
}

Buyer::Buyer(string& path)
{
	ifstream in(path);
	string ignore;
	p_list = new List;
	while (1) {
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
		else if (ignore == "\n") break;
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

void Buyer::service(Queue& queue)
{
	if (!(queue.size())) {
		cout << "Queue is empty" << endl;
		return;
	}
	if (queue.get_tail()->info->get_money() < queue.get_tail()->info->get_list()->get_sum()) {
		cout << "Buyer " << queue.get_tail()->info->get_name() << " does not have enough money to pay his purshaces and has been deleted from the queue." << endl;
	}
	queue.pop_front();
}

void Buyer::service_all(Queue& queue)
{
	int const SIZE = queue.size();
	if (!SIZE) {
		cout << "Queue is empty" << endl;
		return;
	}
	for (int i = 0; i < SIZE; i++) {
		service(queue);
	}
}

void Buyer::print_queue(Queue& queue)
{
	int const SIZE = queue.size();
	if (!SIZE) {
		cout << "Queue is empty" << endl;
		return;
	}
	Node* temp = queue.get_head();
	for (int i = 0; i < SIZE; i++) {
		cout << temp->info->get_name() << endl;
		temp = temp->prev;
	}
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
	if (purshaces_list == nullptr) {
		cout << "Purshaces list is empty" << endl;
		return;
	}
	for (int i = 0; i < size; i++) {
		purshaces_list[i]->get_info();
		cout << endl;
	}
}

void List::erase(int index)
{
	Product** del = purshaces_list;
	if (!(size-1)) {
		purshaces_list = nullptr;
		delete del;
		size = 0;
		return;
	}
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
int List::get_size()
{
	return size;
}
void Buyer::menu(Queue& queue, string path)
{
	int flag = 1;
	ifstream in(path);
	string parameter;
	while (flag) {
		system("cls");
		cout << "1.Get in queue\n"
			<< "2.Get length of queue\n"
			<< "3.Print list of purshaces\n"
			<< "4.Add product from file\n"
			<< "5.Add product from console\n"
			<< "6.Delete product\n"
			<< "7.Get a sum of purshaces prices\n"
			<< "0.Exit\n";
		cout << "Choose menu item: ";
		cin >> flag;
		cout << endl;
		switch (flag) {
		case 1:
			queue.push(this);
			system("pause");
			break;
		case 2:
			cout << "Length of queue is: " << queue.length() << endl;
			system("pause");
			break;
		case 3:
			p_list->print();
			system("pause");
			break;
		case 4:
			in >> parameter;
			if (parameter == "Bread") {
				Bread* b = new Bread;
				b->input_from_file(in);
				p_list->push(b);
			}
			else if (parameter == "Milk") {
				Milk* m = new Milk;
				m->input_from_file(in);
				p_list->push(m);
			}
			else if (parameter == "Cake") {
				Cake* c = new Cake;
				c->input_from_file(in);
				p_list->push(c);
			}
			cout << "Product is added to purshaces list" << endl;
			system("pause");
			break;
		case 5:
			cout << "Enter a type of product: ";
			cin >> parameter;
			if (parameter == "Bread") {
				Bread* b = new Bread;
				b->console_input();
				p_list->push(b);
			}
			else if (parameter == "Milk") {
				Milk* m = new Milk;
				m->console_input();
				p_list->push(m);
			}
			else if (parameter == "Cake") {
				Cake* c = new Cake;
				c->console_input();
				p_list->push(c);
			}
			system("pause");
			break;
		case 6:
			int x;
			p_list->print();
			cout << "Enter index of deleting product: ";
			cin >> x;
			if (x >= p_list->get_size() || x<0) {
				cout << "There are no purchaces with that index" << endl;
				system("pause");
				break;
			}
			p_list->erase(x);
			cout << "Product is deleted" << endl;
			system("pause");
			break;
		case 7:
			cout << "Sum of purshaces list is: ";
			if (p_list->get_purshaces_list() == nullptr) {
				cout << 0 << endl;
				system("pause");
				break;
			}
			cout << p_list->get_sum() << endl;
			system("pause");
			break;
		case 0:
			system("cls");
			break;
		default:
			cout << "Entered index is incorrect" << endl;
		}
	}
}

void Buyer::input_buyers(list<Buyer>& l, string path)
{
	ifstream in(path);
	while (!in.eof()) {
		Buyer b(path);
		l.push_back(b);
	}
}

void Buyer::buyer_enter(Queue& queue, list<Buyer>& l, string path)
{
	string login;
	cout << "Enter a login: ";
	cin >> login;
	for (auto it : l) {
		if (it.name == login) {
			it.menu(queue, path);
			return;
		}
	}
}

List::~List()
{
	for (int i = 0; i < size; i++) {
		delete purshaces_list[i];
	}
	delete purshaces_list;
}

