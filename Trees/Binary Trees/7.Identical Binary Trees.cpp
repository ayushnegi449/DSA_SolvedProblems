//* TC - O(n) SC - O(n) (both)

//? Iterative :
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> Q;
        if (!p or !q)
            return p == q; // If both roots are null
        Q.push(p);
        Q.push(q); // Push both the roots in the queue
        while (!Q.empty())
        {
            TreeNode *left = Q.front();
            Q.pop(); // Store one node in left and pop
            TreeNode *right = Q.front();
            Q.pop(); // Store other in right and pop
            if (!left and !right)
                continue; // If both nodes are null -> continue
            if (!left or !right)
                return false; // If one of them is null, simply return false
            if (left->val != right->val)
                return false; // If they are not equal, return false

            // Push left childs of both nodes
            Q.push(left->left);
            Q.push(right->left);

            // Push right child of both nodes
            Q.push(left->right);
            Q.push(right->right);
        }
        return true;
    }
};

//? Recursive , similar to preorder
class Solution
{
public:
    bool fun(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!q || !p || q->val != p->val)
            return false;

        bool l = fun(p->left, q->left);
        // if(!l) return false;

        bool r = fun(p->right, q->right);
        // if(!r) return false;

        // return true;
        return r * l;
    }

    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!q && !p)
            return true;
        if (!q && p || !p && q || q->val != p->val)
            return false;

        return fun(p, q);
    }
};