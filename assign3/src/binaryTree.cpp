//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 3
// Problem Statement: Create Binary tree and perform following operations:
//					  a.Insert
//                    b.Display
//					  c.Depth of a tree
//					  d.Display leaf-nodes
//					  e.Create a copy of a tree
//============================================================================

#include <stdio.h>
#include <iostream>
#include "binaryTree.h"
#include "stack.cpp"
#include "queue.cpp"
using namespace std;

template<class T>
binaryTree<T>::binaryTree()
{
	root=NULL;
	count=0;
}


template<class T>
binaryTree<T>::~binaryTree()
{

}

template<class T>
void binaryTree<T> :: createTree(node<T>* temp)
{
	node<T>* currNode = temp;
	T dat;
	char choice;
	if(root==NULL)
	{
		cout<<"\n\t\tEnter the data for root node:: ";
		cin>>dat;
		currNode = new node<T>;
		currNode->data=dat;
		root=currNode;
		count++;
		createTree(currNode);
	}
	else
	{
		if(currNode->left==NULL)
		{
			cout<<"Current Node Data -> "<<currNode->data<<endl;
			cout<<"\n\nDo you want to enter data in the left child of the current node :\n[Press 0 - No / Press 1 - Yes]::";
			cin>>choice;
			while(choice!='0' && choice !='1')
			{
				cout<<"\n\n\t\tINVALID ENTRY";
				cout<<"\n\nDo you want to enter data in the left child of the current node :\n[Press 0 - No / Press 1 - Yes]::";
				cin>>choice;
			}
			if(choice=='0')
			{
				currNode->left=NULL;
			}
			else if(choice =='1')
			{
				node<T>* newNode;
				newNode = new node<T>;
				cout<<"\n\t\tEnter the data for left child node:: ";
				cin>>dat;
				newNode->data=dat;
				currNode->left=newNode;
				count++;
				createTree(currNode->left);
			}

		}
		if(currNode->right==NULL)
		{
			cout<<"Current Node Data -> "<<currNode->data<<endl;
			cout<<"\n\nDo you want to enter data in the right child of the current node :\n[Press 0 - No / Press 1 - Yes]::";
			cin>>choice;
			while(choice!='0' && choice !='1')
			{
				cout<<"\n\n\t\tINVALID ENTRY";
				cout<<"\n\nDo you want to enter data in the left child of the current node :\n[Press 0 - No / Press 1 - Yes]::";
				cin>>choice;
			}

			if(choice=='0')
			{
				currNode->right=NULL;
			}
			else if(choice == '1')
			{
				node<T>* newNode;
				newNode = new node<T>;
				cout<<"\n\t\tEnter the data for right child node:: ";
				cin>>dat;
				newNode->data=dat;
				currNode->right=newNode;
				count++;
				createTree(currNode->right);
			}
		}
	}

}

template<class T>
node<T>* binaryTree<T> :: getRoot()
{
	return root;
}

template<class T>
void binaryTree<T> :: setRoot(node<T>* temp)
{
	this->root = temp;
}

template<class T>
void binaryTree<T> :: inOrderDisplayRecursive(node<T>* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 if(temp->left != NULL)
		 {
			 inOrderDisplayRecursive(temp->left);
		 }

		 cout<<temp->data<<"   ";

		 if(temp->right != NULL)
		 {
			 inOrderDisplayRecursive(temp->right);
		 }
	}


}

template<class T>
void binaryTree<T> :: preOrderDisplayRecursive(node<T>* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 cout<<temp->data<<"   ";

		 if(temp->left != NULL)
		 {
			 preOrderDisplayRecursive(temp->left);
		 }

		 if(temp->right != NULL)
		 {
			 preOrderDisplayRecursive(temp->right);
		 }
	}
}

template<class T>
void binaryTree<T> :: postOrderDisplayRecursive(node<T>* temp)
{
	if(root == NULL)
	{
		cout<<"Tree not created \n";
	}
	else
	{
		 if(temp->left != NULL)
		 {
			 postOrderDisplayRecursive(temp->left);
		 }

		 if(temp->right != NULL)
		 {
			 postOrderDisplayRecursive(temp->right);
		 }

		 cout<<temp->data<<"   ";
	}
}

template<class T>
void binaryTree<T> :: inOrderDisplay()
{
	node<T> *temp;
	temp = root;
	stack<node<T>*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			stack.push(temp);
			temp = temp->left;
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
			cout<<temp->data<<"   ";
		}
		temp = temp->right;
	}

}

