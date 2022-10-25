class Solution {
public:
    int height(TreeNode *n)
    {
        if(!n) return 0;
        
        int l = height(n->left);
        int r = height(n->right);
        
        return 1+max(l,r);
    }
    
    
    bool isBalanced(TreeNode* root) {
        
        if(!root) return true;
        
        int l = height(root->left);
        int r = height(root->right);
        
        if(abs(l-r)>1) return false;
        
        bool lsubtree = isBalanced(root->left);
        bool rsubtree = isBalanced(root->right);
        
        if(lsubtree==false || rsubtree==false) return false;
        
        return true;
   
    }
};