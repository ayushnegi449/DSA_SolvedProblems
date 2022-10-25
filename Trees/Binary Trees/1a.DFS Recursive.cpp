//* Recursive:

//? Preorder
class Solution
{
public:
    void preorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> v;
        preorder(root, v);
        return v;
    }
};

//? PostOrder
class Solution
{
public:
    void postorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        postorder(root->left, v);
        postorder(root->right, v);
        v.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> v;
        postorder(root, v);
        return v;
    }
};

//? Inorder
class Solution
{
public:
    void Inorder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        Inorder(root->left, v);
        v.push_back(root->val);
        Inorder(root->right, v);
    }

    vector<int> InorderTraversal(TreeNode *root)
    {
        vector<int> v;
        Inorder(root, v);
        return v;
    }
};
