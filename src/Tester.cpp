#include <iostream>

/*
#include "LinkList.h"

void linkListToTree() {

}
void main() {
    linkList<int> tester;
    for (int i=1; i<16; i++)
        tester.pushBack(i);
    tester.printList();

    tester.pushBack(1);
    tester.pushBack(2);
    tester.pushBack(3);
    tester.pushFront(4);
    tester.popBack();
    tester.printList();

    linkList<int> tester2 = tester;
    tester2.pushFront(3);
    tester2.printList();

    const linkList<int> tester3 = tester;
    tester3.printList();
}
*/

/*
#include "AugmentedBinarySearchTree.h"

void main() {
    augmentedBst<int> aBst;
    aBst.insert(6);
    aBst.insert(3);
    aBst.insert(2);
    aBst.insert(5);
    aBst.insert(4);
    std::cout << "Rank 4 element = " << aBst.getRank(6) << std::endl;
}
*/


#include "BinaryTree.h"

void main() {
    binTree<int> bst;
    for (int i=0; i<9; i++)
        bst.insert(i);
    bst.printTree();
    bst.mirror();
    bst.printTree();
    std::cout << "Height of tree = " << bst.getHeight() << std::endl;
    bst.printAncestor(7);
    std::cout << "Dia of tree = " << bst.getDiameter() << std::endl;
    bst.insert(4);
    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    bst.insert(2);
    bst.printTree();
    bst.inorderTraverse();
    bst.inorderTraverseItr();
    binTree<int> bst2 = bst;
    bst2.insert(6);
    bst2.printTree();
    std::cout << "done" << std::endl;
    bst = bst2;
    bst.insert(4);
    bst.printTree();
    std::cout << "Height of tree = " << bst.getHeight() << std::endl;
    std::cout << "Dia of tree = " << bst.getDiameter() << std::endl;
    bst.remove(3);
    bst.printTree();
    bst.remove(4);
    bst.printTree();
}


/*
#include "BinarySearchTree.h"

void main() {
    binSearchTree<int> bst;
    bst.insert(4);
    bst.insert(3);
    bst.insert(5);
    bst.insert(1);
    bst.insert(2);
    bst.printTree();
    bst.inorderTraverse();
    bst.inorderTraverseItr();
    binSearchTree<int> bst2 = bst;
    bst2.insert(6);
    bst2.printTree();
    std::cout << "done" << std::endl;
    bst = bst2;
    bst.insert(4);
    bst.insert(4);
    bst.insert(4);
    bst.insert(4);
    bst.insert(4);
    bst.insert(4);
    bst.printTree();
    std::cout << "Height of tree = " << bst.getHeight() << std::endl;
    std::cout << "Dia of tree = " << bst.getDiameter() << std::endl;
    bst.remove(3);
    bst.printTree();
    bst.remove(4);
    bst.printTree();
    return;
}
*/