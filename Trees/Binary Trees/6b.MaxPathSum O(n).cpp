class Solution
{
public:
    int mpsum(TreeNode *n, int &msum)
    {
        if (!n)
            return 0;

        int l = mpsum(n->left, msum);

        if (l < 0)
            l = 0;

        int r = mpsum(n->right, msum);

        if (r < 0)
            r = 0;

        msum = max(msum, n->val + l + r);

        return n->val + max(l, r);
    }

    int maxPathSum(TreeNode *root)
    {
        if (!root)
            return 0;

        int msum = INT_MIN;

        mpsum(root, msum);

        return msum;
    }
};