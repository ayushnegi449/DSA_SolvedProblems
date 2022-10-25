// Recursive
class Solution
{
public:
    TreeNode *search(TreeNode *root, int val)
    {
        if (root == NULL || root->val == val)
            return root;

        TreeNode *n = NULL;
        if (val < root->val)
        {
            n = search(root->left, val);
        }
        else
        {
            n = search(root->right, val);
        }

        return n;
    }

    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;

        return search(root, val);
    }
};