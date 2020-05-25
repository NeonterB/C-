// List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template <class T>
class list
{
private:
	class node
	{
		friend class list<T>;
	private:
		node* next;
		node* prev;
		T val;

		node() : next(NULL), prev(NULL) {}
		~node() {}
	};

	node* head;
	node* tail; //Указатель на конец списка
	int count; //Количество элементов в списке
public:
	list() : head(NULL), tail(NULL), count(0) {}
	~list()
	{
		clear(); //Функция освобождает память, используемую для хранения списка
	}
	int getCount() const //Возвращает количество элементов в списке
	{
		return count;
	}

	int add(T data)//Добавление элемента в конец списка. Возвращает количество элементов в списке
	{
		node* to_add = new node;
		to_add->next = NULL;
		to_add->prev = tail;
		tail = to_add;
		to_add->val = data;
		if (head == NULL) //Если в списке нет элементов
			head = to_add;
		else
		{
			node* current;
			for (current = head; current->next != 0; current = current->next);
			current->next = to_add;
		}
		count++;
		return count;
	}

	int del(int x) //Удаление элемента из списка. Возвращает количество элементов в списке. 
	{			   //Возвращает -1, если произошла ошибка
		if (x > count) return -1;
		node* to_del = head;
		if (x == 1) //Если нужно удалить первый элемент
		{
			head = head->next;
			delete to_del;
		}
		else if (x == count) {
			to_del = tail;
			tail = tail->prev;
			delete to_del;
		}
		else
		{
			node* current = head;
			for (int i = 1; i < x - 1; i++)
				current = current->next;
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
		while (to_del != NULL)
		{
			current = current->next;
			delete to_del;
			to_del = current;
		}
		head = NULL;
		count = 0;
	}

	T getData(int x) const //Возвращает данные из списка.
	{
		node* current;
		for (current = head; x > 1; x--)
			current = current->next;
		return current->val;
	}

	void Inversion()
	{
		node* current;
		for (current = head; current != NULL; current = current->prev) {
			swap(current->next, current->prev);
		}
		swap(head, tail);
	}

	node find(T value) {
		node* current;
		for (int x = 0, current = head; current->val != value; current = current->next, x++) {
			if (x > count) {
				return NULL;
			}
		}
		return *current;
	}

	void Output() {
		for (node* current = head; current != NULL; current = current->next) {
			cout << current->val << " ";
		}
		cout << '\n';
	}
};


int main()
{
	list <int> MyList;
	MyList.add(1);
	MyList.add(2);
	MyList.add(3);
	MyList.add(4);
	MyList.add(5);
	MyList.add(6);
	MyList.add(7);
	MyList.add(8);
	MyList.Output();
	
	MyList.Inversion();
	MyList.Output();

	//MyList.del(2);
	//yList.Output();
}