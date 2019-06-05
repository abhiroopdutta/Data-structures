    #include<iostream>
	#include<stack>
    using namespace std;

    struct node		//make a new data type called node, which has int type data, and a pointer to node next.
    {
        int data;	
        node *next;

    };

    class linked_list	
    {
        
        public:
            node *head; //a pointer to node named head is defined and initiliazed with the value NULL
        linked_list()
        {
            head=NULL;
        }



        //insertion at end is O(n)
        void insert_end(int n)		// to insert new node at end of the list, with data n
        {
            node *temp = new node;	//dynamically allocate space to  a node which is pointed by temp
            temp->data = n;		//put n in the data part
            temp->next = NULL;		//next pointer of the node is initialized to NULL

            if(head==NULL)
            {head = temp;}		//if list is empty, then head points to this new node

            else	
            {   
                node *temp1 = head;		// if list isn't empty, then traverse to the last node of the list
                while(temp1->next != NULL)	// and make the next pointer of the last node(which was pointing to NULL earlier)
                {  temp1 = temp1->next;  }	// point to the new node
                temp1->next = temp;
            }
        }



        //insertion at front is O(1)
        void insert_front(int n)		// to insert new node at front of the list
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

        //insertion at nth position is O(n)
        void insert_n(int n, int position)	//insert node at some given position
        {
            node *temp = new node;		//dynamically allocate space for the new node
            temp->data = n;			//put n in the data part
            temp->next = NULL;			//next pointer of the node is initialized to NULL

            node *temp1 = head;			
            for(int i=0; i< (position -2); i++)	//go the node just before the given position's node and get its next pointer
            {   				//make the pointer of the new node point to this next pointer
                temp1 = temp1->next;		// and now make the node just before the given position's node point to the new node.

            }

            temp->next = temp1->next;
            temp1->next = temp;

            
        } 

        
        //deletion at given position is O(n)
        void delete_it(int position)		//to delete node from a given position
        {
             node *temp = head;			//iniialize a pointer to node type to head for traversing

            if(position==1)			//for deletion at first position, head points to the second node and 
            {
		     head = temp->next;
		     delete temp;		// the previous node earlier being pointed by head is deleted
	        }	     

            for(int i=0; i<(position-2);i++)	//go to the previous node than the given position
            {temp = temp->next;} 		//make temp point to this previous node

            node *temp1 = temp->next;		//make temp1 point to the given position node

            temp->next = temp1->next;		//make the pointer of this temp node point to the given position's next node
            delete temp1;			// i.e., make pointer of temp node equal to pointer of temp1 node, and delete temp1
             
        }


        //time complexity of iterative reversal is O(n)
        //space complexity is O(1)
        void reverse()
        {
            node *temp = head; //points to the current node
            node *temp2 = NULL; //saves the pointer to the next node,i.e., saves the pointer "OF" the current node
            node *temp3 = NULL; //saves the pointer to the current node
            while(temp!=NULL)   
            {
                temp2 = temp->next; //save the pointer to the next node
                temp->next = temp3; //make the pointer "OF" the current node point to the previous node
                temp3 = temp;      //save the pointer to the current node, as the current node will be the previous node in next iteration
                temp = temp2;      //increment the current pointer to point to the next node, which was saved in temp2
            }
            head = temp3;
        }


        //time complexity is O(n)
        //space complexity is O(n)
        void reverse_recursion(node *p)
        {
            if(p->next == NULL) //when we reach the end of the list, make head point to the last node
                {
                    head = p;
                    return;
                } 

            reverse_recursion(p->next);
            node *q = p->next; //make q point to the next node from the current node
            q->next = p;       //access the pointer of the next node and make it point to the current node,i.e., point backwards
            p->next = NULL;    //make pointer of the current node point to NULL


        }



        void reverse_stack()
        {
        	stack<struct node* > stk;

        	node *temp = head;
        	while(temp != NULL)
        	{
        		stk.push(temp);
        		temp = temp->next;

        	}


        	
        
        	temp = stk.top();
        	head = temp;
        	stk.pop();

        	
        	while(!stk.empty())
        	{
        		temp->next = stk.top();
        		stk.pop();
        		temp = temp->next;
        		
        	}

        	temp->next = NULL;


			
        }



        //time complexity is O(n)
        //space complexity is O(1)
        void display()				//to display the list
        {
            node *temp1 = head;			//make pointer to a node to traverse the list
            while(temp1 != NULL)		//until we reach one past the last node, whose pointer points to null
            {   
                cout<< temp1->data << endl;	//display the data part of the node
                temp1 = temp1->next;		//make the pointer point to the next node
            }
            cout<<endl;
        }

       
        //time complexity is O(n)
        //space complexity is O(n)
        void display_recursion(node *p)     //a recursive function to display the list
        {   
            if(p==NULL)
                return;
            cout<< p->data <<endl;
            display_recursion(p->next);

        }


        //time complexity is O(n)
        //space complexity is O(n)
        void display_reverse_recursion(node *p)     //a recursive function to display the list
        {   
            if(p==NULL)
                return;
            
            display_reverse_recursion(p->next);
            cout<< p->data <<endl;

        }


        node * just_returns_head()      //a function that just returns the head pointer
        {   
            cout<<endl;
            return head;

        }






    };



    int main()
    {   
        linked_list object;
    
        object.insert_end(1);
        object.display();
        object.insert_end(2);
        object.display();
        object.insert_end(3);
        object.display();
        object.insert_end(4);
        object.display();
        
        object.reverse_stack();
        object.display();

        object.delete_it(3);
        object.display();
        object.reverse();
        object.display();

        node *x = object.just_returns_head();
        object.display_recursion(x);
        x = object.just_returns_head();
        object.display_reverse_recursion(x);

        x = object.just_returns_head();
        object.reverse_recursion(x);
        object.display();


       
        return 0;
    }
