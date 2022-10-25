// Problem Description
// Given a Binary Tree A containing N nodes.
// You need to find the path from Root to a given node B.

// NOTE:
// No two nodes in the tree have same data values.
// You can assume that B is present in the tree A and a path always exists.

// Example Input
// Input 1:

//  A =

//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7

// B = 5

// method 1
bool nodepath(TreeNode *n, int data, vector<int> &arr)
{
    if (!n)
        return false;

    arr.push_back(n->val);

    if (n->val == data)
        return true;

    if (nodepath(n->left, data, arr) || nodepath(n->right, data, arr))
        return true;

    arr.pop_back();

    return false;
}

vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> arr;
    if (!A)
        return arr;

    nodepath(A, B, arr);

    return arr;
}

// method 2
bool path(TreeNode *root, int B, vector<int> &ans)
{
    if (!root)
        return false;

    if (root->val == B)
    {
        ans.push_back(root->val);
        return true;
    }

    if (path(root->left, B, ans) || path(root->right, B, ans))
    {
        ans.insert(ans.begin(), root->val);
        return true;
    }

    return false;
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    vector<int> ans;
    path(A, B, ans);
    return ans;
}