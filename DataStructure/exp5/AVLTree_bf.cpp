#include <iostream>
#include <stack>

#define LENGTH 200

using namespace std;

typedef struct AVL_NODE_bf
{
    int bf; // balance factor
    int data;
    struct AVL_NODE_bf *left, *right;
} avln; // avl tree node, bf


void displayNode(avln *node, int height)
{
    cout << '(';
    if (node == nullptr)
    {
        cout << "NULL";
    }
    else
    {
        if (node->left == nullptr)
        {
            cout << "NULL";
        }
        else
        {
            cout << node->left->data;
        }
        cout << '<';
        cout << node->data;
        cout << '>';
        if (node->right == nullptr)
        {
            cout << "NULL";
        }
        else
        {
            cout << node->right->data;
        }
        cout << ", " << height << ", " << node->bf;
    }
    cout << ')';
}

void displayTree(avln *root, int indent)
{
    if (root != nullptr)
    {
        for (int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
        displayNode(root, indent / 2);
        cout << endl;
        indent += 2;
        displayTree(root->left, indent);
        displayTree(root->right, indent);
    }
}

int getArray(int a[])
{
    char comma;
    int i;
    for(i = 0; cin.peek() != '\n'; i++)
    {
        cin >> a[i] >> comma;
    }
    return i;
}

avln setAVLNode(int data, int bf, avln* left, avln* right)
{
    avln temp;
    temp.data = data;
    temp.bf = bf;
    temp.left = left;
    temp.right = right;
    return temp;
}

/* usage:
 * rotate(p, p->l, p->l->r);
 * rotate(p, p->r, p->r->l);
 */
void rotate(avln *&root, avln *&l_r, avln *&lr_rl) // it's a cycle(root->l->r => root->l => root =>) vise versa.
{
    avln *temp = l_r;
    l_r = lr_rl;
    lr_rl = root;
    root = temp;
}

void R_rotate(avln *&p)
{
    rotate(p, p->left, p->left->right);
}

void L_rotate(avln *&p)
{
    rotate(p, p->right, p->right->left);
}

void balance()
{
}

avln *insert(avln *newNode, avln *root)
{
    if(root == nullptr)
    {
        root = newNode;
    }
    else
    {
        if()
    }
    
}


int main()
{
    stack<avln> avltree;
    avln *root = nullptr;
    int a[LENGTH];
    int n = getArray(a);
    avln temp;
    for(int i = 0; i < n; i++)
    {
        avltree.push(setAVLNode(a[i], 0, nullptr, nullptr))
    }
    return 0;
}