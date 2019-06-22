#include<bits/stdc++.h>
using namespace std;
//initially hole is the 2nd element
//subarray to the left of hole will be our final sorted array
//we pick the first element in the right subarray and insert it into the left subarray
//at the correct position depending upon smaller/greater and shift other elements to right
//time complexity - O(n) best case   O(n square) worst case   O(n square) average case
//space complexity - O(1)   stable because we only shift when stricly less


void insertionsort(vector<int> &a){
    vector<int>::size_type hole;
    int value;
    for(auto i= (a.begin()+1); i!= a.end(); i++){
        value = *i;
        hole = i-a.begin();

        while( (hole>0) && (value<a[hole-1]) ){
            a[hole] = a[hole-1];
            hole--;
        };
        a[hole] = value;
    }
}

int main(){
    vector<int> a{5,4,3,2,1};
    insertionsort(a);

    for(auto i=a.begin(); i!=a.end(); i++)
    cout<<" "<<*i;
    cout<<endl;
    return 0;
}