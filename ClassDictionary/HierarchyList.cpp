#include "HierarchyList.h"

HierarchyList::node* HierarchyList::find(std::string word) {
	return pr_find(word, 0, this);
}

HierarchyList::node* HierarchyList::pr_find(std::string word, int index, HierarchyList* current) {

}

HierarchyList::node* HierarchyList::insert(char symbol, HierarchyList* current) {
	node* current = head;
	for (; current->next != NULL, symbol < current->next->sym; current = current->next);
	node* to_add = new node();
	to_add->sym = symbol;
	to_add->next = current->next;
	current->next = to_add;
}

void HierarchyList::add_translation(std::string word, std::string translation) {
	find(word);
}