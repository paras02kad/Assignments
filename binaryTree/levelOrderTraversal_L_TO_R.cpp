
#include <iostream>
#include <queue>
#include <climits>

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

void levelOrderQueue_L_TO_R(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";
        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return;
}

void levelOrderQueue_R_TO_L(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (q.size() > 0)
    {
        Node *temp = q.front();
        q.pop();
        cout << temp->val << " ";

        if (temp->right != NULL)
            q.push(temp->right);

        if (temp->left != NULL)
            q.push(temp->left);
    }
    return;
}

int level(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(level(root->left), level(root->right)));
}


void levelOrder_left_to_right(Node *root, int curr, int target)
{
    if (root == NULL)
        return;
    if (curr == target)
    {
        cout << root->val << " ";
        return;
    }
    
    levelOrder_left_to_right(root->left,curr,target);
    levelOrder_left_to_right(root->right,curr,target);
}

void levelOrder_right_to_left(Node *root, int curr, int target)
{
    if (root == NULL)
        return;
    if (curr == target)
    {
        cout << root->val << " ";
        return;
    }
    levelOrder_right_to_left(root->right,curr+1,target);
    levelOrder_right_to_left(root->left,curr+1,target);
}

int main()
{

    Node *a = new Node(1);
    Node *b = new Node(2);
    Node *c = new Node(3);
    Node *d = new Node(4);
    Node *e = new Node(5);
    Node *f = new Node(6);
    Node *g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    // levelOrderQueue_L_TO_R(a);
    // cout<<endl;
    // levelOrderQueue_R_TO_L(a);


for (int i = 1; i <= level(a); i++)
{
   levelOrder_right_to_left(a,1,i);
}





    return 0;
}
