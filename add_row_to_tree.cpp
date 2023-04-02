// Given the root of a binary tree and two integers val and depth, add a row of nodes with value val at the given depth depth.

// Note that the root node is at depth 1.

// The adding rule is:

// Given the integer depth, for each not null tree node cur at the depth depth - 1, create two tree nodes with value val as cur's left subtree root and right subtree root.
// cur's original left subtree should be the left subtree of the new left subtree root.
// cur's original right subtree should be the right subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth - 1 at all, then create a tree node with value val as the new root of the whole original tree, and the original tree is the new root's left subtree.

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
   void addRow(TreeNode* root, int val, int depth) {

       if(!root)
       {
           return;
       }

       if(depth==2)
        {
            
            TreeNode *root1 = new TreeNode(val);
            root1->left = root->left;
            root->left=root1;
            
            
                TreeNode *root2 = new TreeNode(val);
                root2->right=root->right;
                root->right=root2;
            
        }
        addRow(root->left,val,depth-1);
        addRow(root->right,val,depth-1);
                
    }
    

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

          if(!root){
        return NULL;
    }
    if(depth == 1){
        TreeNode*temp  = new TreeNode(val);
        temp->left = root;
        return temp;
    }

        addRow(root,val,depth);

        return root;
        
    }
};
