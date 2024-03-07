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


// int level(Node *root)
// {
//     if (root == NULL)
//         return 0;
//     return (1 + max(level(root->left), level(root->right)));
// }

// int checker(Node*root,int maxDia)
// {
//     if(root==NULL)return 0;
//     int len = level(root->right)+level(root->left);
//     maxDia = max(len,maxDia);
//     checker(root->left,maxDia);
//     checker(root->right,maxDia);
//     return maxDia;
// }


// int diameter(Node*root)
// {
// int maxDia = 0;
//  return checker(root,maxDia);

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
//     e->right = f;
//     f->right = g;

// cout<<diameter(a)<<endl;


//     return 0;
// }


class Solution 
{
public:

int level(TreeNode*root)
{
    if(root==NULL)return 0;
    else
    return (1+ max(level(root->left),level(root->right)));
}

    int helper(TreeNode* root,int &maxDia)
    {
        if(root==NULL)return 0;
        int dia = level(root->left)+level(root->right);
         maxDia=max(dia,maxDia);
        helper( root->left, maxDia); 
        helper( root->right,maxDia);
        return maxDia;
    }

int diameterOfBinaryTree(TreeNode* root) 
{
    int maxDia = 0;
    helper(root,maxDia);
    return maxDia;
}

};