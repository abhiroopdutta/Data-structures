#include<iostream>
using namespace std;

//min heap

int maximum = 1000;
int *a = new int[maximum];
int heap_size = 0;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;

}

void check(int i)
{
    if( i>0 && ( a[i] < a[(i-1)/2] ) )
   {
        swap( a[i], a[(i-1)/2] );
        check((i-1)/2);
   }

}

void insert(int n)
{
    if(heap_size == maximum)
    cout<<"heap is full"<<endl;

    else
    {   
        a[heap_size] = n;
        heap_size ++;
    }    

    
    check(heap_size-1);
    

}

void heapify(int i)
{   
    if( (2*i+2) <heap_size && ( a[i] > a[2*i +1] || a[i] > a[2*i +2] ) ) //is node greater than either of its children 
    {

        if(a[2*i +1] < a[2*i +2])    //is the left child smaller, if yes then swap it with parent
        {   
            
            swap(a[i], a[2*i+1]);    
            heapify(2*i +1);
        }

        else if (a[2*i +1] < a[2*i +2]) //or the right child smaller, if yes then swap it with parent
        {
            swap(a[i], a[2*i+2]);
            heapify(2*i+2);
            
        }
    }    
    


//    int left=2*i+1;
//    int right=2*i+2;
//    int small=i;

//    if(left<heap_size && a[left]<a[i])
//    small=left;
//    if(right<heap_size && a[right]<a[small])
//    small=right;
//    if(small!=i)
//    {
//        swap(a[small],a[i]);
//        heapify(small);

//    }



}

void delete_heap()
{
    swap(a[0], a[heap_size -1]);
    heap_size--;
   
    heapify(0);
     
}


void heapsort()
{
    int x = heap_size;
   for(int i=0; i<x; i++)
   {
       swap(a[0], a[heap_size -1]);
       cout<<a[heap_size -1]<<endl;
       heap_size--;
       heapify(0);
   }


}

int main()
{
    insert(7);
    insert(6);
    insert(2);
    insert(1);


    

    delete_heap();

     for(int i=0; i<heap_size; i++)
    cout<<a[i]<<endl;


cout<<endl;
cout<<endl;
cout<<endl;

   heapsort();

    return 0;
}