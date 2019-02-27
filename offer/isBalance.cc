class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot) return true;
        int depth=0,max_dep=0,min_dep=0;
        dfs(pRoot, depth, max_dep, min_dep);
        return max_dep-min_dep<=1?true:false;
        
    }
private:
    void dfs(TreeNode* pRoot, int depth, int& max_dep, int& min_dep)
    {
        if(!pRoot) return;
        
        depth+=1;
      
        if(!pRoot->left&&!pRoot->right)
        {
            if(depth>max_dep){
                max_dep = depth;
            }
            if(depth<min_dep || min_dep==0)
            {
                min_dep = depth;
            }
            return;
        }
        
        if(pRoot->left)
            dfs(pRoot->left, depth, max_dep, min_dep);
        else
        {
            if(depth<min_dep || min_dep==0)
            {
                min_dep = depth;
            }
        }
        if(pRoot->right)
            dfs(pRoot->right, depth, max_dep, min_dep);
        else{
            if(depth<min_dep || min_dep==0)
            {
                min_dep = depth;
            }
        }
    }
};
