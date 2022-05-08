class Solution {
public:
    vector<int> preorder(Node* root) {
        stack <Node*> stk;
        vector<int> visited;
        vector<int> res;
        stk.push(root);
        while (!stk.empty()){
            Node * node = stk.top();
            stk.pop();
            if (node == nullptr || node->val == -1) continue;
            res.push_back(node -> val);
            node-> val = -1;
            auto v = node->children;
            reverse(v.begin(), v.end());
            for (Node * child: v){
                    stk.push(child);
            }
        }
        return res;
    }
};