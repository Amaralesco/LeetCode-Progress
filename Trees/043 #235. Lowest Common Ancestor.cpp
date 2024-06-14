/*   
    Neetcode: Solved 27/150
    Leetcode: Solved 21 Easy 18 Medium
Challenge: #235. Lowest Common Ancestor of a Binary Search Tree
 

Didnt really grasped the problem initially, since it is ordered already by being a BST, which i did not conclude.~After understanding that and seeing the explanation i managed
this solution which worked. More compact NeetCode solution at the EoF. It also makes more sense for the C++ language to make it as is showned by neetcode.

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (cur){
            if(p->val > cur->val && q->val > cur->val ){
                cur = cur->right;
            } 
            else if(p->val < cur->val && q->val < cur->val ){
                cur = cur->left;
            }
            else {
                return cur;
            }
        }
        return cur; //never reaches here
    }
};

/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};
*/