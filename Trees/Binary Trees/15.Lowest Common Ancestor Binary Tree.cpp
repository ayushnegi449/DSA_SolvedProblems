class Solution
{
public:
    TreeNode *dfs(TreeNode *n, TreeNode *x, TreeNode *y)
    {
        if (n == NULL || x == n || y == n) //if the node is null or value of either of the nodes to find matches, return Node.
            return n; 

        TreeNode *l = dfs(n->left, x, y);
        TreeNode *r = dfs(n->right, x, y);

        if (l && r) //if both left and right returns a node , means current node is the lowest commom anscestor
            return n;//return current node.
        if (l)
            return l; //if l is not null , means return l 
        if (r)
            return r; //if r is not null return r.

        return NULL; //if both l and r are null return NULL.

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        TreeNode *res = dfs(root, p, q);
        return res;
    }
};