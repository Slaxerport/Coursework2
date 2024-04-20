#include "Salesman.h"

double Salesman::get_salary()
{
    return salary;
}

void Salesman::input_info(list<Salesman>& l)
{
    cout << "Enter a login: ";
    cin >> login; 
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
            return;
        }
        it++;
    }
    cout << "Salesman is not in worker list already" << endl;
}

void Salesman::file_input(list<Salesman>& l, string path)
{
    string ignore;
    ifstream in(path);
    while (!in.eof()) {
        in >> ignore;
        if(ignore=="Login:") in >> login;
        else if(ignore=="Password:") in >> password;
        else if(ignore=="Money:") in >> money;
        else if(ignore=="Serviced") in >> ignore >> service_clients;
        else if(ignore=="Salary:") in >> salary;

    }
    in.close();
    l.push_back(*this);
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
    return login;
}

string Salesman::get_password()
{
    return password;
}

void Salesman::set_login(string& login)
{
    this->login = login;
}

void Salesman::set_password(string& password)
{
    this->password = password;
}

void Salesman::salesman_enter(list<Salesman>& l, Queue& q)
{
    string login, password;
    int i = 0;
    list<Salesman>::iterator it = l.begin();
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    for (; i < l.size(); i++, it++) {
        if ((login == (*it).get_login()) && (password == (*it).get_password())) {
            cout << "Logon successful!" << endl;
            it->menu(l, q);
            i = -1;
            break;
        }
        it++;
    }
    if (i == -1) {
        return;
    }
    if (it == l.end()) {
        cout << "Logon failed. Incorrect login or password." << endl;
    }
}

template <typename T>
void Salesman::menu(list<Salesman>& l, T& queue) {
    int flag = 1;
    while (flag) {
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
            queue.service();
            break;
        case 2:
            queue.print();
            break;
        case 3:
            cout << "Current salary is: " << this->get_salary() << '\n';
            break;
        case 4:
            queue.service_all();
            break;
        case 5:
            getFire(l);
            flag = 0;
            break;
        case 0:
            break;
        default:
            cout << "Entered index is incorrect" << endl;
        }
    }
}

bool Salesman::operator ==(const Salesman& temp)
{
    return (name == temp.name) && (money == temp.money) && (p_list == temp.p_list) && (salary == temp.salary) && (service_clients == temp.service_clients);
}


