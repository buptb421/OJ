#include <stdio.h>
#include <stdlib.h>

#define LENGTH 200
#define nullptr NULL

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
    int i;
    char s[LENGTH];
    gets(s);
    int count = 0, num = 0;
    int exit_read = 0;
    while(exit_read == 0)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            num = num * 10 + s[i] - '0';
        }
        else if(s[i] == ',')
        {
            a[count] = num;
            num = 0;
            count++;
        }
        else
        {
        	exit_read = 1;
		}
        i++;
    }
    /*
    for(i = 0; i < count; i++)
    {
    	printf("%d ", a[i]);
    	
	}
	printf("\n");
	*/
    return count;
}
/*
int getRand(int a[], int n)
{
	default_random_engine e(10);
	for(int i = 0; i < n; i++)
	{
		a[i] = e() / ;
	}
	return n;
}
*/
typedef struct AVL_NODE_height
{
    int height;
    int data;
    struct AVL_NODE_height *left, *right;
} avlh; // avl tree node, height
/*
void displayNode(avlh *node)
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
        cout << '<';
        if (node->right == nullptr)
        {
            cout << "NULL";
        }
        else
        {
            cout << node->right->data;
        }
        cout << ", " << node->height;
    }
    cout << ')';
}

void displayTree(avlh *root, int indent)
{
    if (root != nullptr)
    {
        for (int i = 0; i < indent; i++)
        {
            cout << ' ';
        }
        displayNode(root);
        cout << endl;
        indent += 2;
        displayTree(root->left, indent);
        displayTree(root->right, indent);
    }
}
*/
avlh *creatAVLNode(int x)
{
    avlh *temp = (avlh*)malloc(sizeof(avlh));
    if (temp == nullptr)
    {
        //cout << "Out of space!!!";
    }
    else
    {
        temp->data = x;
        temp->height = 0;
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

void deductHeight(avlh *p)
{
	if(p != nullptr)
	{
		p->height = Max(getHeight(p->left), getHeight(p->right)) + 1;
	}
}

void preorder(avlh *p)
{
    if (p != nullptr)
    {
        printf("%d,", p->data);
        preorder(p->left);
        preorder(p->right);
    }
}

avlh *rotate_LL(avlh *p)
{
    avlh *temp = p->left;
    p->left = temp->right;
    temp->right = p;
    deductHeight(p);
    deductHeight(temp);
    return temp;                                                                                                                                                                                                                                                                                                                           
}

avlh *rotate_RR(avlh *p)
{
    avlh *temp = p->right;
    p->right = temp->left;
    temp->left = p;
    deductHeight(p);
    deductHeight(temp);
    return temp;
}

avlh *rotate_LR(avlh *p)
{
    p->left = rotate_RR(p->left);
    p = rotate_LL(p);
    return p;
}

avlh *rotate_RL(avlh *p)
{
    p->right = rotate_LL(p->right);
    p = rotate_RR(p);
    return p;
}

avlh *insert(int X, avlh *T)
{
    if (T == nullptr)
    { 
        T = creatAVLNode(X);
    } 
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
    } /* End right */
    /* Else X is in the tree already; we'll do nothing */
    deductHeight(T);
    return T;
}

int main()
{
	
    int a[LENGTH];
    int n = getArray(a);
    //int n = getRand(a, 20);
    
    
    avlh *root = nullptr;
    for (int i = 0; i < n; i++)
    {
        root = insert(a[i], root);
    }
    
    /*
    avlh *root = nullptr;
    char c;
    int num = 0;
    scanf("%c", &c);
    while((c >= '0' && c <= '9') || c == ',')
    {
    	
    	if(c >= '0' && c <= '9')
    	{
    		num = num * 10 - '0' + c;
		}
		else
		{
			root = insert(num, root);
			num = 0;
		}
		scanf("%c", &c);
	}
    */
    //displayTree(root, 0);
    preorder(root);
    
    return 0;
}
