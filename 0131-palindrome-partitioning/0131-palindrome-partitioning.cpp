class Solution {
public:
    
    vector<vector<string>>ans;
    bool palid(string &str)
    {
        int n=str.size();
        
        
        for(int i=0;i<n/2;i++)
        {
            if(str[i]!=str[n-1-i])
            {
                return false;
            }
        }
        return true;
    }
    void help(int idx,string s,vector<string>&temp)
    {
        if(s.size()==0)
        {
            ans.push_back(temp);
        }
        
        for(int i=1;i<=s.size();i++)
        {
            string str=s.substr(0,i);
             // cout<<s<<" : "<<str<<" "<<s.substr(i)<<" "<<idx<<" "<<i<<endl;
            if(palid(str))
            {
                temp.push_back(str);
               
                help(i,s.substr(i),temp);
                    
                temp.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        
        if(s.size()==1)
        {
            return {{s}};
        }
        
        vector<string>temp;
        help(0,s,temp);
        return ans;
        
    }
};