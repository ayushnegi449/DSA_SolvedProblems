int parent_nodes(unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parents, BinaryTreeNode<int> *root, BinaryTreeNode<int> *&target, int start)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BinaryTreeNode<int> *n = q.front();
        q.pop();
        if (n->data == start)
        {
            target = n;
        }
        if (n->left)
        {
            q.push(n->left);
            parents[n->left] = n;
        }
        if (n->right)
        {
            q.push(n->right);
            parents[n->right] = n;
        }
    }
}

int timeToBurnTree(BinaryTreeNode<int> *root, int start)
{
    int ans;
    if (!root)
        return ans;

    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parents;
    unordered_map<BinaryTreeNode<int> *, bool> visited;
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *target;
    parent_nodes(parents, root, target, start);

    q.push(target);
    visited[target] = true;

    int time = 0;
    while (!q.empty())
    {
        int size = q.size();
        bool flag = false;
        for (int i = 0; i < size; i++)
        {

            BinaryTreeNode<int> *n = q.front();
            q.pop();

            if (n->left && visited[n->left] != true)
            {
                flag = true;
                visited[n->left] = true;
                q.push(n->left);
            }
            if (n->right && visited[n->right] != true)
            {
                flag = true;
                visited[n->right] = true;
                q.push(n->right);
            }
            if (parents[n] != 0 && visited[parents[n]] != true)
            {
                flag = true;
                visited[parents[n]] = true;
                q.push(parents[n]);
            }
        }
        if (flag)
            time++;
    }

    return time;
}