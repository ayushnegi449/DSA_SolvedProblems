// Recursive Solution
class Solution
{
public:
    TreeNode *prev = NULL;

    void flatten(TreeNode *root)
    {

        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;

        return;
    }
};

// Iterative Solution
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *n = s.top();
            s.pop();

            if (n->right)
                s.push(n->right);

            if (n->left)
                s.push(n->left);

            if (!s.empty())
                n->right = s.top();
            n->left = NULL;
        }
    }
};

// Morris Traversal

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
                curr = curr->right;
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right != NULL)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
    }
};