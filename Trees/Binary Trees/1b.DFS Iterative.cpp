//* Iterative :

// ? Preorder
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *n = s.top();
            s.pop();
            ans.push_back(n->val);

            if (n->right)
                s.push(n->right);
            if (n->left)
                s.push(n->left);
        }

        return ans;
    }
};

// ? Inorder
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        TreeNode *node = root;
        stack<TreeNode *> s;

        while (true)
        {
            if (node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    return ans;

                node = s.top();
                s.pop();
                ans.push_back(node->val);
                node = node->right;
            }
        }
    }
};

// ? Postorder Using 2 Stacks.
// ? PostOrder is just opposite of preorder.

class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s1; // stack 1 to store the nodes.
        stack<TreeNode *> s2; // stack 2 to store the nodes popped (reverse manner)
        s1.push(root);        // intially stack1 has root value.

        while (!s1.empty())
        {
            TreeNode *n = s1.top(); // storing & removing stack1's top element.
            s1.pop();
            s2.push(n); // push the node to the stack2.
            if (n->left)
                s1.push(n->left); // traverse in left-right manner.
            if (n->right)
                s1.push(n->right);
        }

        while (!s2.empty())
        {
            TreeNode *n = s2.top();
            // since the stack2 has values in the reverse order
            //  i.e. topmost elem is the first element of postorder traversal
            s2.pop();
            ans.push_back(n->val);
        }

        return ans;
    }
};

// ? PostOrder Using 1 stack
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> s;
        TreeNode *curr = root;

        while (curr != NULL || !s.empty()) // checking for curr because initally stack is empty() //do-while will work as well.
        {
            if (curr != NULL)
            {
                s.push(curr);      // pushing root initially
                curr = curr->left; // traverse to the left
            }
            else
            {
                TreeNode *temp = s.top()->right; // if left node is null traverse to the right
                if (temp == NULL)                // if right node is also null
                {
                    temp = s.top(); // take the top element and pop -> push into vector.
                    s.pop();
                    ans.push_back(temp->val);
                    while (!s.empty() && s.top()->right == temp) // since left subtree is checked already and right was null as well, backtracking.
                    {
                        temp = s.top();      
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                    curr = temp; // else curr becomes the right node. (eventually again traversing left side)
            }
        }
        return ans;
    }
};

// my method (previous node pointer)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> s;
        TreeNode *curr = root;
        TreeNode *prev;

        while (curr != NULL || !s.empty())
        {
            if (curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                // if(s.empty()) break;

                curr = s.top();

                if (curr->right != NULL && curr->right != prev)
                {
                    curr = curr->right;
                }
                else
                {
                    ans.push_back(curr->val);
                    s.pop();
                    prev = curr;
                    curr = NULL;
                }
            }
        }

        return ans;
    }
};