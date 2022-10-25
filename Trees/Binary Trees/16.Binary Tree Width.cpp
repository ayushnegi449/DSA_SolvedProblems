// 662. Maximum Width of Binary Tree

// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
// where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that 
// level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();

            int mini = q.front().second; //q.back().second will also work

            int first = 0, last = 0;

            for (int i = 0; i < size; i++)
            {
                auto it = q.front();
                q.pop();

                TreeNode *n = it.first;
                unsigned int idx = it.second - mini;

                if (i == 0)
                    first = idx;
                if (i == size - 1)
                    last = idx;

                if (n->left)
                    q.push({n->left, 2 * idx + 1});
                if (n->right)
                    q.push({n->right, 2 * idx + 2});
            }

            ans = max(ans, (last - first + 1));
        }
        return ans;
    }
};