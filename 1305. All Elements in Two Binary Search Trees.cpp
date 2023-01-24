class Solution {
    vector<int>v;
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        getElements(root1,root2);
        sort(v.begin(),v.end());
        return v;
    }
    private:
    void getElements(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
            return;
        //cout<<root1->val<<root2->val;    
        if(root1!=NULL && root2!=NULL){
            v.push_back(root1->val);
            v.push_back(root2->val);
            getElements(root1->left,root2->left);
            getElements(root1->right,root2->right);

        }
        else{
            if(root1==NULL){
                v.push_back(root2->val);          
                getElements(root1,root2->left);
                getElements(root1,root2->right);
            }
            else{
                v.push_back(root1->val);          
                getElements(root1->left,root2);
                getElements(root1->right,root2);

            }
        }
        return;
    }

};
