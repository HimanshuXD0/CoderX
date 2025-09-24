// Trapping Rainwater
// https://takeuforward.org/data-structure/trapping-rainwater/
// Revision Status : 2
// learn : trapped water is = maximum left and maximum right of standing index - standing index elevetaion itself
// prefix: stores maximum values to left of every each index  
// sufix: stores maximum values to right of every each index  

// DAY-----4
#include<bits/stdc++.h>
using namespace std;

// Appproch -1 (brute force) 
// creating the suffix and prefix array's

// long long trappingWater(int arr[], int n){
//         int left[n], right[n];
//         long long res = 0;
//         int maxLeft = 0, maxRight = 0;

//         for (int i = 0; i < n; i++) {          // -> prefix greater array
//             maxLeft = max(maxLeft, arr[i]);
//             left[i] = maxLeft;
//         }
//         for (int i = n - 1; i >= 0; i--) {    // -> suffix gretaer array
//             maxRight = max(maxRight, arr[i]);
//             right[i] = maxRight;
//         }
//         for (int i = 0; i < n ; i++) {
//             res += (min(left[i], right[i]) - arr[i]);
//         }
//         return res;
//     }


int trapttt(vector<int> arr,int n){
  int total=0;
  int left=0;
  int right=n-1;
  int maxleft=0;
  int maxright=0;
  while(left<right){
    maxright=max(maxright,arr[right]);
    maxleft=max(maxleft,arr[left]);
    total += maxright<maxleft?
    maxright-arr[right--]:maxleft-arr[left++];
  }
    return total;
}


// Approach-2 (Two-pointer)


long long trappingWater(vector<int> arr,int n){
        long long total=0;
        int left=0;
        int right=n-1;
        int leftmax=0,rightmax=0;
          while(left<right){
            rightmax=max(rightmax,arr[right]);
            leftmax=max(leftmax,arr[left]);
            if(leftmax>rightmax){
                {total+=rightmax-arr[right];
                right--;}
            }
            else 
            {total+=leftmax-arr[left];
            left++;}
          }
           return total; 
        }




int main(){

     vector < int > arr;
     int n = arr.size();
     arr = {4,5,2,1,6};
     cout  << trappingWater(arr,n) << endl;
    
    return 0;
}