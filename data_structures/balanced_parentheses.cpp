#include<iostream>
#include<stack>
#include<list>
#include<string>
using std::string;
using namespace std;
using std::string;

stack < char, list<char> > stk;

bool match(char c1, char c2)
{

	if(  (c1 == '}')  &&   (c2 == '{')  )
		return true;     
	else if(  (c1 == ']')  &&   (c2 == '[')  )
		return true; 
	else if(  (c1 == ')')  &&   (c2 == '(')  )
		return true; 		                    
	else
		return false; 

}


bool balanced(string line)
{


for(string::size_type ix = 0; ix != line.size(); ix++)
		{

			if( line[ix] == '{' ||  line[ix] == '[' || line[ix] == '(' )
			stk.push(line[ix]); 

			else if( line[ix] ==  '}' || line[ix] == ']' || line[ix] == ')' )
			{
				if( line.empty() || !match(line[ix], stk.top()) )
					cout<< " not balanced "<<endl; 
				else
					stk.pop(); 

			}

		}

	if(stk.empty())
		cout<<" balanced "<<endl;
	else
		cout<<" not balanced"<<endl;



}

int main()
{

	cout<<"Enter the expression"<<endl;
	string line;
	getline(cin,line);


	balanced(line);


	
	


		
	return 0;
		
	

}