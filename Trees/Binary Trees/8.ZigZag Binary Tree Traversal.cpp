//? Method 1.
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool lr = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> rows(n);

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                int idx = lr ? i : n - 1 - i;

                rows[idx] = node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            lr = !lr;

            ans.push_back(rows);
        }

        return ans;
    }
};

//? Method 2.
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool flag = true;

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                level.push_back(node->val);
            }
            if (flag)
            {
                flag = false;
            }
            else
            {
                flag = true;
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
        }

        return ans;
    }
};