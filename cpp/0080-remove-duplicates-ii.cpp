#include <vector>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size();
        }
        
        int i = 2; // Start writing from index 2 since first two elements are always valid
        
        for (int j = 2; j < nums.size(); ++j) {
            // If the current element is different from the element 2 positions before i, it's valid
            if (nums[j] != nums[i - 2]) {
                nums[i] = nums[j];
                i++;
            }
        }
        
        return i;
    }
};