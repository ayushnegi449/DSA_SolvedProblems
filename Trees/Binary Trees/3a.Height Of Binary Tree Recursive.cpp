class Solution
{
public:
    int h(TreeNode *n)
    {
        if (!n)
            return 0;
        int l = h(n->left);
        int r = h(n->right);

        return 1 + max(l, r);
    }
    int maxDepth(TreeNode *root)
    {
        return h(root);
    }
};