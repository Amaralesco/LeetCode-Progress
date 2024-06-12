/*   
    Neetcode: Solved 26/150
    Leetcode: Solved 21 Easy 17 Medium
Challenge: #100  Same Tree. Find if 2 trees are identical 

Pretty easy while looking at the previous exercises. The only new thing was that i could access tree->val instead of just tree->left and tree->right.
*/


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
       bool result = true;
       dfs(p,q,result);
       return result;
    }
private:
    void dfs (TreeNode* p, TreeNode* q, bool& result){
        if (p == NULL && q == NULL) {
            //result = true;
            return;
        }
        else {
            if (p == NULL || q == NULL){
                result = false;
                return;
            }
        }
        if (q->val == p->val){
            printf("Comparing q->val:%d p->val:%d\n",q->val, p->val);
            dfs(p->left,q->left, result);
            dfs(p->right,q->right, result);
        }
        else{
            result = false;
        }
        
        return;
    }
};