class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n=haystack.size();
        int m=needle.size();
        
        if(n==m)
        {
            if(haystack==needle)
            {
                return 0;
            }
            return -1;
        }
        for(int i=0;i<n-m+1;i++)
        {
            string str=haystack.substr(i,m);
            if(str==needle)
            {
                return i;
            }
        }
        return -1;
        
        
        
    }
};