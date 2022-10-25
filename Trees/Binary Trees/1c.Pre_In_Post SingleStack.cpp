class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> pre, in, post; // create 3 vectors
        if (!root)
            return pre;
        stack<pair<TreeNode *, int>> s; // create a pair with first value as the node ,
                                        //  second for the determination of pre/in/post order. (1-pre 2-in 3-post)
        s.push({root, 1}); // initally push root and 1 in the stack

        while (!s.empty())
        {
            auto it = s.top(); // iterator to point at the top pair in the stack.
            s.pop();

            if (it.second == 1) // if second val is 1 that means it's preorder
            {
                pre.push_back(it.first->val); // push value in preorder vector
                it.second++;                  // iterator increases the second value to 2 , means Inorder
                s.push(it);                   // push it back
                if (it.first->left)
                    s.push({it.first->left, 1}); // traversing to left value ans preorder is root->left->right.
            }
            else if (it.second == 2) // if second val is 1 that means it's Inorder
            {
                in.push_back(it.first->val); // push value in Inorder vector
                it.second++;                 // iterator increases the second value to 3 , means Postorder
                s.push(it);                  // push it back
                if (it.first->right)
                    s.push({it.first->right, 1}); // traversing to right value ans Inorder is left->root->right.
            }
            else
            {
                post.push_back(it.first->val); // just push the element in the Postorder vector and dont push it back.
            }
        }

        return pre / post / in; // depends on the ques
    }
};