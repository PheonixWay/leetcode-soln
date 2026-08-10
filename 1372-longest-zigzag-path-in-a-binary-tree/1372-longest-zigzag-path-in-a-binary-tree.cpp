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
    int max_len=0;
    void dfs(TreeNode* node,bool isLeft,int steps){
        if(!node) return;
        // updating max value at each node
        max_len=max(max_len,steps);

        if(isLeft){
            //Rule followed: Go Left ,increase steps,next move must be right isFlase(false)
            dfs(node->left,false,steps+1);
            //Rule not followed: Go Right,steps resets to 1,next move must be isLeft(true)
            dfs(node->right,true,1);
        }else{
            //Rule followed: Go Right ,increase steps,next move must be Left isFlase(true)
            dfs(node->right,true,steps+1);
            //Rule not followed: Go Left,steps resets to 1,next move must be isLeft(false)
            dfs(node->left,false,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        if(!root) return 0;

        // Ggoing from root to left so isLeft will be false
        dfs(root->left,false,1);

        // Going from root to right so isLeft will be true 
        dfs(root->right,true,1);

        return max_len;
    }
};