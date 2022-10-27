class Solution {
public:
    unordered_map<char,vector<char>>mp;
    vector<string> help(int i,string digits,vector<string> &v)
    {
        if(i==digits.size())
        {
            return v ;
        }
        
        vector<char>temp=mp[digits[i]];
        vector<string>ans;
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<temp.size();j++)
            {
                string str=v[i]+temp[j];
                ans.push_back(str);
            }
        }
       return  help(i+1,digits,ans);
        
    }
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0)
        {
            return {};
        }
        
        mp.clear();
        
        mp['2']={'a','b','c'};
        mp['3']={'d','e','f'};
        mp['4']={'g','h','i'};
        mp['5']={'j','k','l'};
        mp['6']={'m','n','o'};
        mp['7']={'p','q','r','s'};
        mp['8']={'t','u','v'};
        mp['9']={'w','x','y','z'};
        
        vector<string>v;
        v.push_back("");
        // cout<<v.size()<<endl;
        return help(0,digits,v);
        // return v;
        
    
        
        
        
    }
};