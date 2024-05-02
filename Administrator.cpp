#include "Administrator.h"

void Administrator::print_salesmen(list<Salesman>& l)
{
	int i = 0;
	for (list<Salesman>::iterator it = l.begin(); it != l.end(); it++, i++) {
		cout << "Salesman " << i << '\n' << (*it).get_login() << '\n';
	}
}

void Administrator::add_salesman(list<Salesman>& l)
{
	Salesman* salesman = new Salesman;
	salesman->input_info(l);
	l.push_back(*salesman);
}

void Administrator::change_salesman(list<Salesman>& l, int index)
{
	list<Salesman>::iterator it = l.begin();
	advance(it, index);
	(*it).input_info(l);
}

void Administrator::fire(list<Salesman>& l)
{
	int x;
	print_salesmen(l);
	list<Salesman>::iterator it = l.begin();
	cout << "Enter a number of salesman: ";
	cin >> x;
	advance(it, x);
	l.erase(it);
}

void Administrator::assign_bonus(list<Salesman>& l)
{
	int max = -1, salary, index, i = 0;;
	list<Salesman>::iterator it = l.begin();
	for (list<Salesman>::iterator it = l.begin(); it != l.end(); it++, i++) {
		salary = (*it).get_salary();
		if (salary > max) {
			max = salary;
			index = i;
		}
	}
	int m = (l.size() - index - 1);
	advance(it, -m);
	(*it).set_money((*it).get_money() + 250);
}

void Administrator::file_input(string path)
{
	string ignore;
	ifstream in(path);
	while (!in.eof()) {
		in >> ignore;
		if (ignore == "Login:") in >> login;
		else if (ignore == "Password:") in >> password;
		else if (ignore == "Money:") in >> money;
		else if (ignore == "Salary:") in >> salary;
	}
	hash = Hash(password);
	in.close();
}

Administrator* Administrator::administrator_enter(Administrator& admin)
{
	string login, password;
	while (true) {
		cout << "Enter login: ";
		cin >> login;
		cout << "Enter password: ";
		cin >> password;
		if ((login == admin.login) && (Hash(password) == admin.hash)) {
			cout << "Logon successful!" << endl;
			return &admin;
		}
		else {
			cout << "Logon failed. Incorrect login or password." << endl;
		}
	}
}

void Administrator::menu(list<Salesman>& l)
{
	int flag = 1;
	while (flag) {
		cout << "1.Print salesmen list\n"
			<< "2.Add new salesman\n"
			<< "3.Change salesman\n"
			<< "4.Fire a salesman\n"
			<< "5.Assign a bonus\n"
			<< "0.Exit\n";
		cout << "Choose an option: ";
		cin >> flag;
		switch (flag) {
		case 1:
			print_salesmen(l);
			break;
		case 2:
			add_salesman(l);
			break;
		case 3:
			int a;
			cout << "Enter an index of changing salesman: ";
			cin >> a;
			change_salesman(l, a);
			break;
		case 4:
			fire(l);
			break;
		case 5:
			assign_bonus(l);
			break;
		case 0:
			break;
		default:
			cout << "Entered index is incorrect" << endl;
		}
	}
}
