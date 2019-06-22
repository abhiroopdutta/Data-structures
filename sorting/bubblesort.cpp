#include<bits/stdc++.h>
using namespace std;
//bubblesort - if size n, then after n-1(max, worst case) passes array will be sorted
//in each pass, comparison will be made between i, and i+1 element and swapped if i+1 smaller
//after each pass, the largest element will land up at the end of the array
//in 1st pass, n elements will be considered starting from beginning, then n-1, n-2,..
//as from the end array is sorted
//time complexity is O(n square) worst, O(n) best (if already sorted), O(n square) average.
//space complexity is O(1), it is stable because we swap only if strictly less

void bubblesort(vector<int> &a){
    int flag =0;
    int n = a.size();
    //n-1 passes
    for(int i=1; i<= n-1; i++){
        int flag = 0;
        //in each iteration the last element is sorted, so we don't consider the sorted area
        for(auto j= a.begin(); j !=(a.end()-i); j++){
            if( (*j) > (*(j+1)) ){
                swap(*j, *(j+1));
                flag = 1;
            }                    
        }
        if(flag == 0) //no swaps have occurred,i.e., the array is already sorted
                {cout<<"sorted"<<endl; break; }  
    }
}

int main(){
    vector<int> a{5,6,7,8,9,10};
    bubblesort(a);
    for(auto i=a.begin(); i!=a.end(); i++)
    cout<<" "<<*i;
    cout<<endl;

    return 0;
}