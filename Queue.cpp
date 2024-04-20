#include "Queue.h"

void Queue::pop_front()
{
	if (head == nullptr) {
		return;
	}
	Node* del = head;
	if (head == tail) {
		head = tail = nullptr;
		delete del;
	}
	Node* n_head = head->prev;
	n_head->next = nullptr;
	head = n_head;
	if (size() == 2) {
		tail = head;
	}
	delete del;
}

int Queue::size()
{
	int count = 0;
	Node* temp = head;
	while (temp != nullptr) {
		count++;
		temp = temp->prev;
	}
	return count;
}

Node* Queue::end()
{
	return tail;
}

Queue::Queue()
{
	head = tail = nullptr;
}

void Queue::push(Buyer* buyer)
{
	Node* temp = new Node;
	temp->info->set_name(buyer->get_name());
	temp->info->set_money(buyer->get_money());
	temp->info->set_list(buyer->get_list());
	if (head == nullptr) {
		temp->next = temp->prev = nullptr;
		head = tail = temp;
		return;
	}
	temp->next = tail;
	temp->prev = nullptr;
	tail->prev = temp;
	tail = temp;
}
int Queue::length()
{
	int length = 0;
	Node* temp = head;
	while (temp != nullptr) {
		++length;
		temp = temp->prev;
	}
	return length;
}

void Queue::service()
{
	if (end()->info->get_money() < end()->info->get_list()->get_sum()) {
		cout << "Buyer " << end()->info->get_name() << " does not have enough money to pay his purshaces and has been deleted from the queue." << endl;
	}
	pop_front();
}

void Queue::print()
{
	int const SIZE = size();
	Node* temp = head;
	for (int i = 0; i < SIZE; i++) {
		cout << temp->info->get_name() << endl;
		temp = temp->prev;
	}
}

void Queue::service_all()
{
	int const SIZE = size();
	for (int i = 0; i < SIZE; i++) {
		service();
	}
}


