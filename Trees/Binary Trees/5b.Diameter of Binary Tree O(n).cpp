class Solution
{
public:
    int h(TreeNode *n, int &diameter)
    {
        if (!n)
            return 0;

        int l = h(n->left, diameter);
        int r = h(n->right, diameter);

        diameter = max(diameter, l + r);

        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;

        int diameter = 0;
        h(root, diameter);

        return diameter;
    }
};