// Can solve by iterating preorder vector , every node is inserted using bst insert function.
// BST inorder vector is sorted , so sort preorder then create a BST using inorder + preorder vector.

// Recursive
class Solution
{
public:
    TreeNode *bstpreorder(vector<int> &preorder, int &idx, int uplimit)
    {
        if (idx == preorder.size())
            return NULL;

        if (preorder[idx] > uplimit)
            return NULL;

        TreeNode *root = new TreeNode(preorder[idx]);
        idx++;

        root->left = bstpreorder(preorder, idx, root->val);
        root->right = bstpreorder(preorder, idx, uplimit);

        return root;
    }

    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int idx = 0;
        return bstpreorder(preorder, idx, INT_MAX);
    }
};

// Using stack
class Solution
{
public:
    TreeNode *create(vector<int> &preorder, vector<int> &nge, int i, int j)
    {
        if (i > j)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i]);
        int rs = nge[i];
        root->left = create(preorder, nge, i + 1, rs - 1);
        root->right = create(preorder, nge, rs, j);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        int n = preorder.size();
        stack<int> st;
        vector<int> nge(n);
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and preorder[st.top()] < preorder[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                nge[i] = n;
            }
            else
                nge[i] = st.top();
            st.push(i);
        }
        return create(preorder, nge, 0, n - 1);
    }
};