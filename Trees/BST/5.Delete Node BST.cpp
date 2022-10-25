// Iterative
class Solution
{
public:
    TreeNode *helper(TreeNode *root)
    {
        TreeNode *n = NULL;
        if (root->left == NULL)
        {
            n = root->right;
            delete (root);
            return n;
        }
        else if (root->right == NULL)
        {
            n = root->left;
            delete (root);
            // cout<<root->val;
            return n;
        }
        else
        {
            TreeNode *prev = root->left, *node = root->left;
            while (prev->right != NULL)
            {
                prev = prev->right;
            }

            prev->right = root->right;
            delete (root);
            return node;
        }
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return NULL;

        if (root->val == key)
            return helper(root);

        TreeNode *n = root;

        while (root != NULL)
        {
            if (key < root->val)
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left);
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else if (key > root->val)
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                    root = root->right;
            }
        }

        return n;
    }
};

// Recursive
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (!root)
            return NULL;

        if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (root->val == key)
        {
            TreeNode *n = NULL;

            if (root->left == NULL)
            {
                n = root->right;
                delete (root);
                return n;
            }
            else if (root->right == NULL)
            {
                n = root->left;
                delete (root);
                return n;
            }
            else
            {
                TreeNode *node = root->left;
                n = root->left;

                while (n->right != NULL)
                {
                    n = n->right;
                }

                n->right = root->right;
                delete (root);
                return node;
            }
        }

        return root;
    }
};