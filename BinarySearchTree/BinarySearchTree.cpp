#include <iostream>
using namespace std;

template <typename T, typename Y> class btree {

private:

	class node // ласс node содержит данные списка
	{
		friend class btree <typename T, typename Y>;
	private:
		node* right; //”казатель на правого ребенка
		node* left; //”казатель на левого ребенка
		T key;
		Y val;

		node() : right(NULL), left(NULL) {}
	};
	
	node* root;
	int count;

	node* find_place(node* to_place, node* current) {
		if ((to_place->key > current->key) && (current->right != NULL)) {
			return find_place(to_place, current->right);
		}
		else if ((to_place->key > current->key) && (current->right == NULL)) {
			return current;
		}


		if ((to_place->key < current->key) && (current->left != NULL)) {
			return find_place(to_place, current->left);
		}
		else if ((to_place->key < current->key) && (current->left == NULL)) {
			return current;
		}
	}

	void print_subtree(node* Current) {
		if (Current != NULL) {
			print_subtree(Current->left);
			cout << Current->key << " " << Current->val << "\n";
			print_subtree(Current->right);
		}
	}

public:
	btree() : root(NULL), count(0){}


	
	void insert(T Key, Y Val) {
		node* to_add = new node;
		to_add->key = Key;
		to_add->val = Val;

		if (count == 0) {
			root = to_add;
		}
		else {
			node* leaf;
			node* current;
			current = root;
			leaf = find_place(to_add, current);
			if (to_add->key > leaf->key) {
				leaf->right = to_add;
			}
			else if (to_add->key < leaf->key) {
				leaf->left = to_add;
			}
		}
		count++;
	}

	node search(T Key) {
		node* current;
		current = root;
		bool go_on = true;
		while (go_on) {
			if ((current->right != NULL) && (Key > current->key)) {
				current = current->right;
			}
			else if (current->right == NULL) {
				go_on = false;
			}


			if ((current->left != NULL) && (Key > current->key)) {
				current = current->left;
			}
			else if (current->left == NULL) {
				go_on = false;
			}

			if (Key == current->key) {
				return *current;
			}
		}
	}

	node* search_parent(T Key) {
		node* current;
		current = root;
		bool go_on = true;
		while (go_on) {
			if (((current->left != NULL) && (Key == current->left->key)) || ((current->right != NULL) && (Key == current->right->key))) {
				return current;
			}

			if ((current->right != NULL) && (Key > current->key)) {
				current = current->right;
			}
			else if (current->right == NULL) {
				go_on = false;
			}

			else {
				if ((current->left != NULL) && (Key > current->key)) {
					current = current->right;
				}
				else if (current->left == NULL) {
					go_on = false;
				}
			}
		}
		return NULL;
	}

	int get_count() {
		return count;
	}

	void print_tree() {
		node* current = new node;
		current = root;
		print_subtree(current);
	}

	void delete_node(T Key) {
		node* to_del;
		node* to_del_parent;
		node* leaf_parent;
		to_del_parent = search_parent(Key);
		if (to_del_parent == NULL) {
			cout << "Element with the key (" << Key << ") not found\n";
		}
		if (Key == to_del_parent->left->key) {
			to_del = to_del_parent->left;
		}
		else if (Key == to_del_parent->right->key) {
			to_del = to_del_parent->right;
		}

		if (to_del->left != NULL) {
			for (leaf_parent = to_del->left; leaf_parent->right->right != NULL; leaf_parent = leaf_parent->right);
			if (Key == to_del_parent->left->key) {
				to_del_parent->left = leaf_parent->right;
			}
			else if (Key == to_del_parent->right->key) {
				to_del_parent->right = leaf_parent->right;
			}
			to_del_parent->right->right = to_del->right;
			to_del_parent->left->left = to_del->left;
			leaf_parent->right = NULL;
		}
		else if (to_del->right != NULL) {
			for (leaf_parent = to_del->right; (leaf_parent->left != NULL) && (leaf_parent->left->left != NULL); leaf_parent = leaf_parent->left);
			if (Key == to_del_parent->left->key) {
				to_del_parent->left = leaf_parent->left;
			}
			else if (Key == to_del_parent->right->key) {
				to_del_parent->right = leaf_parent->left;
			}
			to_del_parent->right->right = to_del->right;
			to_del_parent->left->left = to_del->left;
			leaf_parent->left = NULL;
		}
		delete to_del;
	}
};


int main() {
	btree<int, string> MyTree;
	MyTree.insert(20, "");
	MyTree.insert(10, "");
	MyTree.insert(30, "");
	MyTree.insert(40, "");
	MyTree.insert(5, "");
	MyTree.insert(15, "");
	MyTree.insert(35, "");
	MyTree.insert(45, "");
	MyTree.insert(31, "");
	MyTree.print_tree();
	MyTree.delete_node(30);
	std::cout << "\n";
	MyTree.print_tree();
	//std::cout<<MyTree.get_count();
	return 0;
}