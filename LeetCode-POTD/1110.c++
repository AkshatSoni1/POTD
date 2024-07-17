// 1110. Delete Nodes And Return Forest

class Solution {
public:
    void solve(TreeNode* root, vector<TreeNode*>& ans, unordered_set<int>& st){
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({root, NULL});

        while(!q.empty()){
            TreeNode* node = q.front().first;
            TreeNode* parent = q.front().second;
            q.pop();
            if(node-> left)
                q.push({node-> left, node});
            if(node-> right)
                q.push({node-> right, node});

            if(st.find(node-> val) != st.end()){
                if(node-> left){
                    ans.push_back(node-> left);
                }
                if(node-> right){
                    ans.push_back(node-> right);
                }
                if(parent){
                if(parent-> left == node)
                    parent-> left = NULL;
                else{
                    parent-> right = NULL;
                }
                }
            }
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& d) {
        unordered_set<int> st;
        vector<TreeNode*> ans;
        for(int i=0; i<d.size(); i++){
            st.insert(d[i]);
        }
        solve(root, ans, st);
        ans.push_back(root);
        for(int i=0; i<ans.size(); ){
            if(st.find(ans[i]->val) != st.end()){
                ans.erase(ans.begin()+i);
            }
            else{
                i++;
            }
        }
        return ans;
    }
};