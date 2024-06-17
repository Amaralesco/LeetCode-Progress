/*   
    Neetcode: Solved 28/150
    Leetcode: Solved 21 Easy 19 Medium
Challenge: #572. Subtree of Another Tree
 
Looked complicated at first, had a good preview of how i intended to solve it but it would not work.
Once i realized i could use the function dfsSameTree() from problem #100 it became easier.
By hearing the video explanation i was able to translate it to code without looking at the coding solution

Cleaner code solution at EoF

*/

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL ){
            return false;
        }
        bool result = true;
        dfsSameTree(root,subRoot, result);
        
        printf("Result: %d\n", result);
        if (result){
            return true;
        }
        else {
            if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)){
                return true;
            }
        }
        return false;
    }
private:
    void dfsSameTree (TreeNode* p, TreeNode* q, bool& result){
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
            dfsSameTree(p->left,q->left, result);
            dfsSameTree(p->right,q->right, result);
        }
        else{
            result = false;
        }      
        return;
    }
};

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL) {
            return false;
        }
        if (isSame(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (root == NULL && subRoot == NULL) {
            return true;
        }
        if (root == NULL || subRoot == NULL) {
            return false;
        }
        if (root->val != subRoot->val) {
            return false;
        }
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
};