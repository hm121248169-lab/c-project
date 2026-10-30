#include <iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    int match[101];
    for(int i=0;i<n;i++){
        match[i]=-1;
    }
    stack<int> st;

    for(int i=0;i<n;i++){
        char ch=s[i];
        if(ch=='(' || ch=='[' ){
            st.push(i);
        }
        else{
            if (!st.empty())
            {
                int top_idx = st.top();
                char top_ch = s[top_idx];
                
                if ((top_ch == '(' && ch == ')') || (top_ch == '[' && ch == ']'))
                {
                    match[top_idx] = i;
                    match[i] = top_idx;
                    st.pop();
                }
            }
        }
        
    }
    string ans;
    for(int i=0;i<n;i++){
        if(match[i]!=-1){
            ans+=s[i];
        }
        else{
            if(s[i]=='(') ans+="()";
            else if(s[i]=='[') ans+="[]";
            else if(s[i]==')') ans+="()";
            else if(s[i]==']') ans+="[]";
        }
    }
    cout<<ans<<endl;
    return 0;
}