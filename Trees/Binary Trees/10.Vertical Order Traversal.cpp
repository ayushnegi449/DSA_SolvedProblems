class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        if(!root) return ans;
        
        map<int,map<int,vector<int>>> nodes;
        queue<pair<TreeNode* , pair<int,int>>> q;
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            
            TreeNode *n  = it.first;
            int idx = it.second.first, val = it.second.second;
            
            nodes[idx][val].push_back(n->val);
            
            if(n->left) q.push({n->left,{idx-1,val+1}});
            if(n->right) q.push({n->right,{idx+1,val+1}});
        }
        
        for(auto idx : nodes)
        {
            vector<int> vs;
            
            for(auto lvl:idx.second)
            {
               sort(lvl.second.begin(),lvl.second.end());
                
                for(int it : lvl.second)
                {
                    vs.push_back(it);
 
                }
            }
            ans.push_back(vs);
        }
        
        return ans;
    }
};