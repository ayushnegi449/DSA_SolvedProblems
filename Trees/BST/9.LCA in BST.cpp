class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (!root)
            return NULL;

        int nval = root->val;
        if (p->val < nval && q->val < nval)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (p->val > nval && q->val > nval)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};