class Solution {
public:
    int evalRPN(vector<string>& token) {
        
        stack<int>st;
        // int ans=0;
        for(int i=0;i<token.size();i++)
        {
            if(token[i]=="/")
            {
                long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int ans=(b/a);
                // cout<<a<<" "<<b<<" "<<ans<<endl;
                st.push((ans));
                
            }
            else if(token[i]=="-")
            {
                long long int a= st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                int ans=(b-a);
                st.push((ans));
            }
            else if(token[i]=="*")
            {
                long long int a= st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int ans=(a*b);
                 st.push((ans));
            }
            else if(token[i]=="+")
            {
                long long int a= st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                long long int ans=(a+b); st.push((ans));
                
            }
            else
            {
                st.push(stoi(token[i]));
            }
        }
        return st.top();
    }
};