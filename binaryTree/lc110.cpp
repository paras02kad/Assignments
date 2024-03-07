/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
!my Solution
*/
class Solution 
{
public:

int level(TreeNode*root)
{
    if(root==NULL)return 0;
    else
    return (1 + max(level(root->right),level(root->left)));
}

    bool isBalanced(TreeNode* root)
    {
      if(root == NULL)return true;

        int left = level(root->left);
        int right = level(root->right);

        if(root->right == NULL && left>1)return false;
        else if(root->left == NULL && right>1)return false;

        if(abs(left - right)>1) return false;
        
        bool leftAns = isBalanced(root->left);
        if(!leftAns)return false;
        bool rightAns = isBalanced(root->right);
        if(!rightAns)return false;

        return true;

    }
};

/*
!best solution
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int operate(TreeNode *root, bool &check){
        // Base case
        if(root==nullptr) return -1;
        // Verifying the Balanced tendency
        int lefty = operate(root->left,check);
        int righty = operate(root->right,check);
        if(abs(lefty-righty)>1) check = false;
        // Recursive case
        return max(lefty,righty) + 1;
    }
    bool isBalanced(TreeNode* root) {
        bool check = true;
        operate(root,check);
        return check;
    }
};