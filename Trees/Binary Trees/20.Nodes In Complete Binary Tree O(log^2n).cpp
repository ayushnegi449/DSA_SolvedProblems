class Solution
{
public:
    int lefth(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->left;
        }

        return h;
    }

    int righth(TreeNode *root)
    {
        int h = 0;
        while (root)
        {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int l = lefth(root);
        int r = righth(root);

        if (l == r)
            return pow(2, l) - 1;

        int lst = countNodes(root->left);
        int rst = countNodes(root->right);

        return 1 + lst + rst;
    }
};