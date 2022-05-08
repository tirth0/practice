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
    
    unordered_map<string, vector<TreeNode*>> memo;
    vector <TreeNode*> getSubTrees(int l,int r){
        vector<TreeNode*> res;
        if (l > r){
            res.push_back(nullptr);
            return res;
        }
        
        string key = to_string(l)+"_"+to_string(r);
        if (memo.find(key)!=memo.end())
            return memo.find(key)->second;
        
        
        for (int i=l ; i<=r; i++){
            vector<TreeNode*> leftTrees = getSubTrees(l, i-1);
            vector<TreeNode*> rightTrees = getSubTrees(i+1, r);
            
            for (TreeNode *left : leftTrees) {
                for (TreeNode *right : rightTrees) {
                  TreeNode *node = new TreeNode(i);
                  node->left = left;
                  node->right = right;
                  res.push_back(node);
                }
            }
            
        }
        memo[key] = res;
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        
        return getSubTrees(1, n);
        
    }   
    
    
    
};