class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string serializedstr = "";
        if (!root)
            return serializedstr;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();

            if (n == NULL)
            {
                serializedstr.append("#,");
            }
            else
            {
                serializedstr.append(to_string(n->val) + ',');
            }

            if (n != NULL)
            {
                q.push(n->left);
                q.push(n->right);
            }
        }

        return serializedstr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream nodestr(data);
        string str = "";

        getline(nodestr, str, ',');

        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();

            getline(nodestr, str, ',');

            if (str == "#")
            {
                n->left = NULL;
            }
            else
            {
                TreeNode *l = new TreeNode(stoi(str));
                n->left = l;
                q.push(l);
            }

            getline(nodestr, str, ',');

            if (str == "#")
            {
                n->right = NULL;
            }
            else
            {
                TreeNode *r = new TreeNode(stoi(str));
                n->right = r;
                q.push(r);
            }
        }

        return root;
    }
};