	#include<iostream>
	
	using namespace std;

	const size_t max_size = 100 ;

	class stack
	{

		public:
			
			int top; 
			
			int A[max_size];


		stack()
		{

			 top = -1;

		}

		//this takes O(1)
		void push(int n)
		{	

			if(top == (max_size - 1))
			{
				cout<<"Stack overflow !"<<endl;
				return;
			}
		
			A[++top] = n; 
		

		
		}

		//this takes O(1)
		void pop()
		{
			if(top == -1)
			{
				cout<<"Stack empty !"<<endl;
				return;
			}

			top--;
		}

		void display()
		{
	
			for(int i = top; i>=0; i--)
			cout<<A[i]<<endl;

		}

		bool isempty()
		{
			if(top==-1)
				return true;
			else
				return false;
		}

		
		void show_top()
		{
			cout<< A[top]<<endl;
		}



	};
	

	int main()
	{

		stack object;
		object.push(1);
		object.push(2);
		object.push(3);
		object.display();
		object.isempty();
		object.show_top();

		


		return 0;
	}
