#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include <iomanip>
#include <new>

#include <stack>

/* The < used in this program must be a total order.*/

template <class T>
class BSTNode{
    public:
        T data;
        BSTNode *P, *LC, *RC; // parent, left children, right children

        BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
            data(value),parent(p),left(l),right(r) {}
};

template <class T>
class BSTree{
    private:
        BSTNode<T> *Root;

    public:
        BSTree();
        ~BSTree();

        void preOrder();
        void inOrder();
        void postOrder();

        BSTNode<T>* search_recursive(T data);
        BSTNode<T>* search_iterative(T data);

        void print_recursive();
        void print_iterative();

        int insert(T data);
        void remove(T data);
        void destroy();
        
    private:
        void preOrder(BSTNode<T>* tree) const;
        void inOrder(BSTNode<T>* tree) const;
        void postOrder(BSTNode<T>* tree) const;

        BSTNode<T>* search_recursive(BSTNode<T>* x, T data) const;
        BSTNode<T>* search_iterative(BSTNode<T>* x, T data) const;

        void print_recursive(BSTNode<T>* tree, int direction);
        void print_iterative(BSTNode<T>* tree, int direction);

        int insert(BSTNode<T>* tree, BSTNode<T>* z);
        BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);
        void destroy(BSTNode<T>* &tree);
};

template <class T>
BSTree<T>::BSTree():Root(nullptr)
{
}

template <class T>
BSTree<T>::~BSTree()
{
    destroy();
}

template <class T>
int insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
   if(z == nullptr)
   {
       std::cout << "The node to be inserted is nullptr." << std::endl;
       return 1;
   }
   else
   {
       if(tree == nullptr)
       {
           tree = z;
           return 2;
       }
       else
       {
            BSTNode<T> *prev, *next;
            next = tree;
            do
            {
                prev = next;
                if(z->data > prev->data)
                {
                    next = prev->right;
                }
                else if (z->data < prev->data)
                {
                    next = prev->left;
                }
                else
                {
                    std::cout << "The node to be inserted is already in." << std::endl;
                }
            } while (next != nullptr);
            z->P = prev;
            if(z->data == prev->data)
            {
                return 3;
            }
            else
            {
                if(z->data > prev->data)
                {
                    prev->right = z;
                }
                else
                {
                    prev->left = z;
                }
                return 0;
            } 
        }
    }
}

template <class T>
int BSTree<T>::insert(T data)
{
    
}

#endif