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
!without the use of queue*/
// class Solution
// {
// public:
//     int size(TreeNode *root)
//     {
//         if (root == NULL)
//             return 0;
//         else
//             return (1 + max(size(root->left), size(root->right)));
//     }
//     void levelPrinter(TreeNode *root, int basic, int value, vector<int> &v)
//     {
//         if (root == NULL)
//             return;
//         else if (basic == value)
//         {
//             v.push_back(root->val);
//             return;
//         }
//         levelPrinter(root->left, basic + 1, value, v);
//         levelPrinter(root->right, basic + 1, value, v);
//     }
//     void printer(TreeNode *root, vector<vector<int>> &ans)
//     {
//         int data = size(root);
//         for (int i = 1; i <= data; i++)
//         {
//             vector<int> v;
//             levelPrinter(root, 1, i, v);
//             ans.push_back(v);
//             cout << endl;
//         }
//     }

//     vector<vector<int>> levelOrder(TreeNode *root)
//     {
//         vector<vector<int>> ans;
//         printer(root, ans);
//         return ans;
//     }
// };

/*
!level order Traversal Using queue
*/

// #include <iostream>
// #include <queue>
// #include <climits>

// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *left;
//     Node *right;

//     Node(int val)
//     {
//         this->val = val;
//         this->right = NULL;
//         this->left = NULL;
//     }
// };

// void levelOrderQueue(Node*root)
// {
//     queue<Node*>q;
//     q.push(root);
//     while(q.size()>0)
//     {
//         Node *temp = q.front();
//         q.pop();
//         cout<<temp->val<<" ";
//         if(temp->left!=NULL)q.push(temp->left);
//         if(temp->right!=NULL)q.push(temp->right);
//     }
//     return;
// }


// int main()
// {

//     Node *a = new Node(1);
//     Node *b = new Node(2);
//     Node *c = new Node(3);
//     Node *d = new Node(4);
//     Node *e = new Node(5);
//     Node *f = new Node(6);
//     Node *g = new Node(7);

//     a->left = b;
//     a->right = c;
//     b->left = d;
//     b->right = e;
//     c->left = f;
//     c->right = g;

//         levelOrderQueue(a);

//     return 0;
// }


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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        while(q.size()>0)
        {
            
            TreeNode*temp = q.front();
            q.pop();

        }

    }
};