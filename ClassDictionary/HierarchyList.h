#pragma once
#include <string>
class HierarchyList {
private:
	class node {
		friend class HierarchyList;
	private:
		node* next;
		HierarchyList* sublist;
		char sym;
		std::string translation;
		node() : next(NULL), sublist(NULL){}
		~node() {}
	};
	node* head;
	node* find(std::string);
	node* pr_find(std::string, int, HierarchyList*);
	node* insert(char, node*);
public:
	HierarchyList() : head(NULL) {}
	std::string get_translation(const std::string) const;
	void add_translation(std::string, std::string);

};
