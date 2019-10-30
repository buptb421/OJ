#include <iostream>
#include <stack>
#include <new>

#define LENGTH 100
using namespace std;

int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int getArray(int a[])
{
    char comma;
    int i;
    for (i = 0; cin.peek() != '\n'; i++)
    {
        cin >> a[i] >> comma;
    }
    return i;
}

typedef struct AVL_NODE_height
{
    int height; // height
    int data;
    struct AVL_NODE_height *left, *right;
} avlh; // avl tree node, height

avlh *creatAVLNode(int x, int height)
{
    avlh *temp = new avlh;
    if (temp == nullptr)
    {
        cout << "Out of space!!!";
    }
    else
    {
        temp->data = x;
        temp->height = height;
        temp->left = nullptr;
        temp->right = nullptr;
    }
    return temp;
}

int getHeight(avlh *pnode) // Alert: with each rotation, the height should be maintained manully.
{
    if (pnode == nullptr)
    {
        return 0;
    }
    else
    {
        return pnode->height;
    }
}

void preorder(avlh *p)
{
    if (p != nullptr)
    {
        cout << p->data << ',';
        preorder(p->left);
        preorder(p->right);
    }
}

avlh *rotate_LL(avlh *p)
{
    avlh *temp = p->left;
    p->left =                                                                                                                                                                                                                                                                                                                                  
}

avlh *rotate_RR(avlh *p)
{
    
}

avlh *rotate_LR(avlh *p)
{
    
}

avlh *rotate_RL(avlh *p)
{
    
}

avlh *insert(int X, avlh *T)
{
    if (T == nullptr)
    { /* Create and return a one-node tree */
        T = creatAVLNode(X, 0);
    } /* End creating a one-node tree */
    else if (X < T->data)
    { /* handle left insertion */
        T->left = insert(X, T->left);
        if (getHeight(T->left) - getHeight(T->right) == 2) /* not balanced */
        {
            if (X < T->left->data) /* LL Rotation */
            {
                T = rotate_LL(T);
            }
            else /* LR Rotation */
            {
                T = rotate_LR(T);
            }
        }
    } /* End left */
    else if (X > T->data)
    { /* handle right insertion */
        T->right = insert(X, T->right);
        {
            if (getHeight(T->right) - getHeight(T->left) == 2) /* not balanced */
            {
                if (X > T->right->data) /* RR Rotation */
                {
                    T = rotate_RR(T);
                }
                else /* RL Rotation */
                {
                    T = rotate_RL(T);
                }
            }
        }
    } /* End right */
    /* Else X is in the tree already; we'll do nothing */
    T->height = Max(getHeight(T->left), getHeight(T->right)) + 1;
    return T;
}

int main()
{
    int a[LENGTH];
    int n = getArray(a);
    avlh *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(a[i], root);
    }
    preorder(root);
    return 0;
}
