//============================================================================
// Class            : SE9
// Batch            : F9
// Roll No.         : 23121
// Author           : Yash Gupta
// Assignment No.   : 1
// Problem Statement: Create Binary tree and perform following operations:
//                    a. Insert
//                    b. Display
//                    c. Depth of a tree
//                    d. Display leaf-nodes
//                    e. Create a copy of a tree
//============================================================================
#include<iostream>
using namespace std;
#include"binaryTree.cpp"
int main()
{
	int data,height;
	char choice,ch;
	binaryTree<int> copy;
	node<int>* temp = NULL;
	binaryTree<int> b1;
	cout<<"\n\n\t\t******CREATING THE TREE******";
	b1.createTree(b1.getRoot());
	do
	{
		cout<<"\n**********WELCOME TO THE MENU**********\n ";
		cout<<"\n\n\t\t1)Display Tree\n\n\t\t2)Insert Data\n\n\t\t3)Copy Tree\n\n\t\t4)Display Leaf Nodes\n\n\t\t5)Find Height\n\n\t\t6)Exit\n";
		cout<<"Enter the Choice : ";
		cin>>choice;
		switch(choice)
		{
			case '1' :
				cout<<"\n\nWhich tree display do you want to call : ";
				cout<<"\n		1) In-Order Display";
				cout<<"\n		2) Pre-Order Display";
				cout<<"\n		3) Post-Order Display";
				cout<<"\n		4) Non-recursive In-Order Display";
				cout<<"\n		5) Non-recursive Pre-Order Display";
				cout<<"\n		6) Non-recursive Post-Order Display";
				cout<<"\n		7) Breadth-Wise Display";
				cout<<"\nChoice : ";
				cin>>ch;
				switch(ch)
				{
					case '1' :
						cout<<"\n\n\t\tRECURSIVE INORDER DISPLAY IS::";
						b1.inOrderDisplayRecursive(b1.getRoot());
						cout<<"\n\n";
						break;
					case '2' :
						cout<<"\n\n\t\tRECURSIVE PREORDER DISPLAY IS::";
						b1.preOrderDisplayRecursive(b1.getRoot());
						cout<<"\n\n";
						break;
					case '3' :
						cout<<"\n\n\t\tRECURSIVE POSTORDER DISPLAY IS::";
						b1.postOrderDisplayRecursive(b1.getRoot());
						cout<<"\n\n";
						break;
					case '4' :
						cout<<"\n\n\t\tNONRECURSIVE INORDER DISPLAY IS::";
						b1.inOrderDisplay();
						cout<<"\n\n";
						break;
					case '5' :
						cout<<"\n\n\t\tNONRECURSIVE PREORDER DISPLAY IS::";
						b1.preOrderDisplay();
						cout<<"\n\n";
						break;
					case '6':
						cout<<"\n\n\t\tNONRECURSIVE POSTORDER DISPLAY IS::";
						b1.postOrderDisplay();
						cout<<"\n\n";
						break;
					case '7' :
						cout<<"\n\n\t\tBREADTH FIRST TREE TRAVERSAL DISPLAY IS::";
						b1.breadthDisplay();
						cout<<"\n\n";
						break;
				}
				break;
			case '2':
				cout<<"Enter the data you want to insert in the tree : ";
				cin>>data;
				b1.insert(data);
				break;
			case '3':
				cout<<"\n\n\t\t!!!COPY OF TREE CREATED!!!";
				temp = b1.copyTree(b1.getRoot(),1);
				copy.setRoot(temp);
				cout<<"\n\n\t\tRECURSIVE INORDER DISPLAY IS::";
				copy.inOrderDisplayRecursive(copy.getRoot());
				cout<<"\n\n\t\tRECURSIVE PREORDER DISPLAY IS::";
				copy.preOrderDisplayRecursive(copy.getRoot());
				cout<<"\n\n\t\tRECURSIVE POSTORDER DISPLAY IS::";
				copy.postOrderDisplayRecursive(copy.getRoot());
				break;
			case '4':
				cout<<"\n\n\t\tLEAF NODES OF TREE ARE::";
				b1.displayLeaf(b1.getRoot());
				cout<<"\n\n";
				break;
			case '5':
				height = b1.findHeight(b1.getRoot());
				cout<<"\n\n\t\tHEIGHT OF TREE IS::"<<height;
				cout<<"\n\n";
				break;
			case '6':
				cout<<"\n\n\t\tEXITING....";
				break;
		}
	}while(choice!='6');
	return 0;
}
