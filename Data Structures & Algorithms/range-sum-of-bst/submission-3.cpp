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
   public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        // int sum=0;
        // TreeNode* curr=root;
        // if(curr->val < low){
        //     return rangeSumBST(root->right,low,high);
        // }
        // if(curr->val > high){
        //     return rangeSumBST(root->left,low,high);
        // }
        // sum+=rangeSumBST(root->left,low,high);
        // sum+=rangeSumBST(root->right,low,high);
        // return sum+root->val;
        stack<TreeNode*> st;
        int sum=0;
        st.push(root);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();

            if(curr->val >=low && curr->val <= high){
                sum+=curr->val;
            }
            if(curr->val < high && curr->right!=nullptr){
                st.push(curr->right);
            }
            if(curr->val > low && curr->left!=nullptr){
                st.push(curr->left);
            }
        }
        return sum;
    }
};