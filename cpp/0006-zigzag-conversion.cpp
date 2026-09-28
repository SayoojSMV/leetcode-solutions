class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows >= s.length())  {
            return s;
        }

        vector<string> rows(numRows);
        int curr = 0;
        bool going_down = false;

        for (char c : s) {
            rows[curr] += c;

            if (curr == 0 || curr == numRows - 1) {
                going_down = !going_down;
            }

            curr += going_down ? 1 : -1;
        }

        string result = "";
        for (const string& row : rows) 
            result += row;

        return result;
    }
};