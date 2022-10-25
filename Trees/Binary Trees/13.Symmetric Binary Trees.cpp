// 101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

class Solution
{
public:
    bool checkSymmetry(TreeNode *l, TreeNode *r)
    {
        if (l == r)
            return true;
        if (!l || !r)
            return false;

        if (l->val != r->val)
            return false;

        bool c1 = checkSymmetry(l->left, r->right);
        bool c2 = checkSymmetry(l->right, r->left);

        return c1 && c2;
    }

    bool isSymmetric(TreeNode *root)
    {

        bool res = checkSymmetry(root->left, root->right);

        return res;
    }
};