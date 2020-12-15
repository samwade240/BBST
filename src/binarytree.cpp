
#include<bits/stdc++.h>
using namespace std;

//Treap: https://www.geeksforgeeks.org/treap-set-2-implementation-of-search-insert-and-delete/


template<class T>
TreapTree<T>::TreapTree(){
	mRoot = NULL;
}

template<class T>
TreapTree<T>::TreapTree(const TreapTree<T> &tree){
	mRoot = tree.mRoot;
	copyHelper(tree.mRoot);
}

template<class T>
void TreapTree<T>::copyHelper(TreapNode<T> *N){
	if(N){
		put(N->key);
		copyHelper(N->left);
		copyHelper(N->right);
	}
}

template<class T>
void TreapTree<T>::destroyHelper(TreapNode<T> *N){
	if(N){
		destroyHelper(N->left);
		destroyHelper(N->right);
		delete(N);
	}
}

template<class T>
TreapTree<T>::~TreapTree(){
	destroyHelper(mRoot);
}

template<class T>
int TreapTree<T>::getHeight(TreapNode<T> *N){
	if(N == NULL){return 0;}
	else{
		int lDepth = getHeight(N->left);
		int rDepth = getHeight(N->right);

		if(lDepth > rDepth)
			return lDepth +1;
		else
			return rDepth +1;
	}
}

template<class T>
int TreapTree<T>::getHeight(){
	return getHeight(mRoot);
}

template<class T>
void TreapTree<T>::put(const T &val){
	TreapNode<T> *root = mRoot;
	mRoot = insert(root, val);
	return;
}

template<class T>
bool TreapTree<T>::remove(const T &val){
	TreapNode<T> *root = mRoot;
	mRoot = deleteNode(root, val);
	return true;
}

