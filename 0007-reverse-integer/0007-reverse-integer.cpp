class Solution {
public:
    
    void rev(string &str)
{
    
    int len = str.length();
    int n = len-1;
    int i = 0;
    while(i<=n){
        //Using the swap method to switch values at each index
        swap(str[i],str[n]);
        n = n-1;
        i = i+1;
}
    }
    int reverse(int x) {
     
        
        string mx=to_string(INT_MAX);
        string mn=to_string(INT_MIN);
        mn=mn.substr(1);
        int dup=abs(x);
        string num=to_string(dup);
        
        rev(num);
        
        if(x<0)
        {
            // mn=mn.substr(1);
            
            if(num.size()>mn.size())
            {
                
                return 0;
            }
            else if(num.size()==mn.size())
            {
                for(int i=0;i<num.size();i++)
                {
                    int temp1=mn[i]-'0';
                    int temp2=num[i]-'0';
                    if(temp1<temp2)
                    {
                        
                        return 0;
                    }
                    else if(temp1>temp2)
                    {
                         return stoi(num)*-1;
                        // break;
                    }
                    
                }
            }
            else
            {
                // cout<<INT_MIN<<endl;
                return stoi(num)*-1;
            }
        }
        else
        {
            if(num.size()>mn.size())
            {
                return 0;
            }
            else if(num.size()==mx.size())
            {
                for(int i=0;i<num.size();i++)
                {
                    int temp1=mx[i]-'0';
                    int temp2=num[i]-'0';
                    if(temp1<temp2)
                    {
                        return 0;
                    }
                    else if(temp1>temp2)
                    {
                        return stoi(num);
                    }
                    
                }
            }
            else
            {
                return stoi(num);
            }
        }
        return stoi(num);

    }
    
};