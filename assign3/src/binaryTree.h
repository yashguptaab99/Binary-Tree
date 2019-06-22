//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Create Binary tree and perform following operations:
//					  a.Insert
//                    b.Display
//					  c.Depth of a tree
//					  d.Display leaf-nodes
//					  e.Create a copy of a tree
//============================================================================


#ifndef BINARYTREE_H_
#define BINARYTREE_H_

template<class T>
struct node
{
	T data;
	node* left;
	node* right;
};

template<class T>
class binaryTree
{

	node<T>* root;
	int count;

	public:
	binaryTree();

	void createTree(node<T>*);
	node<T>* getRoot();
	void setRoot(node<T>*);
	void inOrderDisplayRecursive(node<T>*);
	void preOrderDisplayRecursive(node<T>*);
	void postOrderDisplayRecursive(node<T>*);
	void inOrderDisplay();
	void preOrderDisplay();
	void postOrderDisplay();
	void breadthDisplay();
	int findHeight(node<T>*);
	void displayLeaf(node<T>*);
	node<T>* copyTree(node<T>*,int);
	void insert(T);

	~binaryTree();
};

#endif /* BINARYTREE_H_ */














