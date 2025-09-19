// Count Partitions with Given Difference
// https://takeuforward.org/data-structure/count-partitions-with-given-difference-dp-18/

// Revision Status : 1

#include<bits/stdc++.h>
using namespace std;

// Recursive

int f(int n ,int target, vector<int > arr){

    
    if(n==0) return arr[n]==target;
    if(target==0) return 1;

    int notpick = f(n-1,target,arr);
    int pick=0;
    if(arr[n]<=target) pick = f(n-1,target-arr[n],arr);

    return pick+notpick;
}

int countPartitions(int d, vector<int>& arr){
    int n = arr.size();
    int totSum = 0;
    for(int i=0; i<arr.size();i++){
        totSum += arr[i];
    }
    
    //Checking for edge cases
    // s1- s2 = D
    // s1 = totalsum-s2
    if(totSum-d<0) return 0;
    if((totSum-d)%2==1) return 0;
    
    int s2 = (totSum-d)/2;
    
    vector<vector<int>> dp(n,vector<int>(s2+1,-1));
    return f(n-1,s2,arr);
}

int main(){
     vector<int> arr = {1,2,3,4};
      int k=4;
      int n = arr.size();
      vector<vector<bool>> dp(n,vector<bool>(k+1,false));
      cout<<f(n,k,arr);

    return 0;
}