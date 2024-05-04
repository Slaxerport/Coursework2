#include "Queue.h"

template<typename T>
void Queue<T>::pop_front()
{
	if (head == nullptr) {
		return;
	}
	Node<T>* del = head;
	if (head == tail) {
		head = tail = nullptr;
		delete del;
		return;
	}
	Node<T>* n_head = head->prev;
	n_head->next = nullptr;
	head = n_head;
	if (this->size() == 2) {
		tail = head;
	}
	delete del;
}
template<typename T>
bool Queue<T>::find(const T& b)
{
	Node* temp = head;
	while (temp != nullptr) {
		if (temp->info == b) {
			return true;
		}
		temp = temp->prev;
	}
	return false;
}
template<typename T>
Queue<T>::Queue()
{
	head = tail = nullptr;
}
template<typename T>
void Queue<T>::push(T* buyer)
{
	if (find(buyer)) {
		cout << "Buyer is already in queue" << endl;
		return;
	}
	Node<T>* temp = new Node<T>;
	temp->info = buyer;
	if (head == nullptr) {
		temp->next = temp->prev = nullptr;
		head = tail = temp;
		cout << "Buyer is pushed in the queue" << endl;
		return;
	}
	temp->next = tail;
	temp->prev = nullptr;
	tail = temp;
	cout << "Buyer is pushed in the queue" << endl;
}
template<typename T>
int Queue<T>::length()
{
	int length = 0;
	Node<T>* temp = head;
	while (temp != nullptr) {
		++length;
		temp = temp->prev;
	}
	return length;
}

template<typename T>
Node<T>* Queue<T>::get_head()
{
	return head;
}
template<typename T>
Node<T>* Queue<T>::get_tail()
{
	return tail;
}



