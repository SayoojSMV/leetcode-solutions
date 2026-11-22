#include <string>
#include <vector>

class Solution {
private:
    void backtrack(const string& s, int idx, vector<string>& current, vector<string>& result) {
        if (current.size() == 4) {
            if (idx == s.size()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        int remainingSegments = 4 - current.size();
        int remainingChars = s.size() - idx;
        if (remainingChars < remainingSegments || remainingChars > remainingSegments * 3) {
            return;
        }

        int num = 0;
        for (int len = 1; len <= 3 && idx + len <= s.size(); ++len) {
            if (len > 1 && s[idx] == '0') {
                break;
            }

            num = num * 10 + (s[idx + len - 1] - '0');
            if (num > 255) {
                break;
            }

            current.push_back(s.substr(idx, len));
            backtrack(s, idx + len, current, result);
            current.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        if (s.size() < 4 || s.size() > 12) {
            return result;
        }

        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
};