template<class T>
TreapNode<T>* TreapTree<T>::rightRotate(TreapNode<T> *y)
{
    TreapNode<T> *x = y->left,  *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;


    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
template<class T>
TreapNode<T>* TreapTree<T>::leftRotate(TreapNode<T> *x)
{
    TreapNode<T> *y = x->right, *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Return new root
    return y;
}

/* Utility function to add a new key */
template<class T>
TreapNode<T>* TreapTree<T>::newNode(T key)
{
    TreapNode<T>* temp = new TreapNode<T>;
    temp->key = key;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    return temp;
}

template<class T>
TreapNode<T> * TreapTree<T>::search(T key){
	TreapNode<T> *root = mRoot;
	return searchHelp(root, key);
}

// C function to search a given key in a given BST
template<class T>
TreapNode<T>* TreapTree<T>::searchHelp(TreapNode<T> *root, T key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;

    // Key is greater than root's key
    if (root->key < key)
       return searchHelp(root->right, key);

    // Key is smaller than root's key
    return searchHelp(root->left, key);
}

/* Recursive implementation of insertion in Treap */
template<class T>
TreapNode<T>* TreapTree<T>::insert(TreapNode<T>* root, T key)
{
    // If root is NULL, create a new node and return it
    if (!root){
        return newNode(key);
    }


    // If key is smaller than root
    if (key <= root->key)
    {
        // Insert in left subtree
        root->left = insert(root->left, key);

        // Fix Heap property if it is violated
        if (root->left->priority > root->priority)
	    root = rightRotate(root);
    }
    else  // If key is greater
    {
        // Insert in right subtree
        root->right = insert(root->right, key);

        // Fix Heap property if it is violated
        if (root->right->priority > root->priority)
	    root = leftRotate(root);
    }
    return root;
}

/* Recursive implementation of Delete() */
template<class T>
TreapNode<T>* TreapTree<T>::deleteNode(TreapNode<T>* root, T key)
{
    if (root == NULL){
	return root;
    }


    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // IF KEY IS AT ROOT

    // If left is NULL
    else if (root->left == NULL)
    {
        TreapNode<T> *temp = root->right;
        delete(root);

        root = temp; // Make right child as root
    }

    // If Right is NULL
    else if (root->right == NULL)
    {
        TreapNode<T> *temp = root->left;
        delete(root);

        root = temp; // Make left child as root
    }

    // If ksy is at root and both left and right are not NULL
    else if (root->left->priority < root->right->priority)
    {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root = rightRotate(root);
        root->right = deleteNode(root->right, key);
	}


    return root;
}

template<class T>
std::string TreapTree<T>::preorderString(){
	TreapNode<T> *root = mRoot;
	std::string temp = "";
	preOrderHelper(root, temp);
	return temp;
}

template<class T>
void TreapTree<T>::preOrderHelper(TreapNode<T> *root, std::string &ret){
           if(!root){return;}
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";
        preOrderHelper(root->left, ret);
        preOrderHelper(root->right,ret);
}

template<class T>
std::string TreapTree<T>::inorderString(){
	TreapNode<T> *root = mRoot;
	std::string temp = "";
	inOrderHelper(root,temp);
	return temp;
}

// A utility function to print inorder
// traversal of the tree.
// The function also prints height
// of every node
template<class T>
void TreapTree<T>::inOrderHelper(TreapNode<T> *root, std::string &ret)
{
           if(!root){return;}
        inOrderHelper(root->left, ret);
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";
        inOrderHelper(root->right,ret);

}
template<class T>
std::string TreapTree<T>::postorderString(){
	TreapNode<T> *root = mRoot;
	std::string temp = "";
	postOrderHelper(root,temp);
	return temp;
}

// A utility function to print postorder
// traversal of the tree.
// The function also prints height
// of every node
template<class T>
void TreapTree<T>::postOrderHelper(TreapNode<T> *root, std::string &ret)
{
           if(!root){return;}
        postOrderHelper(root->right,ret);
        postOrderHelper(root->left, ret);
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";

}



//
//
//
//
//
//
//
//
//
// Avl https://www.geeksforgeeks.org/avl-tree-set-2-deletion/
template<class T>
AVLTree<T>::AVLTree(){
	mRoot = NULL;
}

template<class T>
AVLTree<T>::AVLTree(const AVLTree<T> &tree){
	mRoot = tree.mRoot;
	copyHelper(tree.mRoot);
}

template<class T>
void AVLTree<T>::copyHelper(AVLTreeNode<T> *N){
	if(N){
		put(N->key);
		copyHelper(N->left);
		copyHelper(N->right);
	}
}

template<class T>
void AVLTree<T>::destroyHelper(AVLTreeNode<T> *N){
}

template<class T>
AVLTree<T>::~AVLTree(){
	mRoot = NULL;
}

// A utility function to get height
// of the tree
template<class T>
int AVLTree<T>::getheight(AVLTreeNode<T> *N)
{
	if (N == NULL)
	return 0;
	return N->height;
}

template<class T>
int AVLTree<T>::getHeight()
{
	AVLTreeNode<T> *N = mRoot;
	if (N == NULL)
	return 0;
	return N->height;
}

// A utility function to get maximum 
// of two integers
template<class T>
int AVLTree<T>::max(int a, int b){
	return (a > b)? a : b;
}

/* Helper function that allocates a
 new node with the given key and
 NULL left and right pointers. */
template<class T>
AVLTreeNode<T>* AVLTree<T>::newAVLTreeNode(T key){

	AVLTreeNode<T>* node = new AVLTreeNode<T>();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; // new node is initially 
	// added at leaf
	return(node);
}

// A utility function to right 
// rotate subtree rooted with y
// See the diagram given above.
template<class T>
AVLTreeNode<T>* AVLTree<T>::rightRotate(AVLTreeNode<T> *y)
{
AVLTreeNode<T> *x = y->left;
AVLTreeNode<T> *T2 = x->right;

// Perform rotation
x->right = y;
y->left = T2;

// Update heights
y->height = max(getheight(y->left),
getheight(y->right)) + 1;
x->height = max(getheight(x->left),
getheight(x->right)) + 1;

// Return new root
return x;
}

// A utility function to left
// rotate subtree rooted with x
// See the diagram given above.
template<class T>
AVLTreeNode<T>* AVLTree<T>::leftRotate(AVLTreeNode<T> *x)
{
AVLTreeNode<T> *y = x->right;
AVLTreeNode<T> *T2 = y->left;

// Perform rotation
y->left = x;
x->right = T2;

// Update heights
x->height = max(getheight(x->left),
getheight(x->right)) + 1;
y->height = max(getheight(y->left),
getheight(y->right)) + 1;

// Return new root
return y;
}

// Get Balance factor of node N
template<class T>
int AVLTree<T>::getBalance(AVLTreeNode<T> *N)
{
if (N == NULL)
return 0;
return getheight(N->left) -
 getheight(N->right);
}


template<class T>
void AVLTree<T>::put(const T &val){
	AVLTreeNode<T> *root = mRoot;
	mRoot = putHelper(root, val);
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::putHelper(AVLTreeNode<T> *node, T key){

	/* 1. Perform the normal BST rotation */
	if (node == NULL)
		return(newAVLTreeNode(key));

	if (key < node->key)
		node->left = putHelper(node->left, key);
	else if (key > node->key)
		node->right = putHelper(node->right, key);
	else // Equal keys not allowed
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(getheight(node->left), getheight(node->right));

	/* 3. Get the balance factor of this
	ancestor node to check whether
	this node became unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, 
	// then there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

// Right Left Case
	if (balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
template<class T>
AVLTreeNode<T>* AVLTree<T>::minValueNode(AVLTreeNode<T>* node){
	AVLTreeNode<T>* current = node;

/* loop down to find the leftmost leaf */
	while (current->left != NULL)
	current = current->left;

	return current;
}

template<class T>
bool AVLTree<T>::contains(const T &val){
	AVLTreeNode<T> *root = mRoot;
	AVLTreeNode<T> *temp = NULL;
	temp = containsHelper(root, val);
	if(temp != NULL){return true;}
	else{return false;}
}

template<class T>
AVLTreeNode<T>* AVLTree<T>::containsHelper(AVLTreeNode<T> *root, const T &key){
// STEP 1: PERFORM STANDARD BST DELETE
if (root == NULL)
return root;

// If the key to be deleted is smaller
// than the root's key, then it lies 
// in left subtree
if ( key < root->key )
root->left = containsHelper(root->left, key);

// If the key to be deleted is greater
// than the root's key, then it lies
// in right subtree
else if( key > root->key )
root->right = containsHelper(root->right, key);

// if key is same as root's key, then
// This is the node to be deleted
else
{
// node with only one child or no child
if( (root->left == NULL) || 
(root->right == NULL) )
{
AVLTreeNode<T> *temp = root->left ?
 root->left :
 root->right;

// No child case
if (temp == NULL)
{
temp = root;
root = NULL;
}
else // One child case
*root = *temp; // Copy the contents of
 // the non-empty child
return temp;
}
else
{
// node with two children: Get the inorder
// successor (smallest in the right subtree)
AVLTreeNode<T>* temp = minValueNode(root->right);

// Copy the inorder successor's
// data to this node
root->key = temp->key;

// Delete the inorder successor
root->right = containsHelper(root->right,
 temp->key);
}
}

// If the tree had only one node 
// then return
if (root == NULL)
return root;

}


template<class T>
bool AVLTree<T>::remove(const T &val){
	AVLTreeNode<T> *root = mRoot;
	mRoot = removeHelper(root, val);
	return true;
}

// Recursive function to delete a node
// with given key from subtree with
// given root. It returns root of the
// modified subtree.
template<class T>
AVLTreeNode<T>* AVLTree<T>::removeHelper(AVLTreeNode<T>* root, T key){

// STEP 1: PERFORM STANDARD BST DELETE
if (root == NULL)
return root;

// If the key to be deleted is smaller
// than the root's key, then it lies 
// in left subtree
if ( key < root->key )
root->left = removeHelper(root->left, key);

// If the key to be deleted is greater
// than the root's key, then it lies
// in right subtree
else if( key > root->key )
root->right = removeHelper(root->right, key);

// if key is same as root's key, then
// This is the node to be deleted
else
{
// node with only one child or no child
if( (root->left == NULL) || 
(root->right == NULL) )
{
AVLTreeNode<T> *temp = root->left ?
 root->left :
 root->right;

// No child case
if (temp == NULL)
{
temp = root;
root = NULL;
}
else // One child case
*root = *temp; // Copy the contents of
 // the non-empty child
delete(temp);
}
else
{
// node with two children: Get the inorder
// successor (smallest in the right subtree)
AVLTreeNode<T>* temp = minValueNode(root->right);

// Copy the inorder successor's
// data to this node
root->key = temp->key;

// Delete the inorder successor
root->right = removeHelper(root->right,
 temp->key);
}
}

// If the tree had only one node 
// then return
if (root == NULL)
return root;

// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
root->height = 1 + max(getheight(root->left),
 getheight(root->right));

// STEP 3: GET THE BALANCE FACTOR OF
// THIS NODE (to check whether this
// node became unbalanced)
int balance = getBalance(root);

// If this node becomes unbalanced,
// then there are 4 cases

// Left Left Case
if (balance > 1 &&
getBalance(root->left) >= 0)
return rightRotate(root);

// Left Right Case
if (balance > 1 &&
getBalance(root->left) < 0)
{
root->left = leftRotate(root->left);
return rightRotate(root);
}

// Right Right Case
if (balance < -1 &&
getBalance(root->right) <= 0)
return leftRotate(root);

// Right Left Case
if (balance < -1 &&
getBalance(root->right) > 0)
{
root->right = rightRotate(root->right);
return leftRotate(root);
}

return root;
}

template<class T>
std::string AVLTree<T>::preorderString(){
	AVLTreeNode<T> *root = mRoot;
	std::string temp = "";
	preOrderHelper(root,temp);
	return temp;
}

// A utility function to print preorder
// traversal of the tree.
// The function also prints height
// of every node
template<class T>
void AVLTree<T>::preOrderHelper(AVLTreeNode<T> *root, std::string &ret)
{
           if(!root){return;}
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";
        preOrderHelper(root->left, ret);
        preOrderHelper(root->right,ret);

}

template<class T>
std::string AVLTree<T>::inorderString(){
	AVLTreeNode<T> *root = mRoot;
	std::string temp = "";
	inOrderHelper(root,temp);
	return temp;
}

// A utility function to print inorder
// traversal of the tree.
// The function also prints height
// of every node
template<class T>
void AVLTree<T>::inOrderHelper(AVLTreeNode<T> *root, std::string &ret)
{
           if(!root){return;}
        inOrderHelper(root->left, ret);
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";
        inOrderHelper(root->right,ret);

}
template<class T>
std::string AVLTree<T>::postorderString(){
	AVLTreeNode<T> *root = mRoot;
	std::string temp = "";
	postOrderHelper(root,temp);
	return temp;
}

// A utility function to print postorder
// traversal of the tree.
// The function also prints height
// of every node
template<class T>
void AVLTree<T>::postOrderHelper(AVLTreeNode<T> *root, std::string &ret)
{
           if(!root){return;}
        postOrderHelper(root->right,ret);
        postOrderHelper(root->left, ret);
        std::stringstream val;
        val << root->key;
        ret += val.str();
        ret += " ";

}






