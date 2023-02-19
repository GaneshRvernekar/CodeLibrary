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

class TreeNode{
public:
int val;
TreeNode *left;
TreeNode *right;

TreeNode(int x)
{
    val=x;
}

};
class Solution {
public:

    bool traverse(TreeNode *root,int n,string &str)
    {
        if(!root)
        {
            return false;
        }

        if(root->val ==n)
        {
            return true;
        }

        str.push_back('L');
        if(traverse(root->left,n,str))
        {
            return true;
        }
        str.pop_back();

        str.push_back('R');

        if(traverse(root->right,n,str))
        {
            return true;
        }
        str.pop_back();
        return false;
        
    }
    TreeNode* getLca(TreeNode *root,int s,int d)
    {
        if(!root)
        {
            return NULL;
        }

        if(root->val == s || root->val == d)
        {
            return root;
        }

        TreeNode *left = getLca(root->left,s,d);
        TreeNode *right = getLca(root->right,s,d);

        if(left && right)
        {
            return root;
        }

        if(left && !right)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        TreeNode *lca = getLca(root,startValue,destValue);

        string Spath="",Dpath="";

        

        traverse(lca,startValue,Spath);
        traverse(lca,destValue,Dpath);

        cout<<Spath<<" "<<Dpath<<endl;

        for(int i=0;i<Spath.length();i++)
        {
            Spath[i]='U';
        }

        return Spath+Dpath;
        
    }
};