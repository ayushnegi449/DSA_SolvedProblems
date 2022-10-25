int floorInBST(TreeNode<int> *root, int x)
{
    int floor = -1;

    while (root)
    {
        if (root->val == x)
        {
            floor = root->val;
            return floor;
        }
        else if (x < root->val)
        {
            root = root->left;
        }
        else if (x > root->val)
        {
            floor = root->val;
            root = root->right;
        }
    }

    return floor;
}