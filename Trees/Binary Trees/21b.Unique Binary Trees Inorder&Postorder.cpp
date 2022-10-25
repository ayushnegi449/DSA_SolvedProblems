class Solution
{
public:
    TreeNode *bt(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &mp, int is, int ie, int ps, int pe)
    {
        if (is > ie || ps > pe)
            return NULL;

        TreeNode *root = new TreeNode(postorder[pe]);

        int idx = mp[root->val];

        int nodes = idx - is;

        root->left = bt(inorder, postorder, mp, is, idx - 1, ps, pe - nodes - 1);
        root->right = bt(inorder, postorder, mp, idx + 1, ie, pe - nodes, pe - 1);

        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int insize = inorder.size() - 1, postsize = postorder.size() - 1;
        if (inorder.size() == 0)
            return NULL;

        unordered_map<int, int> mp;

        for (int i = 0; i <= insize; i++)
        {
            mp[inorder[i]] = i;
        }

        return bt(inorder, postorder, mp, 0, insize, 0, postsize);
    }
};