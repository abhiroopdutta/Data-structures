	#include<iostream>
	#include<stack> //stack adaptor
	#include<queue> //both queue and priority queue adaptor
	#include<list> //if implementing adaptors on other than default container, then that containers header must be included

	using namespace std;

	

	stack<int> stk; //an empty stack is created, by default stack is implemented in terms of deque
	queue<int> que; //an empty queue is created, by default queue is implemented in terms of deque
	priority_queue<int> pque; //an empty priority queue is created, by default priority_queue is implemented in terms of vector


	//but we can override these
	stack< int, list<int> > stak; //stack can be built on vector, list or deque
									//queue can be built on list or deque as it requires push_front which is not supported by vector
								//priority_queue can be built on a vector or deque as it requires random access which isn't supported by list

	
	int main()
	{



		//common stack operations 
	stak.empty();
	stak.size();
	stak.pop(); //removes but does not return, the top element from the stack
	stak.push(0); //places a new top element on the stack
	stak.top(); //returns but does not remove, the top element from the stack
	stak.pop();




	//common queue, priority_queue operations
	que.empty();
	que.size();
	que.pop();	//removes but does not return the front element from the queue
	que.front(); //returns but does not remove the front element on the queue, this operation can be applied only to a queue
	que.back(); //returns but does not remove the back element on the queue, this operation can be applied only to a queue
	pque.top(); //returns but does not remove the highest priority element, this operation can be applied only to a priority_queue
	que.push(0); //places a new element at the end of the queue or at its appropriate position based on priority in a priority_queue





		return 0;
	}