#include<iostream>
#include<vector>	//fast random access, fast insertion/deletion at the back, slow in the middle
#include<deque>		//fast random access, fast insertion/deletion both at the back and front, slow in the middle
#include<list>		//slow random access, fast insertion/deletion anywhere
using namespace std;
using std::vector;


vector<int> A(10); 		//A has 10 elements of int type value initialized to 0
vector<int> B(10,5);	//B has 10 elements of int type initialized to 5
vector<int> C(B); 		//C is initialized as copy of B
vector<int> D;		//D is an empty vector which will hold elements of type int
					//using the default container constructor gives the best run time performance

list<int> X; //X is an empty list, default constructor


//left-inclusive interval, the element range of vector is
//[ first, last )  includes first and each element up to but not including last

vector<int> E(A.begin(), A.end());	//initialize E with copy of each element of A, end refers to one past the last element
vector<int>::iterator mid = A.begin() + A.size()/2 ; //mid points to the mid point of the vector
vector<int> F(A.begin(), mid) ; //initialize F with first half of the vector A, up to but not including mid*



int main()
{

	cout<<"vector A is empty(1) or full(0) :  "<<A.empty()<<endl;
	cout<<"size of vector B is : "<<B.size()<<endl;
	cout<<"maximum number of elements B can contain : "<<B.max_size()<<endl;

	D.push_back(1);		//push_back returns void and adds element to the end of the vector
	D.push_back(2);	
	D.push_back(3);

	
	X.push_front(1); //push_front adds element to the front of the list, returns void, push_front valid only for list,deque
	X.push_back(4);
	X.push_front(0);
	

	for(vector<int>::size_type i = 0; i != D.size(); i++)	//using subscript D[i] to access the elements of the vector
		cout<< D[i] <<" ";									//valid only for vector and deque
															//D[i] returns a reference to the element indexed by i

	cout<<"using subscript D[i] to traverse"<<endl;
	



	cout<<"the first element in D is : "<< D.front() << endl; //D.front returns a reference to the first element in vector
	cout<<"the last element in D is : "<< D.back() <<endl;	//D.back returns a reference to the last element in vector





	for(vector<int>::size_type i = 0; i != D.size(); i++)	//using member D.at(i) to access the elements of the vector
		cout<< D.at(i) <<" ";									//valid only for vector and deque
															//D.at(i) returns a reference to the element indexed by i
															//it throws an exception if index is out of range

	cout<<"using subscript D.at(i) to traverse"<<endl;


	D.erase(D.begin()); //removes the element referred to by the iterator D.begin()
						//returns an iterator referring to the element after the one deleted
						//returns off the end iterator if D.begin() was the last element


	D.erase(D.begin(), D.begin() + D.size()/2); //removes the range of elements denoted by the two iterators
						//returns an iterator referring after the last one in the range that was deleted
						//returns off the end iterator if the second iterator was itself an off the end 

	D.pop_back(); //removes the last element in the vector, returns void

	X.pop_front(); //removes the first element in the container, valid only for list and deque

	D.clear(); //removes all elements from the vector, returns void



	D.insert(D.begin(),5);
	//inserts 5 before the element referred to by D.end(),returns an iterator referring to the new element added

	D.insert(D.end(),5,2);
	//inserts 5 elements of value 2, before the element referred to by D.end(),returns void
	
	vector<int>::iterator mid1 = D.begin() + D.size()/2 ;
	D.insert(D.begin(), mid1, D.end());
	//inserts elements in the range denoted by iterators mid1 and end(), before the element pointed by begin()

	D.resize(5); //the vector's size will be changed, elements will be deleted from the back
	D.resize(7); //the vector's size will be changed, elements of value 0 will be added to the back 
	D.resize(9,2); //the vector's size will be changed, elements of value 2 will be added to the back


	A=B; //deletes elements in A and copies elements from B into A
	A.swap(B); //after this call, A has elements that were in B and B has elements that were in A
				//swap execution is usually much faster than copying 

	A.assign(B.begin(),B.end());	//replaces elements in A by those in the range denoted by the two iterators 
									//the two iterators must not refer to the elements in A itself

	A.assign(5,-1); //replaces elements in A by 5 elements of value -1s



	for( vector<int>::iterator iter = D.begin(); iter != D.end(); iter++) //using iterator to access elements of the vector
		cout<< *iter <<" ";					 //begin() is a function that returns an iterator refering to the first element of the vector
											//end() is a function that returns an iterator positioned one pas the end of the vector(sentinel)
											 //*iter can be used to dereference the iterator
	cout<<"using iterator to traverse"<<endl;
	




	for(vector<int>::const_iterator iter1 = D.begin(); iter1 != D.end(); iter1++) //using const_iterator to access elements of the vector
		cout<< *iter1 <<" ";						//the const_iterator can only read elements not write
										//when const_iterator is dereferenced, it returns a const so cannot modify 

	cout<<"using const_iterator to traverse"<<endl;
	




	for(vector<int>::reverse_iterator iter2 = D.rbegin(); iter2 != D.rend(); iter2++) //it addresses elements in the reverse order
		cout<< *iter2 <<" ";					 	//r.begin yields an iterator referring to the last element in the vector
													//r.end yields an iterator referring to one past the first element in the vector
	cout<<"using reverse_iterator to traverse"<<endl;





	for(vector<int>::const_reverse_iterator iter3 = D.rbegin(); iter3 != D.rend(); iter3++)
		cout<< *iter3 <<" ";						

	cout<<"using const_reverse_iterator to traverse"<<endl;




	const vector<int>::iterator iter4 = D.begin();
							//an iterator that is a constant is different than a const_iterator, it must be initialzed when defined
									//an iterator that is a constant can be used to modify the element but cannot refer to any other element
									//i.e., the value of the iterator cannot be changed, so it cannot be used to traverse the vector





	//Capacity and Reserve
	//Vectors achieve fast allocation by allocating capacity beyond what is immediately needed
	//the capacity operation tells us how many elements the container could hold before it must allocate more space
	//the reserve operation let US tell the vector how many elements it should be prepared to hold

	vector<int> ivec;
	//size should be zero and capacity is implementation defined
	cout<< "ivec.size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	//we know size of an empty vector is 0 and evidently out library also sets the capacity of an empty vector to 0



	//insert 24 elements
	for(vector<int>::size_type ix = 0; ix != 24; ix ++)
		ivec.push_back(ix);

	cout<< "ivec.size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;
	//when we add elements to the vector, we know that the size is the same as the number of elements we've added,
	//the capacity must be at least as large as size but can be larger, in this implementation,
	//adding 24 elements one at a time results in a capacity of 32
	//but we can reserve some additional space and increase the capacity
	ivec.reserve(50); //sets capacity to at least 50, might be more, implementation defined
	cout<< "ivec.size: " << ivec.size() << " capacity: " << ivec.capacity() << endl;


	//the execution time of creating an n-element vector by calling the push_back n times on an initially empty
	//vector is never more than a constant multiple of n


	vector<vector<int>> vect;
	/*iterating over 2d matrix */
	for(auto i = vect.begin() ; i<vect.end() ; i++){
    for(auto j = i->begin() ; j<i->end() ; j++){
		cout << *j <<" ";
    	cout <<"\n";  
  	}
	}

	return 0;	
}