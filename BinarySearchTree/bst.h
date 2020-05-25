//#ifndef BST_H
//#define BST_H
//
//using namespace std;
//
//template <typename T, typename Y> class BinaryTree
//{
//private:
//	class node // ласс node содержит данные списка
//	{
//		friend class BinaryTree<T, Y>;
//	private:
//		node* right; //”казатель на правого ребенка
//		node* left; //”казатель на левого ребенка
//		T val; //’ранимые в €чейке данные
//		Y key; // люч €чейка
//
//		node() : next(NULL), prev(NULL) {}
//		~node() {
//			clear(); 
//		}
//	};
//
//	node* root; //”казатель на корень
//	int count; // оличество элементов дереве
//
//public:
//	BinaryTree();
//	~BinaryTree();
//	T at(Y);
//	void insert(node);
//	void del(Y);
//};
//#endif BST_H