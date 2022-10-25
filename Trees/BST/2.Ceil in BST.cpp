int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ceilval = -1;

    while (node)
    {
        if (node->data == x)
        {
            ceilval = node->data;
            return ceilval;
        }
        else if (x > node->data)
        {
            node = node->right;
        }
        else if (x < node->data)
        {
            ceilval = node->data;
            node = node->left;
        }
    }

    return ceilval;
}