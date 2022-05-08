class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* left=increasingBST(root->left);
        TreeNode* right=increasingBST(root->right);
        if(left==NULL){
            root->left=NULL;
            root->right=right;
            return root;
        } 
        TreeNode *temp=left;
        while(temp->right!=NULL) temp=temp->right;
        temp->right=root;
        root->left=NULL;
        root->right=right;
        return left;
    }
};