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
		return;
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
template <typename T>
bool Queue::find(const T& b)
{
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->info == b) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

Queue::Queue()
{
	head = tail = nullptr;
}

void Queue::push(Buyer* buyer)
{
	if (find(buyer)) {
		cout << "Buyer is already in queue" << endl;
		return;
	}
	Node* temp = new Node;
	temp->info = buyer;
	if (head == nullptr) {
		temp->next = temp->prev = nullptr;
		head = tail = temp;
		cout << "Buyer is pushed in the queue" << endl;
		return;
	}
	temp->next = tail;
	temp->prev = nullptr;
	tail->prev = temp;
	tail = temp;
	cout << "Buyer is pushed in the queue" << endl;
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


Node* Queue::get_head()
{
	return head;
}

Node* Queue::get_tail()
{
	return tail;
}

//void Queue::set_head(Node* head)
//{
//	this->head = head;
//}
//
//void Queue::set_tail(Node* tail)
//{
//	this->tail = tail;
//}



