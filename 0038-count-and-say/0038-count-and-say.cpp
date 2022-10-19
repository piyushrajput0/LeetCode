class Solution {
public:
    string countAndSay(int n) {
        
        if(n==1)
        {
            return "1";
            }
        
        n--;
        string str="1";
         
        while(n--)
        {
            int m=str.size();
            
            int i=0;
           string ans;
            while(i<m)
            {
                char ch=str[i];
                int cn=0;
                while(i<m && ch==str[i])
                {
                    cn++;
                    i++;
                    
                }
                ans+= to_string(cn)+ch;
            }
            str=ans;
            
            
            
        }
        return str;
        
    }
};