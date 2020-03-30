#include <iostream>
#include "QueueCpp.h"
#include "treeOperations.h"

int main()
{
    Tree t;
    t.createTree();
    std::cout<<"\n";
    
    t.preOrder(t.root);
    std::cout<<"\n";
    
    t.postOrder(t.root);
    std::cout<<"\n";
    
    t.inOrder(t.root);
    std::cout<<"\n";
    
    t.levelOrder(t.root);
    std::cout<<"\n";
    
    std::cout<<t.countNode(t.root);
    std::cout<<"\n";
    
    std::cout<<t.height(t.root)<<"\n";
    
}
