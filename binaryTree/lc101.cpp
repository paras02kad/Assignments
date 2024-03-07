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
!Dont know why is it wrong
// */
// class Solution
// {
// public:
//     void lster(TreeNode *root, vector<int> &lst)
//     {
//         if (root == NULL)
//             return;
//         else
//             lst.push_back(root->val);
//         lster(root->left, lst);
//         lster(root->right, lst);
//     }
//     void rster(TreeNode *root, vector<int> &rst)
//     {
//         if (root == NULL)
//             return;
//         else
//             rst.push_back(root->val);
//         rster(root->right, rst);
//         rster(root->left, rst);
//     }

//     bool isSymmetric(TreeNode *root)
//     {
//         if (root->left != root->right)
//             return false;

//         vector<int> lst;
//         vector<int> rst;

//         lster(root->left, lst);
//         rster(root->right, rst);

//         if (lst.size() != rst.size())
//             return false;

//         for (int i = 0; i < rst.size(); i++)
//         {
//             if (lst[i] == rst[i])
//                 continue;
//             else
//                 return false;
//         }
//         return true;
//     }
// };

//! correct approach
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
class Solution
{
public:
    bool check(TreeNode *l, TreeNode *r)
    {
        if (l == NULL && r == NULL)
            return true;
        else if (l == NULL || r == NULL)
            return false;

        if (l->val == r->val && check(l->left, r->right) && check(l->right, r->left))
            return true;

            return false;
    }

    bool isSymmetric(TreeNode *root)
    {

        return check(root->left, root->right);
    }
};