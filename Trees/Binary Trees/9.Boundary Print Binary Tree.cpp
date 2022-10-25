bool isLeaf(TreeNode<int> *n)
{
    if (!n->left && !n->right)
        return true;

    return false;
}

void leftBoundary(TreeNode<int> *n, vector<int> &ans)
{
    TreeNode<int> *curr = n->left;
    while (curr)
    {
        if (!isLeaf(curr))
            ans.push_back(curr->data);
            
        if (curr->left) 
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void rightBoundary(TreeNode<int> *n, vector<int> &ans)
{
    TreeNode<int> *curr = n->right;
    vector<int> temp;

    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    int s = temp.size() - 1;

    for (int i = s; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}

void leaves(TreeNode<int> *node, vector<int> &ans)
{

    if (isLeaf(node))
    {
        ans.push_back(node->data);
        return;
    }
    if (node->left)
        leaves(node->left, ans);
    if (node->right)
        leaves(node->right, ans);
}

vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    leftBoundary(root, ans);
    leaves(root, ans);
    rightBoundary(root, ans);

    return ans;
}