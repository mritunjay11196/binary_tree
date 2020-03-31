

#ifndef treeOperations_h
#define treeOperations_h

#include "QueueCpp.h"

struct Tree
{
public:
    Node* root;
public:
    Tree(){root = NULL;}
    void createTree();
    void preOrder(Node* p);
    void postOrder(Node* p);
    void inOrder(Node* p);
    void levelOrder(Node* p);
    int countNode(Node* p);
    int height(Node* p);
};

void Tree::createTree()
{
    Node* t;
    Node* p;
    Queue q(100);
    
    std::cout<<"Enter root value: ";
    int value;
    std::cin>>value;
    
    root = new Node;
    root->lchild = root->rchild = NULL;
    root->data = value;
    
    q.enqueue(root);
    
    while(!q.isEmpty())
    {
        p = q.dequeue();
        std::cout<<"Enter value of left child of "<<p->data<<": ";
        std::cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->lchild = t->rchild = NULL;
            t->data = value;
            p->lchild = t;
            q.enqueue(t);
        }
        
        std::cout<<"Enter value of right child "<<p->data<<": ";
        std::cin>>value;
        if(value != -1)
        {
            t = new Node;
            t->lchild = t->rchild = NULL;
            t->data = value;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preOrder(Node* p)
{
    if(p)
    {
        std::cout<<p->data<<" ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
    
}

void Tree::postOrder(Node* p)
{
    if(p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        std::cout<<p->data<<" ";
    }
    
}

void Tree::inOrder(Node* p)
{
    if(p)
    {
        inOrder(p->lchild);
        std::cout<<p->data<<" ";
        inOrder(p->rchild);
    }
    
}

void Tree::levelOrder(Node* p)
{
    Queue q(100);
     
    std::cout<<p->data<<" ";
    q.enqueue(p);
    
    while(!q.isEmpty())
    {
        p = q.dequeue();
        if(p->lchild)
        {
            std::cout<<p->lchild->data<<" ";
            q.enqueue(p->lchild);
        }
        if(p->rchild)
        {
            std::cout<<p->rchild->data<<" ";
            q.enqueue(p->rchild);
        }
    }
}

int Tree::countNode(Node* p)
{
    if(p)
        return countNode(p->lchild)+countNode(p->lchild)+1;
    return 0;
}

int Tree::height(Node* p)
{
    if(p == 0)
        return 0;
    else
    {
        int x=0, y=0;
        x = height(p->lchild);
        y = height(p->rchild);
        if(x>y)
            return x+1;
        else
            return y+1;
    }
}


#endif /* treeOperations_h */
