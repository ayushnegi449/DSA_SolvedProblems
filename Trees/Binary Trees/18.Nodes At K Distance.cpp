// 863. All Nodes Distance K in Binary Tree
// Given the root of a binary tree, the value of a target node target, and an integer k,
// return an array of the values of all nodes that have a distance k from the target node.

// You can return the answer in any order.

// METHOD 1
class Solution
{
public:
    void parent_node(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_n)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();

            if (n->left)
            {
                parent_n[n->left] = n;
                q.push(n->left);
            }
            if (n->right)
            {
                parent_n[n->right] = n;
                q.push(n->right);
            }
        }
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        if (!root)
            return ans;

        unordered_map<TreeNode *, TreeNode *> parent_n;
        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        parent_node(root, parent_n);

        q.push(target);
        visited[target] = true;

        int distance = 0;

        while (!q.empty())
        {
            if (distance++ == k)
                break;

            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *n = q.front();
                q.pop();

                if (n->left && visited[n->left] != true)
                {
                    visited[n->left] = true;
                    q.push(n->left);
                }
                if (n->right && visited[n->right] != true)
                {
                    visited[n->right] = true;
                    q.push(n->right);
                }
                if (parent_n[n] && visited[parent_n[n]] != true)
                {
                    visited[parent_n[n]] = true;
                    q.push(parent_n[n]);
                }
            }
        }

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();
            ans.push_back(n->val);
        }
        return ans;
    }
};

// METHOD 2:
class Solution
{
public:
    bool node_path(TreeNode *root, int x, vector<TreeNode *> &path)
    {
        if (root == NULL)
            return false;
        if (root->val == x)
        {
            path.push_back(root);
            return true;
        }
        if (node_path(root->left, x, path) || node_path(root->right, x, path))
        {
            path.push_back(root);
            return true;
        }
        return false;
    }
    void printkleveldown(TreeNode *root, int k, TreeNode *visited, vector<int> &ans)
    {
        if (root == NULL || root == visited)
            return;
        if (k == 0)
            ans.push_back(root->val);
        if (k > 0)
        {
            printkleveldown(root->left, k - 1, visited, ans);
            printkleveldown(root->right, k - 1, visited, ans);
        }
    }
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<TreeNode *> path;
        vector<int> ans;

        bool x = node_path(root, target->val, path);
        
        for (int i = 0; i < path.size(); i++)
        {
            if (i == 0)
                printkleveldown(path[i], k - i, NULL, ans);
            else
                printkleveldown(path[i], k - i, path[i - 1], ans);
        }
        return ans;
    }
};