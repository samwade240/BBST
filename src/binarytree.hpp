#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>

//******************Treap Tree classes********************
template<class T>
class TreapNode{
    public:
	T key;
	int priority;
	TreapNode<T> *left, *right;
	int height;
};

template<class T>
class TreapTree{
    private:
	TreapNode<T> *mRoot;
	int mSize;
    public:
	TreapNode<T>* rightRotate(TreapNode<T> *y);
	TreapNode<T>* leftRotate(TreapNode<T> *x);
	TreapNode<T>* newNode(T key);
	TreapNode<T>* search(T key);
	TreapNode<T>* searchHelp(TreapNode<T> *root, T key);
	TreapNode<T>* insert(TreapNode<T> *root, T key);
	TreapNode<T>* deleteNode(TreapNode<T> *root, T key);
	void inorder();

	TreapTree();
	TreapTree(const TreapTree<T> &tree);
	void put(const T &val);
	int getHeight();
	int getHeight(TreapNode<T> *N);
	bool contains(const T &val);
	bool remove(const T &val);
	std::string inorderString();
	void inOrderHelper(TreapNode<T> *root, std::string &ret);
	std::string preorderString();
	void preOrderHelper(TreapNode<T> *root, std::string &ret);
	std::string postorderString();
	void postOrderHelper(TreapNode<T> *root, std::string &ret);
	~TreapTree();
	int max(int a, int b){return(a > b)? a : b;}
	void destroyHelper(TreapNode<T> *N);
	void copyHelper(TreapNode<T> *N);

};

//**************AVL Tree classes**************
template<class T>
class AVLTreeNode{
    public:
    T key;
    AVLTreeNode<T> *left;
    AVLTreeNode<T> *right;
    int height;
};

template<class T>
class AVLTree{
    private:
	AVLTreeNode<T> *mRoot;
    public:
	AVLTree();
	AVLTree(const AVLTree<T> &tree);
	void put(const T &val);
	int getHeight();
	bool contains(const T &val);
	AVLTreeNode<T>* containsHelper(AVLTreeNode<T> *root, const T &val);
	bool remove(const T &val);
	std::string inorderString();
	std::string preorderString();
	std::string postorderString();
	~AVLTree();

	//AVL added functions 
	int max(int a, int b);
	int getheight(AVLTreeNode<T> *N);
	AVLTreeNode<T> *newAVLTreeNode(const T key);
	AVLTreeNode<T> *rightRotate(AVLTreeNode<T> *y);
	AVLTreeNode<T> *leftRotate(AVLTreeNode<T> *x);
	int getBalance(AVLTreeNode<T> *N);
	AVLTreeNode<T> *putHelper(AVLTreeNode<T> *node, const T key);
	AVLTreeNode<T> *minValueNode(AVLTreeNode<T> *node);
	AVLTreeNode<T> *removeHelper(AVLTreeNode<T> *root, const T key);
	void preOrderHelper(AVLTreeNode<T> *root, std::string &rey);
	void inOrderHelper(AVLTreeNode<T> *root, std::string &rey);
	void postOrderHelper(AVLTreeNode<T> *root, std::string &rey);
	void destroyHelper(AVLTreeNode<T> *N);
	void copyHelper(AVLTreeNode<T> *N);
};






#include "binarytree.cpp"
#endif

