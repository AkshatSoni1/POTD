//Morris Traversal - Inorder

class Solution {
public:
    TreeNode* findPre(TreeNode* node, TreeNode* curr){
        while(node-> right != NULL && node-> right != curr)
            node = node-> right;
        
        return node;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr-> left == NULL){
                ans.push_back(curr-> val);
                curr = curr-> right;
            }
            else{
                TreeNode* pred = findPre(curr-> left, curr);
                if(pred-> right == NULL){
                    pred-> right = curr;
                    curr = curr-> left;
                }
                else{
                    pred-> right = NULL;
                    ans.push_back(curr-> val);
                    curr = curr-> right;
                }
            }
        }
        return ans;
    }
};