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

    TreeNode* findMin(TreeNode* node){
        while(node->left !=NULL){
            node=node->left;
        }

        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }

        // Step 2: We found the node! Now, delete it.
        else {
            // Scenario 1 & 2: Node has 0 or 1 child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root; // Free the memory
                return temp;
            } 
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Scenario 3: Node has 2 children
            // Find the Inorder Successor (smallest node in the right subtree)
            TreeNode* temp = findMin(root->right);
            
            // Copy the successor's value into our current node
            root->val = temp->val;
            
            // Delete the original successor node from the right subtree
            root->right = deleteNode(root->right, temp->val);
        }

        return root;

    }
};