// 2096. Step-By-Step Directions From a Binary Tree Node to Another

// You are given the root of a binary tree with n nodes. Each node is uniquely assigned a value from 1 to n. You are also given an integer startValue representing the value of the start node s, and a different integer destValue representing the value of the destination node t.
// Find the shortest path starting from node s and ending at node t. Generate step-by-step directions of such path as a string consisting of only the uppercase letters 'L', 'R', and 'U'. Each letter indicates a specific direction:
// 'L' means to go from a node to its left child node.
// 'R' means to go from a node to its right child node.
// 'U' means to go from a node to its parent node.
// Return the step-by-step directions of the shortest path from node s to node t.

class Solution {
public:
    bool findPath(TreeNode* root, int n, string& s){
        if(root == NULL)
            return false;

        if(root-> val == n) return true;
        
        s.push_back('L');
        if(findPath(root-> left, n, s))  return true;
        s.pop_back();

        s.push_back('R');
        if(findPath(root-> right, n, s))  return true;
        s.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int s, int d) {
        string s1 = "";
        string s2 = "";
        findPath(root, s, s1);
        findPath(root, d, s2);

        int idx = 0;
        while(s1.length() && s2.length()){
            if(s1[idx] == s2[idx]){
                idx++;
            }
            else{
                break;
            }
        }

        for(int i=idx; i<s1.length(); i++)
            s1[i] = 'U';
        
        return (s1.substr(idx)+s2.substr(idx));

    }
};