class Solution
{
public:
    vector<int> vals;

    void rightview(TreeNode *n, int lvl)
    {
        // if(!n) return ;

        if (lvl == vals.size())
            vals.push_back(n->val);
        if (n->right)
            rightview(n->right, lvl + 1);
        if (n->left)
            rightview(n->left, lvl + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        if (!root)
            return vals;

        rightview(root, 0);

        return vals;
    }
};

// Iterative
class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        queue<pair<TreeNode *, int>> q;
        map<int, int> mp;

        int lvl = 0;
        TreeNode *n = root;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            n = it.first;
            lvl = it.second;

            if (mp.find(lvl) == mp.end())
            {
                mp[lvl] = n->val;
            }

            if (n->right)
                q.push({n->right, lvl + 1});
            if (n->left)
                q.push({n->left, lvl + 1});
        }

        for (auto it : mp)
        {
            ans.push_back(it.second);
        }

        return ans;
    }
};