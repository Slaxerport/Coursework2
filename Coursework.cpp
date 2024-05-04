#include "Administrator.h"

list<Buyer> buyers_list;
Administrator administrator;
queue<Buyer> buyers_queue;
list<Salesman> salesmen_list;


void enter_menu();

int main()
{
    // test case

   /* Buyer b("Input.txt");
    Buyer b1("Input.txt");
    Queue q;
    q.push(&b);
    q.push(&b1);
    Bread bread("product_input.txt");
    b.push_to_list(&bread);
    cout << q.length() << endl;
    q.print();
    b.print_purshaces();
    cout << b.get_sum();*/
   
    Buyer::input_buyers(buyers_list, "Input_buyer.txt");
    Salesman::input_salesmen(salesmen_list, "Input.txt");
    administrator.file_input("Input_admin.txt");
    enter_menu();
}

void enter_menu()
{
    int x = 1;
    string login, password;
    list<Salesman>::iterator it = salesmen_list.begin();
    while (x) {
        system("cls");
        cout << "1.Enter as a buyer\n"
            << "2.Enter as a salesman\n"
            << "3.Enter as a new salesman\n"
            << "4.Enter as an administrator\n"
            << "0.Exit\n";
        cin >> x;
        switch (x) {
        case 1:
            Buyer::buyer_enter(buyers_queue, buyers_list, "product_input.txt");
            break;
        case 2:
            Salesman::salesman_enter(salesmen_list, buyers_queue);
            break;
        case 3:
            Salesman::create_account(salesmen_list)->menu(salesmen_list, buyers_queue);
            break;
        case 4:
            Administrator::administrator_enter(administrator)->menu(salesmen_list);
            break;
        case 0:
            Buyer::output(buyers_list, "output_buyers.txt");
            Salesman::output(salesmen_list, "output_salesmen.txt");
            break;
        default:
            cout << "Entered index is incorrect" << endl;
            system("pause");
        }
    }
}
