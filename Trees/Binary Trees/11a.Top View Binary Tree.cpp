// Using map
vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    map<int, int> nodes; // first int is for the index , second int stores the values of the nodes
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty()) // bfs traversal
    {
        auto it = q.front();
        q.pop();

        TreeNode<int> *n = it.first;
        int index = it.second;

        // check if the index is present in map cause front view is first index taht occured vertically.
        if (nodes.count(index) == 0)
        {
            nodes[index] = n->val;
        }
        if (n->left)
            q.push({n->left, index - 1});
        if (n->right)
            q.push({n->right, index + 1});
    }

    for (auto vals : nodes)
    {
        // just traverse the map from left most index to the right most and push in vector
        ans.push_back(vals.second);
    }
    return ans;
}

// Using Deque
vector<int> getTopView(TreeNode<int> *root)
{
    deque<int> deq;
    vector<int> ans;
    if (!root)
        return ans;
    queue<pair<TreeNode<int> *, int>> q;
    q.push({root, 0});

    // root node is always in the top-view so:
    deq.push_back(root->val);

    // intially leftmost and rightmost indexes = root index = 0
    int l = 0;
    int r = 0;
    while (!q.empty())
    {
        auto it = q.front();
        TreeNode<int> *t = it.first;
        int idx = it.second;
        q.pop();

        // new node has a vertical level greater than rightmost tree level till now so, add it to top-view
        if (idx > r)
        {
            r = idx;
            deq.push_back(t->val);
        }
        // new node has a vertical level lesse than leftmost tree level till now so, add it to top-view
        if (idx < l)
        {
            l = idx;
            deq.push_front(t->val);
        }
        // insert children
        if (t->left)
            q.push({t->left, idx - 1});
        if (t->right)
            q.push({t->right, idx + 1});
    }
    while (!deq.empty())
    {
        ans.push_back(deq.front());
        deq.pop_front();
    }

    return ans;
}

// Method 3 Using just 2 extra variables.

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;

    queue<pair<TreeNode<int> *, int>> q;

    // store the leftmost and right most index , intially both are 0 since it is it root node
    int l = 0, idx = 0, r = 0;

    // push the root node since it is always included(or just change l = 1 initally and dont push intially (intuitively not correct tho))
    ans.push_back(root->val);
    q.push({root, 0});

    TreeNode<int> *n = NULL;

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        n = it.first;
        idx = it.second;

        if (idx < l) // if index is lower than the leftmost index then it is the front value.
        {
            l = idx;
            ans.insert(ans.begin(), n->val);
        }
        else if (idx > r) // if index is bigger than the rightmost index then it is the last value.
        {
            r = idx;
            ans.push_back(n->val);
        }

        // if idx is bigger than leftmost index but smaller than rightmose index then the current node is just hidden(not visible from top)

        if (n->left)
            q.push({n->left, idx - 1});

        if (n->right)
            q.push({n->right, idx + 1});
    }

    return ans;
}