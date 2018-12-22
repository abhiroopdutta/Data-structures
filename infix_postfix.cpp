#include<iostream>
#include<stack>
#include<string>
using namespace std;

//program to convert infix expression to postfix


bool opening(char c)
{

	if( c == '{' || c == '[' || c == '(' )
		return true;
	else
		return false;
}

bool is_operator(char c)
{

	if( c == '+' || c == '-' || c == '*' || c == '/' )
		return true;
	else
		return false;

}

bool is_operand(char c)
{

	if( c >= 48 && c<=57 )
		return true;
	else 
		return false;

}



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


bool higher_precedence(char c1, char c2)
{

	if(  (c1 == '+')  &&   (c2 == '*')  )
		return true;     
	else if(  (c1 == '-')  &&   (c2 == '*')  )
		return true; 
	else if(  (c1 == '+')  &&   (c2 == '/')  )
		return true; 		
	else if(  (c1 == '-')  &&   (c2 == '/')  )
		return true; 
	else if(  (c1 == '+')  &&   (c2 == '+')  )
		return true; 	
	else if(  (c1 == '-')  &&   (c2 == '+')  )
		return true; 
	else if(  (c1 == '+')  &&   (c2 == '-')  )
		return true; 			                    
	 else if(  (c1 == '-')  &&   (c2 == '-')  )
		return true;
	else
		return false;


}


bool closing(char c)
{

	if( c == '}' || c == ']' || c == ')' )
		return true;
	else
		return false;


}




string postfix(string line)
{
	
	string res;
	stack<char> stk;

	for(string::size_type ix = 0; ix != line.size(); ix++)
	{

		if( opening(line[ix]) )
		{

			stk.push(line[ix]);
			
		}	

		else if ( is_operand(line[ix]) )
		{

			res += line[ix];
			
		}

		else if ( is_operator(line[ix]) )
		{
			while( !stk.empty() && higher_precedence(line[ix], stk.top() ) && !opening(stk.top()) )
				{
					res += stk.top();
					stk.pop();
					

				}
			
			stk.push(line[ix]);		
			
		}

		else if ( closing(line[ix]) )
		{	

			
			while(  !stk.empty() &&  !opening(stk.top()) )
			{

				res += stk.top();
				stk.pop();
				
			}

			stk.pop();
			

		}



	}

	while(!stk.empty())
	{
		res += stk.top();
		stk.pop();
	}
		
	return res;  

}

int main()
{

	cout<<"enter the expression"<<endl;
	string line;
	getline(cin, line);

	cout<<"postfix expression is : "<< postfix(line)<<endl;

	return 0;
}