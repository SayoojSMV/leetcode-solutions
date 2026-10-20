#include <vector>
#include <algorithm>

class Solution {
private:
    void backtrack(std::vector<int>& nums, std::vector<int>& current, 
                   std::vector<bool>& visited, std::vector<std::vector<int>>& result) {
        
        // Base case: if our current path has all elements, we found a valid permutation
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            // If this element is already used, skip it
            if (visited[i]) {
                continue;
            }

            // Skip duplicates: if current element is same as previous, 
            // and the previous one was already used and backtracked, skip this one
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            // Choose
            visited[i] = true;
            current.push_back(nums[i]);

            // Explore
            backtrack(nums, current, visited, result);

            // Un-choose (Backtrack)
            current.pop_back();
            visited[i] = false;
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        std::vector<bool> visited(nums.size(), false);
        
        // Sorting is required to group duplicate numbers together
        std::sort(nums.begin(), nums.end());
        
        backtrack(nums, current, visited, result);
        return result;
    }
};