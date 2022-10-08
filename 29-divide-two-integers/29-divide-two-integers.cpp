class Solution {
public:
    int divide(int dividen, int diviso) {
        
        long long int dividend=dividen;
        long long int divisor=diviso;
        if((dividend==INT_MAX && divisor==1) || (dividend==INT_MIN && divisor==-1))
        {
            return INT_MAX;
        }
        else if((dividend==INT_MAX && divisor ==-1) ||(dividend==INT_MIN && divisor==1))
         {
             return INT_MIN;
         }
        
        int sign=1;
            if(dividend <0)
            {
                dividend=abs(dividend);
                sign*=-1;
            }
        if(divisor<0)
        {
            divisor=abs(divisor);
            sign*=-1;
        }
        
        int res=0;
        while(dividend-divisor>=0)
        {
            int cn=0;
            while((dividend- (divisor<<1<<cn))>=0)
            {
                cn++;
            }
            res+=1<<cn;
            dividend= dividend-(divisor<<cn);
        }
        
        return res*sign;
    }
};