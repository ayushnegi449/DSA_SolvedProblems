class BSTiterator
{
private:
    stack<TreeNode *> s;
    bool reverse = false;

public:
    BSTiterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushNodes(root);
    }

    void pushNodes(TreeNode *root)
    {
        while (root != NULL)
        {
            s.push(root);
            if (!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }

    int next()
    {
        TreeNode *n = s.top();
        s.pop();

        if (!reverse)
            pushNodes(n->right);
        else
            pushNodes(n->left);

        return n->val;
    }

    bool hasnext()
    {
        return !s.empty();
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        BSTiterator l(root, false);
        BSTiterator r(root, true);

        int i = l.next();
        int j = r.next();

        bool flag = false;

        while (i != j)
        {
            int res = i + j;

            if (res == k)
            {
                flag = true;
                break;
            }
            else if (res < k)
            {
                i = l.next();
            }
            else if (res > k)
            {
                j = r.next();
            }
        }

        return flag;
    }
};