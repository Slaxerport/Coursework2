#pragma once
#include "Buyer.h"
class Salesman : public Buyer
{
	void getFire(list<Salesman>& l);
protected:
	string login = "";
	string password = "";
	string hash = "";
	int service_clients = 0;
	double salary = 0;
public:
	double get_salary();
	void input_info(list<Salesman>& l);
	void file_input(list<Salesman>& l, string path);
	static Salesman* create_account(list<Salesman>& l);
	string get_login();
	string get_password();
	void set_login(string& login);
	void set_password(string& password);
	string get_hash();
	static void salesman_enter(list<Salesman>& l, Queue& q);
	static string Hash(string& password);
	void menu(list<Salesman>& l, Queue& queue);
	

	bool operator ==(const Salesman& temp);
};


