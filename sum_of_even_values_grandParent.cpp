// Given the root of a binary tree, return the sum of values of nodes with an even-valued grandparent. If there are no nodes with an even-valued grandparent, return 0.

// A grandparent of a node is the parent of its parent if it exists.


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
       int s=0;
        
        void helper(TreeNode *curr,TreeNode *parent,TreeNode *grandParent)
        {
                if(curr==NULL)
                {
                        return  ;
                }
                if(grandParent!=NULL && grandParent->val%2==0)
                {
                       s+=curr->val; 
                }
                helper(curr->left,curr,parent);
                helper(curr->right,curr,parent);
        }
    int sumEvenGrandparent(TreeNode* root) {
            
            helper(root,NULL,NULL);
            return s;
        
    }
};