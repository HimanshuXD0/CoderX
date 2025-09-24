// Remove K Digits
// https://youtu.be/RCE2L0Zk7xE

// aim ye hai ki starting of string se jaldi se jaldi k bade elements ko htya jaye
// Revision Status : 2
// DAY-----6
#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string S, int k) {
        
        int i = 0;
        stack <char> s;
        while(S[i]!='\0'){
            while(!s.empty() && s.top()>S[i] && k){
                s.pop();
                k--;
            }
            if(!s.empty() || S[i] != '0')   // agr s empty h to zero nhi dalnge 
                s.push(S[i]);
            i++;
        }
        while(!s.empty() && k--)
            s.pop();
        string str = "";
        while(!s.empty()){
            str += s.top();
            s.pop();
        }
        reverse(str.begin(), str.end());
        if(str.empty())
            str += "0";
        return str;
    }

int main(){
    string ans = removeKdigits("15243",3);
    std::cout<<ans;
    return 0;
}
 