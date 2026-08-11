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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int max_sum = INT_MIN;
        int best_level = 1;
        int current_level = 1;

        while (!q.empty()) {
            int level_size = q.size(); // Current floor par kitne log hain
            int current_sum = 0;

            // Is floor ke saare nodes ko process karo
            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();

                current_sum += node->val; // Sum add karo

                // Next floor ke liye bacchon ko queue mein daalo
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }

            // Agar naya max mila, toh record update karo
            // (Strictly '>' use kiya kyunki agar sum same ho, toh humein chota level hi chahiye)
            if (current_sum > max_sum) {
                max_sum = current_sum;
                best_level = current_level;
            }

            current_level++; // Next floor par jaane ke liye level badha do
        }

        return best_level;
    }
};