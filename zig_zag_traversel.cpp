// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
         vector<vector<int>> answer;       
        vector<int> sim;
        if(root==NULL)
        {
            return answer;
        }
    
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
       
        sim.push_back(root->val);
        answer.push_back(sim);

    while((!st1.empty()) || (!st2.empty()))
    {
        vector<int> num;
        while(!st1.empty())
        {
            TreeNode *cur=st1.top();
            
            if(cur->right!=NULL)
            {
                st2.push(cur->right);
                num.push_back(cur->right->val);
            }
            if(cur->left!=NULL)
            {
               st2.push(cur->left);
              num.push_back(cur->left->val);
            }

            st1.pop();
        }
        if(!num.empty())
        {
             answer.push_back(num);
        }
        num.clear();
        while(!st2.empty())
        {
            TreeNode *cur=st2.top();
            if(cur->left!=NULL)
            {
                st1.push(cur->left);
                 num.push_back(cur->left->val);
           
            }
            if(cur->right!=NULL)
            {
               st1.push(cur->right);
                 num.push_back(cur->right->val);
            
            }
           st2.pop();
        }
        if(!num.empty())
        {
             answer.push_back(num);
        }
       
        num.clear();
        
    }
        return answer;
}
  
};