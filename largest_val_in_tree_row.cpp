// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

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
    vector<int> largestValues(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        vector<int> answer;

        answer.push_back(root->val);
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(nullptr);
        int i=0;
        while(!qu.empty())
        {
            TreeNode *curr= qu.front();
             int val=curr->val,n=INT_MIN;
            while(curr!=nullptr)
            {
                if(curr->left)
                {
                    qu.push(curr->left);
                }
                if(curr->right)
                {
                    qu.push(curr->right);
                }
                val=max(val,curr->val);
                qu.pop();
                curr=qu.front();
            }
            qu.pop();
            if(!qu.empty())
            {
                qu.push(nullptr);
            }
            if(i==0)
            {
                i++;
            }else
            {

            answer.push_back(val);
            }
            
        }
        return answer;
     }
};