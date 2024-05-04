#pragma once
#include "Buyer.h"
class Salesman : public Buyer
{
	void getFire(list<Salesman>& l);
	static void file_input(list<Salesman>& l, ifstream& in);
protected:
	string password = "";
	string hash = "";
	int service_clients = 0;
	double salary = 0;
public:
	double get_salary();
	void input_info(list<Salesman>& l);
	static Salesman* create_account(list<Salesman>& l);
	string get_login();
	string get_password();
	void set_salary(double salary);
	int get_service_clients();
	void set_login(string& login);
	void set_password(string& password);
	string get_hash();
	static void salesman_enter(list<Salesman>& l, queue<Buyer>& q);
	static string Hash(string& password);
	void menu(list<Salesman>& l, queue<Buyer>& queue);
	static void input_salesmen(list<Salesman>& l, string path);
	static void output(list<Salesman>& l, string path);

	bool operator ==(const Salesman& temp);
};


