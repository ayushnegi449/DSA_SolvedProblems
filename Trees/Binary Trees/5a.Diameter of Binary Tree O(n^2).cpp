class Solution
{
private:
    int maxi = 0;

public:
    int h(TreeNode *n)
    {
        if (!n)
            return 0;

        int l = h(n->left);
        int r = h(n->right);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = h(root->left);
        int rh = h(root->right);

        maxi = max(maxi, lh + rh);

        if (root->left)
            diameterOfBinaryTree(root->left);
        if (root->right)
            diameterOfBinaryTree(root->right);

        return maxi;
    }
};