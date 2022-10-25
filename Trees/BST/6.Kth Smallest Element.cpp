// Recursive :
class Solution
{
public:
    // int num = 0;
    int kthSmallest(TreeNode *root, int &k)
    {

        if (!root)
        {
            return 0;
        }

        int l = kthSmallest(root->left, k);
        if (l != 0)
        {
            return l;
        }

        // num++;
        // if(num==k)
        k--;
        if (k == 0)
        {
            return root->val;
        }

        int r = kthSmallest(root->right, k);
        if (r != 0)
        {
            return r;
        }

        return 0;
    }
};