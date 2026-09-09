// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long ans;
//         long long temp =n;
//         int digit =0;
//         while(temp > 0){
//             temp /=10;
//             digit++;
//         }
//         if(digit <4) return 0;
//         if(digit >= 4 && digit <=6) ans = n-1000+1;
//         if(digit >= 7 && digit <=9) ans = (n-1000+1)+(n-1000000+1)*2;
//         if(digit >=10 && digit <=12) ans = (n-1000000000+1)*3+((n-1000+1)+(n-1000000+1)*2);
//         if(digit >=13 && digit <=15) ans = (n-1000000000000+1)*4+((n-1000000000+1)*3+((n-1000+1)+(n-1000000+1)*2));
//         return ans;
//     }
// };

class Solution {
public:
    long long countCommas(long long n) {
        long long start = 1000;
        long long comma = 1;
        long long ans = 0;

        while (start <= n) {
            long long end = min(n, start * 1000 - 1);

            ans += (end - start + 1) * comma;

            start *= 1000;
            comma++;
        }

        return ans;
    }
};