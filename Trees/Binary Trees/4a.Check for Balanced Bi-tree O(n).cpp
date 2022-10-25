class Solution
{
public:
    int h(TreeNode *n)
    {
        if (!n)
            return 0;

        int l = h(n->left);

        if (l == -1)
            return -1;

        int r = h(n->right);

        if (r == -1) // if l is -1 || r==-1, means subtree/tree is unbalanced. Return -1 , no need to calculate height for further nodes
            return -1;

        if (abs(l - r) > 1) // if at any subtree/tree height difference is not equal to 0/1 then return -1;
            return -1;

        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {

        if (!root)
            return true;

        return h(root) != -1;
    }
};