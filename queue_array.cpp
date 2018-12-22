#include<iostream>
using namespace std;

const size_t max_size = 2;

int A[max_size];

//if we use linear array, then when elements will be deleted from the front
//there will be wastage, as that space will no longer be available for inserting
//new elements, so instead use circular array,
//where next position is give by  (i+1)%N , where N is the number of elements in the array
//and the previous position is given by (i+N-1)%N
//so array will be full only if (rear+1)%N = front

class queue
{
public:
	int front;
	int rear;

	queue()
	{
		front = -1;
		rear = -1;
	}
	

	//this takes O(1)
	bool is_empty() 
	{
		if(front == -1  &&  rear == -1)
			return true;
		else
			return false;
	}


	//this takes O(1)
	bool is_full()
	{

		if( (rear+1) % max_size == front)
			return true;
		else 
			return false;


	}


	//this takes O(1)
	void remove()
	{
		if(is_empty())
			cout<<"queue is empty"<<endl;
		else if(front == rear)
			front = rear = -1;
		else
			front = (front+1) % max_size  ;


	}

	
	//this takes O(1)
	void insert(int n)
	{
		if( is_full() )
		{	
			cout<<"queue full"<<endl;
			return;

		}

		else if (is_empty())
		{
			front = 0;
			rear = 0;
			A[rear] = n;
		}

		else
		{
			rear = (rear+1)% max_size ;
			A[rear] = n;

		}	


	}


	//this takes O(1)
	void show_front()
	{
		if(front == -1)
			cout<<"stack is empty()" <<endl;
		else
		cout<<A[front]<<endl;

	}


	//this function needs to be modified
	void show()
	{	
		int count = 0;
		if(rear >= 0 && rear < front)
			count = (rear+max_size) - front  + 1;  //new rear  = rear + max_size
		else
			count = rear - front + 1;

		int x = front;
		for(int i = 0; i < count; i++)
			{
				cout<<A[x]<<" this is "<<i<<"st iteration"<<endl;
				x = (x+1)%max_size ;
			}	
	}
};


int main()
{
	queue object;
	object.insert(1);
	object.insert(2);
	
	object.show();
	object.remove();
	object.insert(3);
	object.show();
	object.show_front();


	return 0;
}