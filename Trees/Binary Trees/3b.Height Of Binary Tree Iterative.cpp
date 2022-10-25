// ? Using Variable.
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        TreeNode *n = root;
        q.push(n);
        int h = 0;
        while (!q.empty())
        {
            int size = q.size();

            while (size--)
            {
                TreeNode *n = q.front();
                q.pop();

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }

            h++;
        }

        return h;
    }
};

// ? Using vector.
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        vector<vector<int>> bfs;
        if (!root)
            return 0;
        queue<TreeNode *> q;
        TreeNode *n = root;
        q.push(n);

        while (!q.empty())
        {
            vector<int> level;
            int size = q.size();

            while (size--)
            {
                TreeNode *n = q.front();
                q.pop();

                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
                level.push_back(n->val);
            }

            bfs.push_back(level);
        }

        return bfs.size();
    }
};