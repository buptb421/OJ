#include<iostream>
#include<new>
#include<stack>

#define nullptr NULL

using namespace std;

typedef struct BinarySearchTree{
    int data;
    struct BinarySearchTree *lc, *rc;
} BTnode;
/*
void displayNode(BTnode *node)
{  
	if(node == nullptr)
	{
		cout << "(NULL)";
	}
	else
	{
		if(node->lc == nullptr)
		{
			cout << "NULL";
		}
		else
		{
			cout << node->lc->data;
		}
		cout << " <- ";
		cout << node->data;
		cout << " -> ";
		if(node->rc == nullptr)
		{
			cout << "NULL";
		}
		else
		{
			cout << node->rc->data;
		}
	}
	cout << endl;
}
*/
void traverseTree(BTnode *proot, void preorder(BTnode *&pnode), void inorder(BTnode *&pnode), void postorder(BTnode *&pnode))
{
    stack<BTnode*> s;
    stack<int> t;
    BTnode *pnode = proot;
    while(pnode != nullptr || !s.empty())
    {
        if(pnode != nullptr)
        {
            preorder(pnode);
            s.push(pnode);
            t.push(0);
            pnode = pnode->lc;
        }
        else
        {
        	if(t.top() == 0)
            {
                inorder(s.top());
                t.top() = 1;
                pnode = s.top()->rc;
            }
            else if(t.top() == 1)
            {
                postorder(s.top());
                s.pop();
                t.pop();
            }
            else
            {
                cout << "Error" << endl;
            }
        }     
    }
}
void donothing(BTnode *&pnode)
{

}
/*
void displayTree_iter(BTnode *proot) // preOrder
{
    cout << "  ";
	displayNode(proot);

}

void displayTree(BTnode *proot) 
{
    cout << '{' << endl;
	traverseTree(proot, displayTree_iter, donothing, donothing);
    cout << '}' << endl;
}
*/
BTnode *creatNode(int data)
{
    BTnode *pnode = new BTnode;
    if(pnode != nullptr)
    {
        pnode->data = data;
        pnode->lc = nullptr;
        pnode->rc = nullptr;
    }
    return pnode;
}


void destroyBinaryNode(BTnode *&pnode)
{
    delete pnode;
    pnode = nullptr;
}
void DestroyBinaryTree(BTnode *&proot)
{
    traverseTree(proot, donothing, donothing, destroyBinaryNode);
}

// after insertion, return the father of inserted node.
BTnode *insertBinaryTree(BTnode *pnode, BTnode *proot) // We assume the function will be used when it's certain that proot is not nullptr.
{
    BTnode *pprev, *pnext;
    pnext = proot;
    do{
        pprev = pnext;
        if(pprev->data > pnode->data)
        {
            pnext = pprev->lc; 
        }
        else
        {
            pnext = pprev->rc;
        }
    }while(pnext != nullptr);
    if(pprev->data > pnode->data)
    {
        pprev->lc = pnode; 
    }
    else
    {
        pprev->rc = pnode;
    }
    return pprev;
}

BTnode* ConstructBinaryTree()
{
    BTnode *pnode, *proot;
    char comma;
    int data;
    
    cin >> data >> comma;
    pnode = creatNode(data);
    if(pnode != nullptr)
    {
        proot = pnode;
        while(cin.peek() != '\n' && pnode != nullptr)
        {
            cin >> data >> comma;
            pnode = creatNode(data);
            if(pnode != nullptr)
            {
                insertBinaryTree(pnode, proot);
            }
        }
        if(pnode == nullptr)
        {
            DestroyBinaryTree(proot);
        }
    }
    return proot;
}


void displayNum(BTnode *&pnode)
{
    cout << pnode->data << ',';
}
/*
void preOrder(BTnode *proot)
{
    traverseTree(proot, displayNum, donothing, donothing);
}
*/
void inOrder(BTnode *proot)
{
    traverseTree(proot, donothing, displayNum, donothing);
}
void postOrder(BTnode *proot)
{
    traverseTree(proot, donothing, donothing, displayNum);
}

int main()
{
    BTnode *proot = ConstructBinaryTree();
    if(proot != nullptr)
    {
        //displayTree(proot);
        /*
        preOrder(proot);
        cout << endl;
        */
        
        postOrder(proot);
        cout << endl;

        inOrder(proot);
        cout << endl;

        DestroyBinaryTree(proot);
        proot = nullptr;
    }
    
    return 0;
}
