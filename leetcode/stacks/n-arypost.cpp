class Solution {
public:
    vector<int> postorder(Node* root) {
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
            for (Node * child: node->children){
                    stk.push(child);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};