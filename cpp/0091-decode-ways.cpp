#include <string>
#include <vector>

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        
        int n = s.length();
        int prev2 = 1; // Represents dp[i-2]
        int prev1 = 1; // Represents dp[i-1]
        
        for (int i = 1; i < n; ++i) {
            int current = 0;
            
            // Single digit decoding
            if (s[i] != '0') {
                current += prev1;
            }
            
            // Two digit decoding
            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }
            
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};