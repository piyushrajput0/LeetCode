class Solution {
public:
    bool checkpalid(string str)
    {
        int n=str.size();
        for(int i=0;i<str.size()/2;i++)
        {
            if(str[i]!=str[n-1-i])
            {
                return true;
            }
        }
        return false;
    }
    string breakPalindrome(string palid) {
        
        if(palid.size()==1)
        {
            return "";
        }
        
        for(int i=0;i<palid.size();i++)
        {
            if(palid[i]=='a')
            {
                if(i==palid.size()-1)
                {
                    palid[i]='b';
                    // cout<<1<<endl;
                    return palid;
                }
                
            }
            else
            {
                string str=palid;
                str[i]='a';
                if(checkpalid(str))
                return str;
            }
        }
        return palid;
    }
};