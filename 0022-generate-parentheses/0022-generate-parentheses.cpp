class Solution {
public:
    vector<string>ans;
    
    bool check(string &str)
    {
        stack<char>s;
        
        int i=0;
        int n=str.size();
        while(i<n)
        {
            
                if(s.empty())
                {
                    if(str[i]==')')
                    {
                        return false;
                    }
                    else
                    {
                        s.push('(');
                    }
                }
                else if(str[i]=='(')
                {
                    s.push('(');
                }
                else
                {
                    if(s.top()=='(')
                    {
                        s.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                i++;
                
                
            
            
        
        }
        
        if(s.size()!=0)
        {
            return false;
        }
        return true;
        
    }
    void help(int n,string str)
    {
        if(str.size()==(n*2))
        {
            
            if(check(str))
             ans.push_back(str);
            
            return ;
        }
        
        help(n,str+'(');
        help(n,str+')');
    }
    vector<string> generateParenthesis(int n) {
        
        if(n==1)
        {
            return {"()"};
            
        }
        
        help(n,"");
        return ans;
        
    }
};