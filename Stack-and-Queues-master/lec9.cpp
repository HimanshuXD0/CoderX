// Maximum of all subarrays of size k
// https://takeuforward.org/data-structure/sliding-window-maximum/
// https://youtu.be/MCvGwtkqJS0
// Revision Status : 0
#include<bits/stdc++.h>
using namespace std;

// --- using Priority queue O(nlogk) -- 

 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       vector<int>ans;
       priority_queue<int> q;
       unordered_map<int , int>ump;
       for(int i = 0;i<k;i++){
           ump[arr[i]]++;
           if(ump[arr[i]]<=1)q.push(arr[i]);
   }
        ans.push_back(q.top());
        int i = 1 , j = k;
        
    while(j<n) {
       ump[arr[i-1]]--;ump[arr[j]]++;
       q.push(arr[j]);
       while(ump[q.top()]<1) q.pop();
       ans.push_back(q.top());
       i++;j++;
       
   }
   return ans;
    }

// --- using Deque O(n) -- 

 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
    vector<int> v;
    deque<int> dq;

    for (int i = 0; i < n; ++i) {
        if (!dq.empty() && dq.front() == i-k) // i-k isly jisse out of bound na jaye  q m sirf window elemnt hi ho 
            dq.pop_front();

        while(!dq.empty() && arr[dq.back()]<arr[i])
            dq.pop_back();

        dq.push_back(i);

        // ye isliye taki pheli k ki window banane se phele hi insert na ho ..
        // i kam se kam k-1 times to explore kr le uske baad
        // i atleast k-1 index tak to chlna chiye fr jo q k top h wo ans me jyga 
             if (i>=k-1)  
            v.push_back(arr[dq.front()]);
    }
    return v;
    }



int main(){
    
    return 0;
}