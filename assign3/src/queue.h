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

#ifndef QUEUE_H_
#define QUEUE_H_

template<class T>
class queue
{
	private:
		T *data;
		int count;
		int front;
		int rear;
		int size;
	public:

		queue(int n);//Constructor

		void enqueue(T temp);//FUnction to insert element into queue from rear
		T dequeue();//Function to delete element from fromt
		int isEmpty();//Function to see is queue empty or not
		int isFull();//Function to see is queue full or not

		~queue();

};


#endif /* QUEUE_H_ */
