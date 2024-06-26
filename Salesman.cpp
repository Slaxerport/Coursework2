#include "Salesman.h"

double Salesman::get_salary()
{
    return salary;
}

void Salesman::set_salary(double salary)
{
    this->salary = salary;
}

void Salesman::input_info(list<Salesman>& l)
{
    cout << "Enter a login: ";
    cin >> name; 
    cout << "Enter a password: ";
    cin >> password;
    cout << "Enter amount of money: ";
    cin >> money;
    cout << "Enter amount of serviced clients: ";
    cin >> service_clients;
}

void Salesman::getFire(list<Salesman>& l)
{
    list<Salesman>::iterator it = l.begin();
    while (it!=l.end()) {
        if ((*it) == *this) {
            l.erase(it);
            cout << "Salesman is fired" << endl;
            return;
        }
        it++;
    }
    cout << "Salesman is not in worker list already" << endl;
}

void Salesman::file_input(list<Salesman>& l, ifstream& in)
{
    Salesman s;
    string ignore;
    while (1) {
        if (in.get() == '\n' || in.eof()) break;
        in >> ignore;
        if (ignore == "Login:") in >> s.name;
        else if (ignore == "Password:") in >> s.password;
        else if (ignore == "Money:") in >> s.money;
        else if (ignore == "Serviced") in >> ignore >> s.service_clients;
    }
    s.hash = Hash(s.password);
    s.salary = s.service_clients * 50;
    l.push_back(s);
}

Salesman* Salesman::create_account(list<Salesman>& l)
{
    string login, password;
    Salesman* salesman = new Salesman;
    cout << "Enter a login: ";
    cin >> login;
    cout << "Enter a password: ";
    cin >> password;
    salesman->set_login(login);
    salesman->set_password(password);
    l.push_back(*salesman);
    return salesman;
}

string Salesman::get_login()
{
    return name;
}

string Salesman::get_password()
{
    return password;
}

int Salesman::get_service_clients()
{
    return service_clients;
}

void Salesman::set_login(string& login)
{
    this->name = login;
}

void Salesman::set_password(string& password)
{
    this->password = password;
}

string Salesman::get_hash()
{
    return hash;
}
void Salesman::salesman_enter(list<Salesman>& l, queue<Buyer>& q)
{
    string login, password;
    int i = 0;
    list<Salesman>::iterator it = l.begin();
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    for (; it != l.end(); i++, it++) {
        if ((login == (*it).name) && (Salesman::Hash(password) == (*it).get_hash())) {
            cout << "Logon successful!" << endl;
            system("pause");
            it->menu(l, q);
            i = -1;
            break;
        }
    }
    if (i == -1) {
        return;
    }
    if (it == l.end()) {
        cout << "Logon failed. Incorrect login or password." << endl;
        system("pause");
    }
}

string Salesman::Hash(string& password)
{
    int const DIFF = 23;
    string total = "";
    for (int i = 0; i < password.length(); i++) {
        total += char(password[i] + DIFF);
    }
    return total;
}


void Salesman::menu(list<Salesman>& l, queue<Buyer>& queue) {
    int flag = 1, t;
    while (flag) {
        system("cls");
        cout << "1.Service a client\n"
            << "2.Print queue\n"
            << "3.Print current salary\n"
            << "4.Service all clients\n"
            << "5.Get quit\n"
            << "0.Exit\n"
            << "Choose an option: ";
        cin >> flag;
        switch (flag) {
        case 1:
            t = Buyer::service(queue);
            service_clients += t;
            salary += t * 50.0;
            system("pause");
            break;
        case 2:
            Buyer::print_queue(queue);
            system("pause");
            break;
        case 3:
            cout << "Current salary is: " << this->get_salary() << '\n';
            system("pause");
            break;
        case 4:
            service_clients += queue.size();
            Buyer::service_all(queue);
            system("pause");
            break;
        case 5:
            getFire(l);
            flag = 0;

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

void Salesman::input_salesmen(list<Salesman>& l, string path)
{
    ifstream in(path);
    while(!in.eof()){
        file_input(l, in);
    }
}

void Salesman::output(list<Salesman>& l, string path)
{
    ofstream out(path);
    for (auto el : l) {
        out << " Name: " << el.name
            << " Money: " << el.money
            << " Serviced clients: " << el.service_clients;
        out << endl;
    }
}

bool Salesman::operator ==(const Salesman& temp)
{
    return (name == temp.name) && (money == temp.money) && (p_list == temp.p_list) && (salary == temp.salary) && (service_clients == temp.service_clients);
}


