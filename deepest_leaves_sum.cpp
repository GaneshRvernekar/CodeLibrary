// Given the root of a binary tree, return the sum of values of its deepest leaves.

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
    int deepestLeavesSum(TreeNode* root) {
            
            queue<TreeNode *> qu;
            
            qu.push(root);
            qu.push(NULL);
            int sum1=root->val;
            int sum2=0;
            while(!qu.empty())
            {
                    
                    TreeNode *cur =qu.front();
                  
                    qu.pop();
                    if(cur->left)
                    {
                            sum2+=cur->left->val;
                            qu.push(cur->left);
                    }
                    if(cur->right)
                    {
                            sum2+=cur->right->val;
                            qu.push(cur->right);
                    }
                    if(qu.front()==NULL)
                    {
                            if(sum2>0)
                            {
                                    sum1=sum2;
                                    sum2=0;
                            }
                            qu.pop();
                            if(!qu.empty())
                            {
                                 qu.push(NULL);   
                            }
                            
                    }
            }
            return sum1;
        
    }
};