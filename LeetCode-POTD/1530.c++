class Solution {
public:
    void makeGraph(TreeNode* root, TreeNode* prev, unordered_map<TreeNode*, vector<TreeNode*>>& adj, 
        unordered_set<TreeNode*>& st){
        if(root == NULL) return;
        
        if(!root-> left && !root-> right){
            st.insert(root);
        }

        if(prev){
            adj[root].push_back(prev);
            adj[prev].push_back(root);
        }
        makeGraph(root-> left, root, adj, st);
        makeGraph(root-> right, root, adj, st);
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> adj;
        unordered_set<TreeNode*> st;

        makeGraph(root, NULL, adj, st);

        int cnt = 0;
        for(auto& i:st){
            queue<TreeNode*> q;
            unordered_set<TreeNode*> visited;
            q.push(i);
            int lvl = 0;
            while(!q.empty()){
                int size = q.size();
                while(size--){
                    TreeNode* node = q.front();
                    q.pop();
                    if(st.find(node) != st.end() && node != i){
                        cnt++;
                    }
                    for(auto neigh : adj[node]){
                        if(visited.find(neigh) == visited.end()){
                            q.push(neigh);
                            visited.insert(neigh);
                        }
                    }
                }
                lvl++;
                if(lvl > distance) break;
            }
        }
        return cnt/2;
    }
    };