template<class T>
void binaryTree<T> :: preOrderDisplay()
{
	node<T> *temp;
	temp = root;
	stack<node<T>*> stack;
	if(temp == NULL)
	{
		cout<<"Empty Tree/n";
	}
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			cout<<temp->data<<"   ";
			stack.push(temp);
			temp = temp->left;
		}
		if(stack.isEmpty() == 0)
		{
			temp = stack.pop();
		}
		temp = temp->right;
	}

}

template<class T>
void binaryTree<T> :: postOrderDisplay()
{
	int flag=0;
	node<T> *temp;
	temp = root;
	stack<int> stack1;
	stack<node<T>*> stack2;
	int i=0;
	while(temp != NULL)
	{
		stack2.push(temp);
		stack1.push(0);
		temp = temp->left;
	}
	while(i<count)
	{
		temp = stack2.pop();
		flag = stack1.pop();
		if(flag == 1)
		{
			cout<<temp->data<<"   ";
			i++;
		}
		else
		{
			stack1.push(1);
			stack2.push(temp);
			temp = temp->right;
			while(temp != NULL)
			{
				stack2.push(temp);
				stack1.push(0);
				temp = temp->left;
			}
		}
	}

}

template<class T>
void binaryTree<T> :: breadthDisplay()
{
	node<T> *temp = NULL;
	temp = root;
	queue<node<T>*> Q1(50);
	if(temp == NULL)
	{
		cout<<"Tree is Empty/n";
	}
	else
	{
		while(temp!=NULL)
		{
			cout<<temp->data<<"   ";
			if(temp->left != NULL)
			{
				Q1.enqueue(temp->left);
			}
			if(temp->right != NULL)
			{
				Q1.enqueue(temp->right);
			}
			if(Q1.isEmpty()==0)
			{
				temp = Q1.dequeue();
			}
			else
				temp = NULL;
		}
	}

}

template<class T>
int binaryTree<T> :: findHeight(node<T>* temp)
{
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		return 1+max(findHeight(temp->left),findHeight(temp->right));
	}

}

template<class T>
void binaryTree<T> :: displayLeaf(node<T>* temp)
{
	if(root == NULL)
	{
		cout<<"Tree is Empty/n";
	}
	else
	{
		if(temp->left!=NULL || temp->right != NULL)
		{
			if(temp->left != NULL)
			{
				displayLeaf(temp->left);
			}

			if(temp->right != NULL)
			{
				displayLeaf(temp->right);
			}
		}
		else
		{
			cout<<"   "<<temp->data;
		}
	}

}

template<class T>
node<T>* binaryTree<T> :: copyTree(node<T>* temp,int flag)
{
	node<T> *copy = NULL;
	if(temp != NULL)
	{
		copy = new node<T>;
		copy->data = temp->data;

		if(temp->left != 0)
		{
			copy->left = temp->left;
			copyTree(temp->left,0);
		}

		if(temp->right != 0)
		{
			copy->right = temp->right;
			copyTree(temp->right,0);
		}
	}
	if(flag == 1)
	{
		return copy;
	}

}

template<class T>
void binaryTree<T> :: insert(T data)
{
	char ch;
	int flag = 0;
	T dat;
	node<T> *node1 = NULL;
	stack<node<T>*> stack;
	node<T> *temp = NULL;
	temp = root;
	cout<<"Enter the data of Parent Node : ";
	cin>>dat;
	while(temp != NULL || stack.isEmpty() == 0)
	{
		while(temp != NULL)
		{
			if(temp->data == dat)
			{
				flag = 1;
				break;
			}
			else
			{
				stack.push(temp);
				temp = temp->left;
			}
		}
		if(flag == 0)
		{
			if(stack.isEmpty() == 0)
			{
				temp = stack.pop();
			}
			temp = temp->right;
		}
		else if(flag == 1)
			break;
	}
	if(flag == 1)
	{
		cout<<"\n\nDo you want to enter the new data as left child or right child of the parent node:\n[L-Press 1/R-Press 2]::";
		cin>>ch;
		while(ch!='1' && ch!='2')
		{
			cout<<"\n\n\t\tINVALID ENTRY";
			cout<<"\n\nDo you want to enter the new data as left child or right child of the parent node:\n[L-Press 1/R-Press 2]::";
			cin>>ch;
		}

		if(ch == '1')
		{
			node1 = new node<T>;
			node1->data=data;
			temp->left=node1;
		}
		else if(ch == '2')
		{
			node1 = new node<T>;
			node1->data=data;
			temp->right=node1;
		}
	}

}




