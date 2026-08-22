class Solution {
public:
    string addBinary(string a, string b) {

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string result;

        while (i >= 0 || j >= 0 || carry) {

            int digitA = 0;
            int digitB = 0;

            if (i >= 0) {
                digitA = a[i] - '0';
            }
            
            if (j >= 0) {
                digitB = b[j] - '0';
            }
            
            int sum = digitA + digitB + carry;

            result += char(sum % 2 + '0');

            carry = sum / 2;

            i--;
            j--;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};