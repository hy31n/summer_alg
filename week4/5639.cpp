#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        node = new Node();

        node->data = data;
        node->left = node->right = NULL;

        return node;
    }

    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else
    {
        node->right = insertNode(node->right, data);
    }
    return node;
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << "\n";
}

int main()
{
    Node *root = NULL;
    int input;
    while (true)
    {
        cin >> input;
        if (cin.eof() == true)
            break;

        root = insertNode(root, input);
    }
    postorder(root);
    return 0;
}