class Solution
{
public:
    bool isBSTvalid(TreeNode *root, long minval, long maxval)
    {
        if (root == NULL)
            return true;

        if (root->val >= maxval || root->val <= minval)
            return false;

        bool l = isBSTvalid(root->left, minval, root->val);
        bool r = isBSTvalid(root->right, root->val, maxval);

        return l && r;
    }

    bool isValidBST(TreeNode *root)
    {

        if (!root)
            return true;

        return isBSTvalid(root, LONG_MIN, LONG_MAX);
    }
};