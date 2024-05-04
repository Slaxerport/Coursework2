#include "Buyer.h"

bool Buyer::operator==(const Buyer& b)
{
	return name == b.name && money == b.money && p_list == b.p_list;
}

Buyer::Buyer(ifstream& in)
{
	string ignore;
	p_list = new List;
	in >> ignore >> name; // ignoring name-sign
	in >> ignore >> money; // ignoring money-sign
	while (1) {
		if (in.get() == '\n' || in.eof()) break;
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
}

bool Buyer::find(queue<Buyer>& q, Buyer& temp)
{
	queue<Buyer> temp_q = q;
	for (int i = 0; i < q.size(); i++) {
		if (temp_q.front() == temp) return true;
		temp_q.pop();
	}
	return false;
}

void Buyer::set_name(const string& name)
{
	this->name = name;
}

void Buyer::set_money(const double& money)
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

int Buyer::service(queue<Buyer>& queue)
{
	if (!(queue.size())) {
		cout << "Queue is empty" << endl;
		return 0;
	}
	if (queue.front().get_money() < queue.front().get_list()->get_sum()) {
		cout << "Buyer " << queue.front().get_name() << " does not have enough money to pay his purshaces and has been deleted from the queue." << endl;
	}
	else {
		cout << "Buyer is serviced" << endl;
	}
	queue.pop();
	return 1;
}

void Buyer::service_all(queue<Buyer>& queue)
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

void Buyer::print_queue(queue<Buyer>& q)
{
	int const SIZE = q.size();
	if (!SIZE) {
		cout << "Queue is empty" << endl;
	}
	queue<Buyer> temp = q;
	for (int i = 0; i < SIZE; i++) {
		cout << temp.front().get_name() << endl;
		temp.pop();
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
void Buyer::menu(queue<Buyer>& q, string path)
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
			if (Buyer::find(q, *this)) {
				cout << "Buyer is already in the queue" << endl;
			}
			else {
				q.push(*this);
				cout << "Buyer is pushed to queue" << endl;
			}
			system("pause");
			break;
		case 2:
			cout << "Length of queue is: " << q.size() << endl;
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
			system("pause");
		}
	}
}

void Buyer::input_buyers(list<Buyer>& l, string path)
{
	ifstream in(path);
	while (!in.eof()) {
		Buyer b(in);
		l.push_back(b);
	}
	in.close();
}

void Buyer::buyer_enter(queue<Buyer>& queue, list<Buyer>& l, string path)
{
	system("cls");
	string login;
	cout << "Enter a login: ";
	cin >> login;
	for (auto it : l) {
		if (it.name == login) {
			cout << "Logon succesful!" << endl;
			system("pause");
			it.menu(queue, path);
			return;
		}
	}
	cout << "Incorrect login. Try again" << endl;
	system("pause");
	return buyer_enter(queue, l, path);
}

void Buyer::output(list<Buyer> l, string path)
{
	ofstream out(path);
	for (auto it : l) {
		out << "Name: " << it.name << " Money: " << it.money << ' ';
		for (int i = 0; i < it.get_list()->get_size(); i++) {
			it.get_list()->get_purshaces_list()[i]->info_to_file(out);
		}
		out << endl;
	}
}

List::~List()
{
	for (int i = 0; i < size; i++) {
		delete purshaces_list[i];
	}
	delete purshaces_list;
}

