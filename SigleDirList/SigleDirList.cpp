// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <typename T> class list
{
private:
	class node
	{
		friend class list<T>;
	private:
		node* next;
		T val;

		node() : next(NULL){}
		~node() {}
	};

	node* head;
	node* tail;
	int count;

	void Inver(node* current) {
		if (current->next != NULL) {
			Inver(current->next);
			current->next->next = current;
		}
	}

	bool compare_for_polindrom(node* current, node* to_compare) {
		if (current->val == to_compare->val) {
			current = current->next;
			return true;
		}
		return false;
	}

	node* polindrom(node* head_of_list, node* center, int &index, bool &result) {
		if (result) {
			if (index <= count / 2 - 1) {

				center = polindrom(head_of_list->next, center, ++index, result);

				if (center != NULL) {
					if (center->val == head_of_list->val) {
						return center->next;
					}
					else {
						result = false;
					}
				}
			}
			else {
				return center;
			}
		}
	}

public:
	list() : head(NULL), tail(NULL), count(0) {}
	~list()
	{
		clear();
	}

	int getCount() const
	{
		return count;
	}

	int add(T data)
	{
		node* to_add = new node;
		to_add->val = data;
		if (head == NULL) {
			head = to_add;
			tail = to_add;
		}
		else {
			tail->next = to_add;
			tail = to_add;
		}
		count++;
		return count;
	}

	int insert(T data, int ind) {
		node* to_add = new node;
		to_add->val = data;
		if (ind == 0) {
			to_add->next = head;
			head = to_add;
			return 1;
		}
		else if (ind == count - 1) {
			tail->next = to_add;
			tail = to_add;
			return 1;
		}
		else{
			node* current = head;
			for (int i = 0; i < ind - 1; i++) {
				current = current->next;
			}
			to_add->next = current->next;
			current->next = to_add;
			return 1;
		}
		return -1;
	}

	int del(int x) {
		if (x > count - 1) return -1;
		node* to_del = head;
		if (x == 0) {
			head = head->next;
			delete to_del;
		}
		else if (x == count - 1) {
			to_del = tail;
			node* current = head;
			for (; current->next != tail; current = current->next);
			current->next = NULL;
			tail = current;
			delete to_del;
		}
		else
		{
			node* current = head;
			for (int i = 0; i < x - 1; i++) {
				current = current->next;
			}
			to_del = current->next;
			current->next = current->next->next;
			delete to_del;
		}
		count--;
		return count;
	}

	void clear() //Очистка списка
	{
		node* current = head;
		node* to_del = head;
		while (to_del != NULL) {
			current = current->next;
			delete to_del;
			to_del = current;
		}
		head = NULL;
		count = 0;
	}

	T getData(int x) const
	{
		node* current;
		for (current = head; x > 1; x--) {
			current = current->next;
		}
		return current->val;
	}

	void Inversion(){
		node* current = head;
		node* temp = head;
		head = tail;
		tail = temp;
		Inver(current);
		tail->next = NULL;
	}

	int find(T value) {
		node* current;
		int index = 0;
		for (int x = 0, current = head; current->val != value; current = current->next, x++) {
			if (x > count) {
				return NULL;
			}
			index++;
		}
		return index;
	}

	void Output() {
		for (node* current = head; current != NULL; current = current->next) {
			cout << current->val << " ";
		}
		cout << '\n';
	}

	bool is_polindrom() {
		node* center = head;
		node* begin = head;
		bool res = true;
		int  ind = 0;
		for (int i = 0; i < ((count % 2 == 0) ? (count / 2) : (count / 2 + 1)); i++, center = center->next);
		polindrom(begin, center, ind, res);
		return res;
	}
};


int main()
{
	list <int> MyList;
	MyList.add(1);
	MyList.add(2);
	MyList.add(3);
	MyList.add(5);
	MyList.add(3);
	MyList.add(2);
	MyList.add(1);
	MyList.Output();
	cout << "Polindrom Check: "<< MyList.is_polindrom();
	cout << "\n";

	//MyList.Inversion();
	MyList.Output();

	//MyList.del(1);
	//MyList.Output();

	//MyList.insert(7, 1);
	//MyList.Output();
}