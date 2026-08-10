class Solution {
public:
    int max_len = 0;

    // Ye function ek pair return karega: {Longest Left ZigZag, Longest Right ZigZag}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {-1, -1}; // Base case: null node ki length -1 hoti hai

        // Pehle dono bachhon se unka answer mango (Post-Order Traversal)
        pair<int, int> leftChild = dfs(node->left);
        pair<int, int> rightChild = dfs(node->right);

        // Ab parent apna calculate karega
        // Parent ka left path = 1 + left child ka right path
        int myLeftZigZag = 1 + leftChild.second;
        
        // Parent ka right path = 1 + right child ka left path
        int myRightZigZag = 1 + rightChild.first;

        // Global max ko update kar do
        max_len = max({max_len, myLeftZigZag, myRightZigZag});

        // Apna answer upar apne parent ko bhej do
        return {myLeftZigZag, myRightZigZag};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return max_len;
    }
};