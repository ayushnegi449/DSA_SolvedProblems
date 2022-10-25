// Recursive :
class Solution
{
public:
    // int num = 0;
    int kthLargest(TreeNode *root, int &k)
    {

        if (!root)
        {
            return 0;
        }

        int r = kthLargest(root->right, k);
        if (r != 0)
        {
            return r;
        }

        // num++;
        // if(num==k)
        k--;
        if (k == 0)
        {
            return root->val;
        }

        int l = kthLargest(root->left, k);
        if (l != 0)
        {
            return l;
        }

        return 0;
    }
};