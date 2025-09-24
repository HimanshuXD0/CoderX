// Asteroid Collision
// https://youtu.be/Y82zCeJft-Q
// Revision Status : 2
// DAY-----5
/*

=> So there is just 1 main point that we need to focus on, and that is -:
-> the collision will only happen when top of stack is a +ve number and the element we want to insert is -ve.
And the reason for that is,

- If both elements are of same sign they will continue in that direction itself.
- If the top is -ve and the element we want to insert is +ve then they will continue in opposite directions.

*/

#include<bits/stdc++.h>
using namespace std;

 vector<int> asteroidCollision(int N, vector<int> &ast) {
        // code here
        stack<int> st;
        for(auto x:ast){
            
               if(x>0){
                   st.push(x);
               }
               else{
                   while(!st.empty() && st.top()>0 && st.top()<abs(x)){
                       st.pop();  // st m top udta jyga jb tak top chota hai 
                   }
                   if(!st.empty() && st.top() == abs(x)){
                       st.pop();
                       continue;  // st mai ane wala bhi push na ho isly(khud bhi khtam )
                   }
                   if(!st.empty() && st.top()>abs(x)){
                       continue;   // aage wale ne ast ko hi pura uda diya (khud bhi bch gya )
                   }
                   st.push(x);
               }
            }
            
            vector<int> ans;
            while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }



int main(){
     
    vector<int> v = {3,5,-3};
    int n = v.size();
    v = asteroidCollision(n,v);
    for(auto e:v) std::cout<<e<<" ";

    return 0;
}