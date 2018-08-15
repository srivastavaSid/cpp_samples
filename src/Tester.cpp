#include <iostream>

class Base {
public:
    virtual void print(char a) {
        std::cout << "Base " << a << std::endl;
    }
};

class Derived: public Base {
public:
    void print (float f) {
        std::cout << "Derived " << f << std::endl;
    }
};

int main() {
    Derived d;
    d.print('a');
    return 0;
}
/*
// create tree using inOrder and preOrder arr
#include <queue>

struct treeNode {
    treeNode (int x=0, treeNode* lch=nullptr, treeNode* rch=nullptr)
        : data(x), left(lch), right(rch) {}
    int data;
    treeNode *left, *right;
};

treeNode* crtTree(int *pre, int *in, int sz) {
    int idx(0);
    while (idx < sz) {
        if (in[idx] == pre[0])
            break;
        idx++;
    }

    treeNode *temp = new treeNode(pre[0]);
    if (idx != 0) {
        temp->left = crtTree(pre+1, in, idx);
    }

    if (idx != sz-1) {
        temp->right = crtTree(pre+idx+1, in+idx+1, sz-1-idx);
    }

    return temp;
}

void levelOrder(treeNode* root) {
    std::queue<treeNode*> tempQ;
    tempQ.push(root);
    tempQ.push(nullptr);
    while(! tempQ.empty()) {
        treeNode* temp = tempQ.front();
        tempQ.pop();
        if (temp != nullptr) {
            std::cout << temp->data << " ";
            if (temp->left != nullptr)
                tempQ.push(temp->left);
            if (temp->right != nullptr)
                tempQ.push(temp->right);
        }
        else {
            std::cout << std::endl;
            if (tempQ.size() != 0)
                tempQ.push(nullptr);
        }
    }
    std::cout << std::endl;
}

bool ancestorNodePath (treeNode* root, std::vector<treeNode*>& infoVec, const int& x) {
    if (root == nullptr)
        return false;

    if (root->data == x) {
        infoVec.push_back(root);
        return true;
    }

    if (ancestorNodePath(root->left, infoVec, x) || ancestorNodePath(root->right, infoVec, x)) {
        infoVec.push_back(root);
        return true;
    }
    else
        return false;
}

void printPostOrder(int *pre, int *in, int sz) {
    int idx(0);
    while (idx < sz) {
        if (in[idx] == pre[0])
            break;
        idx++;
    }
    // print left
    if (idx != 0)
        printPostOrder(pre+1, in, idx);

    // print right
    if (idx != sz-1)
        printPostOrder(pre+idx+1, in+idx+1, sz-1-idx);

    // print node
    std::cout << " " << pre[0];
}

void inorderTrav(treeNode *root, std::vector<int>& inOrderVec) {
    if (root == nullptr)
        return;
    inorderTrav(root->left, inOrderVec);
    inOrderVec.push_back(root->data);
    inorderTrav(root->right, inOrderVec);
}

void inorderTravUpdate(treeNode *root, std::vector<int>& inOrderVec) {
    if (root == nullptr)
        return;
    static int idx = 1;
    inorderTravUpdate(root->left, inOrderVec);
    root->data = inOrderVec[idx-1] + inOrderVec[idx+1];
    idx++;
    inorderTravUpdate(root->right, inOrderVec);
}

void updateWithSumOfInorderPreAndSuc(treeNode* root) {
    std::vector<int> inOrder = {0};
    inorderTrav(root, inOrder);
    inOrder.push_back(0);
    inorderTravUpdate(root, inOrder);
}

int main() {
    int inOrder[]  = {8,4,9,2,5,1,10,6,11,3,7};
    int preOrder[] = {1,2,4,8,9,5,3,6,10,11,7};
    int sz = sizeof(inOrder)/sizeof(inOrder[0]);
    printPostOrder(preOrder, inOrder, sz);
    std::cout << std::endl;
    treeNode *root = crtTree(preOrder, inOrder, sz);
    levelOrder(root);
    std::vector<treeNode*> infoAncs;
    if (ancestorNodePath(root, infoAncs, 11)) {
        int dpth = infoAncs.size();
        for(int i=0; i<dpth/2; i++) {
            std::swap(infoAncs[i]->data, infoAncs[dpth-1-i]->data);
        }
        levelOrder(root);
    }
    updateWithSumOfInorderPreAndSuc(root);
    levelOrder(root);
}
*/

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

/*
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
*/

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