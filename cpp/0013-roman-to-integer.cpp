class Solution {
public:
    int romanToInt(string s) {
        int sum=0;
        unordered_map<char, int> romans={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        for (int i=0; i<s.size(); i++) {
            if (romans[s[i]]>=romans[s[i+1]]) {
                sum+=romans[s[i]];
            }
            else {
                sum -= romans[s[i]];
            }
        }
        return sum;
    }
};