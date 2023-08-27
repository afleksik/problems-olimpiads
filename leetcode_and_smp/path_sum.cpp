
// https://leetcode.com/problems/path-sum/description/
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    bool root_to_leaf(TreeNode *root, int targetSum, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr) {
            sum += root->val;
            if (sum == targetSum) {
                return true;
            }
        }
        return root_to_leaf(root->left, targetSum, sum + root->val) || root_to_leaf(root->right, targetSum, sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return root_to_leaf(root, targetSum, sum);
    }
};