using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];

                if (current_sum == target) {
                    return current_sum;
                }
                                    
                if (abs(target - current_sum) < abs(target - closest_sum)) {
                    closest_sum = current_sum;
                }

                if (current_sum < target) {
                    left++;
                } else {
                    right--;
                }

            }
        }

        return closest_sum;
    }
};