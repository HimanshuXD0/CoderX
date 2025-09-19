 
 // House Robber 
 // https://takeuforward.org/data-structure/dynamic-programming-house-robber-dp-6/
 // Revision Status = 2
 // DAY ----6 

 #include<bits/stdc++.h>
 using namespace std;
 
 
 int so(vector<int>& arr){
    int n = arr.size();
    int prev = arr[0];
    int prev2 =0;
    int cur_i=0;
    
    for(int i=1; i<n; i++){
        int nonPick = 0 + prev;
        int pick = arr[i];
        if(i>1)  pick += prev2;
        
        cur_i = max(pick,nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

    int rob(vector<int>& nums) {
      
        vector<int> temp1;
        vector<int> temp2;
        int n=nums.size();
        if(n==1)  return nums[0];
        for(int i=0;i<n;i++){      
            if(i!=0)temp1.push_back(nums[i]); // Make two reduced arrays – arr1(arr-last element) and arr2(arr-first element).
            if(i!=n-1)temp2.push_back(nums[i]);
        }
         int a= so(temp1);
        int b=so(temp2);
        return max(a,b);
    }

    int prac(vector<int> arr){
        vector<int> temp1;
        vector<int> temp2;
        if(arr.size()==1) return arr[0];
        for(int i=0;i<arr.size();i++){
            if(i!=0) temp1.push_back(arr[i]);
            if(i!=arr.size()-1) temp2.push_back(arr[i]);
        }
        int ans1 = so(temp1);
        int ans2 = so(temp2);
        return max(ans1,ans2);
    }

    int adjsum(vector<int> arr, int n ){

        if(n==0) return arr[n];
        int notpick = adjsum(arr,n-1)+0;
        int pick = INT_MIN;
        if(n>1) pick=adjsum(arr,n-2)+arr[n];
        return max(pick,notpick);
    }

    int hr(vector<int> arr){
         vector<int> temp1 ;
         vector<int> temp2 ;
         for(int i = 0;i<arr.size();i++){
            if(i!=0) temp1.push_back(arr[i]);
            if(i!=arr.size()-1) temp2.push_back(arr[i]);
         }
         int n =temp1.size();
         int m =temp2.size();
         int takelast= adjsum(temp1,n-1);
         int takefirst= adjsum(temp2,m-1);
         return max(takefirst,takelast);
    }

    int main(){
     int n ; cin>>n;
     vector<int> arr(n);
     for(int i=0;i<n;i++) cin>>arr[i];
     cout<<hr(arr);
     
 }