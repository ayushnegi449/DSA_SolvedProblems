class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (q.empty() != true)
        {
            int size = q.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();

                if (n->left != NULL)
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);

                level[i] = n->val; // level.pushback(n->val);
            }

            ans.push_back(level);
        }

        return ans;
    }
};