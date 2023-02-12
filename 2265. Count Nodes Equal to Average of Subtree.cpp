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
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        averageOfSubtree1(root,ans);
          return ans;
    }
    pair<int,int> averageOfSubtree1(TreeNode* root, int &ans) {
        if(root==NULL)
            return {0,0};   
        const auto [leftSum, leftCount] = averageOfSubtree1(root->left,ans);
        const auto [rightSum, rightCount] = averageOfSubtree1(root->right,ans); 
        int sum=leftSum + rightSum +root->val;
        const int n = 1 + leftCount + rightCount;
        cout<<sum<<" "<<n<<" ";
        if(round(sum/n)==root->val)
            ans++;
        return {sum ,n};   
    }
};
