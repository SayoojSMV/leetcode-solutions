class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        
        long long N = n;
        if (N < 0) {
            N = -N;
        }
        
        double result = 1.0;
        double current_product = x;
        
        while (N > 0) {
            if (N & 1) {
                result *= current_product;
            }
            current_product *= current_product;
            N >>= 1;
        }
        
        if (n < 0) {
            return 1.0 / result;
        }
        
        return result;
    }
};