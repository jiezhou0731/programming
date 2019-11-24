class Solution {
public:
    int findNthDigit(long long n) {
        long long p1 = 9;
        long long p0 = 1;
        long long d = 1;
        
        while (n - (p1 - p0+1) * d > 0) {
            n -= (p1-p0+1)*d;
            p0 *= 10;
            p1 = p1 * 10 + 9;
            d += 1;
        }
        long long t = (n-1) / d;
        n -= d * t;
        p0 += t;
        long long ans  = 0;
        while (d - n > 0) {
            p0 /= 10;
            d --;
        }
        ans = p0 % 10;
        return ans;
    }
};