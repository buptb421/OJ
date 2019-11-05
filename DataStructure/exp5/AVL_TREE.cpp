#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef struct tree
{
	int data, height;
	struct tree *left;
	struct tree *right;
}node, *avl;

node* create(int data, node *left, node *right)
{
	node* p;
	p = (node *)malloc(sizeof(node));
	if(p == NULL)
		return NULL;
	p->data = data;
	p->height = 0;
	p->left = left;
	p->right = right;
	return p;
}

int Height(node *p)
{
	if(p == NULL)
		return 0;
	else 
		return p->height;
}

int max(int a, int b)
{
	if(a >= b)
		return a;
	else 
		return b;
}

node* llrotate(avl k2)
{
	avl k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max( Height(k2->left), Height(k2->right)) + 1;
    k1->height = max( Height(k1->left), k2->height) + 1;
    return k1;
 }
 
node* rrrotate(avl k1)
{
	avl k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	k1->height = max(Height(k1->left), Height(k1->right)) + 1;
	k2->height = max(Height(k2->right), k1->height) + 1;
	return k2;
 } 
 
 node* lrrotate(avl k3)
 {
 	k3->left = rrrotate(k3->left);
 	return llrotate(k3);
 }
 
 node* rlrotate(avl k1)
 {
 	k1->right = llrotate(k1->right);
 	return rrrotate(k1);
 }
 
 node* insert(avl tree, int data)
 {
 	if(tree == NULL)
 		tree = create(data, NULL, NULL);
 	else if(data < tree->data)
 	{
 		tree->left = insert(tree->left, data);
 		if(Height(tree->left) - Height(tree->right) == 2)
 		{
 			if(data < tree->left->data)
 				tree = llrotate(tree);
 			else
 				tree = lrrotate(tree);
		 }
	 }
	 else if(data > tree->data)
	 {
	 	tree->right = insert(tree->right, data);
	 	if(Height(tree->right) - Height(tree->left) == 2)
	 	{
	 		if(data > tree->right->data)
	 			tree = rrrotate(tree);
	 		else
	 			tree = rlrotate(tree);
		 }
	 }
	 tree->height = max(Height(tree->left), Height(tree->right)+1);
	 return tree;
 }
 
 void displayNode(node *pnode)
{
    cout << '(';
    if (pnode == NULL)
    {
        cout << "NULL";
    }
    else
    {
        if (pnode->left == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << pnode->left->data;
        }
        cout << '<';
        cout << pnode->data;
        cout << '<';
        if (pnode->right == NULL)
        {
            cout << "NULL";
        }
        else
        {
            cout << pnode->right->data;
        }
        cout << ", " << pnode->height;
    }
    cout << ')';
}

void displayTree(node *root, int indent)
{
    if (root != NULL)
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
 
 void print(avl tree)
 {
 	if(tree != NULL)
 	{
 		printf("%d,", tree->data);
 		print(tree->left);
 		print(tree->right);
	 }
 }

int main()
{
	int i, j, temp;
	int arr[100];
	char s[200];
	temp = 0;
	j = 0;
	avl root = NULL;
	gets(s);
	for(i = 0; i<200; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			temp = temp*10 + s[i] - '0';
		else
		{
			if(s[i]!=',')
				break;
			arr[j] = temp;
			j++;
			temp = 0;
		}
	 }
    for(i = 0; i<j; i++)
    {
        root = insert(root, arr[i]);
    }
    displayTree(root, 0);
    //print(root);
    return 0;
}


























