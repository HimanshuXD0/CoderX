// Next Greater Element - I
// https://takeuforward.org/data-structure/next-greater-element-using-stack/
// Revision Status : 1
// DAY ---- 2


/*  --> ek nge vector bna denge ans store krne k liye agr usse gerater ele hai right m to push kr dnge nhi to -1 
    --> piche se traverse krna suru krenge jab tak stack ka top ele chhota hai array k ele  se to pop krte jynge agr bda h push krnge 
    --> jese hi bda ele mila wse hi nge[i] m top dal dnege(check jrur kr lenge st empty na ho ) 
*/
#include<bits/stdc++.h>
using namespace std;

vector < int > nextGreaterElements(vector < int > & nums) {
      int n = nums.size();
      vector <int> nge(n,-1);
      stack <int> st;
      for (int i = n - 1; i >= 0; i--) {

           while (!st.empty() && st.top() <= nums[i])  st.pop();
           if (!st.empty()) nge[i] = st.top();
           st.push(nums[i]);
      }
      return nge;
    }

    vector<int> nextge(vector<int> &nums){
        int n = nums.size();
        vector<int> nge(nums.size(),-1);
         stack<int> st;
         for(int i=n-1;i>=0;i++){
             while(!st.empty()&&st.top()<=nums[i]); st.pop();
            if (!st.empty())  nge[i]=st.top();
             st.push(nums[i]);
         }
    }


int main(){
    
     vector < int > v {5,7,1,2,6,0};
     vector < int > res = nextGreaterElements(v);
     for (int i = 0; i < res.size(); i++) {
      std::cout << res[i] << " ";
  }
    return 0;
}