#ifndef binarySearchTree_h
#define binarySearchTree_h

#include <iostream>
#include "BinaryTree.h"

template<typename T>
class binSearchTree: public binTree<T> {
public:
    binSearchTree ()
        : binTree() {}
    binSearchTree (const binSearchTree& rhs)
        : binTree(rhs) {}
    binSearchTree (binSearchTree&& rhs)
        : binTree(std::move(rhs)) {}
    binSearchTree& operator=(const binSearchTree& rhs) {
        binTree::operator=(rhs);
        return *this;
    }
    binSearchTree& operator=(binSearchTree&& rhs) {
        binTree::operator=(std::move(rhs));
        return *this;
    }
    void insert(const T& x) {
        treeNode* temp = new treeNode(x);
        insertUtil(temp);
    }
    void insert(T&& x) {
        treeNode* temp = new treeNode(std::move(x));
        insertUtil(temp);
    }
    T lowestCommonAncestor(const T& a, const T& b) {
        if (root == nullptr) {
            std::cout << "Tree does not exist" << std::endl;
            return;
        }
        treeNode *lca(nullptr), *temp(root);
        while (lca == nullptr) {
            if (temp->data > a && temp->data > b)
                temp = temp->left;
            else if (temp->data < a && temp->data < b)
                temp = temp->right;
            else
                lca = temp;
        }
        return lca->data;
    }
    void remove(const T& x) {
        root = remUtil(root, x);
    }
private:
    void insertUtil(treeNode* temp) {
        if (root == nullptr) {
            root = temp;
            return;
        }
        treeNode* itr = root;
        while (1) {
            if (temp->data > itr->data) {
                if (itr->right != nullptr)
                    itr = itr->right;
                else {
                    itr->right = temp;
                    break;
                }
            }
            else {
                if (itr->left != nullptr)
                    itr = itr->left;
                else {
                    itr->left = temp;
                    break;
                }
            }
        }
        return;
    }
    treeNode* remUtil(treeNode* pTrNd, const T& x) {
        if (pTrNd != nullptr) {
            if (pTrNd->data > x) {
                pTrNd->left = remUtil(pTrNd->left, x);
            }
            else if (pTrNd->data < x) {
                pTrNd->right = remUtil(pTrNd->right, x);
            }
            else {
                treeNode* temp(nullptr);
                if (pTrNd->left == nullptr) {
                    temp = pTrNd; 
                    pTrNd = pTrNd->right;
                    delete temp;
                }
                else if (pTrNd->right == nullptr) {
                    temp = pTrNd;
                    pTrNd = pTrNd->left;
                    delete temp;
                }
                else {
                    temp = pTrNd->right;
                    if (temp->left == nullptr) {
                        std::swap(pTrNd->data, temp->data);
                        pTrNd->right = temp->right;
                        delete temp;
                    }
                    else {
                        treeNode* tempParent = temp;
                        temp = temp->left;
                        while (temp->left != nullptr) {
                            tempParent = temp;
                            temp = temp->left;
                        }
                        std::swap(pTrNd->data, temp->data);
                        tempParent->left = nullptr;
                        delete temp;
                    }
                }
            }
        }
        return pTrNd;
    }
};
#endif