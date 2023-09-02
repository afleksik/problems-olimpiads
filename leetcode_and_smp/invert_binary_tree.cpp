#include <bits/stdc++.h>

/**

https://leetcode.com/problems/invert-binary-tree/description/
 * Definition for a binary tree node.*/
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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* v;
        queue<TreeNode*> q;

        if (root == NULL) 
            return NULL;

        q.push(root);

        while (!q.empty()) {
            v = q.front();
            swap(v->left, v->right);
            q.pop();
            if (v->left) {
                q.push(v->left);
            }
            if (v->right) {
                q.push(v->right);
            }
        }
        return root;
    }
};