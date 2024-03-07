#include <iostream>
#include<climits>
#include<algorithm>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->right = NULL;
        this->left = NULL;
    }
};


void display(Node *root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    display(root->left);
    display(root->right);
}

int minimumVal(Node*root)
{
    if(root==NULL)return INT_MAX;
    else
    return min(root->val,min(minimumVal(root->left),minimumVal(root->right)));
}

int main()
{
    Node *a = new Node(6);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(5);
    Node *e = new Node(1);
    Node *f = new Node(7);
    Node *g = new Node(8);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

     //display(a);
    cout<<minimumVal(a);

    return 0;
}