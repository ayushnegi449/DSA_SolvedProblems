class Solution
{
public:
    TreeNode *treebuild(vector<int> &preorder, vector<int> &inorder, map<int, int> &indices, int prestart, int preend, int instart, int inend)
    {
        if (instart > inend || prestart > preend)
            return NULL;

        TreeNode *root = new TreeNode(preorder[prestart]);

        int idx = indices[root->val];
        int leftnodes = idx - instart;

        root->left = treebuild(preorder, inorder, indices, prestart + 1, prestart + leftnodes, instart, idx - 1);
        root->right = treebuild(preorder, inorder, indices, prestart + 1 + leftnodes, preend, idx + 1, inend);

        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {

        map<int, int> mp;

        int insize = inorder.size(), presize = preorder.size();

        for (int i = 0; i < insize; i++)
        {
            mp[inorder[i]] = i;
        }

        return treebuild(preorder, inorder, mp, 0, presize - 1, 0, insize - 1);
    }
};