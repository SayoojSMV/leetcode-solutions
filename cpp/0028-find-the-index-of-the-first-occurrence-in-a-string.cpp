class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size()) return -1;
        if (needle.size() == 0) return 0;

        for (int start = 0; start <= haystack.size() - needle.size(); start++) {

            bool found = true;

            for (int j = 0; j < needle.size(); j++) {

                if (haystack[start  + j] != needle[j]) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return start;
            }
        }

        return -1;
    }
};