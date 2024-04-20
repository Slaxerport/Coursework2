#pragma once
#include "Queue.h"
class Salesman : public Buyer
{
	void getFire(list<Salesman>& l);
protected:
	string login = "";
	string password = "";
	int service_clients = 0;
	double salary = service_clients * 50;
public:
	double get_salary();
	void input_info(list<Salesman>& l);
	void file_input(list<Salesman>& l, string path);
	static Salesman* create_account(list<Salesman>& l);
	string get_login();
	string get_password();
	void set_login(string& login);
	void set_password(string& password);

	static void salesman_enter(list<Salesman>& l, Queue& q);

	template <typename T>
	void menu(list<Salesman>& l, T& queue);

	bool operator ==(const Salesman& temp);
};


