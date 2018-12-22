#include<iostream>
using namespace std;

struct node		//make a new data type called node, which has int type data, and a pointer to node next.
    {
        int data;	
        node *next;

    };


class queue
{

	public:
		node *front;
		node *rear;

	queue()
	{
		front = NULL;
		rear = NULL;
	}	

	void push(int n)
	{
		node *temp = new node;

		if(front == NULL && rear == NULL)
		{
			front = temp;
			rear = temp;

		}

		else
		{
			
			rear->next = temp;
			rear = temp;

		}

	}



	void pop()
	{
		node *head = front;
		node *temp = head;
		
		if(head == NULL && rear == NULL)
			cout<<"its empty" <<endl;


		else if(head == rear)
			{
				temp = head;
				head = rear = NULL;
				delete temp;
			}

		else	
			{
				head = temp->next;
				delete temp;
			}

	}


	void display(node *x)
	{
		
		if(x->next == NULL)
			return;
		cout<<x->data<<endl;
		display(x->next);


	}


	node *return_front()
	{

		return front;
	}

};


int main()
{

	queue object;
	object.push(1);
	object.push(2);
	object.push(3);
	node *x = object.return_front();
	object.display(x);
	object.pop();


	node *x = object.return_front();
	object.display(x);

	return 0;
}