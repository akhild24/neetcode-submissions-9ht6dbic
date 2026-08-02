class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        q.push(root);

        while(!q.empty()) {
            int lvlsize = q.size();
            vector<int> tmp;

            while(lvlsize--) {
                TreeNode* t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left != nullptr) q.push(t->left);
                if(t->right != nullptr) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};