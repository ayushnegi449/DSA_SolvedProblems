class Solution
{
public:
    int val(TreeNode *n)
    {
        if (!n)
            return 0;

        int lval = val(n->left);
        if (lval < 0)
            lval = 0;

        int rval = val(n->right);
        if (rval < 0)
            rval = 0;

        return (n->val) + max(lval, rval);
    }

    int maxi = INT_MIN;

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = max(0, val(root->left));
        int r = max(0, val(root->right));

        maxi = max(maxi, l + r + (root->val));

        maxPathSum(root->left);
        maxPathSum(root->right);

        return maxi;
    }
};