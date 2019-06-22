#include<bits/stdc++.h>
using namespace std;
//selection sort - if array size n, select the smallest element in size n-1, n-2, n-3,.. 
//and swap with 1st, 2nd, 3rd,.. element in each iteration respectively.
//array starts getting sorted from the beginning
//time complexity - O(n square)     space complexity - O(1) 
//unstable but can be made stable by "inserting"(instead of swapping) the least value 
//and pushing other elements back by using a linked list


//pass by reference, alias
void selectionsort(vector<int> &arr){
    //we don't have to swap the last element, so n-2 will be last index
    for(auto i=arr.begin(); i!=(arr.end()-1); i++){
        //we choose smallest element from array size of n-1, n-2 n-2 in each iteration
        for(auto j= i+1; j!=arr.end(); j++){
            auto min = min_element(j,arr.end());
            if( (*min) < (*i) )
            {
                swap(*min, *i);
            }
        }
    }
}


int main(){
    vector<int> arr{4,5,3,2,6,7,1,8,9,0};
    selectionsort(arr);
    for(auto i=arr.begin(); i!=arr.end(); i++){
        cout<<" "<<*i;
    }
    cout<<endl;
    return 0;
}