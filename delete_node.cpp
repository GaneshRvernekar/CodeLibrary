// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
         
            TreeNode *cur=root,*p,*par=NULL;
        while(cur!=NULL && cur->val!=key)
        {
            par=cur;
            if(cur->val>key)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
        if(cur==NULL)
        {
            return root;
        }
        if(cur->left ==NULL && cur->right==NULL)
        {
            if(cur==root)
            {
                return NULL;
            }
        }
        if(cur->left == NULL)
        {
           p=cur->right; 
        }
        else if(cur->right==NULL)
        {
            p=cur->left;
        }
        else
        {
            TreeNode *succ= cur->right;
            while(succ->left)
            {
                succ=succ->left;
            }
            succ->left=cur->left;
            p=cur->right;
        }
         if (par == NULL)
        {
            
            return p;
         }
        if(par->left==cur)
        {
            par->left=p;
        }
        else if(par->right==cur)
        {
            par->right=p;
        }
       
        return root;
        
    }
};