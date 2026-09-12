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
 using namespace std;
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }

private:
    int check(TreeNode* node) {
        if (!node) {
            return 0;
        }
        
        int left_height = check(node->left);
        if (left_height == -1) return -1;
        
        int right_height = check(node->right);
        if (right_height == -1) return -1;

        if (abs(left_height - right_height) > 1) {
            return -1;
        }

        return 1 + max(left_height, right_height);
    }
};