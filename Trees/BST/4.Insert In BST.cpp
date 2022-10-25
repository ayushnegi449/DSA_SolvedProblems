// Recursive
class Solution
{
public:
    TreeNode *insert(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *n = new TreeNode(val);
            return n;
        }

        if (val > root->val)
        {
            root->right = insert(root->right, val);
        }
        else if (val < root->val)
        {
            root->left = insert(root->left, val);
        }

        return root;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return insert(root, val);
    }
};

// Iterative
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            TreeNode *n = new TreeNode(val);
            return n;
        }

        TreeNode *node = root;

        while (true)
        {
            if (val > root->val)
            {
                if (root->right == NULL)
                {
                    root->right = new TreeNode(val);
                    break;
                }
                root = root->right;
            }
            else if (val < root->val)
            {
                if (root->left == NULL)
                {
                    root->left = new TreeNode(val);
                    break;
                }
                root = root->left;
            }
        }

        return node;
    }
};