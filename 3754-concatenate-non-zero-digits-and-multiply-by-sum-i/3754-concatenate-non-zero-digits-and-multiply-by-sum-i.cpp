class Solution {
public:
    long long sumAndMultiply(int x) {
            long long num = 0;
            long long i =1;
            long long sum =0;
        while(x > 0){
            int digit  = x%10;
            if(digit % 10 !=0){
                sum = sum +digit;
                num = num +digit*i;
                i = i*10;
            }
                x = x/10;
        }
        return sum*num;
    }
};