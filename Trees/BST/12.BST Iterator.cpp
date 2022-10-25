// TC O(1) Amortized analysis
// SC O(H) at max the stack have max nodes TILL max height.
class BSTIterator
{
private:
    stack<TreeNode *> s;
    void nodepush(TreeNode *root)
    {

        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        nodepush(root);
    }

    int next()
    {

        TreeNode *n = s.top();
        s.pop();

        if (n->right)
        {
            nodepush(n->right);
        }

        return n->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

// Naive approach
// TC O(1) to access values 
// SC O(n) for inorder vector.
class BSTIterator {
public:
    void initialize(TreeNode* root) {
        if (root == NULL) return;
        initialize(root->left);
        tree.push_back(root->val);
        initialize(root->right);
    }
    BSTIterator(TreeNode* root) {
        initialize(root);
        index = 0;
        size = tree.size();
    }
    
    int next() {
        index++;
        return tree[index - 1];
    }
    
    bool hasNext() {
        if (index == size) return false;
        return true;
    }
    vector<int> tree;
    int index;
    int size;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */