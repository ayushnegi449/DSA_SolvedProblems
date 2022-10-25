
vector<int> vals;

void rightview(TreeNode<int> *n, int lvl)
{
    // if(!n) return ;

    if (lvl == vals.size())
        vals.push_back(n->data);
    if (n->left)
        rightview(n->left, lvl + 1);
    if (n->right)
        rightview(n->right, lvl + 1);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    if (!root)
        return vals;

    rightview(root, 0);

    return vals;
}

// Iterative
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> mp;

    int lvl = 0;
    TreeNode<int> *n = root;

    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        n = it.first;
        lvl = it.second;

        if (mp.find(lvl) == mp.end())
        {
            mp[lvl] = n->data;
        }
        if (n->left)
            q.push({n->left, lvl + 1});
        if (n->right)
            q.push({n->right, lvl + 1});
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }

    return ans;
}
