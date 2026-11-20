#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<TreeNode*> buildTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> allTrees;

        for (int val = start; val <= end; ++val) {
            vector<TreeNode*> leftTrees = buildTrees(start, val - 1);
            vector<TreeNode*> rightTrees = buildTrees(val + 1, end);

            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(val, left, right);
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }

public:
    vector<TreeNode*> generateTrees(int n) {
        if (n <= 0) {
            return {};
        }
        return buildTrees(1, n);
    }
};