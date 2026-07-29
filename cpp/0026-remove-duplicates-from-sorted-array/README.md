# 26. Remove Duplicates from Sorted Array

**Difficulty:** Easy

## Problem

Given a sorted integer array `nums`, remove the duplicates **in-place** such that each unique element appears only once. The relative order of the elements should be kept the same.

Return the number of unique elements `k`, where the first `k` elements of `nums` contain the unique values.

## Approach

Since the array is already sorted, duplicate values always appear next to each other.

I used the **two-pointer** technique:

* `i` points to the last unique element.
* `j` scans through the array from left to right.
* Whenever `nums[j]` is different from `nums[i]`, move `i` one step forward and copy `nums[j]` to `nums[i]`.
* At the end, the first `i + 1` elements contain all the unique values.

## Solution (C++)

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
```

## Complexity

* **Time Complexity:** O(n)
* **Space Complexity:** O(1)

## Key Concepts

* Two Pointers
* In-place Array Modification
* Linear Traversal
