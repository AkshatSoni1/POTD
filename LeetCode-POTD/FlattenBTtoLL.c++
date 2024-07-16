class Solution {
public:
    TreeNode* findPre(TreeNode* node){
        while(node-> right != NULL)
            node = node-> right;
        
        return node;
    }
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr-> left){
                TreeNode* pred = findPre(curr-> left);
                pred-> right = curr -> right;
                curr-> right = curr-> left;
                curr-> left = NULL;
            }
            curr = curr-> right;
        }
    }
};