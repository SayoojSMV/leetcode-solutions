#include <vector>

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates: shrink the window from both ends
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
            } 
            // Check if the left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target is in the sorted left half
                } else {
                    left = mid + 1;  // Target is in the right half
                }
            } 
            // Otherwise, the right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;  // Target is in the sorted right half
                } else {
                    right = mid - 1; // Target is in the left half
                }
            }
        }
        
        return false;
    }
};