// Can do using recursion as well.

    // Function to find predecessor and successor of a 'key' in a BST
    pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    // These variables will store the answers
    int predecessor = -1;
    int successor = -1;

    // create a separate pointer to traverse the BST
    BinaryTreeNode<int> *currNode = root;

    // Search until you find a NULL or the 'key'
    while (currNode and currNode->data != key)
    {
        // if key is small...
        if (currNode->data > key)
        {
            //...store currNode's data as successor
            successor = currNode->data;
            // and move left
            currNode = currNode->left;
        }
        else // if key is large...
        {
            //...store currNode's data as predecessor
            predecessor = currNode->data;
            // and move right
            currNode = currNode->right;
        }
    }

    // edge case or if 'key' isn't present in the BST
    if (currNode == NULL)
        return {};

    // search for the correct/perfect predecessor and successor
    BinaryTreeNode<int> *finder;

    // check if a "bigger" predecessor exists
    if (currNode->left)
    {
        // In the left subtree...
        finder = currNode->left;
        //...move to extreme right
        while (finder->right)
            finder = finder->right;
        // there, you'll find the perfect predecessor
        predecessor = finder->data;
    }

    // check if a "smaller" successor exists
    if (currNode->right)
    {
        // In the right subtree...
        finder = currNode->right;
        //...move to the extreme left
        while (finder->left)
            finder = finder->left;
        // There, you'll find the prefect successor
        successor = finder->data;
    }

    // return the answer as a pair
    return {predecessor, successor};
}