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
    void help(int n,string str,int o,int c)
    {
        if(o==n && c==n)
        {
            
            if(check(str))
             ans.push_back(str);
            
            return ;
        }
        
        if(o<n)
        {
            cout<<str<<endl;
           help(n,str+'(',o+1,c);
        }
        
        if(str.size()!=0)
        {
            if(c<n)
             help(n,str+')',o,c+1);
        }
       
    }
    vector<string> generateParenthesis(int n) {
        
        if(n==1)
        {
            return {"()"};
            
        }
        
        help(n,"",0,0);
        return ans;
        
    }
};