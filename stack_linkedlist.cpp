	#include<iostream>
	
	using namespace std;


	struct node		//make a new data type called node, which has int type data, and a pointer to node next.
    {
        int data;	
        node *next;

    };

	class stack
	{

		public:
			
			node *head;

			stack()
			{
				head = NULL;
			}
			
			


		

		void push(int n)
		{	

			node *temp = new node;		//dynamically allocate space to a node which is pointed by temp
           temp->data = n;			//put n in the data part
           temp->next = NULL;			//next pointer of the node is initialized to NULL

           if(head==NULL)			//if list is empty, then head points to this node
           {head = temp;}			

           else
           {
               temp->next = head;		//if list isn't empty, then the new node becomes the first node, and 
               head = temp;			//next pointer of the new node points to the node earlier pointed by head
           } 					//and head now points to the first node,i.e., the new node


		
		}



		void pop()
		{
			
			 node *temp = head;			//iniialize a pointer to node type to head for traversing


            					//for deletion at first position, head points to the second node and 
		     head = temp->next;
		     delete temp;		// the previous node earlier being pointed by head is deleted
	             

		}

		void display()
		{
			 node *temp1 = head;			//make pointer to a node to traverse the list
            while(temp1 != NULL)		//until we reach the last node, whose pointer points to null
            {   
                cout<< temp1->data << endl;	//display the data part of the node
                temp1 = temp1->next;		//make the pointer point to the next node
            }
            cout<<endl;
			
		}

		bool isempty()
		{
			if(head==NULL)
				return true;
			else
				return false;
		}


		void show_top()
		{
			cout<< head->data<<endl;
			
		}



	};
	

	int main()
	{

		stack object;
		object.push(1);
		object.push(2);
		object.push(3);
		object.display();
		cout<<"1 for empty, 0 for not empty, likedlist is : "<<object.isempty()<<endl;	
		object.show_top();
		object.pop();
		cout<<endl;
		object.display();

		
		

		return 0;
	}
