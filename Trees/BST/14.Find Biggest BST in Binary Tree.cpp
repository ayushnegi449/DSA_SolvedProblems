class largestNode
{
public:
    int size, minnode, maxnode;
    largestNode(int size, int minnode, int maxnode)
    {
        this->size = size;
        this->minnode = minnode;
        this->maxnode = maxnode;
    }
};

largestNode bstfinder(TreeNode<int> *root)
{
    if (!root)
    {
        return largestNode(0, INT_MAX, INT_MIN);
    }

    largestNode l = bstfinder(root->left);
    largestNode r = bstfinder(root->right);

    if (root->data > l.maxnode && root->data < r.minnode)
    {
        return largestNode(1 + l.size + r.size, min(root->data, l.minnode), max(root->data, r.maxnode));
    }

    return largestNode(max(l.size, r.size), INT_MIN, INT_MAX);
}

int largestBST(TreeNode<int> *root)
{
    return bstfinder(root).size;
}
