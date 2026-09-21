using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last_seen(256, -1);
        int max_len = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            unsigned char curr = s[right];

            if (last_seen[curr] >= left) {
                left = last_seen[curr] + 1;
            }

            last_seen[curr] = right;

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};