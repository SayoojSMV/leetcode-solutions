class Solution {
private:
    const unordered_map<char, string> phoneMap = {
        {'2', "abc"}, {'3', "def"},{'4', "ghi"}, {'5', "jkl"}, 
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(string digits, int index, string& currentCombination, vector<string>& result) {

        if (index == digits.length()) {
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        string letters = phoneMap.at(currentDigit);

        for (char letter : letters) {
            currentCombination.push_back(letter);

            backtrack(digits, index + 1, currentCombination, result);

            currentCombination.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {

        vector<string> result;

        if (digits.empty()) return result;

        string currentCombination = "";

        backtrack(digits, 0, currentCombination, result);

        return result;
    }
};